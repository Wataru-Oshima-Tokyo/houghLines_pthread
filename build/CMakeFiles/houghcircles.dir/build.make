# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.22.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.22.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/wataruoshima/CSCI612/assignments/week5-6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/wataruoshima/CSCI612/assignments/week5-6/build

# Include any dependencies generated for this target.
include CMakeFiles/houghcircles.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/houghcircles.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/houghcircles.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/houghcircles.dir/flags.make

CMakeFiles/houghcircles.dir/houghCircles.cpp.o: CMakeFiles/houghcircles.dir/flags.make
CMakeFiles/houghcircles.dir/houghCircles.cpp.o: ../houghCircles.cpp
CMakeFiles/houghcircles.dir/houghCircles.cpp.o: CMakeFiles/houghcircles.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wataruoshima/CSCI612/assignments/week5-6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/houghcircles.dir/houghCircles.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/houghcircles.dir/houghCircles.cpp.o -MF CMakeFiles/houghcircles.dir/houghCircles.cpp.o.d -o CMakeFiles/houghcircles.dir/houghCircles.cpp.o -c /Users/wataruoshima/CSCI612/assignments/week5-6/houghCircles.cpp

CMakeFiles/houghcircles.dir/houghCircles.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/houghcircles.dir/houghCircles.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wataruoshima/CSCI612/assignments/week5-6/houghCircles.cpp > CMakeFiles/houghcircles.dir/houghCircles.cpp.i

CMakeFiles/houghcircles.dir/houghCircles.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/houghcircles.dir/houghCircles.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wataruoshima/CSCI612/assignments/week5-6/houghCircles.cpp -o CMakeFiles/houghcircles.dir/houghCircles.cpp.s

# Object files for target houghcircles
houghcircles_OBJECTS = \
"CMakeFiles/houghcircles.dir/houghCircles.cpp.o"

# External object files for target houghcircles
houghcircles_EXTERNAL_OBJECTS =

houghcircles: CMakeFiles/houghcircles.dir/houghCircles.cpp.o
houghcircles: CMakeFiles/houghcircles.dir/build.make
houghcircles: /usr/local/lib/libopencv_gapi.4.5.5.dylib
houghcircles: /usr/local/lib/libopencv_highgui.4.5.5.dylib
houghcircles: /usr/local/lib/libopencv_ml.4.5.5.dylib
houghcircles: /usr/local/lib/libopencv_objdetect.4.5.5.dylib
houghcircles: /usr/local/lib/libopencv_photo.4.5.5.dylib
houghcircles: /usr/local/lib/libopencv_stitching.4.5.5.dylib
houghcircles: /usr/local/lib/libopencv_video.4.5.5.dylib
houghcircles: /usr/local/lib/libopencv_videoio.4.5.5.dylib
houghcircles: /usr/local/lib/libopencv_imgcodecs.4.5.5.dylib
houghcircles: /usr/local/lib/libopencv_dnn.4.5.5.dylib
houghcircles: /usr/local/lib/libopencv_calib3d.4.5.5.dylib
houghcircles: /usr/local/lib/libopencv_features2d.4.5.5.dylib
houghcircles: /usr/local/lib/libopencv_flann.4.5.5.dylib
houghcircles: /usr/local/lib/libopencv_imgproc.4.5.5.dylib
houghcircles: /usr/local/lib/libopencv_core.4.5.5.dylib
houghcircles: CMakeFiles/houghcircles.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/wataruoshima/CSCI612/assignments/week5-6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable houghcircles"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/houghcircles.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/houghcircles.dir/build: houghcircles
.PHONY : CMakeFiles/houghcircles.dir/build

CMakeFiles/houghcircles.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/houghcircles.dir/cmake_clean.cmake
.PHONY : CMakeFiles/houghcircles.dir/clean

CMakeFiles/houghcircles.dir/depend:
	cd /Users/wataruoshima/CSCI612/assignments/week5-6/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wataruoshima/CSCI612/assignments/week5-6 /Users/wataruoshima/CSCI612/assignments/week5-6 /Users/wataruoshima/CSCI612/assignments/week5-6/build /Users/wataruoshima/CSCI612/assignments/week5-6/build /Users/wataruoshima/CSCI612/assignments/week5-6/build/CMakeFiles/houghcircles.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/houghcircles.dir/depend

