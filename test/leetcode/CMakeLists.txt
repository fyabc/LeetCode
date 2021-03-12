cmake_minimum_required(VERSION 3.13)

add_executable(Google_Tests_leetcode_run_1to40
               testProblem1to20.cpp
               testProblem21to40.cpp)
add_executable(Google_Tests_leetcode_run_41to80
               testProblem41to60.cpp
               testProblem61to80.cpp)
target_link_libraries(Google_Tests_leetcode_run_1to40 gtest gtest_main)
target_link_libraries(Google_Tests_leetcode_run_41to80 gtest gtest_main)


add_executable(Google_Tests_leetcode_run_weeklyContest
               testWeeklyContest.cpp)
target_link_libraries(Google_Tests_leetcode_run_weeklyContest gtest gtest_main)
