# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/lida/TechnoPark/yz/tp_c

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lida/TechnoPark/yz/tp_c/iz2/cmakebuild

# Include any dependencies generated for this target.
include CMakeFiles/dyn.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dyn.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dyn.dir/flags.make

CMakeFiles/dyn.dir/iz2/src/parallel.c.o: CMakeFiles/dyn.dir/flags.make
CMakeFiles/dyn.dir/iz2/src/parallel.c.o: ../src/parallel.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lida/TechnoPark/yz/tp_c/iz2/cmakebuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/dyn.dir/iz2/src/parallel.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dyn.dir/iz2/src/parallel.c.o   -c /home/lida/TechnoPark/yz/tp_c/iz2/src/parallel.c

CMakeFiles/dyn.dir/iz2/src/parallel.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dyn.dir/iz2/src/parallel.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lida/TechnoPark/yz/tp_c/iz2/src/parallel.c > CMakeFiles/dyn.dir/iz2/src/parallel.c.i

CMakeFiles/dyn.dir/iz2/src/parallel.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dyn.dir/iz2/src/parallel.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lida/TechnoPark/yz/tp_c/iz2/src/parallel.c -o CMakeFiles/dyn.dir/iz2/src/parallel.c.s

CMakeFiles/dyn.dir/iz2/src/common.c.o: CMakeFiles/dyn.dir/flags.make
CMakeFiles/dyn.dir/iz2/src/common.c.o: ../src/common.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lida/TechnoPark/yz/tp_c/iz2/cmakebuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/dyn.dir/iz2/src/common.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dyn.dir/iz2/src/common.c.o   -c /home/lida/TechnoPark/yz/tp_c/iz2/src/common.c

CMakeFiles/dyn.dir/iz2/src/common.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dyn.dir/iz2/src/common.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lida/TechnoPark/yz/tp_c/iz2/src/common.c > CMakeFiles/dyn.dir/iz2/src/common.c.i

CMakeFiles/dyn.dir/iz2/src/common.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dyn.dir/iz2/src/common.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lida/TechnoPark/yz/tp_c/iz2/src/common.c -o CMakeFiles/dyn.dir/iz2/src/common.c.s

# Object files for target dyn
dyn_OBJECTS = \
"CMakeFiles/dyn.dir/iz2/src/parallel.c.o" \
"CMakeFiles/dyn.dir/iz2/src/common.c.o"

# External object files for target dyn
dyn_EXTERNAL_OBJECTS =

libdyn.so: CMakeFiles/dyn.dir/iz2/src/parallel.c.o
libdyn.so: CMakeFiles/dyn.dir/iz2/src/common.c.o
libdyn.so: CMakeFiles/dyn.dir/build.make
libdyn.so: CMakeFiles/dyn.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lida/TechnoPark/yz/tp_c/iz2/cmakebuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C shared library libdyn.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dyn.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dyn.dir/build: libdyn.so

.PHONY : CMakeFiles/dyn.dir/build

CMakeFiles/dyn.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dyn.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dyn.dir/clean

CMakeFiles/dyn.dir/depend:
	cd /home/lida/TechnoPark/yz/tp_c/iz2/cmakebuild && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lida/TechnoPark/yz/tp_c /home/lida/TechnoPark/yz/tp_c /home/lida/TechnoPark/yz/tp_c/iz2/cmakebuild /home/lida/TechnoPark/yz/tp_c/iz2/cmakebuild /home/lida/TechnoPark/yz/tp_c/iz2/cmakebuild/CMakeFiles/dyn.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dyn.dir/depend
