cmake_minimum_required(VERSION 3.21)
project(Week10Demo)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Week10Demo
        Source.cpp
        UnsortedLinkList.cpp
        UnsortedLinkList.h)
