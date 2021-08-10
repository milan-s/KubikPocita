cmake_minimum_required(VERSION 3.20)
project(KubikPocita)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(KubikPocita main.cpp io.cpp io.h calcs.cpp calcs.h consoleColor.cpp consoleColor.h)
