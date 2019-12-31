//
// Created by fyabc on 2019/12/21.
//

#include "gtest/gtest.h"
#include "leetcode/problem61to70.cpp"
#include "leetcode/problem71to80.cpp"

using namespace std;

TEST(Problem61Test, Basic) {
    Solution61 s;

    auto v1 = ListNode::fromInitList({1, 2, 3, 4, 5});
    auto r1 = ListNode::fromInitList({4, 5, 1, 2, 3});
    EXPECT_EQ(s.rotateRight(v1, 2)->toVector(), r1->toVector());

    auto v2 = ListNode::fromInitList({0, 1, 2});
    auto r2 = ListNode::fromInitList({2, 0, 1});
    EXPECT_EQ(s.rotateRight(v2, 4)->toVector(), r2->toVector());

    auto v3 = ListNode::fromInitList({1, 2, 3, 4, 5});
    auto r3 = ListNode::fromInitList({1, 2, 3, 4, 5});
    EXPECT_EQ(s.rotateRight(v3, 0)->toVector(), r3->toVector());
    EXPECT_EQ(s.rotateRight(v3, 5)->toVector(), r3->toVector());

    auto v4 = ListNode::fromInitList({1, 2});
    auto r4 = ListNode::fromInitList({2, 1});
    EXPECT_EQ(s.rotateRight(v4, 1)->toVector(), r4->toVector());
}

TEST(Problem62Test, Basic) {
    Solution62 s;

    EXPECT_EQ(s.uniquePaths(3, 2), 3);
    EXPECT_EQ(s.uniquePaths(7, 3), 28);
    EXPECT_EQ(s.uniquePaths(10, 10), 48620);
    EXPECT_EQ(s.uniquePaths(51, 9), 1916797311);
}

TEST(Problem63Test, Basic) {
    Solution63 s;

    vector<vector<int>> v1 = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    EXPECT_EQ(s.uniquePathsWithObstacles(v1), 2);

    vector<vector<int>> v2 = {{0, 0}};
    EXPECT_EQ(s.uniquePathsWithObstacles(v2), 1);
}

TEST(Problem64Test, Basic) {
    Solution64 s;

    vector<vector<int>> v1 = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    EXPECT_EQ(s.minPathSum(v1), 7);
}

TEST(Problem65Test, Basic) {
    Solution65 s;

    EXPECT_EQ(s.isNumber("0"), true);
    EXPECT_EQ(s.isNumber("0.1"), true);
    EXPECT_EQ(s.isNumber("abc"), false);
    EXPECT_EQ(s.isNumber("1 a"), false);
    EXPECT_EQ(s.isNumber("2e10"), true);
    EXPECT_EQ(s.isNumber(" -90e3   "), true);
    EXPECT_EQ(s.isNumber("e3"), false);
    EXPECT_EQ(s.isNumber("6e-1"), true);
    EXPECT_EQ(s.isNumber(" 99e2.5"), false);
    EXPECT_EQ(s.isNumber("53.5e93"), true);
    EXPECT_EQ(s.isNumber(" --6"), false);
    EXPECT_EQ(s.isNumber("-+3"), false);
    EXPECT_EQ(s.isNumber("95a54e53"), false);
    EXPECT_EQ(s.isNumber("3."), true);
}

TEST(Problem66Test, Basic) {
    Solution66 s;

    vector<int> v1 = {1, 2, 3};
    vector<int> r1 = {1, 2, 4};
    EXPECT_EQ(s.plusOne(v1), r1);

    vector<int> v2 = {4, 3, 2, 1};
    vector<int> r2 = {4, 3, 2, 2};
    EXPECT_EQ(s.plusOne(v2), r2);

    vector<int> v3 = {1, 9, 9, 9};
    vector<int> r3 = {2, 0, 0, 0};
    EXPECT_EQ(s.plusOne(v3), r3);

    vector<int> v4 = {0};
    vector<int> r4 = {1};
    EXPECT_EQ(s.plusOne(v4), r4);

    vector<int> v5 = {9, 9};
    vector<int> r5 = {1, 0, 0};
    EXPECT_EQ(s.plusOne(v5), r5);
}

TEST(Problem67Test, Basic) {
    Solution67 s;

    EXPECT_EQ(s.addBinary("11", "1"), "100");
    EXPECT_EQ(s.addBinary("0", "0"), "0");
    EXPECT_EQ(s.addBinary("1010", "1011"), "10101");
    EXPECT_EQ(s.addBinary("1111", "1111"), "11110");
}

TEST(Problem68Test, Basic) {
    Solution68 s;

    vector<string> v1 = {"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> r1 = {"This    is    an", "example  of text", "justification.  "};
    EXPECT_EQ(s.fullJustify(v1, 16), r1);

    vector<string> v2 = {"What","must","be","acknowledgment","shall","be"};
    vector<string> r2 = {"What   must   be", "acknowledgment  ", "shall be        "};
    EXPECT_EQ(s.fullJustify(v2, 16), r2);

    vector<string> v3 = {"Science", "is", "what", "we", "understand", "well", "enough", "to", "explain",
                         "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"};
    vector<string> r3 = {"Science  is  what we", "understand      well", "enough to explain to",
                         "a  computer.  Art is", "everything  else  we", "do                  "};
    EXPECT_EQ(s.fullJustify(v3, 20), r3);
}
