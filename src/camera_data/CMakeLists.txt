cmake_minimum_required(VERSION 3.0.2)
project(camera_data)

find_package(catkin REQUIRED COMPONENTS
  rospy
  std_msgs
  sensor_msgs
  message_generation
  tf 
)

catkin_package(
  CATKIN_DEPENDS rospy std_msgs sensor_msgs message_runtime tf
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

install(PROGRAMS
  src/detect.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)


