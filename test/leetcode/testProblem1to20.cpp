//
// Created by v-yaf on 12/10/2019.
//

#include "gtest/gtest.h"
#include "leetcode/problem1to10.cpp"
#include "leetcode/problem11to20.cpp"

using namespace std;

TEST(Problem1Test, Basic) {
    Solution1to10 s;

    std::vector<int> input{2, 7, 11, 15};
    std::vector<int> expect_result{0, 1};
    EXPECT_EQ(s.twoSum(input, 9), expect_result);
}

TEST(Problem2Test, Basic) {
    Solution1to10 s;
    auto l1 = ListNode::fromInitList({2, 4, 3});
    auto l2 = ListNode::fromInitList({5, 6, 4});
    auto expect_result = ListNode::fromInitList({7, 0, 8});
    auto result = s.addTwoNumbers(l1, l2);
    EXPECT_EQ(expect_result->val, result->val);
    EXPECT_EQ(expect_result->next->val, result->next->val);
    EXPECT_EQ(expect_result->next->next->val, result->next->next->val);
    EXPECT_EQ(result->next->next->next, nullptr);
}

TEST(Problem3Test, Basic) {
    Solution1to10 s;
    EXPECT_EQ(s.lengthOfLongestSubstring("abcabcbb"), 3);
    EXPECT_EQ(s.lengthOfLongestSubstring("bbbbb"), 1);
    EXPECT_EQ(s.lengthOfLongestSubstring("pwwkew"), 3);
}

TEST(Problem4Test, Basic) {
    Solution1to10 s;

    vector<int> p1{1, 3, 4, 8, 9}, q1{2, 5, 6, 7, 10, 11};
    EXPECT_EQ(s.findMedianSortedArrays(p1, q1), 6.0);

    vector<int> p2{1, 2, 3}, q2{4, 5, 6, 7, 8, 9, 10, 11};
    EXPECT_EQ(s.findMedianSortedArrays(p2, q2), 6.0);

    vector<int> p3{9, 10, 11}, q3{1, 2, 3, 4, 5, 6, 7, 8};
    EXPECT_EQ(s.findMedianSortedArrays(p3, q3), 6.0);

    vector<int> p4{1, 3}, q4{2};
    EXPECT_EQ(s.findMedianSortedArrays(p4, q4), 2.0);

    vector<int> p5{1, 2}, q5{3, 4};
    EXPECT_EQ(s.findMedianSortedArrays(p5, q5), 2.5);

    vector<int> p6{0, 0}, q6{0, 0};
    EXPECT_EQ(s.findMedianSortedArrays(p6, q6), 0.0);

    vector<int> p7{}, q7{1, 4, 7, 10};
    EXPECT_EQ(s.findMedianSortedArrays(p7, q7), 5.5);
}

TEST(Problem5Test, Basic) {
    Solution1to10 s;

    EXPECT_EQ(s.longestPalindrome("babad"), "bab");
    EXPECT_EQ(s.longestPalindrome("cbbd"), "bb");
}

TEST(Problem6Test, Basic) {
    Solution1to10 s;

    EXPECT_EQ(s.convert("PAYPALISHIRING", 3), "PAHNAPLSIIGYIR");
    EXPECT_EQ(s.convert("PAYPALISHIRING", 4), "PINALSIGYAHRPI");
}

TEST(Problem7Test, Basic) {
    Solution1to10 s;

    EXPECT_EQ(s.reverse(123), 321);
    EXPECT_EQ(s.reverse(-123), -321);
    EXPECT_EQ(s.reverse(120), 21);
    EXPECT_EQ(s.reverse(1534236469), 0);
    EXPECT_EQ(s.reverse(-2147483648LL), 0);
}

TEST(Problem8Test, Basic) {
    Solution1to10 s;

    EXPECT_EQ(s.myAtoi("42"), 42);
    EXPECT_EQ(s.myAtoi("   -42"), -42);
    EXPECT_EQ(s.myAtoi("4193 with words"), 4193);
    EXPECT_EQ(s.myAtoi("words and 987"), 0);
    EXPECT_EQ(s.myAtoi("-91283472332"), -2147483648LL);
}

TEST(Problem9Test, Basic) {
    Solution1to10 s;

    EXPECT_EQ(s.isPalindrome(121), true);
    EXPECT_EQ(s.isPalindrome(-121), false);
    EXPECT_EQ(s.isPalindrome(10), false);
}

TEST(Problem10Test, Basic) {
    Solution1to10 s;

    EXPECT_EQ(s.isMatch("aa", "a"), false);
    EXPECT_EQ(s.isMatch("aa", "a*"), true);
    EXPECT_EQ(s.isMatch("ab", ".*"), true);
    EXPECT_EQ(s.isMatch("aab", "c*a*b*"), true);
    EXPECT_EQ(s.isMatch("mississippi", "mis*is*p*."), false);
    EXPECT_EQ(s.isMatch("abcd", "d*"), false);
}

TEST(Problem11Test, Basic) {
    Solution11 s;

    vector<int> v1{1, 8, 6, 2, 5, 4, 8, 3, 7};
    EXPECT_EQ(s.maxArea(v1), 49);
}

