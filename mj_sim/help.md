Contains simulation specific files
includes :
- lower level controllers
- assets and mesh files for different environments
- scene construction MujocoModel
- controllers (mujoco specific, position velocity torque)
- simulation loop
- contains a ui which will contain necessary buttons to operate the sim for ease of use


to do :
- a functionality to basically reach the joint positions smoothly for task_pose mode it is very fast now we should be able to interpolate to it smoothly. 
- either we add a smooth joint interpolation, or we calculate the error and reach there using dls, a qp ik given a velocity it produces joint vel or position.