cmake_minimum_required(VERSION 3.13)

add_executable(Google_Tests_support_run
               testCommon.cpp
               testUFSet.cpp
               testIO.cpp)
target_link_libraries(Google_Tests_support_run gtest gtest_main)
