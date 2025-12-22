cmake_minimum_required(VERSION 3.28.3)
project(dywoqstl_runtime)

# ================================
#         Configuration
# ================================

include(FetchContent)

FetchContent_Declare(
    dywoqtest
    GIT_REPOSITORY https://github.com/dywoq/test.git
    GIT_TAG v1.1.1
)

FetchContent_MakeAvailable(dywoqtest)

file(GLOB_RECURSE SOURCES src/*.cxx src/**/*.cxx)

# ================================
#           Building
# ================================

# dywoqstl_runtime
add_library(${PROJECT_NAME} STATIC ${SOURCES})
target_compile_options(${PROJECT_NAME} PRIVATE -fno-exceptions -fno-rtti)
target_link_options(${PROJECT_NAME} PRIVATE -nostdlib++)

# Tests executable
add_executable(${PROJECT_NAME}_tests tests/main.cxx)
target_include_directories(${PROJECT_NAME}_tests
    INTERFACE
        ${dywoqtest_SOURCE_DIR}/include
)
