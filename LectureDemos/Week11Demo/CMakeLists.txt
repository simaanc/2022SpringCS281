cmake_minimum_required(VERSION 3.21)
project(Week11Demo)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Week11Demo
        BST.cpp
        BST.h
        Source.cpp)
