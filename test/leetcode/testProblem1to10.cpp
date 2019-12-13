//
// Created by v-yaf on 12/10/2019.
//

#include "gtest/gtest.h"
#include "leetcode/problem1to10.cpp"

using namespace std;

TEST(Problem1Test, Basic) {
    Solution s;

    std::vector<int> input {2, 7, 11, 15};
    std::vector<int> expect_result {0, 1};
    EXPECT_EQ(s.twoSum(input, 9), expect_result);
}

TEST(Problem2Test, Basic) {
    Solution s;
    auto l1 = Solution::ListNode::from_init_list({3, 4, 2});
    auto l2 = Solution::ListNode::from_init_list({4, 6, 5});
    auto expect_result = Solution::ListNode::from_init_list({8, 0, 7});
    auto result = s.addTwoNumbers(l1, l2);
    EXPECT_EQ(expect_result->val, result->val);
    EXPECT_EQ(expect_result->next->val, result->next->val);
    EXPECT_EQ(expect_result->next->next->val, result->next->next->val);
    EXPECT_EQ(result->next->next->next, nullptr);
}

TEST(Problem3Test, Basic) {
    Solution s;
    EXPECT_EQ(s.lengthOfLongestSubstring("abcabcbb"), 3);
    EXPECT_EQ(s.lengthOfLongestSubstring("bbbbb"), 1);
    EXPECT_EQ(s.lengthOfLongestSubstring("pwwkew"), 3);
}

TEST(Problem4Test, Basic) {
    Solution s;

    vector<int> p1 {1, 3, 4, 8, 9}, q1 {2, 5, 6, 7, 10, 11};
    EXPECT_EQ(s.findMedianSortedArrays(p1, q1), 6.0);

    vector<int> p2 {1, 2, 3}, q2 {4, 5, 6, 7, 8, 9, 10, 11};
    EXPECT_EQ(s.findMedianSortedArrays(p2, q2), 6.0);

    vector<int> p3 {9, 10, 11}, q3 {1, 2, 3, 4, 5, 6, 7, 8};
    EXPECT_EQ(s.findMedianSortedArrays(p3, q3), 6.0);

    vector<int> p4 {1, 3}, q4 {2};
    EXPECT_EQ(s.findMedianSortedArrays(p4, q4), 2.0);

    vector<int> p5 {1, 2}, q5 {3, 4};
    EXPECT_EQ(s.findMedianSortedArrays(p5, q5), 2.5);

    vector<int> p6 {0, 0}, q6 {0, 0};
    EXPECT_EQ(s.findMedianSortedArrays(p6, q6), 0.0);

    vector<int> p7 {}, q7 {1, 4, 7, 10};
    EXPECT_EQ(s.findMedianSortedArrays(p7, q7), 5.5);
}

TEST(Problem5Test, Basic) {
    Solution s;

    EXPECT_EQ(s.longestPalindrome("babad"), "bab");
    EXPECT_EQ(s.longestPalindrome("cbbd"), "bb");
}

TEST(Problem6Test, Basic) {
    Solution s;

    EXPECT_EQ(s.convert("PAYPALISHIRING", 3), "PAHNAPLSIIGYIR");
    EXPECT_EQ(s.convert("PAYPALISHIRING", 4), "PINALSIGYAHRPI");
}

TEST(Problem7Test, Basic) {
    Solution s;

    EXPECT_EQ(s.reverse(123), 321);
    EXPECT_EQ(s.reverse(-123), -321);
    EXPECT_EQ(s.reverse(120), 21);
    EXPECT_EQ(s.reverse(1534236469), 0);
    EXPECT_EQ(s.reverse(-2147483648), 0);
}

TEST(Problem8Test, Basic) {
    Solution s;

    EXPECT_EQ(s.myAtoi("42"), 42);
    EXPECT_EQ(s.myAtoi("   -42"), -42);
    EXPECT_EQ(s.myAtoi("4193 with words"), 4193);
    EXPECT_EQ(s.myAtoi("words and 987"), 0);
    EXPECT_EQ(s.myAtoi("-91283472332"), -2147483648);
}

TEST(Problem9Test, Basic) {
    Solution s;

    EXPECT_EQ(s.isPalindrome(121), true);
    EXPECT_EQ(s.isPalindrome(-121), false);
    EXPECT_EQ(s.isPalindrome(10), false);
}

TEST(Problem10Test, Basic) {
    Solution s;

    EXPECT_EQ(s.isMatch("aa", "a"), false);
    EXPECT_EQ(s.isMatch("aa", "a*"), true);
    EXPECT_EQ(s.isMatch("ab", ".*"), true);
    EXPECT_EQ(s.isMatch("aab", "c*a*b*"), true);
    EXPECT_EQ(s.isMatch("mississippi", "mis*is*p*."), false);
}
