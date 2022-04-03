cmake_minimum_required(VERSION 3.14)
project(treePathRelinking)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(treePathRelinking
        disjointSet.cpp
        disjointSet.h
        treePathRelinkingExe.cpp
        ../defines.h
        ../defines.cpp)
