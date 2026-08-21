cmake_minimum_required(VERSION 3.5)
project(armos_control)

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_python REQUIRED)

# Install examples
set(CONTROL control)



install(PROGRAMS

    ${CONTROL}/armos_ros_sim.py
    DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY config
  DESTINATION share/${PROJECT_NAME}
)

# Setup the project
ament_package()
