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
CMAKE_BINARY_DIR = /home/lida/TechnoPark/yz/tp_c/iz2

# Include any dependencies generated for this target.
include CMakeFiles/stat.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/stat.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/stat.dir/flags.make

CMakeFiles/stat.dir/src/stat.c.o: CMakeFiles/stat.dir/flags.make
CMakeFiles/stat.dir/src/stat.c.o: src/stat.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lida/TechnoPark/yz/tp_c/iz2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/stat.dir/src/stat.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/stat.dir/src/stat.c.o   -c /home/lida/TechnoPark/yz/tp_c/iz2/src/stat.c

CMakeFiles/stat.dir/src/stat.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/stat.dir/src/stat.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lida/TechnoPark/yz/tp_c/iz2/src/stat.c > CMakeFiles/stat.dir/src/stat.c.i

CMakeFiles/stat.dir/src/stat.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/stat.dir/src/stat.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lida/TechnoPark/yz/tp_c/iz2/src/stat.c -o CMakeFiles/stat.dir/src/stat.c.s

# Object files for target stat
stat_OBJECTS = \
"CMakeFiles/stat.dir/src/stat.c.o"

# External object files for target stat
stat_EXTERNAL_OBJECTS =

libstat.a: CMakeFiles/stat.dir/src/stat.c.o
libstat.a: CMakeFiles/stat.dir/build.make
libstat.a: CMakeFiles/stat.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lida/TechnoPark/yz/tp_c/iz2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libstat.a"
	$(CMAKE_COMMAND) -P CMakeFiles/stat.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stat.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/stat.dir/build: libstat.a

.PHONY : CMakeFiles/stat.dir/build

CMakeFiles/stat.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/stat.dir/cmake_clean.cmake
.PHONY : CMakeFiles/stat.dir/clean

CMakeFiles/stat.dir/depend:
	cd /home/lida/TechnoPark/yz/tp_c/iz2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lida/TechnoPark/yz/tp_c /home/lida/TechnoPark/yz/tp_c /home/lida/TechnoPark/yz/tp_c/iz2 /home/lida/TechnoPark/yz/tp_c/iz2 /home/lida/TechnoPark/yz/tp_c/iz2/CMakeFiles/stat.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/stat.dir/depend

