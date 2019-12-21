//
// Created by fyabc on 2019/12/21.
//

#include "gtest/gtest.h"
#include "leetcode/problem41to50.cpp"
#include "leetcode/problem51to60.cpp"

using namespace std;

TEST(Problem41Test, Basic) {
    Solution41 s;

    vector<int> v1 = {1, 2, 0};
    EXPECT_EQ(s.firstMissingPositive(v1), 3);

    vector<int> v2 = {3, 4, -1, 1};
    EXPECT_EQ(s.firstMissingPositive(v2), 2);

    vector<int> v3 = {7, 8, 9, 11, 12};
    EXPECT_EQ(s.firstMissingPositive(v3), 1);

    vector<int> v4 = {1, 3, 5, 4, 2};
    EXPECT_EQ(s.firstMissingPositive(v4), 6);
}
