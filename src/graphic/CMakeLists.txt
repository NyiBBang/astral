aux_source_directory(. SRC_LIST)
add_executable(graphic ${SRC_LIST})
include_directories(..)
target_link_libraries(graphic logic)

# SFML
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_LIST_DIR}/cmake_modules)
find_package(SFML 1.6 REQUIRED COMPONENTS graphics window system)
include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(graphic ${SFML_LIBRARIES})

# OpenGL
find_package(OpenGL REQUIRED)
add_definitions(${OPENGL_DEFINITIONS})
include_directories(${OPENGL_INCLUDE_DIRS})
target_link_libraries(graphic ${OPENGL_LIBRARIES})

# Installation
set_target_properties(graphic PROPERTIES RUNTIME_OUTPUT_NAME ${CMAKE_PROJECT_NAME})
install(TARGETS graphic DESTINATION ${ASTRAL_INSTALL_PATH}/bin)

