cmake_minimum_required(VERSION 3.13)

project(aoc)

set(CMAKE_CXX_STANDARD 20) # Enable the C++23 standard

file(GLOB_RECURSE SOURCE_FILES src/*.cpp src/*.hpp)

add_executable(aoc ${SOURCE_FILES})
