#!/usr/bin/env python3
"""
ArmosBridge — ROS2 <-> CyRoSimulator bridge, following the same architecture
as UDPInterface (sim_cyro/udp_interface.py):

  - Main thread   : sim.run(headless=False) -> owns physics + MuJoCo viewer.
  - Background    : rclpy.spin(node)         -> owns ROS2 I/O (like _cmd_loop).
  - No lock, no mailbox: subscriber callbacks write straight into `self._sim`,
    exactly like UDPInterface._dispatch() does. Telemetry is published from
    inside sim.on_step(), exactly like UDPInterface._on_sim_step().

Per-arm topics/services; arm identity is inferred from endpoint name
(e.g. /armos/<arm_id>/joint_control), not from a message field.

Mode model:
  1. The per-message `mode` field selects the concrete CyRoSimulator
      ControlMode, same mapping UDPInterface._dispatch uses.
  2. Per arm, set_mode is called only when the requested ControlMode changes
      (including the first received command), then retained until changed.

Safety-relevant deviation from UDPInterface._dispatch's literal statement
order: UDP calls `sim.set_mode(...)` *before* writing the target (e.g.
set_tcp_pose). That's two separate Python statements, so there's a small
GIL-preemption window where the sim thread could run a tick already in the
new mode but before the new target lands — reading whatever the previous
target was. Here the target is written *first*, `set_mode` *last*, which
closes that specific window: set_joint_pos/set_tcp_pose/etc. don't depend on
which mode is currently active, so writing them early is safe, and by the
time set_mode flips, the target is already fresh.

ASSUMPTIONS — confirm against your actual generated interfaces and
sim_types.py; each is marked inline with `# ASSUMPTION:`.
"""

import threading
import time
from functools import partial
from pathlib import Path

import numpy as np
import rclpy
import yaml
from ament_index_python.packages import get_package_share_directory
from rclpy.node import Node

# ASSUMPTION: message/service package name — adjust to your actual package.
from armos_interfaces.msg import ArmosCartControl, ArmosJointControl, ArmosTelemetry
from armos_interfaces.srv import ArmosSetGripper

from sim.simulator import CyRoSimulator
from sim.sim_types import ControlMode, Telemetry

# ASSUMPTION: ControlMode members match sim_cyro.types usage seen in
# udp_interface.py (JOINT_POS, JOINT_VEL, JOINT_TORQUE, TASK_POSE, TASK_VEL).
_JOINT_SUBMODE = {
    0: ControlMode.JOINT_POS,
    1: ControlMode.JOINT_VEL,
    2: ControlMode.JOINT_TORQUE,
}
_CART_SUBMODE = {
    0: ControlMode.TASK_POSE,
    1: ControlMode.TASK_VEL,
}
_DEFAULT_CONFIG_NAME = "duman.yaml"

def _euler_to_rotmat(a: float, b: float, c: float) -> np.ndarray:
    """a, b, c -> rotation matrix.

    ASSUMPTION: intrinsic XYZ (roll-pitch-yaw) convention, radians — confirm
    against whatever produces ArmosCartControl on the sending side. A wrong
    convention here gives a silently wrong orientation, not an error.
    """
    ca, sa = np.cos(a), np.sin(a)
    cb, sb = np.cos(b), np.sin(b)
    cc, sc = np.cos(c), np.sin(c)
    Rx = np.array([[1, 0, 0], [0, ca, -sa], [0, sa, ca]])
    Ry = np.array([[cb, 0, sb], [0, 1, 0], [-sb, 0, cb]])
    Rz = np.array([[cc, -sc, 0], [sc, cc, 0], [0, 0, 1]])
    return Rz @ Ry @ Rx


