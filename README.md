# StarletControls
A lightweight input &amp; control management library for Starlet projects with OpenGL engines in mind.

## Features
- Keyboard, mouse, and scroll handling via **InputManager**
- Extendable controller abstraction: `Controller<T>`
- Drop-in controllers:
    - `FreeCameraController` for free-moving cameras
    - `ModelController` for interactive transform + scale + rotation

## Building the Project
This project uses **CMake**. Follow these steps to build:

### Standalone

#### 1. Clone the Repository
```bash
git clone https://github.com/Masonlet/StarletControls.git
cd StarletControls
```

#### 2. Create a build Directory and Generate Build Files
```bash
mkdir build
cd build
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..
```
`-DCMAKE_EXPORT_COMPILE_COMMANDS=ON` flag generates a `compile_commands.json` file  
Can be safely omitted on Windows if you're using Visual Studio

#### 3. Build the Project
- **Linux**:
  ```bash
  make
  ```

- **Windows**:
  ```bash
  cmake --build .
  ```
  Or open the generated `.sln` file in Visual Studio and build the solution.

### As a Dependency

```cmake
include(FetchContent)

FetchContent_Declare(StarletControls GIT_REPOSITORY https://github.com/Masonlet/StarletControls.git GIT_TAG main)
FetchContent_MakeAvailable(StarletControls)

target_link_libraries(YourAppName PRIVATE StarletControls)
```

