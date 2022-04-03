cmake_minimum_required(VERSION 3.12)
project(ej2floyd)

set(CMAKE_CXX_STANDARD 14)

add_executable(ej2floyd defines.h floyd.cpp floyd.h ../defines.cpp floydExe.cpp)
