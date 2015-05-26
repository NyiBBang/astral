set(gtest_force_shared_crt ON CACHE BOOL "Always use msvcrt.dll")

# GMock will automatically lookup for GTest in the folder that
# contains it, so we don't need to add gtest as a subdirectory.
add_subdirectory(gmock)

