# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_COMMAND = /apps/sylar/bin/cmake

# The command to remove a file.
RM = /apps/sylar/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/qlinux/CPP/myPrac/CPP/tinyProjects/my_json/01/C++

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/qlinux/CPP/myPrac/CPP/tinyProjects/my_json/01/C++/build

# Include any dependencies generated for this target.
include CMakeFiles/leptjson_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/leptjson_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/leptjson_test.dir/flags.make

CMakeFiles/leptjson_test.dir/test.cpp.o: CMakeFiles/leptjson_test.dir/flags.make
CMakeFiles/leptjson_test.dir/test.cpp.o: ../test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qlinux/CPP/myPrac/CPP/tinyProjects/my_json/01/C++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/leptjson_test.dir/test.cpp.o"
	/apps/sylar/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/leptjson_test.dir/test.cpp.o -c /home/qlinux/CPP/myPrac/CPP/tinyProjects/my_json/01/C++/test.cpp

CMakeFiles/leptjson_test.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/leptjson_test.dir/test.cpp.i"
	/apps/sylar/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qlinux/CPP/myPrac/CPP/tinyProjects/my_json/01/C++/test.cpp > CMakeFiles/leptjson_test.dir/test.cpp.i

CMakeFiles/leptjson_test.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/leptjson_test.dir/test.cpp.s"
	/apps/sylar/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qlinux/CPP/myPrac/CPP/tinyProjects/my_json/01/C++/test.cpp -o CMakeFiles/leptjson_test.dir/test.cpp.s

# Object files for target leptjson_test
leptjson_test_OBJECTS = \
"CMakeFiles/leptjson_test.dir/test.cpp.o"

# External object files for target leptjson_test
leptjson_test_EXTERNAL_OBJECTS =

leptjson_test: CMakeFiles/leptjson_test.dir/test.cpp.o
leptjson_test: CMakeFiles/leptjson_test.dir/build.make
leptjson_test: libleptjson.a
leptjson_test: CMakeFiles/leptjson_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/qlinux/CPP/myPrac/CPP/tinyProjects/my_json/01/C++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable leptjson_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/leptjson_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/leptjson_test.dir/build: leptjson_test

.PHONY : CMakeFiles/leptjson_test.dir/build

CMakeFiles/leptjson_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/leptjson_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/leptjson_test.dir/clean

CMakeFiles/leptjson_test.dir/depend:
	cd /home/qlinux/CPP/myPrac/CPP/tinyProjects/my_json/01/C++/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/qlinux/CPP/myPrac/CPP/tinyProjects/my_json/01/C++ /home/qlinux/CPP/myPrac/CPP/tinyProjects/my_json/01/C++ /home/qlinux/CPP/myPrac/CPP/tinyProjects/my_json/01/C++/build /home/qlinux/CPP/myPrac/CPP/tinyProjects/my_json/01/C++/build /home/qlinux/CPP/myPrac/CPP/tinyProjects/my_json/01/C++/build/CMakeFiles/leptjson_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/leptjson_test.dir/depend