class ArmosBridge(Node):
    def __init__(self, sim: CyRoSimulator):
        super().__init__("armos_bridge")
        self._sim = sim
        self._active_mode = {arm_id: None for arm_id in sim.arm_ids}

        # --- per-arm topics/services; arm is inferred from endpoint name ---
        self._joint_sub = {}
        self._cart_sub = {}
        self._telem_pub = {}
        self._gripper_srv = {}
        for arm_id in sim.arm_ids:
            base = f"/armos/{arm_id}"
            self._gripper_srv[arm_id] = self.create_service(
                ArmosSetGripper,
                f"{base}/setgripper",
                partial(self._on_set_gripper, arm_id),
            )
            self._joint_sub[arm_id] = self.create_subscription(
                ArmosJointControl,
                f"{base}/joint_control",
                partial(self._on_joint_cmd, arm_id),
                10,
            )
            self._cart_sub[arm_id] = self.create_subscription(
                ArmosCartControl,
                f"{base}/cart_control",
                partial(self._on_cart_cmd, arm_id),
                10,
            )
            
            self._telem_pub[arm_id] = self.create_publisher(
                ArmosTelemetry,
                f"{base}/telemetry",
                10,
            )

        # --- startup: joint-position mode, YAML home config, per requirement ---
        for arm_id in sim.arm_ids:
            cfg = sim.arm_config(arm_id)
            sim.set_joint_pos(arm_id, cfg.q_home)   # target first
            sim.set_mode(arm_id, ControlMode.JOINT_POS)  # mode last

        sim.on_step(self._publish_telemetry)  # telemetry published in the sim's own loop

        self.get_logger().info(
            f"ArmosBridge ready | arms={sim.arm_ids} | "
            f"startup mode=JOINT_POS, target=q_home | per-arm endpoints=/armos/<arm_id>/*"
        )

    # ------------------------------------------------------------------ #
    # ROS2 callbacks (background thread) — write straight into sim, no   #
    # lock/mailbox, matching UDPInterface._dispatch's direct-write model #
    # ------------------------------------------------------------------ #
    def _on_joint_cmd(self, arm_id: str, msg: ArmosJointControl):
        if msg.mode not in _JOINT_SUBMODE:
            self.get_logger().warn(f"[{arm_id}] unknown joint mode {msg.mode}")
            return

        ndof = self._sim.ndof(arm_id)
        q = np.array(
            [msg.joint1, msg.joint2, msg.joint3, msg.joint4,
             msg.joint5, msg.joint6, msg.joint7],
            dtype=float,
        )[:ndof]  # ASSUMPTION: extra fields ignored for <7-DOF arms

        if msg.mode == 0:
            self._sim.set_joint_pos(arm_id, q)
        elif msg.mode == 1:
            self._sim.set_joint_vel(arm_id, q)
        elif msg.mode == 2:
            self._sim.set_joint_torque(arm_id, q)
        self._maybe_set_mode(arm_id, _JOINT_SUBMODE[msg.mode])

    def _on_cart_cmd(self, arm_id: str, msg: ArmosCartControl):
        if msg.mode not in _CART_SUBMODE:
            self.get_logger().warn(f"[{arm_id}] unknown cart mode {msg.mode}")
            return

        if msg.mode == 0:  # pose: x,y,z = position, a,b,c = euler orientation
            pos = np.array([msg.x, msg.y, msg.z], dtype=float)
            rot = _euler_to_rotmat(msg.a, msg.b, msg.c)
            self._sim.set_tcp_pose(arm_id, pos, rot)
        else:  # velocity: x,y,z = linear vel, a,b,c = angular vel
            lin = np.array([msg.x, msg.y, msg.z], dtype=float)
            ang = np.array([msg.a, msg.b, msg.c], dtype=float)
            self._sim.set_tcp_vel(arm_id, lin, ang)
        self._maybe_set_mode(arm_id, _CART_SUBMODE[msg.mode])

    def _on_set_gripper(
        self,
        arm_id: str,
        request: ArmosSetGripper.Request,
        response: ArmosSetGripper.Response,
    ):
        position = request.position
        try:
            self._sim.set_gripper(arm_id, position)
        except (KeyError, ValueError) as exc:
            response.success = False
            response.message = str(exc)
            return response

        response.success = True
        response.message = "Gripper position set"
        return response

    # ------------------------------------------------------------------ #
    # Sim-thread hook — called from inside sim._tick() via on_step,      #
    # same as UDPInterface._on_sim_step. Loops over arms every tick.     #
    # ------------------------------------------------------------------ #
    def _publish_telemetry(self, tick: int, t: float, telem: Telemetry):
        for arm_id in self._sim.arm_ids:
            arm_t = self._get_arm_telem(telem, arm_id)
            if arm_t is None:
                continue
            msg = ArmosTelemetry()
            msg.timestamp = float(telem.timestamp)
            msg.joint_pos = self._float_array(arm_t["joint_pos"])
            msg.joint_vel = self._float_array(arm_t["joint_vel"])
            msg.joint_torque = self._float_array(arm_t["joint_torque"])
            msg.wrench = self._float_array(arm_t["wrench"])
            msg.tcp_pose = self._float_array(arm_t["tcp_pose"])
            msg.tcp_twist = self._float_array(arm_t["tcp_twist"])
            msg.manipulability = float(arm_t["manipulability"])
            msg.singularity_distance = float(arm_t["singularity_distance"])
            self._telem_pub[arm_id].publish(msg)

    # ------------------------------------------------------------------ #
    # Helpers                                                            #
    # ------------------------------------------------------------------ #
    def _get_arm_telem(self, telem: Telemetry, arm_id: str):
        if arm_id not in telem.joint_pos:
            return None

        return {
            "joint_pos": telem.joint_pos[arm_id],
            "joint_vel": telem.joint_vel.get(arm_id, np.zeros(0)),
            "joint_torque": telem.joint_torque.get(arm_id, np.zeros(0)),
            "wrench": telem.wrench.get(arm_id, np.zeros(6)),
            "tcp_pose": telem.tcp_pose.get(arm_id, np.zeros((4, 4))),
            "tcp_twist": telem.tcp_twist.get(arm_id, np.zeros(6)),
            "manipulability": telem.manipulability.get(arm_id, 0.0),
            "singularity_distance": telem.singularity_distance.get(arm_id, 0.0),
        }

    @staticmethod
    def _float_array(value) -> list[float]:
        return np.asarray(value, dtype=float).reshape(-1).tolist()

    def _maybe_set_mode(self, arm_id: str, requested_mode: ControlMode):
        if self._active_mode.get(arm_id) == requested_mode:
            return
        self._sim.set_mode(arm_id, requested_mode)
        self._active_mode[arm_id] = requested_mode

    def _current_joint_pos(self, telem: Telemetry, arm_id: str) -> np.ndarray:
        arm_t = self._get_arm_telem(telem, arm_id)
        if arm_t is not None:
            return np.asarray(arm_t["joint_pos"], dtype=float).copy()
        return self._sim.arm_config(arm_id).q_home.copy()  # fallback

