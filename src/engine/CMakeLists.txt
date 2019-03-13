set(
  astral_engine_SOURCES
  engine.hpp engine.cpp
)

add_library(
  astral_engine
  ${astral_engine_SOURCES}
)

target_include_directories(
  astral_engine
  PUBLIC
    ${PROJECT_SOURCE_DIR}/src
    ${Boost_INCLUDE_DIR}
)

target_link_libraries(
  astral_engine
  PUBLIC
    astral_toolkit
)
