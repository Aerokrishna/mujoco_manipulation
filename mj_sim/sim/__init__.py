"""
sim_cyro — MuJoCo simulation framework for the CyRo tri-arm robotic system.

Quick Start
-----------
    from sim_cyro import CyRoSimulator, ControlMode, Telemetry
    import numpy as np

    sim = CyRoSimulator()
    sim.set_mode("left", ControlMode.JOINT_POS)
    sim.set_joint_pos("left", [0.0, 0.3, 0.0, -0.5, 0.0, 0.8, 0.0])
    sim.set_gripper("left", 0.5)   # 0=closed, 1=open
    sim.set_stereo_yaw(0.1, -0.1)  # camera yaw [rad]
    sim.enable_stereo_images(size=(612, 512))

    # Manual stepping loop
    for tick in range(1000):
        telem: Telemetry = sim.step()
        if tick % 100 == 0:
            left_img, right_img = sim.get_stereo_images()  # RGB uint8 arrays

Control Modes
-------------
    JOINT_POS    – Joint position target           (no extra deps)
    JOINT_VEL    – Joint velocity, integrated      (no extra deps)
    JOINT_TORQUE – Torque + gravity compensation   (no extra deps)
    TASK_POSE    – Cartesian SE3 via Pink IK       (needs pinocchio, pink)
    TASK_VEL     – Cartesian twist via Jacobian    (needs pinocchio)
"""

from sim_types import ArmConfig, ControlMode, Telemetry
from simulator import CyRoSimulator

__version__ = "0.1.0"

__all__ = [
    "CyRoSimulator",
    "ControlMode",
    "Telemetry",
    "ArmConfig",
    "StereoShmPublisher",
    "StereoShmSubscriber",
    "get_assets_path",
]

# Backward-compatible alias
TriArmSimulator = CyRoSimulator


def get_assets_path():
    """Return the path to the package's assets directory (configs, XML, meshes)."""
    from pathlib import Path
    return Path(__file__).parent / "assets"
