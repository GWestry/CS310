cmake_minimum_required(VERSION 3.16)

project(MediaPlayer VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)
enable_testing()

include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.6.0
)
FetchContent_MakeAvailable(Catch2)

add_library(PlaylistCore Song.cpp Playlist.cpp SortedArrayPlaylist.cpp)
target_include_directories(PlaylistCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(playlist_tests tests/test_playlist.cpp)
target_link_libraries(playlist_tests PRIVATE PlaylistCore Catch2::Catch2WithMain)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(Catch)
catch_discover_tests(playlist_tests)

find_package(SFML 2.5 COMPONENTS graphics audio window system QUIET)
if(NOT SFML_FOUND)
    message(STATUS "SFML was not found. Downloading SFML for the player target.")
    FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.1
    )
    FetchContent_MakeAvailable(SFML)
endif()

add_executable(player main.cpp MediaPlayer.cpp)
target_link_libraries(player PRIVATE PlaylistCore sfml-graphics sfml-audio sfml-window sfml-system)
