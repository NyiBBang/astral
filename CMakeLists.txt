cmake_minimum_required(VERSION 2.8)

project(astral)

# Add C++11 support
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

set(ASTRAL_INSTALL_PATH ${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME})

# RPATH handling
SET(CMAKE_INSTALL_RPATH ${ASTRAL_INSTALL_PATH} "/usr/local/bin" "/usr/lib" "/usr/lib64")

add_subdirectory(src)

