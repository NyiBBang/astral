set(
  test_astral_engine_SOURCES
    test_engine.cpp
)

add_executable(
  astral_test_engine
    ${test_astral_engine_SOURCES}
)

add_test(
  NAME test_engine
  COMMAND astral_test_engine
)

target_link_libraries(
  astral_test_engine
    astral_engine
    gmock_main
)