TEST(Problem12Test, Basic) {
    Solution12 s;

    EXPECT_EQ(s.intToRoman(3), "III");
    EXPECT_EQ(s.intToRoman(4), "IV");
    EXPECT_EQ(s.intToRoman(9), "IX");
    EXPECT_EQ(s.intToRoman(58), "LVIII");
    EXPECT_EQ(s.intToRoman(1994), "MCMXCIV");
}

TEST(Problem13Test, Basic) {
    Solution13 s;

    EXPECT_EQ(s.romanToInt("III"), 3);
    EXPECT_EQ(s.romanToInt("IV"), 4);
    EXPECT_EQ(s.romanToInt("IX"), 9);
    EXPECT_EQ(s.romanToInt("LVIII"), 58);
    EXPECT_EQ(s.romanToInt("MCMXCIV"), 1994);
}

TEST(Problem14Test, Basic) {
    Solution14 s;

    vector<string> v1 = {"flower", "flow", "flight"};
    EXPECT_EQ(s.longestCommonPrefix(v1), "fl");

    vector<string> v2 = {"dog", "racecar", "car"};
    EXPECT_EQ(s.longestCommonPrefix(v2), "");

    vector<string> v3 = {};
    EXPECT_EQ(s.longestCommonPrefix(v3), "");

    vector<string> v4 = {"a", "b"};
    EXPECT_EQ(s.longestCommonPrefix(v4), "");
}

TEST(Problem15Test, Basic) {
    Solution15 s;

    vector<int> v1 = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> r1 = {{-1, 0,  1},
                              {-1, -1, 2}};
    sort(r1.begin(), r1.end());
    EXPECT_EQ(s.threeSum(v1), r1);

    vector<int> v2 = {-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6};
    vector<vector<int>> r2 = {{-4, -2, 6},
                              {-4, 0,  4},
                              {-4, 1,  3},
                              {-4, 2,  2},
                              {-2, -2, 4},
                              {-2, 0,  2}};
    EXPECT_EQ(s.threeSum(v2), r2);

    vector<int> v3(3000, 0);
    vector<vector<int>> r3 = {{0, 0, 0}};
    EXPECT_EQ(s.threeSum(v3), r3);
}

TEST(Problem16Test, Basic) {
    Solution16 s;

    vector<int> v1 = {-1, 2, 1, 4};
    EXPECT_EQ(s.threeSumClosest(v1, 1), 2);

    vector<int> v2 = {1, 1, 1, 1};
    EXPECT_EQ(s.threeSumClosest(v2, 0), 3);

    vector<int> v3 = {1, 2, 4, 8, 16, 32, 64, 128};
    EXPECT_EQ(s.threeSumClosest(v3, 82), 82);
}

TEST(Problem17Test, Basic) {
    Solution17 s;

    vector<string> r1 = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    EXPECT_EQ(s.letterCombinations("23"), r1);

    vector<string> r2 = {};
    EXPECT_EQ(s.letterCombinations(""), r2);
}

TEST(Problem18Test, Basic) {
    Solution18 s;

    vector<int> v1 = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> r1 = {{-1, 0,  0, 1},
                              {-2, -1, 1, 2},
                              {-2, 0,  0, 2}};
    sort(r1.begin(), r1.end());
    EXPECT_EQ(s.fourSum(v1, 0), r1);

    vector<int> v2 = {0, 0, 0, 0};
    vector<vector<int>> r2 = {{0, 0, 0, 0}};
    EXPECT_EQ(s.fourSum(v2, 0), r2);

    vector<int> v3 = {-3, -1, 0, 2, 4, 5};
    vector<vector<int>> r3 = {{-3, -1, 0, 5}};
    EXPECT_EQ(s.fourSum(v3, 1), r3);

    vector<int> v4 = {-3, -2, -1, 0, 0, 1, 2, 3};
    vector<vector<int>> r4 = {{-3, -2, 2, 3},
                              {-3, -1, 1, 3},
                              {-3, 0,  0, 3},
                              {-3, 0,  1, 2},
                              {-2, -1, 0, 3},
                              {-2, -1, 1, 2},
                              {-2, 0,  0, 2},
                              {-1, 0,  0, 1}};
    EXPECT_EQ(s.fourSum(v4, 0), r4);
}

TEST(Problem19Test, Basic) {
    Solution19 s;

    auto l1 = ListNode::fromInitList({1, 2, 3, 4, 5});
    vector<int> r1 = {1, 2, 3, 5};
    EXPECT_EQ(s.removeNthFromEnd(l1, 2)->toVector(), r1);

    auto l2 = ListNode::fromInitList({1, 2, 3, 4, 5});
    vector<int> r2 = {2, 3, 4, 5};
    EXPECT_EQ(s.removeNthFromEnd(l2, 5)->toVector(), r2);

    auto l3 = ListNode::fromInitList({1, 2, 3, 4, 5});
    vector<int> r3 = {1, 2, 3, 4};
    EXPECT_EQ(s.removeNthFromEnd(l3, 1)->toVector(), r3);
}

TEST(Problem20Test, Basic) {
    Solution20 s;

    EXPECT_EQ(s.isValid("()"), true);
    EXPECT_EQ(s.isValid("()[]{}"), true);
    EXPECT_EQ(s.isValid("(]"), false);
    EXPECT_EQ(s.isValid("([)]"), false);
    EXPECT_EQ(s.isValid("{[]}"), true);
}
