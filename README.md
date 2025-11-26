# LeetCode Easy Solutions

A C++ implementation of LeetCode Easy problems, organized as a library with unit tests.

## Overview

This project contains solutions to various LeetCode Easy array problems, implemented in C++17. The solutions are organized as a static library that can be used in your own projects or tested using the included test suite.

## Prerequisites

- **C++17 compatible compiler** (GCC 7+, Clang 5+, MSVC 2017+)
- **CMake 3.14 or higher**
- **Make** or **Ninja** build system

## Building the Project

### Quick Build (using build script)

```bash
chmod +x build.sh
./build.sh
```

This will:
1. Create a `build/` directory
2. Configure CMake
3. Build the project

### Manual Build

```bash
mkdir -p build
cd build
cmake ..
cmake --build .
```

## Project Structure

```
leetcode-easy/
├── include/          # Header files
│   ├── Arrays.h      # Array problem declarations
│   └── SharedStructs.h
├── src/              # Implementation files
│   ├── Arrays.cpp    # Array problem implementations
│   └── main.cpp      # Sandbox for quick testing
├── tests/            # Unit tests
│   └── ArraysTests.cpp
├── build/            # Build directory (generated, gitignored)
├── CMakeLists.txt    # Main CMake configuration
└── build.sh          # Build script
```

## Running Tests

After building, run the test suite:

```bash
cd build
ctest
```

Or run tests directly:

```bash
cd build
./tests/ArraysTests
```

## Using the Sandbox

The `sandbox` executable allows you to quickly test functions. Modify `src/main.cpp` to test different functions:

```bash
cd build
./sandbox
```

## Development

### Adding New Problems (Example: Arrays)

1. Add function declaration to `include/Arrays.h`
2. Add implementation to `src/Arrays.cpp`
3. Add tests to `tests/ArraysTests.cpp`
4. Rebuild and run tests

### Running Individual Tests

You can filter tests when using CTest:

```bash
cd build
ctest -R ArraysTests
```

## License

This project is for educational purposes.

