# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /work

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /work/cmake

# Include any dependencies generated for this target.
include rpc_manager/client/CMakeFiles/rpc_client.dir/depend.make

# Include the progress variables for this target.
include rpc_manager/client/CMakeFiles/rpc_client.dir/progress.make

# Include the compile flags for this target's objects.
include rpc_manager/client/CMakeFiles/rpc_client.dir/flags.make

rpc_manager/client/CMakeFiles/rpc_client.dir/rpc_client.cpp.o: rpc_manager/client/CMakeFiles/rpc_client.dir/flags.make
rpc_manager/client/CMakeFiles/rpc_client.dir/rpc_client.cpp.o: ../rpc_manager/client/rpc_client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/work/cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object rpc_manager/client/CMakeFiles/rpc_client.dir/rpc_client.cpp.o"
	cd /work/cmake/rpc_manager/client && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rpc_client.dir/rpc_client.cpp.o -c /work/rpc_manager/client/rpc_client.cpp

rpc_manager/client/CMakeFiles/rpc_client.dir/rpc_client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rpc_client.dir/rpc_client.cpp.i"
	cd /work/cmake/rpc_manager/client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /work/rpc_manager/client/rpc_client.cpp > CMakeFiles/rpc_client.dir/rpc_client.cpp.i

rpc_manager/client/CMakeFiles/rpc_client.dir/rpc_client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rpc_client.dir/rpc_client.cpp.s"
	cd /work/cmake/rpc_manager/client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /work/rpc_manager/client/rpc_client.cpp -o CMakeFiles/rpc_client.dir/rpc_client.cpp.s

rpc_manager/client/CMakeFiles/rpc_client.dir/rpc_client.cpp.o.requires:

.PHONY : rpc_manager/client/CMakeFiles/rpc_client.dir/rpc_client.cpp.o.requires

rpc_manager/client/CMakeFiles/rpc_client.dir/rpc_client.cpp.o.provides: rpc_manager/client/CMakeFiles/rpc_client.dir/rpc_client.cpp.o.requires
	$(MAKE) -f rpc_manager/client/CMakeFiles/rpc_client.dir/build.make rpc_manager/client/CMakeFiles/rpc_client.dir/rpc_client.cpp.o.provides.build
.PHONY : rpc_manager/client/CMakeFiles/rpc_client.dir/rpc_client.cpp.o.provides

rpc_manager/client/CMakeFiles/rpc_client.dir/rpc_client.cpp.o.provides.build: rpc_manager/client/CMakeFiles/rpc_client.dir/rpc_client.cpp.o


# Object files for target rpc_client
rpc_client_OBJECTS = \
"CMakeFiles/rpc_client.dir/rpc_client.cpp.o"

# External object files for target rpc_client
rpc_client_EXTERNAL_OBJECTS =

rpc_manager/client/librpc_client.a: rpc_manager/client/CMakeFiles/rpc_client.dir/rpc_client.cpp.o
rpc_manager/client/librpc_client.a: rpc_manager/client/CMakeFiles/rpc_client.dir/build.make
rpc_manager/client/librpc_client.a: rpc_manager/client/CMakeFiles/rpc_client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/work/cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library librpc_client.a"
	cd /work/cmake/rpc_manager/client && $(CMAKE_COMMAND) -P CMakeFiles/rpc_client.dir/cmake_clean_target.cmake
	cd /work/cmake/rpc_manager/client && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rpc_client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
rpc_manager/client/CMakeFiles/rpc_client.dir/build: rpc_manager/client/librpc_client.a

.PHONY : rpc_manager/client/CMakeFiles/rpc_client.dir/build

rpc_manager/client/CMakeFiles/rpc_client.dir/requires: rpc_manager/client/CMakeFiles/rpc_client.dir/rpc_client.cpp.o.requires

.PHONY : rpc_manager/client/CMakeFiles/rpc_client.dir/requires

rpc_manager/client/CMakeFiles/rpc_client.dir/clean:
	cd /work/cmake/rpc_manager/client && $(CMAKE_COMMAND) -P CMakeFiles/rpc_client.dir/cmake_clean.cmake
.PHONY : rpc_manager/client/CMakeFiles/rpc_client.dir/clean

rpc_manager/client/CMakeFiles/rpc_client.dir/depend:
	cd /work/cmake && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /work /work/rpc_manager/client /work/cmake /work/cmake/rpc_manager/client /work/cmake/rpc_manager/client/CMakeFiles/rpc_client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : rpc_manager/client/CMakeFiles/rpc_client.dir/depend

