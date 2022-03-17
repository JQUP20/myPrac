cmake_minimum_required(VERSION 3.13)

# Enable C++11
set(CMAKE_CXX_STANDARD 11)

project(test_binary_tree)

include_directories("./*")

add_executable(test_binary_tree test_binary_tree.cpp BinaryTree.cpp BinaryTree.h)
