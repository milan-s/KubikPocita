cmake_minimum_required(VERSION 3.20)
project(KubikPocita)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(KubikPocita main.cpp io.cpp io.h calcs.cpp calcs.h consoleColor.cpp consoleColor.h)
