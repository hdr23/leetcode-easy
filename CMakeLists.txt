cmake_minimum_required(VERSION 3.14)
project(LeetCodeEasy)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(ENABLE_COVERAGE "Enable code coverage (e.g. gcov)" OFF)
if(ENABLE_COVERAGE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif()

include_directories(include)

# Source files
set(SOURCES
    src/ArrayProblems.cpp
    src/StringProblems.cpp
    src/LinkedListProblems.cpp
    src/TreeProblems.cpp
    src/OtherProblems.cpp
)

# Create the library
add_library(LeetCodeLib ${SOURCES})

add_executable(sandbox src/main.cpp)

target_link_libraries(sandbox LeetCodeLib)

# Enable testing
enable_testing()
add_subdirectory(tests)