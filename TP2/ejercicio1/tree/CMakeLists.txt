cmake_minimum_required(VERSION 3.14)
project(tree)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(tree
        disjointSet.cpp
        disjointSet.h
        treeExe.cpp
        ../defines.h
        ../defines.cpp)
