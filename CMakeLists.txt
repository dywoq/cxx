cmake_minimum_required(VERSION 3.28.3)
project(dywoqcxx LANGUAGES CXX)

# Configuration

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Base
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
file(GLOB_RECURSE CORE_SOURCES src/core/**/*.cxx src/core/*.cxx)
file(GLOB_RECURSE RUNTIME_SOURCES src/runtime/**/*.cxx src/runtime/*.cxx)
file(GLOB_RECURSE LIB_SOURCES src/lib/**/*.cxx src/lib/*.cxx)

# Building

# Binary
add_library(${PROJECT_NAME} STATIC ${CORE_SOURCES} ${RUNTIME_SOURCES} ${LIB_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include/)
target_compile_options(${PROJECT_NAME} PRIVATE -fno-exceptions -fno-rtti)
