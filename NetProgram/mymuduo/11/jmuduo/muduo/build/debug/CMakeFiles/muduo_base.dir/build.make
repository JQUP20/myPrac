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
CMAKE_SOURCE_DIR = /home/qlinux/CPP/myPrac/NetProgram/jmuduo/muduo/base

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/qlinux/CPP/myPrac/NetProgram/jmuduo/muduo/build/debug

# Include any dependencies generated for this target.
include CMakeFiles/muduo_base.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/muduo_base.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/muduo_base.dir/flags.make

CMakeFiles/muduo_base.dir/Timestamp.o: CMakeFiles/muduo_base.dir/flags.make
CMakeFiles/muduo_base.dir/Timestamp.o: /home/qlinux/CPP/myPrac/NetProgram/jmuduo/muduo/base/Timestamp.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qlinux/CPP/myPrac/NetProgram/jmuduo/muduo/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/muduo_base.dir/Timestamp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/muduo_base.dir/Timestamp.o -c /home/qlinux/CPP/myPrac/NetProgram/jmuduo/muduo/base/Timestamp.cc

CMakeFiles/muduo_base.dir/Timestamp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/muduo_base.dir/Timestamp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qlinux/CPP/myPrac/NetProgram/jmuduo/muduo/base/Timestamp.cc > CMakeFiles/muduo_base.dir/Timestamp.i

CMakeFiles/muduo_base.dir/Timestamp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/muduo_base.dir/Timestamp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qlinux/CPP/myPrac/NetProgram/jmuduo/muduo/base/Timestamp.cc -o CMakeFiles/muduo_base.dir/Timestamp.s

# Object files for target muduo_base
muduo_base_OBJECTS = \
"CMakeFiles/muduo_base.dir/Timestamp.o"

# External object files for target muduo_base
muduo_base_EXTERNAL_OBJECTS =

libmuduo_base.a: CMakeFiles/muduo_base.dir/Timestamp.o
libmuduo_base.a: CMakeFiles/muduo_base.dir/build.make
libmuduo_base.a: CMakeFiles/muduo_base.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/qlinux/CPP/myPrac/NetProgram/jmuduo/muduo/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libmuduo_base.a"
	$(CMAKE_COMMAND) -P CMakeFiles/muduo_base.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/muduo_base.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/muduo_base.dir/build: libmuduo_base.a

.PHONY : CMakeFiles/muduo_base.dir/build

CMakeFiles/muduo_base.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/muduo_base.dir/cmake_clean.cmake
.PHONY : CMakeFiles/muduo_base.dir/clean

CMakeFiles/muduo_base.dir/depend:
	cd /home/qlinux/CPP/myPrac/NetProgram/jmuduo/muduo/build/debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/qlinux/CPP/myPrac/NetProgram/jmuduo/muduo/base /home/qlinux/CPP/myPrac/NetProgram/jmuduo/muduo/base /home/qlinux/CPP/myPrac/NetProgram/jmuduo/muduo/build/debug /home/qlinux/CPP/myPrac/NetProgram/jmuduo/muduo/build/debug /home/qlinux/CPP/myPrac/NetProgram/jmuduo/muduo/build/debug/CMakeFiles/muduo_base.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/muduo_base.dir/depend

