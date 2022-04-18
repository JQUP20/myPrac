# Install script for directory: /home/qlinux/CPP/myPrac/NetProgram/src/21/jmuduo/muduo/base

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/qlinux/CPP/myPrac/NetProgram/src/21/build/debug-install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/qlinux/CPP/myPrac/NetProgram/src/21/build/debug/lib/libmuduo_base.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/muduo/base" TYPE FILE FILES
    "/home/qlinux/CPP/myPrac/NetProgram/src/21/jmuduo/muduo/base/Atomic.h"
    "/home/qlinux/CPP/myPrac/NetProgram/src/21/jmuduo/muduo/base/BlockingQueue.h"
    "/home/qlinux/CPP/myPrac/NetProgram/src/21/jmuduo/muduo/base/BoundedBlockingQueue.h"
    "/home/qlinux/CPP/myPrac/NetProgram/src/21/jmuduo/muduo/base/Condition.h"
    "/home/qlinux/CPP/myPrac/NetProgram/src/21/jmuduo/muduo/base/CountDownLatch.h"
    "/home/qlinux/CPP/myPrac/NetProgram/src/21/jmuduo/muduo/base/CurrentThread.h"
    "/home/qlinux/CPP/myPrac/NetProgram/src/21/jmuduo/muduo/base/Exception.h"
    "/home/qlinux/CPP/myPrac/NetProgram/src/21/jmuduo/muduo/base/LogStream.h"
    "/home/qlinux/CPP/myPrac/NetProgram/src/21/jmuduo/muduo/base/Logging.h"
    "/home/qlinux/CPP/myPrac/NetProgram/src/21/jmuduo/muduo/base/Mutex.h"
    "/home/qlinux/CPP/myPrac/NetProgram/src/21/jmuduo/muduo/base/Singleton.h"
    "/home/qlinux/CPP/myPrac/NetProgram/src/21/jmuduo/muduo/base/StringPiece.h"
    "/home/qlinux/CPP/myPrac/NetProgram/src/21/jmuduo/muduo/base/Thread.h"
    "/home/qlinux/CPP/myPrac/NetProgram/src/21/jmuduo/muduo/base/ThreadLocal.h"
    "/home/qlinux/CPP/myPrac/NetProgram/src/21/jmuduo/muduo/base/ThreadLocalSingleton.h"
    "/home/qlinux/CPP/myPrac/NetProgram/src/21/jmuduo/muduo/base/ThreadPool.h"
    "/home/qlinux/CPP/myPrac/NetProgram/src/21/jmuduo/muduo/base/Timestamp.h"
    "/home/qlinux/CPP/myPrac/NetProgram/src/21/jmuduo/muduo/base/Types.h"
    "/home/qlinux/CPP/myPrac/NetProgram/src/21/jmuduo/muduo/base/copyable.h"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/qlinux/CPP/myPrac/NetProgram/src/21/build/debug/muduo/base/tests/cmake_install.cmake")

endif()

