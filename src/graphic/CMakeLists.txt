set(graphic_SOURCES
    IDrawable.h
    CrossDrawable.cpp CrossDrawable.h
    Drawer.cpp Drawer.h
    WindowDisplay.cpp WindowDisplay.h
    entrypoint.cpp entrypoint.h
)
if (WIN32)
  list(APPEND graphic_SOURCES main_win32.cpp)
else()
  list(APPEND graphic_SOURCES main.cpp)
endif()

add_executable(graphic WIN32 ${graphic_SOURCES})
target_link_libraries(graphic logic)

# SFML
find_package(SFML 2.5 REQUIRED COMPONENTS graphics window system)
target_include_directories(graphic PRIVATE ${SFML_INCLUDE_DIR})
target_link_libraries(graphic ${SFML_LIBRARIES})
if (WIN32)
  add_custom_command(
    TARGET graphic
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
      "${SFML_DIR}/bin"
      $<TARGET_FILE_DIR:graphic>
  )
endif()

# OpenGL
find_package(OpenGL REQUIRED)
add_definitions(${OPENGL_DEFINITIONS})
target_include_directories(graphic PRIVATE ${OPENGL_INCLUDE_DIRS})
target_link_libraries(graphic ${OPENGL_LIBRARIES})

# Installation
set_target_properties(graphic PROPERTIES RUNTIME_OUTPUT_NAME ${CMAKE_PROJECT_NAME})
install(TARGETS graphic DESTINATION ${ASTRAL_INSTALL_PATH}/bin)

