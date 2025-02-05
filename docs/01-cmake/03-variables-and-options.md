# Variables and Options in CMake

## Variables & Options in CMake

- Variables are used to store values, so that they can be used later in the project.
- Variables are defined using the `set` command.

```cmake
set(VARIABLE_NAME value) # variableName, value

${VARIABLE_NAME} # reference to the variable


# ---- options ----
option(COMPILE_EXECUTABLE "Whether to compile the executable" ON)

if (COMPILE_EXECUTABLE) # use option in conditional statements
    add_subdirectory(app)
else()
    message(STATUS "Not compiling executable")
endif()
```

---

## Changing the value of a variable at runtime

- We can use `-D{variableName}={value}` option to change the value of a variable at runtime.

```bash
cmake -DCOMPILE_EXECUTABLE=OFF ..
```

!!! secondary "Note"
    - This feature is heavily used when we are building a library for release.
    - We use `-DCMAKE_BUILD_TYPE=Release` option to change the value of `CMAKE_BUILD_TYPE` variable at runtime.
    - This will let CMAKE know that we will relase the library, so perform maximum optimizations.

```bash
cd debug
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .

# ---- release build ----

cd ../release
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
```

---

## Contionals statements

```cmake
if(<condition>)
  <commands>
elseif(<condition>) # optional block, can be repeated
  <commands>
else()              # optional block
  <commands>
endif()
```

---

## Some commonly used standard variables

```cmake
set(CMAKE_CXX_STANDARD          17) # set c++ standard to 17
set(CMAKE_CXX_STANDARD_REQUIRED ON) # without cpp 17, compiler will give error
set(CMAKE_CXX_EXTENSIONS        OFF) # it's fine to use c++ 17 without extensions (like, bits/stdc++.h)
```

**Project-Related Variables:**

* **`CMAKE_CURRENT_SOURCE_DIR`**: The directory containing the current CMakeLists.txt file.
* **`CMAKE_CURRENT_BINARY_DIR`**: The directory where the build system files (e.g., Makefiles) are generated.
* **`PROJECT_SOURCE_DIR`**: The root directory of the project.
* **`PROJECT_BINARY_DIR`**: The root directory of the build system files.
* **`PROJECT_NAME`**: The name of the project, as specified in the `project()` command.
* **`CMAKE_BUILD_TYPE`**: The build type (e.g., Debug, Release, MinSizeRel, RelWithDebInfo).

**Compiler and Platform Variables:**

* **`CMAKE_CXX_COMPILER`**: The C++ compiler.
* **`CMAKE_C_COMPILER`**: The C compiler.
* **`CMAKE_SYSTEM_NAME`**: The name of the operating system (e.g., Linux, Windows, macOS).
* **`CMAKE_SYSTEM_PROCESSOR`**: The processor architecture (e.g., x86_64, arm).

**Build System Variables:**

* **`CMAKE_MAKE_PROGRAM`**: The path to the Make program.
* **`CMAKE_NINJA_EXECUTABLE`**: The path to the Ninja build system.
* **`CMAKE_GENERATOR`**: The name of the build system generator (e.g., Unix Makefiles, Visual Studio).

**Other Useful Variables:**

* **`CMAKE_INSTALL_PREFIX`**: The installation prefix for the project.
* **`CMAKE_INCLUDE_PATH`**: The include path for header files.
* **`CMAKE_LIBRARY_PATH`**: The library search path.
