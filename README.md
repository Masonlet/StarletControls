# StarletControls
A lightweight input management library for Starlet projects with OpenGL engines in mind.

## Features
- Unified **InputManager** that handles keyboard and mouse inputs
- **KeyboardManager** for key states + key events
- **MouseManager** for cursor movement, scroll, and lock state

## Using as a Dependency
```cmake
include(FetchContent)

FetchContent_Declare(StarletControls GIT_REPOSITORY https://github.com/Masonlet/StarletControls.git GIT_TAG main)
FetchContent_MakeAvailable(StarletControls)

target_link_libraries(YourAppName PRIVATE StarletControls)
```
