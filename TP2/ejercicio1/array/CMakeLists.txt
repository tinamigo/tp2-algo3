cmake_minimum_required(VERSION 3.14)
project(array)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(array
        arrayExe.cpp
        disjointSet.cpp
        disjointSet.h
        ../defines.h
        ../defines.cpp)