def _resolve_config_path(config_path: str | None = None) -> Path:
    candidates = []

    if config_path:
        requested_path = Path(config_path).expanduser()
        if requested_path.is_absolute():
            candidates.append(requested_path)
        else:
            candidates.extend((Path.cwd() / requested_path, requested_path))

    if config_path is None or config_path == _DEFAULT_CONFIG_NAME:
        try:
            share_dir = Path(get_package_share_directory("armos_control"))
            candidates.append(share_dir / "config" / _DEFAULT_CONFIG_NAME)
        except Exception:
            pass

    script_path = Path(__file__).resolve()
    for base in [script_path.parent, *script_path.parents[:6]]:
        candidates.append(base / "config" / (config_path or _DEFAULT_CONFIG_NAME))

    for path in candidates:
        if path.exists():
            return path

    raise FileNotFoundError(
        f"Could not locate configuration file '{config_path or _DEFAULT_CONFIG_NAME}'. "
        "Pass an absolute path or a path relative to the current directory."
    )


def _resolve_runtime_config(config_path: Path) -> Path:
    with open(config_path, "r", encoding="utf-8") as fh:
        cfg = yaml.safe_load(fh) or {}

    scene_name = cfg.get("scene_xml_path")
    robot_name = cfg.get("robot_xml_path")
    if not scene_name or not robot_name:
        raise ValueError(
            f"Configuration {config_path} must define scene_xml_path and robot_xml_path"
        )

    script_path = Path(__file__).resolve()
    asset_dirs = [config_path.parent]
    for base in [script_path.parent, *script_path.parents[:6]]:
        for workspace_root in (base, base / "mujoco_manipulation"):
            assets_root = workspace_root / "armos_sim" / "assets"
            for candidate in (assets_root, assets_root / cfg.get("assets_dir")):
                if candidate not in asset_dirs:
                    asset_dirs.append(candidate)

    def find_asset(name: str) -> Path | None:
        requested = Path(name).expanduser()
        candidates = [requested] if requested.is_absolute() else [
            asset_dir / requested for asset_dir in asset_dirs
        ]
        return next((candidate.resolve() for candidate in candidates if candidate.is_file()), None)

    scene_xml = find_asset(scene_name)
    robot_xml = find_asset(robot_name)
    if scene_xml is None or robot_xml is None:
        raise FileNotFoundError(
            f"MuJoCo XML assets from {config_path} were not found: "
            f"scene_xml_path={scene_name!r}, robot_xml_path={robot_name!r}"
        )

    cfg["scene_xml_path"] = str(scene_xml)
    cfg["robot_xml_path"] = str(robot_xml)

    runtime_path = config_path.with_name(f"{config_path.stem}_runtime.yaml")
    with open(runtime_path, "w", encoding="utf-8") as fh:
        yaml.safe_dump(cfg, fh, sort_keys=False)

    return runtime_path


def main():
    rclpy.init()

    config_node = rclpy.create_node("armos_config")
    config_node.declare_parameter("config_path", _DEFAULT_CONFIG_NAME)
    config_name = config_node.get_parameter("config_path").value
    config_node.destroy_node()

    config_path = _resolve_config_path(str(config_name))
    runtime_config = _resolve_runtime_config(config_path)
    sim = CyRoSimulator(config_path=runtime_config)
    node = ArmosBridge(sim)

    spin_thread = threading.Thread(target=rclpy.spin, args=(node,), daemon=True)
    spin_thread.start()

    try:
        time.sleep(1)  # let OS scheduler settle before launching the viewer
        sim.run(headless=False)  # blocks main thread; opens the MuJoCo viewer
    finally:
        sim.close()
        rclpy.shutdown()
        spin_thread.join(timeout=1.0)


if __name__ == "__main__":
    main()