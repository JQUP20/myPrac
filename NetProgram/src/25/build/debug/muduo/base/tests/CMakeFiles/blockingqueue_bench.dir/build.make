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
include muduo/base/tests/CMakeFiles/blockingqueue_bench.dir/depend.make

# Include the progress variables for this target.
include muduo/base/tests/CMakeFiles/blockingqueue_bench.dir/progress.make

# Include the compile flags for this target's objects.
include muduo/base/tests/CMakeFiles/blockingqueue_bench.dir/flags.make

muduo/base/tests/CMakeFiles/blockingqueue_bench.dir/BlockingQueue_bench.cc.o: muduo/base/tests/CMakeFiles/blockingqueue_bench.dir/flags.make
muduo/base/tests/CMakeFiles/blockingqueue_bench.dir/BlockingQueue_bench.cc.o: /home/qlinux/CPP/myPrac/NetProgram/src/25/jmuduo/muduo/base/tests/BlockingQueue_bench.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qlinux/CPP/myPrac/NetProgram/src/25/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object muduo/base/tests/CMakeFiles/blockingqueue_bench.dir/BlockingQueue_bench.cc.o"
	cd /home/qlinux/CPP/myPrac/NetProgram/src/25/build/debug/muduo/base/tests && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/blockingqueue_bench.dir/BlockingQueue_bench.cc.o -c /home/qlinux/CPP/myPrac/NetProgram/src/25/jmuduo/muduo/base/tests/BlockingQueue_bench.cc

muduo/base/tests/CMakeFiles/blockingqueue_bench.dir/BlockingQueue_bench.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/blockingqueue_bench.dir/BlockingQueue_bench.cc.i"
	cd /home/qlinux/CPP/myPrac/NetProgram/src/25/build/debug/muduo/base/tests && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qlinux/CPP/myPrac/NetProgram/src/25/jmuduo/muduo/base/tests/BlockingQueue_bench.cc > CMakeFiles/blockingqueue_bench.dir/BlockingQueue_bench.cc.i

muduo/base/tests/CMakeFiles/blockingqueue_bench.dir/BlockingQueue_bench.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/blockingqueue_bench.dir/BlockingQueue_bench.cc.s"
	cd /home/qlinux/CPP/myPrac/NetProgram/src/25/build/debug/muduo/base/tests && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qlinux/CPP/myPrac/NetProgram/src/25/jmuduo/muduo/base/tests/BlockingQueue_bench.cc -o CMakeFiles/blockingqueue_bench.dir/BlockingQueue_bench.cc.s

# Object files for target blockingqueue_bench
blockingqueue_bench_OBJECTS = \
"CMakeFiles/blockingqueue_bench.dir/BlockingQueue_bench.cc.o"

# External object files for target blockingqueue_bench
blockingqueue_bench_EXTERNAL_OBJECTS =

bin/blockingqueue_bench: muduo/base/tests/CMakeFiles/blockingqueue_bench.dir/BlockingQueue_bench.cc.o
bin/blockingqueue_bench: muduo/base/tests/CMakeFiles/blockingqueue_bench.dir/build.make
bin/blockingqueue_bench: lib/libmuduo_base.a
bin/blockingqueue_bench: muduo/base/tests/CMakeFiles/blockingqueue_bench.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/qlinux/CPP/myPrac/NetProgram/src/25/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../../bin/blockingqueue_bench"
	cd /home/qlinux/CPP/myPrac/NetProgram/src/25/build/debug/muduo/base/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/blockingqueue_bench.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
muduo/base/tests/CMakeFiles/blockingqueue_bench.dir/build: bin/blockingqueue_bench

.PHONY : muduo/base/tests/CMakeFiles/blockingqueue_bench.dir/build

muduo/base/tests/CMakeFiles/blockingqueue_bench.dir/clean:
	cd /home/qlinux/CPP/myPrac/NetProgram/src/25/build/debug/muduo/base/tests && $(CMAKE_COMMAND) -P CMakeFiles/blockingqueue_bench.dir/cmake_clean.cmake
.PHONY : muduo/base/tests/CMakeFiles/blockingqueue_bench.dir/clean

muduo/base/tests/CMakeFiles/blockingqueue_bench.dir/depend:
	cd /home/qlinux/CPP/myPrac/NetProgram/src/25/build/debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/qlinux/CPP/myPrac/NetProgram/src/25/jmuduo /home/qlinux/CPP/myPrac/NetProgram/src/25/jmuduo/muduo/base/tests /home/qlinux/CPP/myPrac/NetProgram/src/25/build/debug /home/qlinux/CPP/myPrac/NetProgram/src/25/build/debug/muduo/base/tests /home/qlinux/CPP/myPrac/NetProgram/src/25/build/debug/muduo/base/tests/CMakeFiles/blockingqueue_bench.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : muduo/base/tests/CMakeFiles/blockingqueue_bench.dir/depend

