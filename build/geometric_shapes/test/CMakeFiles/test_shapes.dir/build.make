# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nvidia/ws_d1/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nvidia/ws_d1/build

# Include any dependencies generated for this target.
include geometric_shapes/test/CMakeFiles/test_shapes.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include geometric_shapes/test/CMakeFiles/test_shapes.dir/compiler_depend.make

# Include the progress variables for this target.
include geometric_shapes/test/CMakeFiles/test_shapes.dir/progress.make

# Include the compile flags for this target's objects.
include geometric_shapes/test/CMakeFiles/test_shapes.dir/flags.make

geometric_shapes/test/CMakeFiles/test_shapes.dir/test_shapes.cpp.o: geometric_shapes/test/CMakeFiles/test_shapes.dir/flags.make
geometric_shapes/test/CMakeFiles/test_shapes.dir/test_shapes.cpp.o: /home/nvidia/ws_d1/src/geometric_shapes/test/test_shapes.cpp
geometric_shapes/test/CMakeFiles/test_shapes.dir/test_shapes.cpp.o: geometric_shapes/test/CMakeFiles/test_shapes.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/nvidia/ws_d1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object geometric_shapes/test/CMakeFiles/test_shapes.dir/test_shapes.cpp.o"
	cd /home/nvidia/ws_d1/build/geometric_shapes/test && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT geometric_shapes/test/CMakeFiles/test_shapes.dir/test_shapes.cpp.o -MF CMakeFiles/test_shapes.dir/test_shapes.cpp.o.d -o CMakeFiles/test_shapes.dir/test_shapes.cpp.o -c /home/nvidia/ws_d1/src/geometric_shapes/test/test_shapes.cpp

geometric_shapes/test/CMakeFiles/test_shapes.dir/test_shapes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_shapes.dir/test_shapes.cpp.i"
	cd /home/nvidia/ws_d1/build/geometric_shapes/test && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nvidia/ws_d1/src/geometric_shapes/test/test_shapes.cpp > CMakeFiles/test_shapes.dir/test_shapes.cpp.i

geometric_shapes/test/CMakeFiles/test_shapes.dir/test_shapes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_shapes.dir/test_shapes.cpp.s"
	cd /home/nvidia/ws_d1/build/geometric_shapes/test && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nvidia/ws_d1/src/geometric_shapes/test/test_shapes.cpp -o CMakeFiles/test_shapes.dir/test_shapes.cpp.s

# Object files for target test_shapes
test_shapes_OBJECTS = \
"CMakeFiles/test_shapes.dir/test_shapes.cpp.o"

# External object files for target test_shapes
test_shapes_EXTERNAL_OBJECTS =

