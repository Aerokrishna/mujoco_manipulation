#!/usr/bin/env python
"""Run the CyRo simulation demo."""

import time
import numpy as np
from .simulator import CyRoSimulator
from .sim_types import ControlMode, Telemetry
from .constants import _CONTROL_HZ
from pathlib import Path
import sys 

sys.path.insert(0, str(Path(__file__).resolve().parents[2])) 
from robot_kinematics.manyplot.telemetry_logger import TelemetryLogger

dual_arm = False

assets = Path(__file__).parent / ".." / "assets" / "duman"
if dual_arm:
    default = assets / "dual_franka.yaml"
else:
    default = assets / "duman.yaml"

telem_log = TelemetryLogger()

def main_demo() -> None:
    time.sleep(1)

    sim = CyRoSimulator(config_path=default)

    def on_step(tick: int, t: float, telem: Telemetry) -> None:
        if tick == 2:
            sim.set_mode("left", ControlMode.JOINT_POS)

        if tick == 400:
            print("ROBOT SHUD MOVE")
            sim.set_mode("left", ControlMode.JOINT_POS)
            sim.set_joint_pos("left",q=[0.4,0.,0.5,0,1,0.6])
    sim.on_step(on_step)
    sim.set_gripper()

    try:
        sim.run(headless=False)
    except KeyboardInterrupt:
        print("\nStopping simulation...")
    finally:
        print("Cleaning up...")
        try:
            # sim.stop()
            sim.close()
        except AttributeError:
            pass

if __name__ == "__main__":
    main_demo()
    