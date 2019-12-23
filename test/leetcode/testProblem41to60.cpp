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
    EXPECT_TRUE(s.isMatch("a", "a*"));
}

TEST(Problem45Test, Basic) {
    Solution45 s;

    vector<int> v1 = {2, 3, 1, 1, 4};
    EXPECT_EQ(s.jump(v1), 2);

    vector<int> v2 = {2, 3, 0, 1, 4};
    EXPECT_EQ(s.jump(v2), 2);
}

TEST(Problem46Test, Basic) {
    Solution46 s;

    vector<int> v1 = {1, 2, 3};
    vector<vector<int>> r1 = {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
    EXPECT_EQ(s.permute(v1), r1);
}

TEST(Problem47Test, Basic) {
    Solution47 s;

    vector<int> v1 = {1, 1, 2};
    vector<vector<int>> r1 = {{1, 1, 2}, {1, 2, 1}, {2, 1, 1}};
    EXPECT_EQ(s.permuteUnique(v1), r1);
}

TEST(Problem48Test, Basic) {
    vector<vector<int>> v1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> r1 = {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}};
    Solution48::rotate(v1);
    EXPECT_EQ(v1, r1);

    vector<vector<int>> v2 = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    vector<vector<int>> r2 = {{15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}};
    Solution48::rotate(v2);
    EXPECT_EQ(v2, r2);

    vector<vector<int>> v3 = {};
    vector<vector<int>> r3 = {};
    Solution48::rotate(v3);
    EXPECT_EQ(v3, r3);

    vector<vector<int>> v4 = {{1}};
    vector<vector<int>> r4 = {{1}};
    Solution48::rotate(v4);
    EXPECT_EQ(v4, r4);
}

TEST(Problem49Test, Basic) {
    vector<string> v1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    set<set<string>> r1 = {{"ate", "eat", "tea"}, {"nat", "tan"}, {"bat"}};

    auto out1 = Solution49::groupAnagrams(v1);
    set<set<string>> outSet1;
    for (const auto& strVec: out1) {
        outSet1.insert(set<string> {strVec.begin(), strVec.end()});
    }
    EXPECT_EQ(outSet1, r1);
}

TEST(Problem50Test, Basic) {
    Solution50 s;

    EXPECT_NEAR(s.myPow(2.00000, 10), 1024.00000, 1e-5);
    EXPECT_NEAR(s.myPow(2.10000, 3), 9.26100, 1e-5);
    EXPECT_NEAR(s.myPow(2.00000, -2), 0.25000, 1e-5);
    EXPECT_NEAR(s.myPow(1.00012, 1024), 1.13074, 1e-5);
}

TEST(Problem51Test, Basic) {
    Solution51 s;

    vector<vector<string>> r1 = {
        {".Q..", "...Q", "Q...", "..Q."},
        {"..Q.", "Q...", "...Q", ".Q.."},
    };
    EXPECT_EQ(s.solveNQueens(4), r1);
}

TEST(Problem52Test, Basic) {
    Solution52 s;

    EXPECT_EQ(s.totalNQueens(4), 2);
}

TEST(Problem53Test, Basic) {
    Solution53 s;

    vector<int> v1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    EXPECT_EQ(s.maxSubArray(v1), 6);
}
