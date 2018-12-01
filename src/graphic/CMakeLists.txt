set(graphic_SOURCES
    IDrawable.h
    CrossDrawable.cpp CrossDrawable.h
    Drawer.cpp Drawer.h
    WindowDisplay.cpp WindowDisplay.h
    main.cpp
)
add_executable(graphic ${graphic_SOURCES})
target_link_libraries(graphic logic)

# SFML
find_package(SFML 2.5 REQUIRED COMPONENTS graphics window system)
target_include_directories(graphic PRIVATE ${SFML_INCLUDE_DIR})
target_link_libraries(graphic ${SFML_LIBRARIES})

# OpenGL
find_package(OpenGL REQUIRED)
add_definitions(${OPENGL_DEFINITIONS})
target_include_directories(graphic PRIVATE ${OPENGL_INCLUDE_DIRS})
target_link_libraries(graphic ${OPENGL_LIBRARIES})

# Installation
set_target_properties(graphic PROPERTIES RUNTIME_OUTPUT_NAME ${CMAKE_PROJECT_NAME})
install(TARGETS graphic DESTINATION ${ASTRAL_INSTALL_PATH}/bin)

