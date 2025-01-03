# Using a Library in CMake

!!! success "Basic idea"
    We will be required to compile the library, and then link it with our executable.

---

## Directory structure

```bash
|-- CMakeLists.txt
|-- main.cpp
|-- lib.h
|-- lib.cpp
```

---

## `lib.h` file

```cpp
# pragma once // to avoid multiple inclusion
void printHelloWorld();
```

---

## `lib.cpp` file

```cpp
#include "lib.h"
#include <iostream>

void printHelloWorld() {
    std::cout << "Hello World!" << std::endl;
}
```

---

## `main.cpp` file

```cpp
#include "lib.h"

int main() {
    printHelloWorld();
    return 0;
}
```

---

## `CMakeLists.txt` file

```cmake
cmake_minimum_required(VERSION 3.21)
project(cmake-example VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD          17) # set c++ standard to 17
set(CMAKE_CXX_STANDARD_REQUIRED ON) # without cpp 17, compiler will give error
set(CMAKE_CXX_EXTENSIONS        OFF) # it's fine to use c++ 17 without extensions (like, bits/stdc++.h)

add_library(myLib STATIC lib.cpp) # libraryName, STATIC/SHARED, fileName

add_executable(myExecutable main.cpp) # executableName,  fileName

target_link_libraries(myExecutable PUBLIC myLib) # targetName, PUBLIC/PRIVATE/INTERFACE, libraryName
```

---

## Compiling and running

```bash
mkdir build && cd build
cmake ..
cmake --build .
./myExecutable
```

- To build only library

```cpp
cmake --build . --target myLib
```

- When we build only library, executable will not be built.
- But, when we build executable, library will be built, as it is a dependency (linked).

---

## Following a directory structure

```bash
|-- src/
|   |-- CMakeLists.txt
|   |-- main.cpp
|-- lib/
|   |-- CMakeLists.txt
|   |-- mylib1/
|       |-- CMakeLists.txt
|       |-- lib.cpp
|-- include/
|   |-- lib.h
|-- CMakeLists.txt
```

!!! warning "Note"
    - Keeping `lib.h` file in `include` directory is a good practice if you want your users to be able to use your library.

    - If you want to hide the implementation details of your library, you can put it along with the actual implementation files in `lib` directory.

- Top level `CMakeLists.txt` file will be responsible for building the entire project.
- It will call `CMakeLists.txt` file in `src` and `lib` directories.
- Variables and functions defined in `CMakeLists.txt` file in `src` and `lib` directories will be available in the top level `CMakeLists.txt` file.

---

## CMake builtin functions

- `add_subdirectory` function is used to call `CMakeLists.txt` file in `src` and `lib` directories.
- `include_directories` function is used to add include directories to the project.
- `target_include_directories` function is used to add include directories to a specific target.
- `target_link_libraries` function is used to link a specific target with a library.
- `add_library` function is used to create a library. And it can be `STATIC` or `SHARED`.
- `add_executable` function is used to create an executable.

---

## CMakeLists.txt file in each directory

- `root level`

```cpp
cmake_minimum_required(VERSION 3.21)
project(cmake-example VERSION 1.0.0 LANGUAGES CXX)

set(EXECUTABLE_NAME myExecutable)
set(LIBRARY_NAME myLib)

add_subdirectory(lib) // first build the library
add_subdirectory(include) // then link the library with the include directory

add_subdirectory(src) // build executable, and link it with the library
```

- `lib` directory

```cpp
add_subdirectory(mylib1) # call CMakeLists.txt file in mylib1 directory
```

- `lib/mylib1` directory

```cpp
add_library(${LIBRARY_NAME} STATIC lib.cpp)
```

- `include` directory

```cpp
add_subdirectory(mylib1) # call CMakeLists.txt file in mylib1 directory
```

- `include/mylib1` directory

```cpp
target_include_directories(${LIBRARY_NAME} PUBLIC "./") # add include directory to the library
```

- `src` directory

```cpp
include_directories("../include") # add include directory to the executable
add_executable(${EXECUTABLE_NAME} main.cpp)
target_link_libraries(${EXECUTABLE_NAME} PUBLIC ${LIBRARY_NAME})
```

---

## Running the project

```bash
mkdir build && cd build
cmake ..
cmake --build .
./myExecutable
```
