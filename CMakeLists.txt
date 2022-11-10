cmake_minimum_required(VERSION 3.13)

project(LeetCode)

set(CMAKE_CXX_STANDARD 17)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    # /MDd: To avoid the linking error
    add_compile_options("/MDd" "/std:c++17")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_compile_options("-std=c++17")
endif ()

include_directories(${PROJECT_SOURCE_DIR})

add_subdirectory(support)
add_subdirectory(leetcode)
add_subdirectory(test)
