cmake_minimum_required(VERSION 3.20)
project(template)

set(CMAKE_CXX_STANDARD 23)

#add_library(template map.h map.cpp)

add_executable(template Node.cpp Node.hpp BST.cpp BST.h)