set(gui_SOURCES
  common_main.hpp common_main.cpp
)
if (WIN32)
  list(APPEND gui_SOURCES main_win32.cpp)
else()
  list(APPEND gui_SOURCES main.cpp)
endif()

add_executable(
  astral_gui WIN32
  ${gui_SOURCES}
)

set_target_properties(
  astral_gui
  PROPERTIES
    RUNTIME_OUTPUT_NAME astral
    DEBUG_POSTFIX _d
)

target_link_libraries(
  astral_gui
  PUBLIC
    sfml-graphics
    sfml-window
)

if(WIN32 AND NOT SFML_STATIC_LIBRARIES)
  add_custom_command(
    TARGET astral_gui POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      $<TARGET_FILE:sfml-graphics>
      $<TARGET_FILE:sfml-system>
      $<TARGET_FILE:sfml-window>
      $<TARGET_FILE_DIR:astral_gui>
  )
endif()
