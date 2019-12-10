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

    vector<int> v1 {1, 3}, v2 {2};
    EXPECT_EQ(s.findMedianSortedArrays(v1, v2), 2.0);

    vector<int> v3 {1, 2}, v4 {3, 4};
    EXPECT_EQ(s.findMedianSortedArrays(v3, v4), 2.5);
}
