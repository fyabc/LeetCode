cmake_minimum_required(VERSION 3.13)

add_executable(Google_Tests_support_run
               testForwardList.cpp
               testCommon.cpp
               testGraph.cpp
               testUFSet.cpp
               testIO.cpp
               testString.cpp)
target_link_libraries(Google_Tests_support_run Leetcode_Support_ForwardList)
target_link_libraries(Google_Tests_support_run gtest gtest_main)
