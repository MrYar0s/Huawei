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
CMAKE_SOURCE_DIR = /home/mryaros/Huawei/Tree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mryaros/Huawei/Tree/build

# Include any dependencies generated for this target.
include tree/tests/CMakeFiles/test.dir/depend.make

# Include the progress variables for this target.
include tree/tests/CMakeFiles/test.dir/progress.make

# Include the compile flags for this target's objects.
include tree/tests/CMakeFiles/test.dir/flags.make

tree/tests/CMakeFiles/test.dir/gtest.cpp.o: tree/tests/CMakeFiles/test.dir/flags.make
tree/tests/CMakeFiles/test.dir/gtest.cpp.o: ../tree/tests/gtest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mryaros/Huawei/Tree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tree/tests/CMakeFiles/test.dir/gtest.cpp.o"
	cd /home/mryaros/Huawei/Tree/build/tree/tests && $(CMAKE_COMMAND) -E __run_co_compile --tidy="clang-tidy;--format-style=file;--header-filter=." --source=/home/mryaros/Huawei/Tree/tree/tests/gtest.cpp -- /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/gtest.cpp.o -c /home/mryaros/Huawei/Tree/tree/tests/gtest.cpp

tree/tests/CMakeFiles/test.dir/gtest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/gtest.cpp.i"
	cd /home/mryaros/Huawei/Tree/build/tree/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mryaros/Huawei/Tree/tree/tests/gtest.cpp > CMakeFiles/test.dir/gtest.cpp.i

tree/tests/CMakeFiles/test.dir/gtest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/gtest.cpp.s"
	cd /home/mryaros/Huawei/Tree/build/tree/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mryaros/Huawei/Tree/tree/tests/gtest.cpp -o CMakeFiles/test.dir/gtest.cpp.s

# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/gtest.cpp.o"

# External object files for target test
test_EXTERNAL_OBJECTS =

tree/tests/test: tree/tests/CMakeFiles/test.dir/gtest.cpp.o
tree/tests/test: tree/tests/CMakeFiles/test.dir/build.make
tree/tests/test: /usr/lib/x86_64-linux-gnu/libgtest_main.a
tree/tests/test: /usr/lib/x86_64-linux-gnu/libgtest.a
tree/tests/test: tree/tests/CMakeFiles/test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mryaros/Huawei/Tree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test"
	cd /home/mryaros/Huawei/Tree/build/tree/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tree/tests/CMakeFiles/test.dir/build: tree/tests/test

.PHONY : tree/tests/CMakeFiles/test.dir/build

tree/tests/CMakeFiles/test.dir/clean:
	cd /home/mryaros/Huawei/Tree/build/tree/tests && $(CMAKE_COMMAND) -P CMakeFiles/test.dir/cmake_clean.cmake
.PHONY : tree/tests/CMakeFiles/test.dir/clean

tree/tests/CMakeFiles/test.dir/depend:
	cd /home/mryaros/Huawei/Tree/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mryaros/Huawei/Tree /home/mryaros/Huawei/Tree/tree/tests /home/mryaros/Huawei/Tree/build /home/mryaros/Huawei/Tree/build/tree/tests /home/mryaros/Huawei/Tree/build/tree/tests/CMakeFiles/test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tree/tests/CMakeFiles/test.dir/depend

