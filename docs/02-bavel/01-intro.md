# Introduction to Bazel

## What is Bazel?

Bazel is an open-source build and test tool from Google, designed to handle large-scale projects efficiently. It supports multiple programming languages (e.g., Python, Java, C++, Go) and offers fast, reliable, and reproducible builds. Bazel excels in managing dependencies and parallelizing builds, making it a popular choice for complex, multi-language systems.

---

## Why Use Bazel?

1. **Speed**:
    - Bazel optimizes build times by caching outputs and reusing them when inputs haven’t changed.
    - It performs parallel builds, leveraging all available CPU cores.

2. **Reproducibility**:
    - Builds are deterministic; the same inputs always produce the same outputs, regardless of the environment.

3. **Language Agnostic**:
    - Supports multiple languages like C++, Java, Python, Go, and more within the same project.

4. **Scalability**:
    - Handles large, multi-language codebases with ease.

5. **Cross-Platform**:
    - Works seamlessly across Windows, macOS, and Linux.

6. **Dependency Management**:
    - Explicitly manages dependencies to ensure consistency and avoid unexpected conflicts.

---

## Basic Idea Behind Bazel

- **Declarative Build System**:
    - Bazel uses `BUILD` files to describe the components of your project and their dependencies.
    - You define what to build (targets), not how to build it.

- **Targets and Rules**:
    - **Targets**: Represent buildable outputs like binaries, libraries, or test executables.
    - **Rules**: Define how to build targets (e.g., `cc_binary` for C++ binaries, `py_library` for Python libraries).

- **WORKSPACE**:
    - The root configuration file, which defines external dependencies and the project’s workspace.

- **Caching**:
    - Bazel avoids rebuilding files if their inputs haven’t changed, ensuring faster incremental builds.

---

## Typical Workflow with Bazel

- **Set Up Workspace**:
    - Create a `WORKSPACE` file in the root of your project to define external dependencies and the workspace.

- **Write BUILD Files**:
    - Each directory in the project contains a `BUILD` file that specifies the targets and their dependencies.
    - Example of a `BUILD` file:
      ```python
      cc_binary(
          name = "hello_world",
          srcs = ["hello_world.cpp"],
          deps = ["@some_library"],
      )
      ```

- **Build Targets**:
    - Use the Bazel CLI to build a target:
       ```bash
       bazel build //path/to:target
       ```

- **Run Tests**:
    - Run tests defined in the `BUILD` file:
       ```bash
       bazel test //path/to:test_target
       ```

- **Run the Binary**:
    - Execute a binary you just built:
       ```bash
       bazel run //path/to:binary
       ```

- **Add External Dependencies**:
    - Use repository rules in the `WORKSPACE` file, like `http_archive`:
       ```python
       load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

       http_archive(
           name = "example_lib",
           urls = ["https://example.com/library.tar.gz"],
           strip_prefix = "library-1.0",
       )
       ```

---

## Summary

Bazel provides a robust, scalable, and efficient build system for projects of all sizes. By understanding its core concepts—`WORKSPACE`, `BUILD` files, rules, and targets—you can manage dependencies, optimize builds, and ensure consistency across platforms. The workflow revolves around defining dependencies explicitly and using the CLI for building, testing, and running targets.
