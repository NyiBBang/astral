set(
  astral_tookit_SOURCES
  expected.hpp
  non_copyable.hpp
)

add_library(
  astral_toolkit
  INTERFACE
)

target_sources(
  astral_toolkit INTERFACE
  ${astral_toolkit_SOURCES}
)

target_include_directories(
  astral_toolkit
  INTERFACE
    ${PROJECT_SOURCE_DIR}/src
    ${Boost_INCLUDE_DIR}
)

target_compile_features(
  astral_toolkit
  INTERFACE
    cxx_std_17
)