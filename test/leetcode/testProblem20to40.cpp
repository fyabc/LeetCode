//
// Created by v-yaf on 12/17/2019.
//

#include "gtest/gtest.h"
#include "leetcode/problem21to30.cpp"
#include "leetcode/problem31to40.cpp"

using namespace std;

TEST(Problem21Test, Basic) {
    Solution21 s;

    auto ll1 = ListNode::fromInitList({1, 2, 4}), lr1 = ListNode::fromInitList({1, 3, 4});
    auto r1 = ListNode::fromInitList({1, 1, 2, 3, 4, 4});
    EXPECT_EQ(s.mergeTwoLists(ll1, lr1)->toVector(), r1->toVector());
}

TEST(Problem22Test, Basic) {
    Solution22 s;
    vector<string> r1 = {"((()))", "(()())", "(())()", "()(())", "()()()"};
    EXPECT_EQ(s.generateParenthesis(3), r1);

    vector<string> r2 = {""};
    EXPECT_EQ(s.generateParenthesis(0), r2);
}

TEST(Problem23Test, Basic) {
    Solution23 s;

    vector<ListNode*> l1 = {
        ListNode::fromInitList({1, 4, 5}),
        ListNode::fromInitList({1, 3, 4}),
        ListNode::fromInitList({2, 6}),
    };
    auto r1 = ListNode::fromInitList({1, 1, 2, 3, 4, 4, 5, 6});
    EXPECT_EQ(s.mergeKLists(l1)->toVector(), r1->toVector());
}

TEST(Problem24Test, Basic) {
    Solution24 s;

    auto l1 = ListNode::fromInitList({1, 2, 3, 4});
    auto r1 = ListNode::fromInitList({2, 1, 4, 3});
    EXPECT_EQ(s.swapPairs(l1)->toVector(), r1->toVector());

    auto l2 = ListNode::fromInitList({1, 2, 3});
    auto r2 = ListNode::fromInitList({2, 1, 3});
    EXPECT_EQ(s.swapPairs(l2)->toVector(), r2->toVector());
}

TEST(Problem25Test, Basic) {
    Solution25 s;

    auto l1 = ListNode::fromInitList({1, 2, 3, 4, 5});
    auto r1 = ListNode::fromInitList({2, 1, 4, 3, 5});
    EXPECT_EQ(s.reverseKGroup(l1, 2)->toVector(), r1->toVector());

    auto l2 = ListNode::fromInitList({1, 2, 3, 4, 5});
    auto r2 = ListNode::fromInitList({3, 2, 1, 4, 5});
    EXPECT_EQ(s.reverseKGroup(l2, 3)->toVector(), r2->toVector());
}

TEST(Problem26Test, Basic) {
    Solution26 s;

    vector<int> v1 = {1, 1, 2};
    vector<int> r1 = {1, 2};
    EXPECT_EQ(s.removeDuplicates(v1), 2);
    EXPECT_TRUE(equal(r1.begin(), r1.end(), v1.begin()));

    vector<int> v2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    vector<int> r2 = {0, 1, 2, 3, 4};
    EXPECT_EQ(s.removeDuplicates(v2), 5);
    EXPECT_TRUE(equal(r2.begin(), r2.end(), v2.begin()));
}

TEST(Problem27Test, Basic) {
    Solution27 s;

    vector<int> v1 = {3, 2, 2, 3};
    vector<int> r1 = {2, 2};
    EXPECT_EQ(s.removeElement(v1, 3), 2);
    EXPECT_TRUE(equal(r1.begin(), r1.end(), v1.begin()));

    vector<int> v2 = {0, 1, 2, 2, 3, 0, 4, 2};
    vector<int> r2 = {0, 1, 3, 0, 4};
    EXPECT_EQ(s.removeElement(v2, 2), 5);
    EXPECT_TRUE(equal(r2.begin(), r2.end(), v2.begin()));
}

