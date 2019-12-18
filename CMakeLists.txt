cmake_minimum_required(VERSION 3.13)

project(LeetCode)

set(CMAKE_CXX_STANDARD 17)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # Disable the warning about "[[nodiscard]]".
    # TODO: Do this in more elegant way.
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-attributes")
endif()

include_directories(${PROJECT_SOURCE_DIR})

add_subdirectory(support)
add_subdirectory(leetcode)
add_subdirectory(test)
