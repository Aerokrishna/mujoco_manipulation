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
        if tick==0:
            sim.set_mode("left", ControlMode.JOINT_POS)
            sim.set_joint_pos("left", q = [0.0,
            -0.78539816,
                0.0,
            -2.35619449,
                0.0,
                1.57079633,
                0.78539816])

        if tick ==100:
            # sim.set_mode("left", ControlMode.TASK_POSE)
            # sim.set_flange_pose("left", [0, 0.60, 0.5], rot = telem.flange_pose["left"][:3][:3])
            sim.set_mode("left", ControlMode.TASK_POSE)
            # sim.set_mode("left", ControlMode.JOINT_VEL)

            sim.show_object_frame("attachment_site")
            sim.show_object_frame("world")

        if tick>100:
            # sim.set_tcp_vel("left", linear=[-0.05, 0., -0.06], angular=[0.,0.0,0.])
            sim.set_tcp_pose("left", pos=[0.3, 0, 0.1], rot = [[ 9.99995667e-01,  2.00273503e-03, -2.15762363e-03],
 [ 2.00269853e-03, -9.99997994e-01, -1.90771176e-05 ],
 [-2.15765751e-03,  1.47559653e-05, -9.99997672e-01 ]])
            
            # sim.set_joint_vel("left", [0, 0, 0.2, 0.2,0.1,0,0])
            # print("pos joint :", telem.joint_pos["left"])
            # print("vel joint", telem.joint_vel["left"])
            print("vel tcp", telem.tcp_pose["left"])
        
    sim.on_step(on_step)
    sim.run(headless=False)

if __name__ == "__main__":
    main_demo()