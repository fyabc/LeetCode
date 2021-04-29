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

TEST(Problem69Test, Basic) {
    Solution69 s;

    EXPECT_EQ(s.mySqrt(4), 2);
    EXPECT_EQ(s.mySqrt(8), 2);
    EXPECT_EQ(s.mySqrt(0), 0);
    EXPECT_EQ(s.mySqrt(1), 1);
}

TEST(Problem70Test, Basic) {
    Solution70 s;

    EXPECT_EQ(s.climbStairs(2), 2);
    EXPECT_EQ(s.climbStairs(3), 3);
}

TEST(Problem71Test, Basic) {
    Solution71 s;

    EXPECT_EQ(s.simplifyPath("/home/"), "/home");
    EXPECT_EQ(s.simplifyPath("/../"), "/");
    EXPECT_EQ(s.simplifyPath("/home//foo/"), "/home/foo");
    EXPECT_EQ(s.simplifyPath("/a/./b/../../c/"), "/c");
}

TEST(Problem72Test, Basic) {
    Solution72 s;

    EXPECT_EQ(s.minDistance("horse", "ros"), 3);
    EXPECT_EQ(s.minDistance("intention", "execution"), 5);
    EXPECT_EQ(s.minDistance("b", ""), 1);
}

TEST(Problem73Test, Basic) {
    using S73 = Solution73;

    vector<vector<int>> m1 = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    vector<vector<int>> m1a = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};

    S73::setZeroes(m1);
    EXPECT_EQ(m1, m1a);

    vector<vector<int>> m2 = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    vector<vector<int>> m2a = {{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}};
}

TEST(Problem74Test, Basic) {
    vector<vector<int>> m1 = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    EXPECT_EQ(Solution74::searchMatrix(m1, 3), true);

    vector<vector<int>> m2 = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    EXPECT_EQ(Solution74::searchMatrix(m2, 13), false);
}

TEST(Problem75Test, Basic) {
    vector<int> v1 = {2, 0, 2, 1, 1, 0};
    vector<int> r1 = {0, 0, 1, 1, 2, 2};

    Solution75::sortColors(v1);
    EXPECT_EQ(v1, r1);

    vector<int> v2 = {2, 0, 1};
    vector<int> r2 = {0, 1, 2};

    Solution75::sortColors(v2);
    EXPECT_EQ(v2, r2);

    vector<int> v3 = {0};
    vector<int> r3 = {0};

    Solution75::sortColors(v3);
    EXPECT_EQ(v3, r3);

    vector<int> v4 = {1};
    vector<int> r4 = {1};

    Solution75::sortColors(v4);
    EXPECT_EQ(v4, r4);
}

TEST(Problem76Test, Basic) {
    EXPECT_EQ(Solution76::minWindow("ADOBECODEBANC", "ABC"), "BANC");
    EXPECT_EQ(Solution76::minWindow("a", "a"), "a");
}

TEST(Problem77Test, Basic) {
    set<vector<int>> s1 {{2, 4}, {3, 4}, {2, 3}, {1, 2}, {1, 3}, {1, 4}};
    auto r1 = Solution77::combine(4, 2);
    EXPECT_EQ(set<vector<int>>(r1.begin(), r1.end()), s1);

    vector<vector<int>> v2 {{1}};
    EXPECT_EQ(Solution77::combine(1, 1), v2);
}

TEST(Problem78Test, Basic) {
    set<vector<int>> s1 {{}, {1}, {2}, {1, 2}, {3}, {1, 3}, {2, 3}, {1, 2, 3}};
    vector<int> v1 {1, 2, 3};
    auto r1 = Solution78::subsets(v1);
    EXPECT_EQ(set<vector<int>>(r1.begin(), r1.end()), s1);

    set<vector<int>> s2 {{}, {0}};
    vector<int> v2 {0};
    auto r2 = Solution78::subsets(v2);
    EXPECT_EQ(set<vector<int>>(r2.begin(), r2.end()), s2);
}

TEST(Problem79Test, Basic) {
    vector<vector<char>> b1 {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    auto b2 = b1, b3 = b1;

    EXPECT_EQ(Solution79::exist(b1, "ABCCED"), true);
    EXPECT_EQ(Solution79::exist(b2, "SEE"), true);
    EXPECT_EQ(Solution79::exist(b3, "ABCB"), false);
}

TEST(Problem80Test, Basic) {
    vector<int> v1 {1, 1, 1, 2, 2, 3};
    vector<int> out1 {1, 1, 2, 2, 3};
    EXPECT_EQ(Solution80::removeDuplicates(v1), 5);
    EXPECT_EQ(v1, out1);

    vector<int> v2 {0, 0, 1, 1, 1, 1, 2, 3, 3};
    vector<int> out2 {0, 0, 1, 1, 2, 3, 3};
    EXPECT_EQ(Solution80::removeDuplicates(v2), 7);
    EXPECT_EQ(v2, out2);
}
