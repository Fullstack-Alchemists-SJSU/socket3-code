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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/aditya-kulkarni/Projects/SJSU/CMPE275/Mini Project 1/session/src/socket"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/aditya-kulkarni/Projects/SJSU/CMPE275/Mini Project 1/session/src/socket/build"

# Include any dependencies generated for this target.
include CMakeFiles/socket-lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/socket-lib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/socket-lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/socket-lib.dir/flags.make

CMakeFiles/socket-lib.dir/server.cpp.o: CMakeFiles/socket-lib.dir/flags.make
CMakeFiles/socket-lib.dir/server.cpp.o: /home/aditya-kulkarni/Projects/SJSU/CMPE275/Mini\ Project\ 1/session/src/socket/server.cpp
CMakeFiles/socket-lib.dir/server.cpp.o: CMakeFiles/socket-lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/aditya-kulkarni/Projects/SJSU/CMPE275/Mini Project 1/session/src/socket/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/socket-lib.dir/server.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/socket-lib.dir/server.cpp.o -MF CMakeFiles/socket-lib.dir/server.cpp.o.d -o CMakeFiles/socket-lib.dir/server.cpp.o -c "/home/aditya-kulkarni/Projects/SJSU/CMPE275/Mini Project 1/session/src/socket/server.cpp"

CMakeFiles/socket-lib.dir/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/socket-lib.dir/server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/aditya-kulkarni/Projects/SJSU/CMPE275/Mini Project 1/session/src/socket/server.cpp" > CMakeFiles/socket-lib.dir/server.cpp.i

CMakeFiles/socket-lib.dir/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/socket-lib.dir/server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/aditya-kulkarni/Projects/SJSU/CMPE275/Mini Project 1/session/src/socket/server.cpp" -o CMakeFiles/socket-lib.dir/server.cpp.s

# Object files for target socket-lib
socket__lib_OBJECTS = \
"CMakeFiles/socket-lib.dir/server.cpp.o"

# External object files for target socket-lib
socket__lib_EXTERNAL_OBJECTS =

libsocket-lib.a: CMakeFiles/socket-lib.dir/server.cpp.o
libsocket-lib.a: CMakeFiles/socket-lib.dir/build.make
libsocket-lib.a: CMakeFiles/socket-lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/home/aditya-kulkarni/Projects/SJSU/CMPE275/Mini Project 1/session/src/socket/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libsocket-lib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/socket-lib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/socket-lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/socket-lib.dir/build: libsocket-lib.a
.PHONY : CMakeFiles/socket-lib.dir/build

CMakeFiles/socket-lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/socket-lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/socket-lib.dir/clean

CMakeFiles/socket-lib.dir/depend:
	cd "/home/aditya-kulkarni/Projects/SJSU/CMPE275/Mini Project 1/session/src/socket/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/aditya-kulkarni/Projects/SJSU/CMPE275/Mini Project 1/session/src/socket" "/home/aditya-kulkarni/Projects/SJSU/CMPE275/Mini Project 1/session/src/socket" "/home/aditya-kulkarni/Projects/SJSU/CMPE275/Mini Project 1/session/src/socket/build" "/home/aditya-kulkarni/Projects/SJSU/CMPE275/Mini Project 1/session/src/socket/build" "/home/aditya-kulkarni/Projects/SJSU/CMPE275/Mini Project 1/session/src/socket/build/CMakeFiles/socket-lib.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/socket-lib.dir/depend

