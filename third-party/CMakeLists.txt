if(ASTRAL_BUILD_TESTS)
  set(gtest_force_shared_crt ON CACHE BOOL "Always use msvcrt.dll")
  add_subdirectory(googletest)
endif()
