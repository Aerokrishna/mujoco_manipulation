"""CyRoSimulator — high-level API for the tri-arm simulation."""

from __future__ import annotations

import logging
import multiprocessing
import sys
import threading
import time
from pathlib import Path
from typing import TYPE_CHECKING, Callable, Dict, List, Optional

# if TYPE_CHECKING:

import mujoco
import mujoco.viewer
import numpy as np

from constants import _CONTROL_HZ, _N_SUBSTEPS
from controller import _ArmController, _PinkSolver
from loader import _RobotLoader
from mj_model import _MuJoCoModel
from pinocchio_sync import _PinocchioSync
from telemetry import _TelemetryCollector
from sim_types import ArmConfig, ControlMode, Telemetry
from viewer_frames import (
    draw_all_frames,
    poses_equal,
    read_object_pose,
    resolve_object_ref,
)
from sim_types import ArmConfig, ControlMode, Telemetry, ToolParams

try:
    import pinocchio  # noqa: F401
    _PIN_OK = True
except ImportError:
    _PIN_OK = False

try:
    import pink  # noqa: F401
    _PINK_OK = True
except ImportError:
    _PINK_OK = False

logger = logging.getLogger(__name__)

_VIEWER_SYNC_STRIDE = max(1, _CONTROL_HZ // 25)


def _resolve_config_path(config_path) -> Path:
    """Resolve config path; use bundled default if None."""
    if config_path is not None:
        return Path(config_path)
    assets = Path(__file__).parent / ".." / "assets" / "franka_emika_panda"
    default = assets / "config_cyro_audi.yaml"
    if not default.exists():
        raise FileNotFoundError(
            f"Default config not found at {default}. "
            "Install the package properly or pass config_path explicitly."
        )
    return default


class CyRoSimulator:
    """
    High-level simulator for the CyRo tri-arm robot.

    Parameters
    ----------
    config_path : str | Path, optional
        Path to YAML config. Defaults to bundled config_cyro_audi.yaml.
    xml_path : str | Path, optional
        Path to MJCF scene (programmatic use).
    arm_configs : dict[str, ArmConfig], optional
        Pre-built arm configs (paired with xml_path).
    """

    def __init__(
        self,
        config_path=None,
        *,
        xml_path=None,
        arm_configs: Optional[Dict[str, ArmConfig]] = None,
    ):
        logging.basicConfig(
            level=logging.INFO,
            format="%(asctime)s [%(levelname)s] %(name)s: %(message)s",
        )

        if xml_path is not None and arm_configs is not None:
            self._xml_path = Path(xml_path)
            self._arm_configs = arm_configs
            self._aux_config = dict(_RobotLoader._DEFAULT_AUX)
        else:
            cfg_path = _resolve_config_path(config_path)
            self._xml_path, self._arm_configs, self._aux_config = _RobotLoader.from_yaml(
                cfg_path
            )

        preloaded = self._aux_config.pop("_preloaded_model", None)
        self._mj = _MuJoCoModel(self._xml_path, preloaded_model=preloaded)
        self._pin_sync = _PinocchioSync(self._arm_configs, self._mj)

        self._pink_solvers: Dict[str, Optional[_PinkSolver]] = {
            arm_id: (
                _PinkSolver(
                    cfg,
                    self._pin_sync._pin_models[arm_id],
                    self._pin_sync._pin_data[arm_id],
                )
                if (_PINK_OK and arm_id in self._pin_sync._pin_models)
                else None
            )
            for arm_id, cfg in self._arm_configs.items()
        }

        self._controllers: Dict[str, _ArmController] = {
            arm_id: _ArmController(
                cfg,
                self._mj,
                self._pin_sync,
                self._pink_solvers[arm_id],
            )
            for arm_id, cfg in self._arm_configs.items()
        }

        self._telem = _TelemetryCollector(
            self._mj,
            self._arm_configs,
            self._pin_sync,
            self._controllers,
            self._aux_config,
        )

        self._sim_time = 0.0
        self._dt = 1.0 / _CONTROL_HZ
        self._running = False
        self._callbacks: list[Callable[[int, float, Telemetry], None]] = []
        self._pre_tick_callbacks: list[Callable[[], None]] = []
        self._last_telem: Optional[Telemetry] = None
        self._object_frames: list[str] = []
        self._custom_frames: dict[str, np.ndarray] = {}
        self._frames_redraw_pending = False
        self._object_frame_ref_cache: dict[str, tuple] = {}
        self._drawn_object_pose_cache: dict[str, tuple] = {}
        self._frames_lock = threading.Lock()

        self._reset_to_home()
        logger.info(
            "CyRoSimulator ready | arms=%s | %d Hz | %d substeps | "
            "Pinocchio=%s | Pink=%s",
            list(self._arm_configs.keys()),
            _CONTROL_HZ,
            _N_SUBSTEPS,
            _PIN_OK,
            _PINK_OK,
        )

    @property
    def sim_time(self) -> float:
        return self._sim_time

    @property
    def arm_ids(self) -> List[str]:
        return list(self._arm_configs.keys())

    def ndof(self, arm_id: str) -> int:
        return self._arm_configs[arm_id].ndof

    def arm_config(self, arm_id: str) -> ArmConfig:
        self._check_arm(arm_id)
        return self._arm_configs[arm_id]

    def set_tool_params(self, arm_id: str, tool: ToolParams) -> None:
        self._check_arm(arm_id)
        self._arm_configs[arm_id].tool = tool

    def set_mode(self, arm_id: str, mode: ControlMode) -> None:
        self._check_arm(arm_id)
        self._controllers[arm_id].set_mode(mode)

    def set_joint_pos(self, arm_id: str, q) -> None:
        self._check_arm(arm_id)
        self._controllers[arm_id].set_joint_pos(np.asarray(q, dtype=float))

    def set_joint_vel(self, arm_id: str, qdot) -> None:
        self._check_arm(arm_id)
        self._controllers[arm_id].set_joint_vel(np.asarray(qdot, dtype=float))

    def set_joint_torque(self, arm_id: str, tau) -> None:
        self._check_arm(arm_id)
        self._controllers[arm_id].set_joint_torque(
            np.asarray(tau, dtype=float)
        )

    def set_flange_pose(self, arm_id: str, pos, rot=None) -> None:
        self._check_arm(arm_id)
        rot = np.eye(3) if rot is None else np.asarray(rot, dtype=float)
        self._controllers[arm_id].set_flange_pose(np.asarray(pos, dtype=float), rot)

    def set_tcp_pose(self, arm_id: str, pos, rot=None) -> None:
        self._check_arm(arm_id)
        rot = np.eye(3) if rot is None else np.asarray(rot, dtype=float)
        self._controllers[arm_id].set_tcp_pose(np.asarray(pos, dtype=float), rot)

    def set_flange_vel(self, arm_id: str, linear, angular) -> None:
        self._check_arm(arm_id)
        self._controllers[arm_id].set_flange_vel(
            np.asarray(linear, dtype=float),
            np.asarray(angular, dtype=float),
        )

    def set_tcp_vel(self, arm_id: str, linear, angular) -> None:
        self._check_arm(arm_id)
        self._controllers[arm_id].set_tcp_vel(
            np.asarray(linear, dtype=float),
            np.asarray(angular, dtype=float),
        )

    def set_gripper_joints(self, arm_id: str, q) -> None:
        """Set dg3f gripper joint angles for 'left' or 'right' arm.

        q : array of 12 angles [rad], ordered finger1→finger2→finger3,
            each finger: [j1, j2, j3, j4] (proximal-to-distal).
        """
        dg3f = self._aux_config.get("dg3f_grippers", {})
        act_names = dg3f.get(arm_id)
        if not act_names:
            raise ValueError(f"No dg3f gripper configured for arm '{arm_id}'")
        q = np.asarray(q, dtype=float)
        if q.shape != (len(act_names),):
            raise ValueError(
                f"Expected {len(act_names)} joint angles, got {q.shape}"
            )
        for name, val in zip(act_names, q):
            self._mj.set_actuator(name, val)

    def set_gripper(self, arm_id: str, position: float) -> None:
        # Set gripper position. Arm must be 'left' or 'right': 0=closed, 1=open
        if arm_id not in ("left", "right"):
            raise ValueError(f"Gripper only on left/right arms, not '{arm_id}'")
        act = self._aux_config["grippers"].get(arm_id)
        if not act:
            raise ValueError(f"No gripper configured for arm '{arm_id}'")
        
        open_pos = self._aux_config["gripper_open"]
        closed_pos = self._aux_config["gripper_closed"]
        pos = np.clip(float(position), 0.0, 1.0)
        target = closed_pos + pos * (open_pos - closed_pos)

        self._mj.set_actuator(act, target)

    def set_actuator(self, actuator_name: str, value: float) -> None:
        self._mj.set_actuator(actuator_name, float(value))

    def get_telemetry(self) -> Telemetry:
        if self._last_telem is None:
            self._pin_sync.sync()
            self._last_telem = self._telem.collect(self._sim_time)
        return self._last_telem

    def show_object_frame(self, object_name: str) -> None:
        """Register an RGB axis frame on a named body, site, or geom.

        Drawn in the passive viewer loop at viewer refresh rate (~20 Hz).
        """
        if not object_name:
            return
        ref = resolve_object_ref(self._mj.model, object_name)
        if ref is None:
            logger.debug("Object frame not found in model: %r", object_name)
            return
        with self._frames_lock:
            if object_name not in self._object_frames:
                self._object_frames.append(object_name)
                self._object_frame_ref_cache[object_name] = ref
                self._frames_redraw_pending = True

    def remove_object_frame(self, object_name: str) -> None:
        """Stop drawing a named object frame overlay."""
        with self._frames_lock:
            if object_name in self._object_frames:
                self._object_frames.remove(object_name)
                self._object_frame_ref_cache.pop(object_name, None)
                self._drawn_object_pose_cache.pop(object_name, None)
                self._frames_redraw_pending = True

    def show_custom_frame(self, name: str, pose: np.ndarray) -> None:
        """Register a named 4x4 pose overlay in the MuJoCo world frame.

        Drawn in the passive viewer loop at viewer refresh rate (~20 Hz).
        Re-sending the same pose is a no-op.
        """
        if not name:
            raise ValueError("Frame name must be non-empty")
        T = np.asarray(pose, dtype=float)
        if T.shape != (4, 4):
            raise ValueError(f"Frame pose must be 4x4, got {T.shape}")
        if not np.all(np.isfinite(T)):
            raise ValueError("Frame pose must contain only finite values")
        with self._frames_lock:
            existing = self._custom_frames.get(name)
            if existing is not None and poses_equal(
                existing[:3, 3], existing[:3, :3], T[:3, 3], T[:3, :3],
            ):
                return
            self._custom_frames[name] = T.copy()
            self._frames_redraw_pending = True

    def remove_custom_frame(self, name: str) -> None:
        """Remove a named custom frame overlay."""
        with self._frames_lock:
            removed = self._custom_frames.pop(name, None)
            if removed is not None:
                self._frames_redraw_pending = True

    def _object_poses_changed(
        self,
        object_frames: list[str],
        ref_cache: dict[str, tuple[int, int]],
    ) -> bool:
        """Return True when any tracked object frame pose differs from the draw cache."""
        for name in object_frames:
            ref = ref_cache.get(name)
            if ref is None:
                changed = True
                return changed
            pos, rmat = read_object_pose(self._mj.data, ref[0], ref[1])
            cached = self._drawn_object_pose_cache.get(name)
            if cached is None:
                changed = True
                return changed
            cached_pos, cached_rmat = cached
            if not poses_equal(pos, rmat, cached_pos, cached_rmat):
                changed = True
                return changed
        changed = False
        return changed

    def _update_drawn_object_pose_cache(self, data, object_frames: list[str]) -> None:
        """Refresh the drawn-pose cache after writing object frame overlays."""
        for name in object_frames:
            ref = self._object_frame_ref_cache.get(name)
            if ref is None:
                continue
            pos, rmat = read_object_pose(data, ref[0], ref[1])
            self._drawn_object_pose_cache[name] = (pos.copy(), rmat.copy())

    def on_step(
        self,
        fn: Callable[[int, float, Telemetry], None],
    ) -> None:
        self._callbacks.append(fn)

    def before_tick(self, fn: Callable[[], None]) -> None:
        """Register a callback invoked at the very start of each tick, before
        the control loop writes data.ctrl.  Use this to forward viewer slider
        values (data.ctrl set by the passive viewer between ticks) into the
        joint-position targets before ctrl.compute() runs."""
        self._pre_tick_callbacks.append(fn)

    def step(self) -> Telemetry:
        self._tick()
        return self._last_telem  # type: ignore[return-value]

    def run(
        self,
        duration: Optional[float] = None,
        headless: bool = False,
    ) -> None:
        self._running = True
        if headless:
            self._loop_headless(duration)
        else:
            self._loop_viewer(duration)

    def stop(self) -> None:
        self._running = False

    def close(self) -> None:
        self._running = False

    def __enter__(self) -> "CyRoSimulator":
        return self

    def __exit__(self, *_) -> None:
        self.close()

    def reset(self) -> None:
        self._reset_to_home()
        self._sim_time = 0.0
        self._last_telem = None

    def _tick(self) -> None:
        for cb in self._pre_tick_callbacks:
            cb()

        dt = self._dt
        t = self._sim_time

        self._pin_sync.sync()
        self._mj.clear_applied()

        for arm_id, ctrl in self._controllers.items():
            cfg = self._arm_configs[arm_id]
            q_ref, tau_ff = ctrl.compute(dt)
            self._mj.set_ctrl_pos(cfg.actuator_names, q_ref)
            if np.any(tau_ff != 0.0):
                self._mj.add_ctrl_torque(cfg.joint_names, tau_ff)

        self._mj.physics_step()
        self._sim_time += dt

        if not np.all(np.isfinite(self._mj.data.qpos)):
            logger.warning(
                "NaN in qpos at t=%.4f — snapping to ctrl refs.", t
            )
            for arm_id, ctrl in self._controllers.items():
                cfg = self._arm_configs[arm_id]
                for i, jname in enumerate(cfg.joint_names):
                    adr = self._mj.model.jnt_qposadr[
                        self._mj.joint_id(jname)
                    ]
                    self._mj.data.qpos[adr] = ctrl._q_ref[i]
            self._mj.data.qvel[:] = 0.0
            self._mj.data.qacc[:] = 0.0
            mujoco.mj_forward(self._mj.model, self._mj.data)

        self._last_telem = self._telem.collect(t)

    def _loop_headless(self, duration: Optional[float]) -> None:
     
        tick = 0
        while self._running:
            if duration is not None and self._sim_time >= duration:
                break
            t0 = time.perf_counter()
            self._tick()
            
            if self._callbacks and self._last_telem:
                for _cb in self._callbacks:
                    _cb(tick, self._sim_time, self._last_telem)
            sleep_t = self._dt - (time.perf_counter() - t0)
            if sleep_t > 0:
                time.sleep(sleep_t)
            tick += 1
        self._running = False

    def _loop_viewer(self, duration: Optional[float]) -> None:
        
        with mujoco.viewer.launch_passive(
            self._mj.model,
            self._mj.data,
            show_left_ui=False,
            show_right_ui=False,
        ) as viewer:
            viewer.cam.azimuth = 135
            viewer.cam.elevation = -20
            viewer.cam.distance = 2.5
            viewer.cam.lookat = np.array([0.0, 0.0, 0.6])
            tick = 0
            while viewer.is_running() and self._running:
                if duration is not None and self._sim_time >= duration:
                    break
                t0 = time.perf_counter()
                self._tick()
                
                if self._callbacks and self._last_telem:
                    for _cb in self._callbacks:
                        _cb(tick, self._sim_time, self._last_telem)
                if tick % _VIEWER_SYNC_STRIDE == 0:
                    with self._frames_lock:
                        object_frames = list(self._object_frames)
                        custom_frames = dict(self._custom_frames)
                        redraw_pending = self._frames_redraw_pending
                        ref_cache = dict(self._object_frame_ref_cache)
                    if object_frames or custom_frames:
                        if redraw_pending or self._object_poses_changed(
                            object_frames, ref_cache,
                        ):
                            draw_all_frames(
                                viewer,
                                self._mj.model,
                                self._mj.data,
                                object_frames,
                                custom_frames,
                                ref_cache,
                            )
                            with self._frames_lock:
                                self._update_drawn_object_pose_cache(
                                    self._mj.data, object_frames,
                                )
                                self._frames_redraw_pending = False
                    elif redraw_pending:
                        viewer.user_scn.ngeom = 0
                        with self._frames_lock:
                            self._frames_redraw_pending = False
                    viewer.sync()
                sleep_t = self._dt - (time.perf_counter() - t0)
                if sleep_t > 0:
                    time.sleep(sleep_t)
                tick += 1

    def _reset_to_home(self) -> None:
        for arm_id, cfg in self._arm_configs.items():
            ctrl = self._controllers[arm_id]
            ctrl._q_ref = cfg.q_home.copy()
            for i, jname in enumerate(cfg.joint_names):
                adr = self._mj.model.jnt_qposadr[self._mj.joint_id(jname)]
                self._mj.data.qpos[adr] = cfg.q_home[i]
            self._mj.set_ctrl_pos(cfg.actuator_names, cfg.q_home)
        # Close grippers and zero camera yaw
        for arm_id in ("left", "right"):
            if arm_id in self._aux_config.get("grippers", {}):
                self.set_gripper(arm_id, 0.0)
        for arm_id, act_names in self._aux_config.get("dg3f_grippers", {}).items():
            for name in act_names:
                self._mj.set_actuator(name, 0.0)
        mujoco.mj_forward(self._mj.model, self._mj.data)

    def _check_arm(self, arm_id: str) -> None:
        if arm_id not in self._arm_configs:
            raise ValueError(
                f"Unknown arm '{arm_id}'. Valid: {self.arm_ids}"
            )
