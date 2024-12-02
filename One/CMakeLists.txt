cmake_minimum_required(VERSION 3.13)

project(aoc)

set(CMAKE_CXX_STANDARD 20) # Enable the C++23 standard

file(GLOB_RECURSE SOURCE_FILES src/*.cpp src/*.hpp)

add_executable(aoc ${SOURCE_FILES})

# Copy `.input` files to the output directory
file(GLOB INPUT_FILES src/*.input) # Find all .input files
foreach(INPUT_FILE ${INPUT_FILES})
    add_custom_command(
        TARGET aoc POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${INPUT_FILE} $<TARGET_FILE_DIR:aoc>
        COMMENT "Copying ${INPUT_FILE} to output directory"
    )
endforeach()

foreach(INPUT_FILE ${INPUT_FILES})
    add_custom_command(
        TARGET aoc POST_BUILD  # This will run after the executable is built
        COMMAND ${CMAKE_COMMAND} -E copy ${INPUT_FILE} ${CMAKE_BINARY_DIR}/CMakeFiles/aoc.dir/src/
        COMMENT "Copying ${INPUT_FILE} to output directory"
    )
endforeach()

