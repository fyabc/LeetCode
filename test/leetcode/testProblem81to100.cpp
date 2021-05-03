//
// Created by fyabc on 2019/12/21.
//

#include "gtest/gtest.h"
#include "leetcode/problem81to90.cpp"
#include "leetcode/problem91to100.cpp"

using namespace std;

TEST(Problem76Test, Basic) {
    vector<int> v1 {2, 5, 6, 0, 0, 1, 2};
    EXPECT_EQ(Solution81::search(v1, 0), true);

    vector<int> v2 = v1;
    EXPECT_EQ(Solution81::search(v2, 3), false);
}
