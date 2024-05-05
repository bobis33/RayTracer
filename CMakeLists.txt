cmake_minimum_required(VERSION 3.27)

set(CMAKE_BUILD_TYPE Release)

option(USE_CLANG_TIDY "Use Clang-tidy" OFF)

project(raytracer
        DESCRIPTION "EPITECH | B-OOP-400 | RayTracer"
        LANGUAGES CXX
        VERSION 0.1.0
)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)

include(${CMAKE_MODULE_PATH}/myVariables.cmake)

# Build Doxygen documentation
include(${CMAKE_MODULE_PATH}/MakeDoc.cmake)

# Clang format
if (USE_CLANG_TIDY)
    include(${CMAKE_MODULE_PATH}/ClangTidy.cmake)
endif()

# Local plugins
add_subdirectory(App/plugins)

# Static library
add_subdirectory(lib)

# Main executable
add_executable(${PROJECT_NAME} ${SOURCES})

target_sources(${PROJECT_NAME} PRIVATE
        ${SRC_DIR}/main.cpp
        ${SRC_DIR}/core.cpp
        ${SRC_DIR}/Loader/plugin.cpp
        ${SRC_DIR}/Parser/utils.cpp
        ${SRC_DIR}/Parser/parser.cpp
        ${SRC_DIR}/Parser/camera.cpp
        ${SRC_DIR}/Parser/light.cpp
        ${SRC_DIR}/Parser/renderer.cpp
        ${SRC_DIR}/Parser/shape.cpp
        ${SRC_DIR}/Factory/light.cpp
        ${SRC_DIR}/Factory/material.cpp
        ${SRC_DIR}/Factory/renderer.cpp
        ${SRC_DIR}/Factory/shape.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE my_lib config++)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
target_compile_options(${PROJECT_NAME} PRIVATE ${WARNING_FLAGS})
set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE ON)
