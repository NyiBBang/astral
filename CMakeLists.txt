cmake_minimum_required(VERSION 3.14)

# Project declaration
project(astral)
set(${PROJECT_NAME}_MAJOR_VERSION 0)
set(${PROJECT_NAME}_MINOR_VERSION 0)
set(${PROJECT_NAME}_PATCH_VERSION 0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(ASTRAL_BUILD_TESTS "Build astral tests" TRUE)
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

find_package(
	SFML 2.5.1
	REQUIRED
	COMPONENTS
		window
		graphics
)

include_directories(${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR}/src)

add_subdirectory(third-party)
add_subdirectory(src)

if(ASTRAL_BUILD_TESTS)
	enable_testing()
	add_subdirectory(tests)
endif()
