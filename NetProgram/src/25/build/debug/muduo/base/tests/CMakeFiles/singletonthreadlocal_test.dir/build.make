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
CMAKE_SOURCE_DIR = /home/qlinux/CPP/myPrac/NetProgram/src/25/jmuduo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/qlinux/CPP/myPrac/NetProgram/src/25/build/debug

# Include any dependencies generated for this target.
include muduo/base/tests/CMakeFiles/singletonthreadlocal_test.dir/depend.make

# Include the progress variables for this target.
include muduo/base/tests/CMakeFiles/singletonthreadlocal_test.dir/progress.make

# Include the compile flags for this target's objects.
include muduo/base/tests/CMakeFiles/singletonthreadlocal_test.dir/flags.make

muduo/base/tests/CMakeFiles/singletonthreadlocal_test.dir/SingletonThreadLocal_test.cc.o: muduo/base/tests/CMakeFiles/singletonthreadlocal_test.dir/flags.make
muduo/base/tests/CMakeFiles/singletonthreadlocal_test.dir/SingletonThreadLocal_test.cc.o: /home/qlinux/CPP/myPrac/NetProgram/src/25/jmuduo/muduo/base/tests/SingletonThreadLocal_test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qlinux/CPP/myPrac/NetProgram/src/25/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object muduo/base/tests/CMakeFiles/singletonthreadlocal_test.dir/SingletonThreadLocal_test.cc.o"
	cd /home/qlinux/CPP/myPrac/NetProgram/src/25/build/debug/muduo/base/tests && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/singletonthreadlocal_test.dir/SingletonThreadLocal_test.cc.o -c /home/qlinux/CPP/myPrac/NetProgram/src/25/jmuduo/muduo/base/tests/SingletonThreadLocal_test.cc

muduo/base/tests/CMakeFiles/singletonthreadlocal_test.dir/SingletonThreadLocal_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/singletonthreadlocal_test.dir/SingletonThreadLocal_test.cc.i"
	cd /home/qlinux/CPP/myPrac/NetProgram/src/25/build/debug/muduo/base/tests && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qlinux/CPP/myPrac/NetProgram/src/25/jmuduo/muduo/base/tests/SingletonThreadLocal_test.cc > CMakeFiles/singletonthreadlocal_test.dir/SingletonThreadLocal_test.cc.i

muduo/base/tests/CMakeFiles/singletonthreadlocal_test.dir/SingletonThreadLocal_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/singletonthreadlocal_test.dir/SingletonThreadLocal_test.cc.s"
	cd /home/qlinux/CPP/myPrac/NetProgram/src/25/build/debug/muduo/base/tests && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qlinux/CPP/myPrac/NetProgram/src/25/jmuduo/muduo/base/tests/SingletonThreadLocal_test.cc -o CMakeFiles/singletonthreadlocal_test.dir/SingletonThreadLocal_test.cc.s

# Object files for target singletonthreadlocal_test
singletonthreadlocal_test_OBJECTS = \
"CMakeFiles/singletonthreadlocal_test.dir/SingletonThreadLocal_test.cc.o"

# External object files for target singletonthreadlocal_test
singletonthreadlocal_test_EXTERNAL_OBJECTS =

bin/singletonthreadlocal_test: muduo/base/tests/CMakeFiles/singletonthreadlocal_test.dir/SingletonThreadLocal_test.cc.o
bin/singletonthreadlocal_test: muduo/base/tests/CMakeFiles/singletonthreadlocal_test.dir/build.make
bin/singletonthreadlocal_test: lib/libmuduo_base.a
bin/singletonthreadlocal_test: muduo/base/tests/CMakeFiles/singletonthreadlocal_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/qlinux/CPP/myPrac/NetProgram/src/25/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../../bin/singletonthreadlocal_test"
	cd /home/qlinux/CPP/myPrac/NetProgram/src/25/build/debug/muduo/base/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/singletonthreadlocal_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
muduo/base/tests/CMakeFiles/singletonthreadlocal_test.dir/build: bin/singletonthreadlocal_test

.PHONY : muduo/base/tests/CMakeFiles/singletonthreadlocal_test.dir/build

muduo/base/tests/CMakeFiles/singletonthreadlocal_test.dir/clean:
	cd /home/qlinux/CPP/myPrac/NetProgram/src/25/build/debug/muduo/base/tests && $(CMAKE_COMMAND) -P CMakeFiles/singletonthreadlocal_test.dir/cmake_clean.cmake
.PHONY : muduo/base/tests/CMakeFiles/singletonthreadlocal_test.dir/clean

muduo/base/tests/CMakeFiles/singletonthreadlocal_test.dir/depend:
	cd /home/qlinux/CPP/myPrac/NetProgram/src/25/build/debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/qlinux/CPP/myPrac/NetProgram/src/25/jmuduo /home/qlinux/CPP/myPrac/NetProgram/src/25/jmuduo/muduo/base/tests /home/qlinux/CPP/myPrac/NetProgram/src/25/build/debug /home/qlinux/CPP/myPrac/NetProgram/src/25/build/debug/muduo/base/tests /home/qlinux/CPP/myPrac/NetProgram/src/25/build/debug/muduo/base/tests/CMakeFiles/singletonthreadlocal_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : muduo/base/tests/CMakeFiles/singletonthreadlocal_test.dir/depend

