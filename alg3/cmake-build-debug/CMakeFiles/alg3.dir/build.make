# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /home/parfenkov/clion-2016.3.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/parfenkov/clion-2016.3.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/parfenkov/CLionProjects/alg3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/parfenkov/CLionProjects/alg3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/alg3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/alg3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/alg3.dir/flags.make

CMakeFiles/alg3.dir/main.cpp.o: CMakeFiles/alg3.dir/flags.make
CMakeFiles/alg3.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parfenkov/CLionProjects/alg3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/alg3.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/alg3.dir/main.cpp.o -c /home/parfenkov/CLionProjects/alg3/main.cpp

CMakeFiles/alg3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/alg3.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parfenkov/CLionProjects/alg3/main.cpp > CMakeFiles/alg3.dir/main.cpp.i

CMakeFiles/alg3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/alg3.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parfenkov/CLionProjects/alg3/main.cpp -o CMakeFiles/alg3.dir/main.cpp.s

CMakeFiles/alg3.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/alg3.dir/main.cpp.o.requires

CMakeFiles/alg3.dir/main.cpp.o.provides: CMakeFiles/alg3.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/alg3.dir/build.make CMakeFiles/alg3.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/alg3.dir/main.cpp.o.provides

CMakeFiles/alg3.dir/main.cpp.o.provides.build: CMakeFiles/alg3.dir/main.cpp.o


# Object files for target alg3
alg3_OBJECTS = \
"CMakeFiles/alg3.dir/main.cpp.o"

# External object files for target alg3
alg3_EXTERNAL_OBJECTS =

alg3: CMakeFiles/alg3.dir/main.cpp.o
alg3: CMakeFiles/alg3.dir/build.make
alg3: CMakeFiles/alg3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/parfenkov/CLionProjects/alg3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable alg3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/alg3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/alg3.dir/build: alg3

.PHONY : CMakeFiles/alg3.dir/build

CMakeFiles/alg3.dir/requires: CMakeFiles/alg3.dir/main.cpp.o.requires

.PHONY : CMakeFiles/alg3.dir/requires

CMakeFiles/alg3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/alg3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/alg3.dir/clean

CMakeFiles/alg3.dir/depend:
	cd /home/parfenkov/CLionProjects/alg3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/parfenkov/CLionProjects/alg3 /home/parfenkov/CLionProjects/alg3 /home/parfenkov/CLionProjects/alg3/cmake-build-debug /home/parfenkov/CLionProjects/alg3/cmake-build-debug /home/parfenkov/CLionProjects/alg3/cmake-build-debug/CMakeFiles/alg3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/alg3.dir/depend

