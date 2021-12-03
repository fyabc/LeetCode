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

TEST(Problem93Test, Basic) {
    set<string> s1 = {"255.255.11.135", "255.255.111.35"};
    auto r1 = Solution93::restoreIpAddresses("25525511135");
    set<string> rs1(r1.begin(), r1.end());
    EXPECT_EQ(s1, rs1);

    set<string> s2 = {"0.0.0.0"};
    auto r2 = Solution93::restoreIpAddresses("0000");
    set<string> rs2(r2.begin(), r2.end());
    EXPECT_EQ(s2, rs2);

    set<string> s3 = {"1.1.1.1"};
    auto r3 = Solution93::restoreIpAddresses("1111");
    set<string> rs3(r3.begin(), r3.end());
    EXPECT_EQ(s3, rs3);

    set<string> s4 = {"0.10.0.10", "0.100.1.0"};
    auto r4 = Solution93::restoreIpAddresses("010010");
    set<string> rs4(r4.begin(), r4.end());
    EXPECT_EQ(s4, rs4);

    set<string> s5 = {"1.0.10.23", "1.0.102.3", "10.1.0.23", "10.10.2.3", "101.0.2.3"};
    auto r5 = Solution93::restoreIpAddresses("101023");
    set<string> rs5(r5.begin(), r5.end());
    EXPECT_EQ(s5, rs5);
}

TEST(Problem94Test, Basic) {
    auto t1 = new TreeNode {1,
        nullptr,
        new TreeNode{2,
            new TreeNode {3},
            nullptr,
        }};
    vector<int> r1 {1, 3, 2};
    EXPECT_EQ(Solution94::inorderTraversal(t1), r1);

    vector<int> r2;
    EXPECT_EQ(Solution94::inorderTraversal(nullptr), r2);

    auto t3 = new TreeNode {1};
    vector<int> r3 {1};
    EXPECT_EQ(Solution94::inorderTraversal(t3), r3);

    auto t4 = new TreeNode {1,new TreeNode {2},nullptr};
    vector<int> r4 {2, 1};
    EXPECT_EQ(Solution94::inorderTraversal(t4), r4);

    auto t5 = new TreeNode {1, nullptr, new TreeNode {2}};
    vector<int> r5 {1, 2};
    EXPECT_EQ(Solution94::inorderTraversal(t5), r5);
}
