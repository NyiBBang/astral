cmake_minimum_required(VERSION 3.11)

# Project declaration
project(astral)
set(${PROJECT_NAME}_MAJOR_VERSION 0)
set(${PROJECT_NAME}_MINOR_VERSION 0)
set(${PROJECT_NAME}_PATCH_VERSION 0)

# Default build type is debug
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type for the project" FORCE)
endif()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Modules and packages
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake/Modules")
enable_testing()

# Install path is inside a directory named after the project
set(ASTRAL_INSTALL_PATH ${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME})

include_directories(${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR}/src)

add_subdirectory(third-party)
add_subdirectory(src)

