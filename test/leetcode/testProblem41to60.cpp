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

TEST(Problem42Test, Basic) {
    Solution42 s;

    vector<int> v1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    EXPECT_EQ(s.trap(v1), 6);

    vector<int> v2 = {};
    EXPECT_EQ(s.trap(v2), 0);

    vector<int> v3 = {5};
    EXPECT_EQ(s.trap(v3), 0);
}

TEST(Problem43Test, Basic) {
    Solution43 s;

    EXPECT_EQ(s.multiply("2", "3"), "6");
    EXPECT_EQ(s.multiply("123", "456"), "56088");
    EXPECT_EQ(s.multiply("123", "0"), "0");
    EXPECT_EQ(s.multiply("123", "1"), "123");
}

TEST(Problem44Test, Basic) {
    Solution44 s;

    EXPECT_FALSE(s.isMatch("aa", "a"));
    EXPECT_TRUE(s.isMatch("aa", "*"));
    EXPECT_FALSE(s.isMatch("cb", "?a"));
    EXPECT_TRUE(s.isMatch("acdeb", "*a*b"));
    EXPECT_FALSE(s.isMatch("acdcb", "a*c?b"));
}
