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
CMAKE_SOURCE_DIR = /home/qlinux/CPP/myPrac/NetProgram/mymuduo/03/jmuduo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/qlinux/CPP/myPrac/NetProgram/mymuduo/03/build/debug

# Include any dependencies generated for this target.
include muduo/base/tests/CMakeFiles/timestamp_unittest.dir/depend.make

# Include the progress variables for this target.
include muduo/base/tests/CMakeFiles/timestamp_unittest.dir/progress.make

# Include the compile flags for this target's objects.
include muduo/base/tests/CMakeFiles/timestamp_unittest.dir/flags.make

muduo/base/tests/CMakeFiles/timestamp_unittest.dir/Timestamp_unittest.cc.o: muduo/base/tests/CMakeFiles/timestamp_unittest.dir/flags.make
muduo/base/tests/CMakeFiles/timestamp_unittest.dir/Timestamp_unittest.cc.o: /home/qlinux/CPP/myPrac/NetProgram/mymuduo/03/jmuduo/muduo/base/tests/Timestamp_unittest.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qlinux/CPP/myPrac/NetProgram/mymuduo/03/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object muduo/base/tests/CMakeFiles/timestamp_unittest.dir/Timestamp_unittest.cc.o"
	cd /home/qlinux/CPP/myPrac/NetProgram/mymuduo/03/build/debug/muduo/base/tests && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/timestamp_unittest.dir/Timestamp_unittest.cc.o -c /home/qlinux/CPP/myPrac/NetProgram/mymuduo/03/jmuduo/muduo/base/tests/Timestamp_unittest.cc

muduo/base/tests/CMakeFiles/timestamp_unittest.dir/Timestamp_unittest.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/timestamp_unittest.dir/Timestamp_unittest.cc.i"
	cd /home/qlinux/CPP/myPrac/NetProgram/mymuduo/03/build/debug/muduo/base/tests && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qlinux/CPP/myPrac/NetProgram/mymuduo/03/jmuduo/muduo/base/tests/Timestamp_unittest.cc > CMakeFiles/timestamp_unittest.dir/Timestamp_unittest.cc.i

muduo/base/tests/CMakeFiles/timestamp_unittest.dir/Timestamp_unittest.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/timestamp_unittest.dir/Timestamp_unittest.cc.s"
	cd /home/qlinux/CPP/myPrac/NetProgram/mymuduo/03/build/debug/muduo/base/tests && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qlinux/CPP/myPrac/NetProgram/mymuduo/03/jmuduo/muduo/base/tests/Timestamp_unittest.cc -o CMakeFiles/timestamp_unittest.dir/Timestamp_unittest.cc.s

# Object files for target timestamp_unittest
timestamp_unittest_OBJECTS = \
"CMakeFiles/timestamp_unittest.dir/Timestamp_unittest.cc.o"

# External object files for target timestamp_unittest
timestamp_unittest_EXTERNAL_OBJECTS =

bin/timestamp_unittest: muduo/base/tests/CMakeFiles/timestamp_unittest.dir/Timestamp_unittest.cc.o
bin/timestamp_unittest: muduo/base/tests/CMakeFiles/timestamp_unittest.dir/build.make
bin/timestamp_unittest: lib/libmuduo_base.a
bin/timestamp_unittest: muduo/base/tests/CMakeFiles/timestamp_unittest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/qlinux/CPP/myPrac/NetProgram/mymuduo/03/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../../bin/timestamp_unittest"
	cd /home/qlinux/CPP/myPrac/NetProgram/mymuduo/03/build/debug/muduo/base/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/timestamp_unittest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
muduo/base/tests/CMakeFiles/timestamp_unittest.dir/build: bin/timestamp_unittest

.PHONY : muduo/base/tests/CMakeFiles/timestamp_unittest.dir/build

muduo/base/tests/CMakeFiles/timestamp_unittest.dir/clean:
	cd /home/qlinux/CPP/myPrac/NetProgram/mymuduo/03/build/debug/muduo/base/tests && $(CMAKE_COMMAND) -P CMakeFiles/timestamp_unittest.dir/cmake_clean.cmake
.PHONY : muduo/base/tests/CMakeFiles/timestamp_unittest.dir/clean

muduo/base/tests/CMakeFiles/timestamp_unittest.dir/depend:
	cd /home/qlinux/CPP/myPrac/NetProgram/mymuduo/03/build/debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/qlinux/CPP/myPrac/NetProgram/mymuduo/03/jmuduo /home/qlinux/CPP/myPrac/NetProgram/mymuduo/03/jmuduo/muduo/base/tests /home/qlinux/CPP/myPrac/NetProgram/mymuduo/03/build/debug /home/qlinux/CPP/myPrac/NetProgram/mymuduo/03/build/debug/muduo/base/tests /home/qlinux/CPP/myPrac/NetProgram/mymuduo/03/build/debug/muduo/base/tests/CMakeFiles/timestamp_unittest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : muduo/base/tests/CMakeFiles/timestamp_unittest.dir/depend

