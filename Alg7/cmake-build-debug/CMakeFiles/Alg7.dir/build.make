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
CMAKE_SOURCE_DIR = /home/parfenkov/CLionProjects/Alg7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/parfenkov/CLionProjects/Alg7/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Alg7.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Alg7.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Alg7.dir/flags.make

CMakeFiles/Alg7.dir/main.cpp.o: CMakeFiles/Alg7.dir/flags.make
CMakeFiles/Alg7.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parfenkov/CLionProjects/Alg7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Alg7.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Alg7.dir/main.cpp.o -c /home/parfenkov/CLionProjects/Alg7/main.cpp

CMakeFiles/Alg7.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Alg7.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parfenkov/CLionProjects/Alg7/main.cpp > CMakeFiles/Alg7.dir/main.cpp.i

CMakeFiles/Alg7.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Alg7.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parfenkov/CLionProjects/Alg7/main.cpp -o CMakeFiles/Alg7.dir/main.cpp.s

CMakeFiles/Alg7.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Alg7.dir/main.cpp.o.requires

CMakeFiles/Alg7.dir/main.cpp.o.provides: CMakeFiles/Alg7.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Alg7.dir/build.make CMakeFiles/Alg7.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Alg7.dir/main.cpp.o.provides

CMakeFiles/Alg7.dir/main.cpp.o.provides.build: CMakeFiles/Alg7.dir/main.cpp.o


# Object files for target Alg7
Alg7_OBJECTS = \
"CMakeFiles/Alg7.dir/main.cpp.o"

# External object files for target Alg7
Alg7_EXTERNAL_OBJECTS =

Alg7: CMakeFiles/Alg7.dir/main.cpp.o
Alg7: CMakeFiles/Alg7.dir/build.make
Alg7: CMakeFiles/Alg7.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/parfenkov/CLionProjects/Alg7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Alg7"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Alg7.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Alg7.dir/build: Alg7

.PHONY : CMakeFiles/Alg7.dir/build

CMakeFiles/Alg7.dir/requires: CMakeFiles/Alg7.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Alg7.dir/requires

CMakeFiles/Alg7.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Alg7.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Alg7.dir/clean

CMakeFiles/Alg7.dir/depend:
	cd /home/parfenkov/CLionProjects/Alg7/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/parfenkov/CLionProjects/Alg7 /home/parfenkov/CLionProjects/Alg7 /home/parfenkov/CLionProjects/Alg7/cmake-build-debug /home/parfenkov/CLionProjects/Alg7/cmake-build-debug /home/parfenkov/CLionProjects/Alg7/cmake-build-debug/CMakeFiles/Alg7.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Alg7.dir/depend
