# Configuration

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# FetchContent
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

include(GoogleTest)

# Find source files
file(GLOB_RECURSE TEST_RUNTIME_SOURCES runtime/*.cxx runtime/**/*.cxx)
file(GLOB_RECURSE TEST_LIB_SOURCES lib/*.cxx lib/**/*.cxx)
file(GLOB_RECURSE TEST_CORE_SOURCES core/*.cxx core/**/*.cxx)

# Add tests
function(add_test_exe name)
    add_executable(${name} ${ARGN})
    target_link_libraries(${name} PRIVATE dywoqcxx GTest::gtest GTest::gtest_main)
    gtest_discover_tests(${name})
endfunction()

add_test_exe(tests_runtime ${TEST_RUNTIME_SOURCES})
add_test_exe(tests_lib ${TEST_LIB_SOURCES})
add_test_exe(tests_core ${TEST_CORE_SOURCES})

