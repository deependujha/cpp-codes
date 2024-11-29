# Introduction to CMake

![cmake logo](../images/cmake/cmake.jpeg)

- We used to write makefiles to build our projects. But, for large projects, it becomes difficult to maintain and manage.
- CMake is a build system generator. It is used to generate build files for various build systems.
- CMake is a cross-platform build system.
- We write `CMakeLists.txt` file to configure the build system.
- To build a project, we need to run `cmake` command.

!!! info "CMake must know!"
    - CMake is not a build system.
    - CMake is a build-system generator. It generates the build system files.

    What are build-system?

    - A file that contains code for how to link different files, compile them, etc for the current os/hardware.
    - e.g., Makefiles, Ninja, etc.

---

## A simple cpp file

```cpp
// main.cpp
#include <iostream>

int main() {
    std::cout << "Hello World!" << std::endl;
    return 0;
}
```

---

## CMakeLists.txt file

```cmake
# CMakeLists.txt
cmake_minimum_required(VERSION 3.21)
project(cmake-example VERSION 1.0.0 LANGUAGES CXX) // project name, version, languages

add_executable(cpp-codes main.cpp) // executableName,  fileName
```

- We use `CXX` for C++ files. Since, '+' will be considered as a operator in CMake.

---

## Build the project

```bash
mkdir build && cd build # to keep the root directory clean
cmake .. # specifying the path of the CMakeLists.txt file
# the above command will generate the build files
cmake --build . # to build the project
```

---

## Run executable

```bash
./cpp-codes # to run the executable
```

---

## Some important flags 🇬🇧

- `-S` specify the CMakeLists.txt file path
- `-B` specify the build directory
- `-G` specify the build generator name (makefile, ninja, etc.)

```bash
mkdir build && cd build
cmake -S .. -B . # option 1
cmake .. # option 2 (builds in the current directory by default)


# =================

# generate the build file for make/ninja
# run `cmake --help` for more info

cmake .. -G "Unix Makefiles"
cmake .. -G "Ninja"
```
