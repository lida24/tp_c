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
include CMakeFiles/static.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/static.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/static.dir/flags.make

CMakeFiles/static.dir/iz2/src/main.c.o: CMakeFiles/static.dir/flags.make
CMakeFiles/static.dir/iz2/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lida/TechnoPark/yz/tp_c/iz2/cmakebuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/static.dir/iz2/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/static.dir/iz2/src/main.c.o   -c /home/lida/TechnoPark/yz/tp_c/iz2/src/main.c

CMakeFiles/static.dir/iz2/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/static.dir/iz2/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lida/TechnoPark/yz/tp_c/iz2/src/main.c > CMakeFiles/static.dir/iz2/src/main.c.i

CMakeFiles/static.dir/iz2/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/static.dir/iz2/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lida/TechnoPark/yz/tp_c/iz2/src/main.c -o CMakeFiles/static.dir/iz2/src/main.c.s

# Object files for target static
static_OBJECTS = \
"CMakeFiles/static.dir/iz2/src/main.c.o"

# External object files for target static
static_EXTERNAL_OBJECTS =

static: CMakeFiles/static.dir/iz2/src/main.c.o
static: CMakeFiles/static.dir/build.make
static: libstat.a
static: CMakeFiles/static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lida/TechnoPark/yz/tp_c/iz2/cmakebuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable static"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/static.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/static.dir/build: static

.PHONY : CMakeFiles/static.dir/build

CMakeFiles/static.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/static.dir/cmake_clean.cmake
.PHONY : CMakeFiles/static.dir/clean

CMakeFiles/static.dir/depend:
	cd /home/lida/TechnoPark/yz/tp_c/iz2/cmakebuild && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lida/TechnoPark/yz/tp_c /home/lida/TechnoPark/yz/tp_c /home/lida/TechnoPark/yz/tp_c/iz2/cmakebuild /home/lida/TechnoPark/yz/tp_c/iz2/cmakebuild /home/lida/TechnoPark/yz/tp_c/iz2/cmakebuild/CMakeFiles/static.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/static.dir/depend

