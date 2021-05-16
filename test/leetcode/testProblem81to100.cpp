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
