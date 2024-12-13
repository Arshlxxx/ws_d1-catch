cmake_minimum_required(VERSION 3.0.2)
project(control_robot)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  moveit_ros_move_group
  moveit_ros_planning_interface
  roscpp
  rospy
  std_msgs
)

## Declare a catkin package
catkin_package()

## Include directories
include_directories(
  ${catkin_INCLUDE_DIRS}
)

## Add executable
add_executable(demo_node src/demo1.cpp)

## Link libraries
target_link_libraries(demo_node
  ${catkin_LIBRARIES}
)
