cmake_minimum_required(VERSION 3.21)
project(Week13Demo)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Week13Demo
        BST.cpp
        BST.h
        Source.cpp)
