cmake_minimum_required(VERSION 3.12)
project(ej2dijkstra)

set(CMAKE_CXX_STANDARD 14)

add_executable(ej2dijkstra dijkstra.cpp defines.h dijkstra.h defines.cpp dijkstraExe.cpp)