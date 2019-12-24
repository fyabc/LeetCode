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
}
