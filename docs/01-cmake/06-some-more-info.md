# CMake Notes: `function`, `include`, and `FetchContent`

## 1. `function`

### Purpose:

Defines reusable blocks of CMake code. It creates a local scope, meaning variables defined inside a function won't affect the global scope unless explicitly modified.

### Syntax:

```cmake
function(FunctionName arg1 arg2)
    # Body of the function
    message("Argument 1: ${arg1}")
    message("Argument 2: ${arg2}")
endfunction()
```

### Example:

```cmake
function(print_message msg)
    message("Message: ${msg}")
endfunction()

print_message("Hello, CMake!")
```

Output:
```
Message: Hello, CMake!
```

---

## 2. `include`
### Purpose:
Includes another CMake script file to reuse its logic. Useful for modularizing CMake code.

### Syntax:
```cmake
include(FileName.cmake [OPTIONAL] [RESULT_VARIABLE var])
```

### Example:
**Main CMakeLists.txt**
```cmake
include(helper.cmake)
hello_world()
```

**helper.cmake**
```cmake
function(hello_world)
    message("Hello from helper.cmake!")
endfunction()
```

Output:
```
Hello from helper.cmake!
```

---

## 3. `FetchContent`
### Purpose:
Fetches and integrates external dependencies directly into the build process.

### Syntax:
```cmake
include(FetchContent)
FetchContent_Declare(
    <Name>
    GIT_REPOSITORY <url>
    GIT_TAG <commit/tag/branch>
)
FetchContent_MakeAvailable(<Name>)
```

### Example:
```cmake
include(FetchContent)

FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.11.2
)

FetchContent_MakeAvailable(json)

add_executable(my_app main.cpp)
target_link_libraries(my_app PRIVATE nlohmann_json::nlohmann_json)
```

This fetches the `nlohmann/json` library and links it to `my_app`.

---

### Summary Table:
| Feature       | Purpose                                     | Key Point                           |
|---------------|---------------------------------------------|-------------------------------------|
| `function`    | Defines reusable logic in local scope       | Use for modular code blocks         |
| `include`     | Includes another CMake script               | Helps in splitting CMake logic      |
| `FetchContent`| Fetches external dependencies dynamically   | Simplifies dependency management    |
