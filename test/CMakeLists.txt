include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(unit_tests 
  helper/test_helper.hpp
  helper/test_helper.cpp
  test.cpp 
  logger_test.cpp 
  config_test.cpp)

# include directories
target_include_directories(unit_tests PUBLIC 
  ${CMAKE_CURRENT_SOURCE_DIR}/helper
  ${CMAKE_CURRENT_SOURCE_DIR}/../src/core/base//logger
  ${CMAKE_CURRENT_SOURCE_DIR}/../src/core/base/config)

# add link library
target_link_libraries(unit_tests gtest_main logger config)

# add test
add_test(NAME unit_tests COMMAND unit_tests)