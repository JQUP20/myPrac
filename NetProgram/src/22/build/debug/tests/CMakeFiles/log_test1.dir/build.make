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
CMAKE_SOURCE_DIR = /home/qlinux/CPP/myPrac/NetProgram/src/22/jmuduo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/qlinux/CPP/myPrac/NetProgram/src/22/build/debug

# Include any dependencies generated for this target.
include tests/CMakeFiles/log_test1.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/log_test1.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/log_test1.dir/flags.make

tests/CMakeFiles/log_test1.dir/Log_test1.cc.o: tests/CMakeFiles/log_test1.dir/flags.make
tests/CMakeFiles/log_test1.dir/Log_test1.cc.o: /home/qlinux/CPP/myPrac/NetProgram/src/22/jmuduo/tests/Log_test1.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qlinux/CPP/myPrac/NetProgram/src/22/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/log_test1.dir/Log_test1.cc.o"
	cd /home/qlinux/CPP/myPrac/NetProgram/src/22/build/debug/tests && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/log_test1.dir/Log_test1.cc.o -c /home/qlinux/CPP/myPrac/NetProgram/src/22/jmuduo/tests/Log_test1.cc

tests/CMakeFiles/log_test1.dir/Log_test1.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/log_test1.dir/Log_test1.cc.i"
	cd /home/qlinux/CPP/myPrac/NetProgram/src/22/build/debug/tests && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qlinux/CPP/myPrac/NetProgram/src/22/jmuduo/tests/Log_test1.cc > CMakeFiles/log_test1.dir/Log_test1.cc.i

tests/CMakeFiles/log_test1.dir/Log_test1.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/log_test1.dir/Log_test1.cc.s"
	cd /home/qlinux/CPP/myPrac/NetProgram/src/22/build/debug/tests && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qlinux/CPP/myPrac/NetProgram/src/22/jmuduo/tests/Log_test1.cc -o CMakeFiles/log_test1.dir/Log_test1.cc.s

# Object files for target log_test1
log_test1_OBJECTS = \
"CMakeFiles/log_test1.dir/Log_test1.cc.o"

# External object files for target log_test1
log_test1_EXTERNAL_OBJECTS =

bin/log_test1: tests/CMakeFiles/log_test1.dir/Log_test1.cc.o
bin/log_test1: tests/CMakeFiles/log_test1.dir/build.make
bin/log_test1: lib/libmuduo_base.a
bin/log_test1: tests/CMakeFiles/log_test1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/qlinux/CPP/myPrac/NetProgram/src/22/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/log_test1"
	cd /home/qlinux/CPP/myPrac/NetProgram/src/22/build/debug/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/log_test1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/log_test1.dir/build: bin/log_test1

.PHONY : tests/CMakeFiles/log_test1.dir/build

tests/CMakeFiles/log_test1.dir/clean:
	cd /home/qlinux/CPP/myPrac/NetProgram/src/22/build/debug/tests && $(CMAKE_COMMAND) -P CMakeFiles/log_test1.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/log_test1.dir/clean

tests/CMakeFiles/log_test1.dir/depend:
	cd /home/qlinux/CPP/myPrac/NetProgram/src/22/build/debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/qlinux/CPP/myPrac/NetProgram/src/22/jmuduo /home/qlinux/CPP/myPrac/NetProgram/src/22/jmuduo/tests /home/qlinux/CPP/myPrac/NetProgram/src/22/build/debug /home/qlinux/CPP/myPrac/NetProgram/src/22/build/debug/tests /home/qlinux/CPP/myPrac/NetProgram/src/22/build/debug/tests/CMakeFiles/log_test1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/log_test1.dir/depend

