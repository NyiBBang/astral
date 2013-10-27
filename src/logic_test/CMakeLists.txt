aux_source_directory(. SRC_LIST)
add_executable(logic_test ${SRC_LIST})
include_directories(..)
target_link_libraries(logic_test logic)
target_link_libraries(logic_test boost_unit_test_framework)

