//
// Created by fyabc on 2019/12/21.
//

#include "gtest/gtest.h"
#include "leetcode/problem81to90.cpp"
#include "leetcode/problem91to100.cpp"

using namespace std;

TEST(Problem81Test, Basic) {
    vector<int> v1 {2, 5, 6, 0, 0, 1, 2};
    EXPECT_EQ(Solution81::search(v1, 0), true);

    vector<int> v2 = v1;
    EXPECT_EQ(Solution81::search(v2, 3), false);

    vector<int> v3 {1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1};
    EXPECT_EQ(Solution81::search(v3, 2), true);
}

TEST(Problem82Test, Basic) {
    auto l1 = ListNode::fromInitList({1, 2, 3, 3, 4, 4, 5});
    vector<int> r1 {1, 2, 5};
    EXPECT_EQ(Solution82::deleteDuplicates(l1)->toVector(), r1);

    auto l2 = ListNode::fromInitList({1, 1, 1, 2, 3});
    vector<int> r2 {2, 3};
    EXPECT_EQ(Solution82::deleteDuplicates(l2)->toVector(), r2);
}

TEST(Problem83Test, Basic) {
    auto l1 = ListNode::fromInitList({1, 1, 2});
    vector<int> r1 {1, 2};
    EXPECT_EQ(Solution83::deleteDuplicates(l1)->toVector(), r1);

    auto l2 = ListNode::fromInitList({1, 1, 2, 3, 3});
    vector<int> r2 {1, 2, 3};
    EXPECT_EQ(Solution83::deleteDuplicates(l2)->toVector(), r2);
}

TEST(Problem84Test, Basic) {
    vector<int> v1 {2, 1, 5, 6, 2, 3};
    EXPECT_EQ(Solution84::largestRectangleArea(v1), 10);

    vector<int> v2 {2, 4};
    EXPECT_EQ(Solution84::largestRectangleArea(v2), 4);
}

TEST(Problem85Test, Basic) {
    vector<vector<char>> m1 {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    EXPECT_EQ(Solution85::maximalRectangle(m1), 6);

    vector<vector<char>> m2 {};
    EXPECT_EQ(Solution85::maximalRectangle(m2), 0);

    vector<vector<char>> m3 {{'0'}};
    EXPECT_EQ(Solution85::maximalRectangle(m3), 0);

    vector<vector<char>> m4 {{'1'}};
    EXPECT_EQ(Solution85::maximalRectangle(m4), 1);

    vector<vector<char>> m5 {{'0', '0'}};
    EXPECT_EQ(Solution85::maximalRectangle(m5), 0);
}

TEST(Problem86Test, Basic) {
    auto l1 = ListNode::fromInitList({1, 4, 3, 2, 5, 2});
    vector<int> r1 {1, 2, 2, 4, 3, 5};
    EXPECT_EQ(Solution86::partition(l1, 3)->toVector(), r1);

    auto l2 = ListNode::fromInitList({2, 1});
    vector<int> r2 {1, 2};
    EXPECT_EQ(Solution86::partition(l2, 2)->toVector(), r2);
}

TEST(Problem87Test, Basic) {
    EXPECT_EQ(Solution87::isScramble("great", "rgeat"), true);
    EXPECT_EQ(Solution87::isScramble("abcde", "caebd"), false);
    EXPECT_EQ(Solution87::isScramble("a", "a"), true);
    EXPECT_EQ(Solution87::isScramble("abc", "bca"), true);
    EXPECT_EQ(Solution87::isScramble("abcdefghijklmnopq", "efghijklmnopqcadb"), false);
}

TEST(Problem88Test, Basic) {
    vector<int> v1 = {1, 2, 3, 0, 0, 0}, v2 = {2, 5, 6};
    vector<int> r1 = {1, 2, 2, 3, 5, 6};
    Solution88::merge(v1, 3, v2, 3);
    EXPECT_EQ(v1, r1);

    vector<int> v3 = {1}, v4 = {};
    vector<int> r2 = {1};
    Solution88::merge(v3, 1, v4, 0);
    EXPECT_EQ(v3, r2);
}

TEST(Problem89Test, Basic) {
    vector<int> v1 = {0, 1, 3, 2};
    EXPECT_EQ(Solution89::grayCode(2), v1);

    vector<int> v2 = {0, 1};
    EXPECT_EQ(Solution89::grayCode(1), v2);
}

TEST(Problem90Test, Basic) {
    vector<int> v1 = {1, 2, 2};
    set<vector<int>> s1 = {{}, {1}, {1, 2}, {1, 2, 2}, {2}, {2, 2}};
    auto r1 = Solution90::subsetsWithDup(v1);
    set<vector<int>> rs1(r1.begin(), r1.end());
    EXPECT_EQ(s1, rs1);

    vector<int> v2 = {0};
    set<vector<int>> s2 = {{}, {0}};
    auto r2 = Solution90::subsetsWithDup(v2);
    set<vector<int>> rs2(r2.begin(), r2.end());
    EXPECT_EQ(s2, rs2);
}

TEST(Problem91Test, Basic) {
    EXPECT_EQ(Solution91::numDecodings("12"), 2);
    EXPECT_EQ(Solution91::numDecodings("226"), 3);
    EXPECT_EQ(Solution91::numDecodings("0"), 0);
    EXPECT_EQ(Solution91::numDecodings("06"), 0);
}

TEST(Problem92Test, Basic) {
    auto l1 = ListNode::fromInitList({1, 2, 3, 4, 5});
    vector<int> v1 {1, 4, 3, 2, 5};
    EXPECT_EQ(Solution92::reverseBetween(l1, 2, 4)->toVector(), v1);

    auto l2 = ListNode::fromInitList({5});
    vector<int> v2 {5};
    EXPECT_EQ(Solution92::reverseBetween(l2, 1, 1)->toVector(), v2);
}
