aux_source_directory(. SRC_LIST)
add_executable(astral ${SRC_LIST})
include_directories(..)
target_link_libraries(astral logic)
target_link_libraries(astral sfml-graphics)
target_link_libraries(astral sfml-window)
target_link_libraries(astral sfml-system)
target_link_libraries(astral GL)

install(TARGETS astral DESTINATION ${ASTRAL_INSTALL_PATH})

