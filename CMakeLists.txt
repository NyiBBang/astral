cmake_minimum_required(VERSION 2.8.11)

# Project declaration
project(astral)
set(${PROJECT_NAME}_MAJOR_VERSION 0)
set(${PROJECT_NAME}_MINOR_VERSION 0)
set(${PROJECT_NAME}_PATCH_VERSION 0)

# By default, we compile in debug
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type for the project" FORCE)
endif()

# Using C++11
include(CheckCXXCompilerFlag)
check_cxx_compiler_flag(-std=c++11 COMPILER_SUPPORTS_CXX11)
check_cxx_compiler_flag(-std=c++0x COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    add_definitions(-std=c++11)
elseif(COMPILER_SUPPORTS_CXX0X)
    add_definitions(-std=c++0x)
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

# Install path is inside a directory named as the project
set(ASTRAL_INSTALL_PATH ${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME})

include_directories(${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR}/src)

# Testing
enable_testing()

add_subdirectory(third-party)
add_subdirectory(src)

