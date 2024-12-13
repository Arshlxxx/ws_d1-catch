cmake_minimum_required(VERSION 3.0.2)
project(launch)

## 查找 catkin 依赖
find_package(catkin REQUIRED COMPONENTS
  rospy
  std_msgs
)

## catkin_package 不需要定义库
catkin_package()

## 安装 launch 文件
install(DIRECTORY launch/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/launch
)

## 安装可执行的脚本（确保 sleep_node.py 可执行）
install(PROGRAMS
  scripts/sleep_node.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)