TEST(Problem28Test, Basic) {
    Solution28 s;

    EXPECT_EQ(s.strStr("hello", "ll"), 2);
    EXPECT_EQ(s.strStr("aaaaa", "bba"), -1);
    EXPECT_EQ(s.strStr("aaaaa", ""), 0);
    EXPECT_EQ(s.strStr("abbbaaaaaaabbababbbbabababbbbbbbaaaaaaabbaaabbaababbbbababababaabbbbbbaaaaababbbbaaabababbbaaaabbbaabbbbbbabababbabaaaaabaabaaababbbaaabaababbaaabaaababbabbbbababaaaaaaababaabaabbaabbbaaabaaaaaa",
                       "aabaaaabababbbabababbbaabaabaaaaabaabbbaabbbbba"), -1);
}

TEST(Problem29Test, Basic) {
    Solution29 s;

    EXPECT_EQ(s.divide(10, 3), 3);
    EXPECT_EQ(s.divide(7, -3), -2);
}

TEST(Problem30Test, Basic) {
    Solution30 s;

    vector<string> w1 = {"foo", "bar"};
    vector<int> r1 = {0, 9};
    EXPECT_EQ(s.findSubstring("barfoothefoobarman", w1), r1);

    vector<string> w2 = {"word", "good", "best", "word"};
    vector<int> r2 = {};
    EXPECT_EQ(s.findSubstring("wordgoodgoodgoodbestword", w2), r2);
}

TEST(Problem31Test, Basic) {
    vector<int> v1 = {1, 2, 3};
    vector<int> r1 = {1, 3, 2};
    Solution31::nextPermutation(v1);
    EXPECT_EQ(v1, r1);

    vector<int> v2 = {3, 2, 1};
    vector<int> r2 = {1, 2, 3};
    Solution31::nextPermutation(v2);
    EXPECT_EQ(v2, r2);

    vector<int> v3 = {1, 1, 5};
    vector<int> r3 = {1, 5, 1};
    Solution31::nextPermutation(v3);
    EXPECT_EQ(v3, r3);
}

TEST(Problem32Test, Basic) {
    Solution32 s;

    EXPECT_EQ(s.longestValidParentheses("(()"), 2);
    EXPECT_EQ(s.longestValidParentheses(")()())"), 4);
    EXPECT_EQ(s.longestValidParentheses("(()(()"), 2);
    EXPECT_EQ(s.longestValidParentheses("())())"), 2);
    EXPECT_EQ(s.longestValidParentheses("(())((()))"), 10);
    EXPECT_EQ(s.longestValidParentheses(""), 0);
    EXPECT_EQ(s.longestValidParentheses("(((((("), 0);
}

TEST(Problem33Test, Basic) {
    Solution33 s;

    vector<int> v1 = {4, 5, 6, 7, 0, 1, 2};
    EXPECT_EQ(s.search(v1, 0), 4);

    vector<int> v2 = {4, 5, 6, 7, 0, 1, 2};
    EXPECT_EQ(s.search(v2, 3), -1);

    vector<int> v3 = {};
    EXPECT_EQ(s.search(v3, 0), -1);

    vector<int> v4 = {1};
    EXPECT_EQ(s.search(v4, 1), 0);
}

TEST(Problem34Test, Basic) {
    Solution34 s;

    vector<int> v1 = {5, 7, 7, 8, 8, 10};
    vector<int> r1 = {3, 4};
    EXPECT_EQ(s.searchRange(v1, 8), r1);

    vector<int> v2 = {5, 7, 7, 8, 8, 10};
    vector<int> r2 = {-1, -1};
    EXPECT_EQ(s.searchRange(v2, 6), r2);
}

TEST(Problem35Test, Basic) {
    Solution35 s;

    vector<int> v1 = {1, 3, 5, 6};
    EXPECT_EQ(s.searchInsert(v1, 5), 2);
    EXPECT_EQ(s.searchInsert(v1, 2), 1);
    EXPECT_EQ(s.searchInsert(v1, 7), 4);
    EXPECT_EQ(s.searchInsert(v1, 0), 0);
}

TEST(Problem36Test, Basic) {
    Solution36 s;

    vector<vector<char>> b1 = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };
    EXPECT_EQ(s.isValidSudoku(b1), true);

    auto b2 = b1;
    b2[0][0] = '8';
    EXPECT_EQ(s.isValidSudoku(b2), false);
}
