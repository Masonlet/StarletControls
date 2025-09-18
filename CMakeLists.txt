cmake_minimum_required(VERSION 3.23)

set(CONTROL_NAME StarletControls)
set(CONTROL_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(CONTROL_INC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/inc")

project(${CONTROL_NAME} LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_SUPPRESS_REGENERATION ON)

add_library(${CONTROL_NAME} STATIC)

file(GLOB_RECURSE CONTROLS_SRC CONFIGURE_DEPENDS ${CONTROL_SRC_DIR}/*.cpp)
file(GLOB_RECURSE CONTROLS_HEADERS CONFIGURE_DEPENDS ${CONTROL_INC_DIR}/StarletControls/*.hpp)

source_group(TREE ${CONTROL_SRC_DIR} PREFIX "Source Files" FILES ${CONTROLS_SRC})
source_group(TREE ${CONTROL_INC_DIR} PREFIX "Header Files" FILES ${CONTROLS_HEADERS})

target_sources(${CONTROL_NAME} PUBLIC ${CONTROLS_HEADERS} PRIVATE ${CONTROLS_SRC})
target_include_directories(${CONTROL_NAME} PUBLIC $<BUILD_INTERFACE:${CONTROL_INC_DIR}> $<INSTALL_INTERFACE:include>)

include(FetchContent)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_Declare(glfw GIT_REPOSITORY https://github.com/glfw/glfw.git GIT_TAG 3.4)
FetchContent_MakeAvailable(glfw)

FetchContent_Declare(StarletScene GIT_REPOSITORY https://github.com/masonlet/starletscene.git GIT_TAG main)
FetchContent_Declare(StarletMath GIT_REPOSITORY https://github.com/masonlet/starletmath.git GIT_TAG main)
FetchContent_MakeAvailable(StarletMath StarletScene)

target_link_libraries(${CONTROL_NAME} PUBLIC glfw StarletScene StarletMath)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "External")
