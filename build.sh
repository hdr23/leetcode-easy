#!/bin/bash
mkdir -p build
cd build

# Run CMake to generate build files in the current 'build' directory using the parent directory's CMakeLists.txt
cmake ..

# Build the project using the generated build files (this will compile the code)
cmake --build .