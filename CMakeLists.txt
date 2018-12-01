cmake_minimum_required(VERSION 3.11)

# Project declaration
project(astral)
set(${PROJECT_NAME}_MAJOR_VERSION 0)
set(${PROJECT_NAME}_MINOR_VERSION 0)
set(${PROJECT_NAME}_PATCH_VERSION 0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(BUILD_SHARED_LIBS "" FALSE)

# Modules and packages
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake/Modules")

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME ON)
find_package(
	Boost 1.67
	REQUIRED
)


# Install path is inside a directory named after the project
set(ASTRAL_INSTALL_PATH ${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME})

include_directories(${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR}/src)

enable_testing()
add_subdirectory(third-party)
add_subdirectory(src)

