cmake_minimum_required(VERSION 3.14)
project(LeetCodeEasy)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

# Source files
set(SOURCES
    src/Arrays.cpp
    src/Strings.cpp
)

# Create the library
add_library(LeetCodeLib ${SOURCES})

add_executable(sandbox src/main.cpp)

target_link_libraries(sandbox LeetCodeLib)

# Enable testing
enable_testing()
add_subdirectory(tests)