"""Per-arm controller with mode switching and solvers."""

from __future__ import annotations

import logging
from dataclasses import dataclass
from typing import Dict, Optional, Tuple

import numpy as np

from constants import _BLEND_TIME
from mj_model import _MuJoCoModel
from pinocchio_sync import _PinocchioSync, _wxyz_to_R
from sim_types import ArmConfig, ControlMode, _JointCmd, _TaskCmd

try:
    import pinocchio as pin
    _PIN_OK = True
except ImportError:
    _PIN_OK = False

try:
    import pink
    from pink import Configuration
    from pink.tasks import FrameTask, PostureTask
    _PINK_OK = True
except ImportError:
    _PINK_OK = False

logger = logging.getLogger(__name__)


class _ModeLatch:
    """Blends joint reference from old to new mode over _BLEND_TIME seconds."""

    def __init__(self, ndof: int):
        self._mode = ControlMode.JOINT_POS
        self._blend_t = 0.0
        self._q_latch = np.zeros(ndof)
        self._qdot_latch = np.zeros(ndof)

    @property
    def mode(self) -> ControlMode:
        return self._mode

    @property
    def q_latch(self) -> np.ndarray:
        return self._q_latch

    def switch(
        self,
        new_mode: ControlMode,
        q_now: np.ndarray,
        qdot_now: np.ndarray,
    ) -> None:
        if new_mode == self._mode:
            return
        logger.debug("Mode switch: %s → %s", self._mode.name, new_mode.name)
        self._q_latch = q_now.copy()
        self._qdot_latch = qdot_now.copy()
        self._blend_t = 0.0
        self._mode = new_mode

    def alpha(self, dt: float) -> float:
        self._blend_t += dt
        return min(1.0, self._blend_t / _BLEND_TIME)


class _PinkSolver:
    """Wraps a Pink QP-based differential IK for one arm."""

    def __init__(self, cfg: ArmConfig, pin_model, pin_data):
        self._cfg = cfg
        self._model = pin_model
        self._data = pin_data
        self._config = None
        self._ee_task = None
        self._posture_task = None
        if _PINK_OK and _PIN_OK:
            self._setup()

    def _setup(self) -> None:
        q0 = pin.neutral(self._model)
        self._config = Configuration(self._model, self._data, q0)
        self._ee_task = FrameTask(
            f"{self._cfg.arm_id}_ee",
            position_cost=1.0,
            orientation_cost=0.5,
        )
        self._posture_task = PostureTask(cost=1e-3)
        self._posture_task.set_target(np.zeros(self._model.nq))

    def solve(self, q: np.ndarray, target_SE3, dt: float) -> np.ndarray:
        ndof = self._cfg.ndof
        if not _PINK_OK or self._config is None:
            return np.zeros(ndof)
        q_safe = np.clip(
            np.nan_to_num(q, nan=0.0, posinf=2.8, neginf=-2.8),
            self._cfg.q_lo,
            self._cfg.q_hi,
        )
        q_pin = np.zeros(self._model.nq)
        q_pin[:ndof] = q_safe
        self._config.update(q_pin)
        self._ee_task.set_target(target_SE3)
        try:
            vel = pink.solve_ik(
                self._config,
                [self._ee_task, self._posture_task],
                dt,
                solver="quadprog",
                safety_break=False,
            )
        except Exception as exc:
            logger.warning("Pink IK failed (%s) — holding position.", exc)
            return np.zeros(ndof)
        return vel[:ndof]


