cmake_minimum_required(VERSION 3.12)
project(ej2bellmanFord)

set(CMAKE_CXX_STANDARD 14)

add_executable(ej2bellmanFord defines.h bellmanFord.cpp bellmanFord.h defines.cpp bellmanFordExe.cpp)