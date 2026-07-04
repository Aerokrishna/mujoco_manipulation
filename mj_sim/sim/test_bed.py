#!/usr/bin/env python
"""Run the CyRo simulation demo."""

import time
import numpy as np
from simulator import CyRoSimulator
from sim_types import ControlMode, Telemetry
from constants import _CONTROL_HZ

def main_demo() -> None:
    """Run the built-in demo (interactive MuJoCo viewer)."""
    time.sleep(1)  # let OS scheduler settle before launching viewer

    sim = CyRoSimulator()

    def on_step(tick: int, t: float, telem: Telemetry) -> None:
        sim.set_mode("left", ControlMode.TASK_VEL)

        if tick >400:
            sim.set_flange_vel("left", linear=[0,0,-0.1],angular=[0,0,0])
        if tick % 10 == 0:
            print(telem)

    sim.on_step(on_step)
    sim.run(headless=False)


if __name__ == "__main__":
    main_demo()