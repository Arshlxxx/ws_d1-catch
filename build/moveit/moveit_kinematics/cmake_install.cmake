# Install script for directory: /home/nvidia/ws_d1/src/moveit/moveit_kinematics

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/nvidia/ws_d1/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/nvidia/ws_d1/build/moveit/moveit_kinematics/catkin_generated/installspace/moveit_kinematics.pc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/moveit_kinematics/cmake" TYPE FILE FILES
    "/home/nvidia/ws_d1/build/moveit/moveit_kinematics/catkin_generated/installspace/moveit_kinematicsConfig.cmake"
    "/home/nvidia/ws_d1/build/moveit/moveit_kinematics/catkin_generated/installspace/moveit_kinematicsConfig-version.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/moveit_kinematics" TYPE FILE FILES "/home/nvidia/ws_d1/src/moveit/moveit_kinematics/package.xml")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/moveit_kinematics" TYPE FILE FILES
    "/home/nvidia/ws_d1/src/moveit/moveit_kinematics/kdl_kinematics_plugin_description.xml"
    "/home/nvidia/ws_d1/src/moveit/moveit_kinematics/lma_kinematics_plugin_description.xml"
    "/home/nvidia/ws_d1/src/moveit/moveit_kinematics/srv_kinematics_plugin_description.xml"
    "/home/nvidia/ws_d1/src/moveit/moveit_kinematics/cached_ik_kinematics_plugin_description.xml"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/nvidia/ws_d1/build/moveit/moveit_kinematics/kdl_kinematics_plugin/cmake_install.cmake")
  include("/home/nvidia/ws_d1/build/moveit/moveit_kinematics/lma_kinematics_plugin/cmake_install.cmake")
  include("/home/nvidia/ws_d1/build/moveit/moveit_kinematics/srv_kinematics_plugin/cmake_install.cmake")
  include("/home/nvidia/ws_d1/build/moveit/moveit_kinematics/ikfast_kinematics_plugin/cmake_install.cmake")
  include("/home/nvidia/ws_d1/build/moveit/moveit_kinematics/cached_ik_kinematics_plugin/cmake_install.cmake")
  include("/home/nvidia/ws_d1/build/moveit/moveit_kinematics/test/cmake_install.cmake")

endif()

