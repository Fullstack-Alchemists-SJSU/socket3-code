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
CMAKE_SOURCE_DIR = "/home/aditya-kulkarni/Projects/SJSU/CMPE275/Mini Project 1/c++/session"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/aditya-kulkarni/Projects/SJSU/CMPE275/Mini Project 1/c++/session/build"

# Include any dependencies generated for this target.
include CMakeFiles/Socket.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Socket.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Socket.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Socket.dir/flags.make

CMakeFiles/Socket.dir/src/server.cpp.o: CMakeFiles/Socket.dir/flags.make
CMakeFiles/Socket.dir/src/server.cpp.o: /home/aditya-kulkarni/Projects/SJSU/CMPE275/Mini\ Project\ 1/c++/session/src/server.cpp
CMakeFiles/Socket.dir/src/server.cpp.o: CMakeFiles/Socket.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/aditya-kulkarni/Projects/SJSU/CMPE275/Mini Project 1/c++/session/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Socket.dir/src/server.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Socket.dir/src/server.cpp.o -MF CMakeFiles/Socket.dir/src/server.cpp.o.d -o CMakeFiles/Socket.dir/src/server.cpp.o -c "/home/aditya-kulkarni/Projects/SJSU/CMPE275/Mini Project 1/c++/session/src/server.cpp"

CMakeFiles/Socket.dir/src/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Socket.dir/src/server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/aditya-kulkarni/Projects/SJSU/CMPE275/Mini Project 1/c++/session/src/server.cpp" > CMakeFiles/Socket.dir/src/server.cpp.i

CMakeFiles/Socket.dir/src/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Socket.dir/src/server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/aditya-kulkarni/Projects/SJSU/CMPE275/Mini Project 1/c++/session/src/server.cpp" -o CMakeFiles/Socket.dir/src/server.cpp.s

# Object files for target Socket
Socket_OBJECTS = \
"CMakeFiles/Socket.dir/src/server.cpp.o"

# External object files for target Socket
Socket_EXTERNAL_OBJECTS =

Socket: CMakeFiles/Socket.dir/src/server.cpp.o
Socket: CMakeFiles/Socket.dir/build.make
Socket: CMakeFiles/Socket.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/home/aditya-kulkarni/Projects/SJSU/CMPE275/Mini Project 1/c++/session/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Socket"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Socket.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Socket.dir/build: Socket
.PHONY : CMakeFiles/Socket.dir/build

CMakeFiles/Socket.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Socket.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Socket.dir/clean

CMakeFiles/Socket.dir/depend:
	cd "/home/aditya-kulkarni/Projects/SJSU/CMPE275/Mini Project 1/c++/session/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/aditya-kulkarni/Projects/SJSU/CMPE275/Mini Project 1/c++/session" "/home/aditya-kulkarni/Projects/SJSU/CMPE275/Mini Project 1/c++/session" "/home/aditya-kulkarni/Projects/SJSU/CMPE275/Mini Project 1/c++/session/build" "/home/aditya-kulkarni/Projects/SJSU/CMPE275/Mini Project 1/c++/session/build" "/home/aditya-kulkarni/Projects/SJSU/CMPE275/Mini Project 1/c++/session/build/CMakeFiles/Socket.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/Socket.dir/depend

