//
// Created by fyabc on 2021/5/9.
//

#include "gtest/gtest.h"
#include "support/ForwardList.h"

#include <stack>
#include <vector>

using namespace std;
using namespace leetcode;

TEST(TestForwardList, Basic) {
    vector<int> v1 {1, 2, 3, 5};
    auto l1 = ListNode::fromInitList({1, 2, 3, 5});
    auto l2 = ListNode::fromContainer(v1);

    EXPECT_EQ(l1->toVector(), v1);
    EXPECT_EQ(l2->toVector(), v1);
}

TEST(TestForwardList, Equal) {
    auto l1 = ListNode::fromInitList({1, 2, 3, 5});
    auto l2 = ListNode::fromInitList({1, 2, 3, 5});
    ListNode* l3 = nullptr;

    EXPECT_TRUE(fwList_Equal(l1, l2));
    EXPECT_FALSE(fwList_Equal(l1, l3));
}

TEST(TestForwardList, AppendNode) {
    auto l1 = ListNode::fromInitList({1, 2, 3, 5});
    auto l1tail = fwList_GetTail(l1);
    vector<int> v1 {1, 2, 3, 5, 10};

    fwList_Append(10, l1, l1tail);
    EXPECT_EQ(l1->toVector(), v1);
}
