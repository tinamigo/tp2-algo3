cmake_minimum_required(VERSION 3.12)
project(ejercicio2)

set(CMAKE_CXX_STANDARD 14)

add_executable(ejercicio2 main.cpp dijkstra.cpp defines.h bellmanFord.cpp dijkstra.h bellmanFord.h floyd.cpp floyd.h dijkstraDenso.cpp dijkstraDenso.h defines.cpp)