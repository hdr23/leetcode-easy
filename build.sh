#!/bin/bash
COVERAGE=""
BUILD_TYPE=""
CLEAN=""
while [[ $# -gt 0 ]]; do
  case $1 in
    --coverage)
      COVERAGE="-DENABLE_COVERAGE=ON"
      shift
      ;;
    --debug)
      BUILD_TYPE="-DCMAKE_BUILD_TYPE=Debug"
      shift
      ;;
    --clean)
      CLEAN=1
      shift
      ;;
    *)
      echo "Unknown option: $1"
      exit 1
      ;;
  esac
done

if [[ -n "$CLEAN" ]]; then
  rm -rf build
fi
mkdir -p build
cd build

# Run CMake to generate build files in the current 'build' directory using the parent directory's CMakeLists.txt
cmake .. $COVERAGE $BUILD_TYPE

# Build the project using the generated build files (this will compile the code)
cmake --build .