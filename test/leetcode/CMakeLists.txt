cmake_minimum_required(VERSION 3.13)

add_executable(Google_Tests_leetcode_run_1to40
               testProblem1to20.cpp
               testProblem21to40.cpp)
add_executable(Google_Tests_leetcode_run_41to80
               testProblem41to60.cpp
               testProblem61to80.cpp)
add_executable(Google_Tests_leetcode_run_81to120
               testProblem81to100.cpp
               testProblem101to120.cpp)
target_link_libraries(Google_Tests_leetcode_run_1to40 gtest gtest_main)
target_link_libraries(Google_Tests_leetcode_run_41to80 gtest gtest_main)
target_link_libraries(Google_Tests_leetcode_run_81to120 gtest gtest_main Leetcode_Support_ForwardList)


add_executable(Google_Tests_leetcode_run_weeklyContest
               weeklyContest/testWC221to240.cpp)
target_link_libraries(Google_Tests_leetcode_run_weeklyContest gtest gtest_main)
