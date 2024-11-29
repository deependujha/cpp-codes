# Configure Files in CMake

- `configure files` is used to copy file from one directory to another and modify some of its contents.

## UseCase

!!! quote ""
    - Let's say we are working on a CLI app, and when user runs `--version`, we want to print the version of the app.
    - Our CMakeLists.txt file also needs to know the version of the app.
    - So, either we can specify the version at each place, or we can just specify it once, and other places can use it.

---

## Idea

- The main idea is, we will specify the values of variables in the `CMakeLists.txt` file.
- Then, we will create a template type file (`filename.hpp.in`), that will have variables and the values will be replaced with the actual values when we run `cmake`.
- This template file will be used by other cpp files, to print the version of the app.

---

## Directory structure

```bash
|-- CMakeLists.txt
|-- configured/
|   |-- CMakeLists.txt
|   |-- config.hpp.in # template file
|-- main.cpp
```

---

## Code

- `config.hpp.in` file

```cpp
#pragma once

#include <cstdint>
#include <string_view>

static constexpr std::string_view project_name = "@PROJECT_NAME@";
static constexpr std::string_view project_version = "@PROJECT_VERSION@";

static constexpr std::int32_t project_version_major{@PROJECT_VERSION_MAJOR@};
static constexpr std::int32_t project_version_minor{@PROJECT_VERSION_MINOR@};
static constexpr std::int32_t project_version_patch{@PROJECT_VERSION_PATCH@};
```

- `configured/CMakeLists.txt` file

```cmake
# Note: If you open the config.hhp.in file in VSCode it is normal that the code has red squiggly lines.
# VSCode think its a normal header file, which it isnt.
# But thats okay.
configure_file(
    "config.hpp.in" # input file
    "${CMAKE_BINARY_DIR}/configured_files/include/config.hpp" # output file
    ESCAPE_QUOTES
)
```

- `CMakeLists.txt` file

```cmake
cmake_minimum_required(VERSION 3.22)

project(CppProjectTemplate VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

set(LIBRARY_NAME Library)
set(EXECUTABLE_NAME Executable)

add_subdirectory(configured)

add_executable(${EXECUTABLE_NAME} main.cpp)

target_include_directories(
    ${EXECUTABLE_NAME}
    PRIVATE
    "${CMAKE_BINARY_DIR}/configured_files/include"
) # include directory with target (executable)
```

---

## Using the configured files in cpp files

```cpp
#include <iostream>

#include "config.hpp"

int main()
{
    std::cout << project_name << '\n';
    std::cout << project_version << '\n';

    return 0;
}
```
