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
    vector<int> v1 {1, -1, 1};
    vector<int> v2 {1, -10, 9, 1};
    EXPECT_EQ(WC231Q2_Problem1785::minElements(v1, 3, -4), 2);
    EXPECT_EQ(WC231Q2_Problem1785::minElements(v2, 100, 0), 1);
}

TEST(WC231Q3_Problem1786Test, Basic) {
    vector<vector<int>> g1 {{1, 2, 3}, {1, 3, 3}, {2, 3, 1}, {1, 4, 2}, {5, 2, 2}, {3, 5, 1}, {5, 4, 10}};
    EXPECT_EQ(WC231Q3_Problem1786::countRestrictedPaths(5, g1), 3);

    vector<vector<int>> g2 {{1, 3, 1}, {4, 1, 2}, {7, 3, 4}, {2, 5, 3}, {5, 6, 1}, {6, 7, 2}, {7, 5, 3}, {2, 6, 4}};
    EXPECT_EQ(WC231Q3_Problem1786::countRestrictedPaths(7, g2), 1);

    vector<vector<int>> g3 {{6,2,9},{2,1,7},{6,5,10},{4,3,1},{3,1,8},{4,6,4},{5,1,7},{1,4,7},{4,5,3},{3,6,6},{5,3,9},{1,6,6},{3,2,2},{5,2,8}};
    EXPECT_EQ(WC231Q3_Problem1786::countRestrictedPaths(6, g3), 4);
}

TEST(WC231Q4_Problem1787Test, Basic) {
//    vector<int> v1 {1, 2, 0, 3, 0};
//    EXPECT_EQ(WC231Q4_Problem1787::minChanges(v1, 1), 3);
//
//    vector<int> v2 {3, 4, 5, 2, 1, 7, 3, 4, 7};
//    EXPECT_EQ(WC231Q4_Problem1787::minChanges(v2, 3), 3);
//
//    vector<int> v3 {1, 2, 4, 1, 2, 5, 1, 2, 6};
//    EXPECT_EQ(WC231Q4_Problem1787::minChanges(v3, 3), 3);
//
//    vector<int> v4 {4,11,31,2,16,12,0,27,11,26,8,23,2,2,22,5,9};
//    EXPECT_EQ(WC231Q4_Problem1787::minChanges(v4, 3), 13);
//
//    vector<int> v5 {165,22,35,196,128,58,159,47,104,34,228,43,249,226,157,6,174,117,234,141,166,83,170,143,99,133,199,
//                    196,207,142,101,89,122,127,15,38,255,185,109,232,115,76,188,254,95,177,241,37,70,45,193,241,76,76};
//    EXPECT_EQ(WC231Q4_Problem1787::minChanges(v5, 21), 33);
//
//    vector<int> v6 {231,167,89,85,224,180,45,58,23,108,157,95,108,64,206,109,147,28,194,17,4,46,74,96,237,109,114,122,
//                    161,76,181,251,9,82,44,15,242,7,23,109,210,109,181,12,14,226,61,49,8,74,19,152,4,137,243,27,187,200,
//                    168,145,188,203,98,193,253,133,164,198,132,119,148,146,94,43,181,123,212,83,157};
//    EXPECT_EQ(WC231Q4_Problem1787::minChanges(v6, 2), 75);

    vector<int> v7 {6,2,3,9,2,3,4,2,3};
    EXPECT_EQ(WC231Q4_Problem1787::minChanges(v7, 3), 3);
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
