//
// Created by fyabc on 2021/3/12.
//

#include "gtest/gtest.h"
#include "leetcode/weeklyContest/WC221to230.cpp"
#include "leetcode/weeklyContest/WC231to240.cpp"

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

TEST(WC231Q1_Problem1784Test, Basic) {
    EXPECT_EQ(WC231Q1_Problem1784::checkOnesSegment("1001"), false);
    EXPECT_EQ(WC231Q1_Problem1784::checkOnesSegment("110"), true);
}

TEST(WC231Q2_Problem1785Test, Basic) {
    vector v1 {1, -1, 1};
    vector v2 {1, -10, 9, 1};
    EXPECT_EQ(WC231Q2_Problem1785::minElements(v1, 3, -4), 2);
    EXPECT_EQ(WC231Q2_Problem1785::minElements(v2, 100, 0), 1);
}

TEST(WC237Q1_Problem1832Test, Basic) {
    EXPECT_EQ(WC237Q1_Problem1832::checkIfPangram("thequickbrownfoxjumpsoverthelazydog"), true);
    EXPECT_EQ(WC237Q1_Problem1832::checkIfPangram("leetcode"), false);
}

TEST(WC237Q2_Problem1833Test, Basic) {
    vector<int> v1 {1, 3, 2, 4, 1};
    vector<int> v2 {10, 6, 8, 7, 7, 8};
    vector<int> v3 {1, 6, 3, 1, 2, 5};
    EXPECT_EQ(WC237Q2_Problem1833::maxIceCream(v1, 7), 4);
    EXPECT_EQ(WC237Q2_Problem1833::maxIceCream(v2, 5), 0);
    EXPECT_EQ(WC237Q2_Problem1833::maxIceCream(v3, 20), 6);
}

TEST(WC237Q3_Problem1834Test, Basic) {
    vector<vector<int>> t1 = {{1, 2}, {2, 4}, {3, 2}, {4, 1}};
    vector<vector<int>> t2 = {{7, 10}, {7, 12}, {7, 5}, {7, 4}, {7, 2}};
    vector<vector<int>> t3 = {{35, 36}, {11, 7}, {15, 47}, {34, 2}, {47, 19}, {16, 14}, {19, 8},
                              {7, 34}, {38, 15}, {16, 18}, {27, 22}, {7, 15}, {43, 2}, {10, 5},
                              {5, 4}, {3, 11}};

    EXPECT_EQ(WC237Q3_Problem1834::getOrder(t1), vector<int>({0, 2, 3, 1}));
    EXPECT_EQ(WC237Q3_Problem1834::getOrder(t2), vector<int>({4, 3, 2, 0, 1}));
    EXPECT_EQ(WC237Q3_Problem1834::getOrder(t3), vector<int>({15,14,13,1,6,3,5,12,8,11,9,4,10,7,0,2}));
}

TEST(WC237Q4_Problem1835Test, Basic) {
    vector<int> v11 = {1, 2, 3}, v12 = {6, 5};
    vector<int> v21 = {12}, v22 = {4};

    EXPECT_EQ(WC237Q4_Problem1835::getXORSum(v11, v12), 0);
    EXPECT_EQ(WC237Q4_Problem1835::getXORSum(v21, v22), 4);
}
