## ONX

**ONX** is a handy framework for quickly setting up Vulkan-based projects. It's implemented in C, with plans for a Rust FFI later on. This library helps streamline the boring parts like initialization and management, so you can jump straight into development.

## Memory Leak Check

To check for memory leaks in your application, use **Valgrind**:

```bash
valgrind --leak-check=full ./onx_thr
```
This helps keep your memory clean and efficient.

## Building ONX

### Standalone Build

If you want to build **ONX** by itself, follow these steps:

1. **Configure the Build**:
   ```bash
   cmake -S . -B _build
   ```
   This sets everything up for the build.

2. **Compile the Project**:
   ```bash
   cmake --build _build
   ```

### Include as a Subdirectory

To include **ONX** in another CMake project:

1. **Add to CMakeLists.txt** of your main project:
   ```cmake
   add_subdirectory(path/to/onx)
   ```
   Replace `path/to/onx` with the actual path to the **ONX** directory.

2. **Link to Your Target**: In your project's CMakeLists.txt, you can link against the **ONX** library with the following command:
   ```cmake
   target_link_libraries(your_project ONX::ONX)
   ```
   Replace `your_project` with the actual name of your target.

And that’s it! You're ready to start your projects with **ONX**, making your life a bit easier.