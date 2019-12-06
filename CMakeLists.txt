cmake_minimum_required(VERSION 3.13)

project(LeetCode)

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR})

add_subdirectory(support)
add_subdirectory(leetcode)
add_subdirectory(test)
