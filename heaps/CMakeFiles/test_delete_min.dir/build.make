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
CMAKE_SOURCE_DIR = "/home/claudia/Units/Algorithmic Design/AD_homeworks/code/heaps"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/claudia/Units/Algorithmic Design/AD_homeworks/code/heaps"

# Include any dependencies generated for this target.
include CMakeFiles/test_delete_min.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_delete_min.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_delete_min.dir/flags.make

CMakeFiles/test_delete_min.dir/tests/test_delete_min.c.o: CMakeFiles/test_delete_min.dir/flags.make
CMakeFiles/test_delete_min.dir/tests/test_delete_min.c.o: tests/test_delete_min.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/claudia/Units/Algorithmic Design/AD_homeworks/code/heaps/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/test_delete_min.dir/tests/test_delete_min.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_delete_min.dir/tests/test_delete_min.c.o   -c "/home/claudia/Units/Algorithmic Design/AD_homeworks/code/heaps/tests/test_delete_min.c"

CMakeFiles/test_delete_min.dir/tests/test_delete_min.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_delete_min.dir/tests/test_delete_min.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/claudia/Units/Algorithmic Design/AD_homeworks/code/heaps/tests/test_delete_min.c" > CMakeFiles/test_delete_min.dir/tests/test_delete_min.c.i

CMakeFiles/test_delete_min.dir/tests/test_delete_min.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_delete_min.dir/tests/test_delete_min.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/claudia/Units/Algorithmic Design/AD_homeworks/code/heaps/tests/test_delete_min.c" -o CMakeFiles/test_delete_min.dir/tests/test_delete_min.c.s

CMakeFiles/test_delete_min.dir/tests/test_delete_min.c.o.requires:

.PHONY : CMakeFiles/test_delete_min.dir/tests/test_delete_min.c.o.requires

CMakeFiles/test_delete_min.dir/tests/test_delete_min.c.o.provides: CMakeFiles/test_delete_min.dir/tests/test_delete_min.c.o.requires
	$(MAKE) -f CMakeFiles/test_delete_min.dir/build.make CMakeFiles/test_delete_min.dir/tests/test_delete_min.c.o.provides.build
.PHONY : CMakeFiles/test_delete_min.dir/tests/test_delete_min.c.o.provides

CMakeFiles/test_delete_min.dir/tests/test_delete_min.c.o.provides.build: CMakeFiles/test_delete_min.dir/tests/test_delete_min.c.o


# Object files for target test_delete_min
test_delete_min_OBJECTS = \
"CMakeFiles/test_delete_min.dir/tests/test_delete_min.c.o"

# External object files for target test_delete_min
test_delete_min_EXTERNAL_OBJECTS =

test_delete_min: CMakeFiles/test_delete_min.dir/tests/test_delete_min.c.o
test_delete_min: CMakeFiles/test_delete_min.dir/build.make
test_delete_min: libbinheap.so
test_delete_min: libcommon.a
test_delete_min: CMakeFiles/test_delete_min.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/claudia/Units/Algorithmic Design/AD_homeworks/code/heaps/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable test_delete_min"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_delete_min.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_delete_min.dir/build: test_delete_min

.PHONY : CMakeFiles/test_delete_min.dir/build

CMakeFiles/test_delete_min.dir/requires: CMakeFiles/test_delete_min.dir/tests/test_delete_min.c.o.requires

.PHONY : CMakeFiles/test_delete_min.dir/requires

CMakeFiles/test_delete_min.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_delete_min.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_delete_min.dir/clean

CMakeFiles/test_delete_min.dir/depend:
	cd "/home/claudia/Units/Algorithmic Design/AD_homeworks/code/heaps" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/claudia/Units/Algorithmic Design/AD_homeworks/code/heaps" "/home/claudia/Units/Algorithmic Design/AD_homeworks/code/heaps" "/home/claudia/Units/Algorithmic Design/AD_homeworks/code/heaps" "/home/claudia/Units/Algorithmic Design/AD_homeworks/code/heaps" "/home/claudia/Units/Algorithmic Design/AD_homeworks/code/heaps/CMakeFiles/test_delete_min.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/test_delete_min.dir/depend
