cmake_minimum_required(VERSION 3.21)
project(Lab2Exercise1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab2Exercise1
        SortedAddressLinkList.cpp
        SortedAddressLinkList.h
        SortedAddressList.cpp
        SortedAddressList.h
        Source.cpp)
