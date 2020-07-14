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
CMAKE_SOURCE_DIR = "/home/claudia/Units/Algorithmic Design/AD_homeworks/code/strassen"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/claudia/Units/Algorithmic Design/AD_homeworks/code/strassen"

# Include any dependencies generated for this target.
include CMakeFiles/strassen_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/strassen_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/strassen_test.dir/flags.make

CMakeFiles/strassen_test.dir/main.c.o: CMakeFiles/strassen_test.dir/flags.make
CMakeFiles/strassen_test.dir/main.c.o: main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/claudia/Units/Algorithmic Design/AD_homeworks/code/strassen/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/strassen_test.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/strassen_test.dir/main.c.o   -c "/home/claudia/Units/Algorithmic Design/AD_homeworks/code/strassen/main.c"

CMakeFiles/strassen_test.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/strassen_test.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/claudia/Units/Algorithmic Design/AD_homeworks/code/strassen/main.c" > CMakeFiles/strassen_test.dir/main.c.i

CMakeFiles/strassen_test.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/strassen_test.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/claudia/Units/Algorithmic Design/AD_homeworks/code/strassen/main.c" -o CMakeFiles/strassen_test.dir/main.c.s

CMakeFiles/strassen_test.dir/main.c.o.requires:

.PHONY : CMakeFiles/strassen_test.dir/main.c.o.requires

CMakeFiles/strassen_test.dir/main.c.o.provides: CMakeFiles/strassen_test.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/strassen_test.dir/build.make CMakeFiles/strassen_test.dir/main.c.o.provides.build
.PHONY : CMakeFiles/strassen_test.dir/main.c.o.provides

CMakeFiles/strassen_test.dir/main.c.o.provides.build: CMakeFiles/strassen_test.dir/main.c.o


CMakeFiles/strassen_test.dir/matrix.c.o: CMakeFiles/strassen_test.dir/flags.make
CMakeFiles/strassen_test.dir/matrix.c.o: matrix.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/claudia/Units/Algorithmic Design/AD_homeworks/code/strassen/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/strassen_test.dir/matrix.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/strassen_test.dir/matrix.c.o   -c "/home/claudia/Units/Algorithmic Design/AD_homeworks/code/strassen/matrix.c"

CMakeFiles/strassen_test.dir/matrix.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/strassen_test.dir/matrix.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/claudia/Units/Algorithmic Design/AD_homeworks/code/strassen/matrix.c" > CMakeFiles/strassen_test.dir/matrix.c.i

CMakeFiles/strassen_test.dir/matrix.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/strassen_test.dir/matrix.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/claudia/Units/Algorithmic Design/AD_homeworks/code/strassen/matrix.c" -o CMakeFiles/strassen_test.dir/matrix.c.s

CMakeFiles/strassen_test.dir/matrix.c.o.requires:

.PHONY : CMakeFiles/strassen_test.dir/matrix.c.o.requires

CMakeFiles/strassen_test.dir/matrix.c.o.provides: CMakeFiles/strassen_test.dir/matrix.c.o.requires
	$(MAKE) -f CMakeFiles/strassen_test.dir/build.make CMakeFiles/strassen_test.dir/matrix.c.o.provides.build
.PHONY : CMakeFiles/strassen_test.dir/matrix.c.o.provides

CMakeFiles/strassen_test.dir/matrix.c.o.provides.build: CMakeFiles/strassen_test.dir/matrix.c.o


CMakeFiles/strassen_test.dir/strassen.c.o: CMakeFiles/strassen_test.dir/flags.make
CMakeFiles/strassen_test.dir/strassen.c.o: strassen.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/claudia/Units/Algorithmic Design/AD_homeworks/code/strassen/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/strassen_test.dir/strassen.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/strassen_test.dir/strassen.c.o   -c "/home/claudia/Units/Algorithmic Design/AD_homeworks/code/strassen/strassen.c"

CMakeFiles/strassen_test.dir/strassen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/strassen_test.dir/strassen.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/claudia/Units/Algorithmic Design/AD_homeworks/code/strassen/strassen.c" > CMakeFiles/strassen_test.dir/strassen.c.i

CMakeFiles/strassen_test.dir/strassen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/strassen_test.dir/strassen.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/claudia/Units/Algorithmic Design/AD_homeworks/code/strassen/strassen.c" -o CMakeFiles/strassen_test.dir/strassen.c.s

CMakeFiles/strassen_test.dir/strassen.c.o.requires:

