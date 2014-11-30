# Add the executable
aux_source_directory(. SRC_LIST)
add_executable(logic_test ${SRC_LIST})
include_directories(..)
target_link_libraries(logic_test logic)

# Linked to BOOST
find_package(Boost REQUIRED COMPONENTS unit_test_framework)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(logic_test ${Boost_LIBRARIES})

add_test(NAME logic_test COMMAND logic_test)

