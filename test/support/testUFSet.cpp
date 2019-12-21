//
// Created by v-yaf on 12/6/2019.
//

#include "gtest/gtest.h"
#include "support/UFSet.h"

using namespace std;
using namespace leetcode;

TEST(UFSetTest, BasicUsage) {
    UFSet ufs{10};
    EXPECT_EQ(ufs.count(), 10);
    EXPECT_EQ(ufs.connected(7, 8), false);

    ufs.union_(3, 5);
    ufs.union_(4, 8);
    ufs.union_(1, 3);
    ufs.union_(5, 4);
    EXPECT_EQ(ufs.count(), 6);
    EXPECT_EQ(ufs.connected(1, 4), true);
}
