"""Pinocchio sync: per-arm kinematic models synchronized with MuJoCo."""

from __future__ import annotations

import logging
from typing import Dict, Tuple

import mujoco
import numpy as np

from mj_model import _MuJoCoModel
from sim_types import ArmConfig

try:
    import pinocchio as pin
    _PIN_OK = True
except ImportError:
    _PIN_OK = False


def _wxyz_to_R(q: np.ndarray) -> np.ndarray:
    """Unit quaternion [w, x, y, z] → 3×3 rotation matrix."""
    w, x, y, z = q
    return np.array([
        [1 - 2 * (y * y + z * z), 2 * (x * y - w * z), 2 * (x * z + w * y)],
        [2 * (x * y + w * z), 1 - 2 * (x * x + z * z), 2 * (y * z - w * x)],
        [2 * (x * z - w * y), 2 * (y * z + w * x), 1 - 2 * (x * x + y * y)],
    ])


class _PinocchioSync:
    """
    Maintains one Pinocchio Model/Data per arm, synchronized with MuJoCo
    each control tick. Falls back to finite-difference Jacobians when
    Pinocchio is unavailable.
    """

    def __init__(
        self, arm_configs: Dict[str, ArmConfig], mj: _MuJoCoModel
    ):
        self._mj = mj
        self._cfgs = arm_configs
        self._pin_models: Dict[str, object] = {}
        self._pin_data: Dict[str, object] = {}
        self._q: Dict[str, np.ndarray] = {}
        self._qdot: Dict[str, np.ndarray] = {}

        for arm_id, cfg in arm_configs.items():
            self._q[arm_id] = np.zeros(cfg.ndof)
            self._qdot[arm_id] = np.zeros(cfg.ndof)
            if _PIN_OK:
                m, d = self._build_pin_model(cfg, mj.model)
                self._pin_models[arm_id] = m
                self._pin_data[arm_id] = d
                logging.getLogger(__name__).info(
                    "Pinocchio model '%s': nq=%d nv=%d", arm_id, m.nq, m.nv
                )

    @staticmethod
    def _se3_from_start_to_body(mj_model, start_id: int, body_id: int):
        """Accumulate SE3 from start_body frame to body_id frame by walking the parent chain."""
        transforms = []
        cur = body_id
        while cur != start_id:
            R = _wxyz_to_R(mj_model.body_quat[cur].copy())
            pos = mj_model.body_pos[cur].copy()
            transforms.append(pin.SE3(R, pos))
            cur = int(mj_model.body_parentid[cur])
        result = pin.SE3.Identity()
        for t in reversed(transforms):
            result = result * t
        return result

    @staticmethod
    def _build_pin_model(cfg: ArmConfig, mj_model) -> Tuple:
        model = pin.Model()
        model.name = cfg.arm_id
        parent_pin_id = 0

        start_id = mujoco.mj_name2id(
            mj_model, mujoco.mjtObj.mjOBJ_BODY, cfg.start_body
        )

        for jname in cfg.joint_names:
            jid = mujoco.mj_name2id(
                mj_model, mujoco.mjtObj.mjOBJ_JOINT, jname
            )
            body_id = int(mj_model.jnt_bodyid[jid])

            if parent_pin_id == 0:
                # First joint: place it relative to the Pinocchio universe (= start_body frame).
                # Walk the fixed body chain from start_body to this joint's body, then
                # apply the joint anchor offset. This handles start_body being an ancestor
                # of the first joint's body (e.g. *_robot_base_link → *_robot_link1).
                jnt_pos = mj_model.jnt_pos[jid].copy()
                T_start_to_body = _PinocchioSync._se3_from_start_to_body(
                    mj_model, start_id, body_id
                )
                placement = T_start_to_body * pin.SE3(np.eye(3), jnt_pos)
            else:
                R_body = _wxyz_to_R(mj_model.body_quat[body_id].copy())
                pos_body = mj_model.body_pos[body_id].copy()
                placement = pin.SE3(R_body, pos_body)
            joint_model = _PinocchioSync._revolute_model(
                mj_model.jnt_axis[jid].copy()
            )
            pin_jid = model.addJoint(
                parent_pin_id, joint_model, placement, jname
            )

            mass = float(mj_model.body_mass[body_id])
            com = mj_model.body_ipos[body_id].copy()
            inertia = np.diag(mj_model.body_inertia[body_id].copy())
            model.appendBodyToJoint(
                pin_jid,
                pin.Inertia(mass, com, inertia),
                pin.SE3.Identity(),
            )
            parent_pin_id = pin_jid

        ee_site_id  = mujoco.mj_name2id(
            mj_model, mujoco.mjtObj.mjOBJ_SITE, cfg.ee_site
        )
        ee_body_id  = int(mj_model.site_bodyid[ee_site_id])

        # Walk any fixed (jointless) bodies between the last joint's body and
        # the ee_site's parent body (e.g. Flexiv's *_robot_flange body).
        last_jid      = mujoco.mj_name2id(
            mj_model, mujoco.mjtObj.mjOBJ_JOINT, cfg.joint_names[-1]
        )
        last_body_id  = int(mj_model.jnt_bodyid[last_jid])
        T_fixed_chain = _PinocchioSync._se3_from_start_to_body(
            mj_model, last_body_id, ee_body_id
        )

        R_ee   = _wxyz_to_R(mj_model.site_quat[ee_site_id].copy())
        ee_pos = mj_model.site_pos[ee_site_id].copy()
        model.addFrame(pin.Frame(
            f"{cfg.arm_id}_ee",
            parent_pin_id,
            0,
            T_fixed_chain * pin.SE3(R_ee, ee_pos),
            pin.FrameType.OP_FRAME,
        ))

        model.lowerPositionLimit = cfg.q_lo
        model.upperPositionLimit = cfg.q_hi
        return model, model.createData()

    @staticmethod
    def _revolute_model(axis: np.ndarray):
        a = axis / (np.linalg.norm(axis) + 1e-12)
        if np.allclose(np.abs(a), [0, 0, 1], atol=0.1):
            return pin.JointModelRZ()
        if np.allclose(np.abs(a), [0, 1, 0], atol=0.1):
            return pin.JointModelRY()
        if np.allclose(np.abs(a), [1, 0, 0], atol=0.1):
            return pin.JointModelRX()
        return pin.JointModelRevoluteUnaligned(
            float(a[0]), float(a[1]), float(a[2])
        )

    def sync(self) -> None:
        for arm_id, cfg in self._cfgs.items():
            q = self._mj.get_qpos(cfg.joint_names)
            qdot = self._mj.get_qvel(cfg.joint_names)
            self._q[arm_id] = q
            self._qdot[arm_id] = qdot
            if _PIN_OK and arm_id in self._pin_models:
                m, d = self._pin_models[arm_id], self._pin_data[arm_id]
                q_pin = pin.neutral(m)
                q_pin[: cfg.ndof] = q
                pin.forwardKinematics(m, d, q_pin)
                pin.computeJointJacobians(m, d, q_pin)
                pin.updateFramePlacements(m, d)

    def get_q(self, arm_id: str) -> np.ndarray:
        return self._q[arm_id].copy()

    def get_qdot(self, arm_id: str) -> np.ndarray:
        return self._qdot[arm_id].copy()

    def get_flange_twist(self, arm_id: str) -> np.ndarray:
        """6D spatial velocity [vx, vy, vz, wx, wy, wz] at the flange.

        Uses the same Jacobian as TASK_VEL control (``get_jacobian @ qdot``).
        """
        return self.get_jacobian(arm_id) @ self._qdot[arm_id]

    def get_jacobian(self, arm_id: str) -> np.ndarray:
        cfg = self._cfgs[arm_id]
        if _PIN_OK and arm_id in self._pin_models:
            m, d = self._pin_models[arm_id], self._pin_data[arm_id]
            frame_id = m.getFrameId(f"{arm_id}_ee")
            J = pin.getFrameJacobian(
                m, d, frame_id,
                pin.ReferenceFrame.LOCAL_WORLD_ALIGNED,
            )
            return J[:, : cfg.ndof]
        return self._finite_diff_jacobian(arm_id)

    def _finite_diff_jacobian(self, arm_id: str) -> np.ndarray:
        cfg = self._cfgs[arm_id]
        eps = 1e-5
        J = np.zeros((6, cfg.ndof))
        pos0, _ = self._mj.get_site_pose(cfg.ee_site)
        for i, jname in enumerate(cfg.joint_names):
            tmp = mujoco.MjData(self._mj.model)
            tmp.qpos[:] = self._mj.data.qpos[:]
            adr = self._mj.model.jnt_qposadr[self._mj.joint_id(jname)]
            tmp.qpos[adr] += eps
            mujoco.mj_fwdPosition(self._mj.model, tmp)
            sid = self._mj.site_id(cfg.ee_site)
            J[:3, i] = (
                tmp.site_xpos[sid] - pos0
            ) / eps
        return J

    def get_flange_pose(self, arm_id: str) -> np.ndarray:
        """Returns a (4,4) SE3 transform of the flange in the arm's base frame."""
        if _PIN_OK and arm_id in self._pin_models:
            m, d = self._pin_models[arm_id], self._pin_data[arm_id]
            frame_id = m.getFrameId(f"{arm_id}_ee")
            return d.oMf[frame_id].homogeneous.copy()
        # Fallback: transform world-frame site pose into arm base frame
        cfg = self._cfgs[arm_id]
        pos_w, R_w = self._mj.get_site_pose(cfg.ee_site)
        T_world_ee = np.eye(4)
        T_world_ee[:3, :3] = R_w
        T_world_ee[:3, 3] = pos_w
        R_b = cfg.base_world_rot
        T_world_base = np.eye(4)
        T_world_base[:3, :3] = R_b
        T_world_base[:3, 3] = cfg.base_world
        T_base_world = np.eye(4)
        T_base_world[:3, :3] = R_b.T
        T_base_world[:3, 3] = -R_b.T @ cfg.base_world
        return T_base_world @ T_world_ee

    def get_manipulability(self, arm_id: str) -> float:
        J = self.get_jacobian(arm_id)[:3, :]
        return float(np.sqrt(max(0.0, np.linalg.det(J @ J.T))))

    def get_singularity_distance(self, arm_id: str) -> float:
        sv = np.linalg.svd(
            self.get_jacobian(arm_id), compute_uv=False
        )
        return 0.0 if sv[0] < 1e-12 else float(sv[-1] / sv[0])