.PHONY : CMakeFiles/strassen_test.dir/strassen.c.o.requires

CMakeFiles/strassen_test.dir/strassen.c.o.provides: CMakeFiles/strassen_test.dir/strassen.c.o.requires
	$(MAKE) -f CMakeFiles/strassen_test.dir/build.make CMakeFiles/strassen_test.dir/strassen.c.o.provides.build
.PHONY : CMakeFiles/strassen_test.dir/strassen.c.o.provides

CMakeFiles/strassen_test.dir/strassen.c.o.provides.build: CMakeFiles/strassen_test.dir/strassen.c.o


CMakeFiles/strassen_test.dir/test.c.o: CMakeFiles/strassen_test.dir/flags.make
CMakeFiles/strassen_test.dir/test.c.o: test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/claudia/Units/Algorithmic Design/AD_homeworks/code/strassen/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/strassen_test.dir/test.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/strassen_test.dir/test.c.o   -c "/home/claudia/Units/Algorithmic Design/AD_homeworks/code/strassen/test.c"

CMakeFiles/strassen_test.dir/test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/strassen_test.dir/test.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/claudia/Units/Algorithmic Design/AD_homeworks/code/strassen/test.c" > CMakeFiles/strassen_test.dir/test.c.i

CMakeFiles/strassen_test.dir/test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/strassen_test.dir/test.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/claudia/Units/Algorithmic Design/AD_homeworks/code/strassen/test.c" -o CMakeFiles/strassen_test.dir/test.c.s

CMakeFiles/strassen_test.dir/test.c.o.requires:

.PHONY : CMakeFiles/strassen_test.dir/test.c.o.requires

CMakeFiles/strassen_test.dir/test.c.o.provides: CMakeFiles/strassen_test.dir/test.c.o.requires
	$(MAKE) -f CMakeFiles/strassen_test.dir/build.make CMakeFiles/strassen_test.dir/test.c.o.provides.build
.PHONY : CMakeFiles/strassen_test.dir/test.c.o.provides

CMakeFiles/strassen_test.dir/test.c.o.provides.build: CMakeFiles/strassen_test.dir/test.c.o


# Object files for target strassen_test
strassen_test_OBJECTS = \
"CMakeFiles/strassen_test.dir/main.c.o" \
"CMakeFiles/strassen_test.dir/matrix.c.o" \
"CMakeFiles/strassen_test.dir/strassen.c.o" \
"CMakeFiles/strassen_test.dir/test.c.o"

# External object files for target strassen_test
strassen_test_EXTERNAL_OBJECTS =

strassen_test: CMakeFiles/strassen_test.dir/main.c.o
strassen_test: CMakeFiles/strassen_test.dir/matrix.c.o
strassen_test: CMakeFiles/strassen_test.dir/strassen.c.o
strassen_test: CMakeFiles/strassen_test.dir/test.c.o
strassen_test: CMakeFiles/strassen_test.dir/build.make
strassen_test: CMakeFiles/strassen_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/claudia/Units/Algorithmic Design/AD_homeworks/code/strassen/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable strassen_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/strassen_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/strassen_test.dir/build: strassen_test

.PHONY : CMakeFiles/strassen_test.dir/build

CMakeFiles/strassen_test.dir/requires: CMakeFiles/strassen_test.dir/main.c.o.requires
CMakeFiles/strassen_test.dir/requires: CMakeFiles/strassen_test.dir/matrix.c.o.requires
CMakeFiles/strassen_test.dir/requires: CMakeFiles/strassen_test.dir/strassen.c.o.requires
CMakeFiles/strassen_test.dir/requires: CMakeFiles/strassen_test.dir/test.c.o.requires

.PHONY : CMakeFiles/strassen_test.dir/requires

CMakeFiles/strassen_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/strassen_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/strassen_test.dir/clean

CMakeFiles/strassen_test.dir/depend:
	cd "/home/claudia/Units/Algorithmic Design/AD_homeworks/code/strassen" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/claudia/Units/Algorithmic Design/AD_homeworks/code/strassen" "/home/claudia/Units/Algorithmic Design/AD_homeworks/code/strassen" "/home/claudia/Units/Algorithmic Design/AD_homeworks/code/strassen" "/home/claudia/Units/Algorithmic Design/AD_homeworks/code/strassen" "/home/claudia/Units/Algorithmic Design/AD_homeworks/code/strassen/CMakeFiles/strassen_test.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/strassen_test.dir/depend

