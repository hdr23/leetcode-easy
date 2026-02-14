#!/bin/bash
COVERAGE=""
while [[ $# -gt 0 ]]; do
  case $1 in
    --coverage)
      COVERAGE="-DENABLE_COVERAGE=ON"
      shift
      ;;
    *)
      echo "Unknown option: $1"
      exit 1
      ;;
  esac
done

mkdir -p build
cd build

# Run CMake to generate build files in the current 'build' directory using the parent directory's CMakeLists.txt
cmake .. $COVERAGE

# Build the project using the generated build files (this will compile the code)
cmake --build .