cmake_minimum_required(VERSION 3.16)

project(MathLibProject VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(MathApp src/main.cpp src/math_functions.cpp)

target_include_directories(MathApp PUBLIC include)

#Enable testing
enable_testing()

#Fetch Catch2
include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.6.0 # Use the latest stable version.
)
FetchContent_MakeAvailable(Catch2)

#Add test executable
add_executable(unit_tests tests/math_tests.cpp
src/math_functions.cpp)
target_link_libraries(unit_tests PRIVATE
Catch2::Catch2WithMain)
target_include_directories(unit_tests PUBLIC include)

#Discover and add tests to CTest
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)
catch_discover_tests(unit_tests)

