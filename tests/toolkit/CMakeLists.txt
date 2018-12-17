set(
  test_astral_toolkit_SOURCES
    test_expected.cpp
)

add_executable(
  astral_test_toolkit
    ${test_astral_toolkit_SOURCES}
)

add_test(
  NAME test_toolkit
  COMMAND astral_test_toolkit
)

target_link_libraries(
  astral_test_toolkit
    astral_toolkit
    gmock_main
)
