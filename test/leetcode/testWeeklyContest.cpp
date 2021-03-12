//
// Created by fyabc on 2021/3/12.
//

#include "gtest/gtest.h"
#include "leetcode/weeklyContest/weeklyContest221to230.cpp"

using namespace std;

TEST(WC224Q2_Problem1726Test, Basic) {
    vector<int> v1 {2, 3, 4, 6};
    EXPECT_EQ(WC224Q2_Problem1726::tupleSameProduct(v1), 8);

    vector<int> v2 {1, 2, 4, 5, 10};
    EXPECT_EQ(WC224Q2_Problem1726::tupleSameProduct(v2), 16);

    vector<int> v3 {2, 3, 4, 6, 8, 12};
    EXPECT_EQ(WC224Q2_Problem1726::tupleSameProduct(v3), 40);

    vector<int> v4 {2, 3, 5, 7};
    EXPECT_EQ(WC224Q2_Problem1726::tupleSameProduct(v4), 0);
}

TEST(WC224Q3_Problem1727Test, Basic) {
    vector<vector<int>> m1 {{0, 0, 1}, {1, 1, 1}, {1, 0, 1}};
    EXPECT_EQ(WC224Q3_Problem1727::largestSubmatrix(m1), 4);

    vector<vector<int>> m2 {{1, 0, 1, 0, 1}};
    EXPECT_EQ(WC224Q3_Problem1727::largestSubmatrix(m2), 3);

    vector<vector<int>> m3 {{1, 1, 0}, {1, 0, 1}};
    EXPECT_EQ(WC224Q3_Problem1727::largestSubmatrix(m3), 2);

    vector<vector<int>> m4 {{0, 0}, {0, 0}};
    EXPECT_EQ(WC224Q3_Problem1727::largestSubmatrix(m4), 0);
}

TEST(WC225Q2_Problem1737Test, Basic) {
    EXPECT_EQ(WC225Q2_Problem1737::minCharacters("aba", "caa"), 2);
    EXPECT_EQ(WC225Q2_Problem1737::minCharacters("dabadd", "cda"), 3);
}

TEST(WC225Q3_Problem1738Test, Basic) {
    vector<vector<int>> m1 {{5, 2}, {1, 6}}, m2 = m1, m3 = m1, m4 = m1;
    EXPECT_EQ(WC225Q3_Problem1738::kthLargestValue(m1, 1), 7);
    EXPECT_EQ(WC225Q3_Problem1738::kthLargestValue(m2, 2), 5);
    EXPECT_EQ(WC225Q3_Problem1738::kthLargestValue(m3, 3), 4);
    EXPECT_EQ(WC225Q3_Problem1738::kthLargestValue(m4, 4), 0);
}