/home/nvidia/ws_d1/devel/lib/geometric_shapes/test_shapes: geometric_shapes/test/CMakeFiles/test_shapes.dir/test_shapes.cpp.o
/home/nvidia/ws_d1/devel/lib/geometric_shapes/test_shapes: geometric_shapes/test/CMakeFiles/test_shapes.dir/build.make
/home/nvidia/ws_d1/devel/lib/geometric_shapes/test_shapes: gtest/lib/libgtest.so
/home/nvidia/ws_d1/devel/lib/geometric_shapes/test_shapes: /home/nvidia/ws_d1/devel/lib/libgeometric_shapes.so.0.7.7
/home/nvidia/ws_d1/devel/lib/geometric_shapes/test_shapes: /opt/ros/noetic/lib/librandom_numbers.so
/home/nvidia/ws_d1/devel/lib/geometric_shapes/test_shapes: /opt/ros/noetic/lib/libresource_retriever.so
/home/nvidia/ws_d1/devel/lib/geometric_shapes/test_shapes: /opt/ros/noetic/lib/libroscpp_serialization.so
/home/nvidia/ws_d1/devel/lib/geometric_shapes/test_shapes: /opt/ros/noetic/lib/librostime.so
/home/nvidia/ws_d1/devel/lib/geometric_shapes/test_shapes: /usr/lib/aarch64-linux-gnu/libboost_date_time.so.1.71.0
/home/nvidia/ws_d1/devel/lib/geometric_shapes/test_shapes: /opt/ros/noetic/lib/libcpp_common.so
/home/nvidia/ws_d1/devel/lib/geometric_shapes/test_shapes: /usr/lib/aarch64-linux-gnu/libboost_system.so.1.71.0
/home/nvidia/ws_d1/devel/lib/geometric_shapes/test_shapes: /usr/lib/aarch64-linux-gnu/libboost_thread.so.1.71.0
/home/nvidia/ws_d1/devel/lib/geometric_shapes/test_shapes: /usr/lib/aarch64-linux-gnu/libconsole_bridge.so.0.4
/home/nvidia/ws_d1/devel/lib/geometric_shapes/test_shapes: /usr/lib/aarch64-linux-gnu/libboost_system.so.1.71.0
/home/nvidia/ws_d1/devel/lib/geometric_shapes/test_shapes: /usr/lib/aarch64-linux-gnu/libboost_filesystem.so.1.71.0
/home/nvidia/ws_d1/devel/lib/geometric_shapes/test_shapes: /usr/lib/aarch64-linux-gnu/libassimp.so.5
/home/nvidia/ws_d1/devel/lib/geometric_shapes/test_shapes: /usr/lib/aarch64-linux-gnu/libqhull_r.so
/home/nvidia/ws_d1/devel/lib/geometric_shapes/test_shapes: /opt/ros/noetic/lib/librandom_numbers.so
/home/nvidia/ws_d1/devel/lib/geometric_shapes/test_shapes: /opt/ros/noetic/lib/libresource_retriever.so
/home/nvidia/ws_d1/devel/lib/geometric_shapes/test_shapes: /opt/ros/noetic/lib/libroscpp_serialization.so
/home/nvidia/ws_d1/devel/lib/geometric_shapes/test_shapes: /opt/ros/noetic/lib/librostime.so
/home/nvidia/ws_d1/devel/lib/geometric_shapes/test_shapes: /usr/lib/aarch64-linux-gnu/libboost_date_time.so.1.71.0
/home/nvidia/ws_d1/devel/lib/geometric_shapes/test_shapes: /opt/ros/noetic/lib/libcpp_common.so
/home/nvidia/ws_d1/devel/lib/geometric_shapes/test_shapes: /usr/lib/aarch64-linux-gnu/libboost_system.so.1.71.0
/home/nvidia/ws_d1/devel/lib/geometric_shapes/test_shapes: /usr/lib/aarch64-linux-gnu/libboost_thread.so.1.71.0
/home/nvidia/ws_d1/devel/lib/geometric_shapes/test_shapes: /usr/lib/aarch64-linux-gnu/libconsole_bridge.so.0.4
/home/nvidia/ws_d1/devel/lib/geometric_shapes/test_shapes: /usr/lib/aarch64-linux-gnu/libconsole_bridge.so.0.4
/home/nvidia/ws_d1/devel/lib/geometric_shapes/test_shapes: /opt/ros/noetic/lib/aarch64-linux-gnu/libfcl.so
/home/nvidia/ws_d1/devel/lib/geometric_shapes/test_shapes: /usr/lib/aarch64-linux-gnu/libccd.so
/home/nvidia/ws_d1/devel/lib/geometric_shapes/test_shapes: /usr/lib/aarch64-linux-gnu/libm.so
/home/nvidia/ws_d1/devel/lib/geometric_shapes/test_shapes: /opt/ros/noetic/lib/liboctomap.so
/home/nvidia/ws_d1/devel/lib/geometric_shapes/test_shapes: /opt/ros/noetic/lib/liboctomath.so
/home/nvidia/ws_d1/devel/lib/geometric_shapes/test_shapes: geometric_shapes/test/CMakeFiles/test_shapes.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/nvidia/ws_d1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/nvidia/ws_d1/devel/lib/geometric_shapes/test_shapes"
	cd /home/nvidia/ws_d1/build/geometric_shapes/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_shapes.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
geometric_shapes/test/CMakeFiles/test_shapes.dir/build: /home/nvidia/ws_d1/devel/lib/geometric_shapes/test_shapes
.PHONY : geometric_shapes/test/CMakeFiles/test_shapes.dir/build

geometric_shapes/test/CMakeFiles/test_shapes.dir/clean:
	cd /home/nvidia/ws_d1/build/geometric_shapes/test && $(CMAKE_COMMAND) -P CMakeFiles/test_shapes.dir/cmake_clean.cmake
.PHONY : geometric_shapes/test/CMakeFiles/test_shapes.dir/clean

geometric_shapes/test/CMakeFiles/test_shapes.dir/depend:
	cd /home/nvidia/ws_d1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nvidia/ws_d1/src /home/nvidia/ws_d1/src/geometric_shapes/test /home/nvidia/ws_d1/build /home/nvidia/ws_d1/build/geometric_shapes/test /home/nvidia/ws_d1/build/geometric_shapes/test/CMakeFiles/test_shapes.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : geometric_shapes/test/CMakeFiles/test_shapes.dir/depend

