# Configuration

# FetchContent
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

include(GoogleTest)

# Runtime
file(GLOB_RECURSE TEST_RUNTIME_SOURCES runtime/*.cxx runtime/**/*.cxx)
add_executable(tests_runtime ${TEST_RUNTIME_SOURCES})
target_link_libraries(tests_runtime PRIVATE GTest::gtest GTest::gtest_main)
add_test(NAME TESTS_RUNTIME COMMAND tests_runtime)
gtest_discover_tests(tests_runtime)

# Lib
file(GLOB_RECURSE TEST_LIB_SOURCES lib/*.cxx lib/**/*.cxx)
add_executable(tests_lib ${TEST_LIB_SOURCES})
target_link_libraries(tests_lib PRIVATE GTest::gtest GTest::gtest_main)
add_test(NAME TESTS_LIB COMMAND tests_lib)
gtest_discover_tests(tests_lib)

# Core
file(GLOB_RECURSE TEST_CORE_SOURCES core/*.cxx core/**/*.cxx)
add_executable(tests_core ${TEST_CORE_SOURCES})
target_link_libraries(tests_core PRIVATE GTest::gtest GTest::gtest_main)
add_test(NAME TESTS_CORE COMMAND tests_core)
gtest_discover_tests(tests_core)