class _ArmController:
    """
    Unified mode-switching controller for a single arm.

    Joint-space modes work without Pinocchio or Pink.
    TASK_POSE and TASK_VEL require both libraries.
    """

    def __init__(
        self,
        cfg: ArmConfig,
        mj: _MuJoCoModel,
        pin_sync: _PinocchioSync,
        pink_solver: Optional[_PinkSolver],
    ):
        self._cfg = cfg
        self._mj = mj
        self._sync = pin_sync
        self._pink = pink_solver
        self._latch = _ModeLatch(cfg.ndof)
        self._q_ref = cfg.q_home.copy()
        self._joint_cmd: Optional[_JointCmd] = None
        self._task_cmd: Optional[_TaskCmd] = None

    def set_mode(self, mode: ControlMode) -> None:
        q = self._sync.get_q(self._cfg.arm_id)
        qdot = self._sync.get_qdot(self._cfg.arm_id)
        prev_mode = self._latch.mode
        self._latch.switch(mode, q, qdot)
        if mode != prev_mode and np.all(np.isfinite(q)):
            self._q_ref = np.clip(q, self._cfg.q_lo, self._cfg.q_hi)

    def set_joint_pos(self, q: np.ndarray) -> None:
        self._joint_cmd = _JointCmd(
            position=np.clip(q, self._cfg.q_lo, self._cfg.q_hi)
        )

    def set_joint_vel(self, qdot: np.ndarray) -> None:
        self._joint_cmd = _JointCmd(velocity=np.asarray(qdot, dtype=float))

    def set_joint_torque(self, tau: np.ndarray) -> None:
        self._joint_cmd = _JointCmd(torque=np.asarray(tau, dtype=float))

    def set_flange_pose(self, pos: np.ndarray, rot: np.ndarray) -> None:
        cmd = _TaskCmd()
        cmd.position = np.asarray(pos)
        cmd.orientation = np.asarray(rot)
        cmd.use_tcp = False
        self._task_cmd = cmd

    def set_tcp_pose(self, pos: np.ndarray, rot: np.ndarray) -> None:
        cmd = _TaskCmd()
        cmd.position = np.asarray(pos)
        cmd.orientation = np.asarray(rot)
        cmd.use_tcp = True
        self._task_cmd = cmd

    def set_flange_vel(self, linear: np.ndarray, angular: np.ndarray) -> None:
        cmd = _TaskCmd()
        cmd.linear_vel = np.asarray(linear)
        cmd.angular_vel = np.asarray(angular)
        cmd.use_tcp = False
        self._task_cmd = cmd

    def set_tcp_vel(self, linear: np.ndarray, angular: np.ndarray) -> None:
        cmd = _TaskCmd()
        cmd.linear_vel = np.asarray(linear)
        cmd.angular_vel = np.asarray(angular)
        cmd.use_tcp = True
        self._task_cmd = cmd

    def compute(self, dt: float) -> Tuple[np.ndarray, np.ndarray]:
        """Returns (q_ref, tau_feedforward) for this tick."""
        ndof = self._cfg.ndof
        q_raw = self._sync.get_q(self._cfg.arm_id)
        qdot_raw = self._sync.get_qdot(self._cfg.arm_id)
        bias_raw = self._mj.get_qfrc_bias(self._cfg.joint_names)

        q = np.clip(
            np.where(np.isfinite(q_raw), q_raw, self._q_ref),
            self._cfg.q_lo,
            self._cfg.q_hi,
        )
        qdot = np.clip(
            np.where(np.isfinite(qdot_raw), qdot_raw, 0.0),
            -10.0,
            10.0,
        )
        tau_grav = np.clip(
            np.where(np.isfinite(bias_raw), bias_raw, 0.0),
            -500.0,
            500.0,
        )

        mode = self._latch.mode
        q_new = self._q_ref.copy()
        tau_ff = np.zeros(ndof)

        if mode == ControlMode.JOINT_POS:
            # Match JOINT_VEL behavior: keep gravity compensation active
            # so position control does not fight static load.
            tau_ff = tau_grav.copy()
            if self._joint_cmd and self._joint_cmd.position is not None:
                q_new = self._joint_cmd.position

        elif mode == ControlMode.JOINT_VEL:
            tau_ff = tau_grav.copy()
            if self._joint_cmd and self._joint_cmd.velocity is not None:
                self._q_ref = np.clip(
                    self._q_ref + self._joint_cmd.velocity * dt,
                    self._cfg.q_lo,
                    self._cfg.q_hi,
                )
            q_new = self._q_ref.copy()

        elif mode == ControlMode.JOINT_TORQUE:
            q_new = q.copy()
            tau_ff = tau_grav.copy()
            if self._joint_cmd and self._joint_cmd.torque is not None:
                tau_ff = tau_ff + self._joint_cmd.torque

        elif mode == ControlMode.TASK_POSE:
            tau_ff = tau_grav.copy()
            q_new = self._compute_task_pose(q, dt)

        elif mode == ControlMode.TASK_VEL:
            tau_ff = tau_grav.copy()
            q_new = self._compute_task_vel(q, dt)

        a = self._latch.alpha(dt)
        if a < 1.0:
            q_new = (1.0 - a) * self._latch.q_latch + a * q_new

        self._q_ref = q_new.copy()
        return q_new, tau_ff

    def _safe_q(self, q: np.ndarray) -> np.ndarray:
        return np.clip(
            np.nan_to_num(q, nan=0.0, posinf=2.8, neginf=-2.8),
            self._cfg.q_lo,
            self._cfg.q_hi,
        )

    def _tcp_in_flange(self) -> np.ndarray:
        """4×4 SE3 of TCP in flange frame, from tool params."""
        tl = self._cfg.tool.tcp_location
        T = np.eye(4)
        T[:3, :3] = _wxyz_to_R(tl[3:])
        T[:3, 3] = tl[:3]
        return T

    def _compute_task_pose(self, q: np.ndarray, dt: float) -> np.ndarray:
        if not (_PINK_OK and _PIN_OK and self._pink and self._task_cmd):
            if not (_PINK_OK and _PIN_OK):
                logger.warning(
                    "TASK_POSE requires Pinocchio + Pink. "
                    "Falling back to holding position."
                )
            return q.copy()
        q_safe = self._safe_q(q)

        if self._task_cmd.use_tcp:
            # TCP target → flange target: T_flange = T_tcp @ inv(T_tcp_in_flange)
            T_tcp = np.eye(4)
            T_tcp[:3, :3] = self._task_cmd.orientation
            T_tcp[:3, 3] = self._task_cmd.position
            T_tf = self._tcp_in_flange()
            R_tf = T_tf[:3, :3]
            T_tf_inv = np.eye(4)
            T_tf_inv[:3, :3] = R_tf.T
            T_tf_inv[:3, 3] = -R_tf.T @ T_tf[:3, 3]
            T_flange = T_tcp @ T_tf_inv
            target = pin.SE3(T_flange[:3, :3], T_flange[:3, 3])
        else:
            target = pin.SE3(self._task_cmd.orientation, self._task_cmd.position)
        qdot = self._pink.solve(q_safe, target, dt)
        return np.clip(
            q_safe + qdot * dt,
            self._cfg.q_lo,
            self._cfg.q_hi,
        )

    def _compute_task_vel(self, q: np.ndarray, dt: float) -> np.ndarray:
        if not self._task_cmd:
            return self._q_ref.copy()
        q_safe = self._safe_q(q)

        omega = self._task_cmd.angular_vel
        if self._task_cmd.use_tcp:
            # TCP twist → flange twist: v_flange = v_tcp - ω × (R_flange @ p_tcp)
            p_tcp_local = self._cfg.tool.tcp_location[:3]
            R_flange = self._sync.get_flange_pose(self._cfg.arm_id)[:3, :3]
            v_flange = self._task_cmd.linear_vel - np.cross(omega, R_flange @ p_tcp_local)
        else:
            v_flange = self._task_cmd.linear_vel

        twist = np.concatenate([v_flange, omega])
        J = self._sync.get_jacobian(self._cfg.arm_id)
        if not np.all(np.isfinite(J)):
            return self._q_ref.copy()
        lam = 0.05
        J_dls = J.T @ np.linalg.inv(J @ J.T + lam * np.eye(6))
        qdot_cmd = J_dls @ twist
        speed = np.linalg.norm(qdot_cmd)
        if speed > 1.0:
            qdot_cmd /= speed
        self._q_ref = np.clip(
            self._q_ref + qdot_cmd * dt,
            self._cfg.q_lo,
            self._cfg.q_hi,
        )
        return self._q_ref.copy()
