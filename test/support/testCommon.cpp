//
// Created by v-yaf on 12/23/2019.
//

#include "gtest/gtest.h"
#include "support/Common.h"

#include <stack>
#include <vector>

using namespace std;
using namespace leetcode;

TEST(TestGetTypename, Basic) {
    EXPECT_EQ(getTypename<int>(), "int");
    EXPECT_EQ(getTypename<int&>(), "int");
    EXPECT_EQ(getTypename<int&&>(), "int");
}

TEST(TestIsContainer, Basic) {
    EXPECT_TRUE(isContainer<vector<int>>::value);
    EXPECT_TRUE(isContainer<int[5]>::value);
    EXPECT_TRUE(isContainer<vector<int>&>::value);
    EXPECT_FALSE(isContainer<int>::value);
    EXPECT_FALSE(isContainer<int[]>::value);
    EXPECT_FALSE(isContainer<stack<int>>::value);

    EXPECT_TRUE(isContainer2<vector<int>>::value);
    EXPECT_TRUE(isContainer2<int[5]>::value);
    EXPECT_TRUE(isContainer2<vector<int>&>::value);
    EXPECT_FALSE(isContainer2<int>::value);
    EXPECT_FALSE(isContainer2<int[]>::value);
    EXPECT_FALSE(isContainer2<stack<int>>::value);
}
