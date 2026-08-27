cmake_minimum_required(VERSION 3.16)

project(MathLibProject VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(MathApp src/main.cpp src/math_functions.cpp)

target_include_directories(MathApp PUBLIC include)
