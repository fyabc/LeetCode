cmake_minimum_required(VERSION 3.13)

add_executable(Google_Tests_leetcode_run
               testProblem1to20.cpp
               testProblem20to40.cpp)
target_link_libraries(Google_Tests_leetcode_run gtest gtest_main)
