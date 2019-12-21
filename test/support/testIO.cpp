//
// Created by fyabc on 2019/12/21.
//

#include "gtest/gtest.h"
#include "support/IO.h"

using namespace std;
using namespace leetcode;

#define CAPTURE_STDOUT(code) [&] {                  \
    testing::internal::CaptureStdout();             \
    code;                                           \
    return testing::internal::GetCapturedStdout();  \
}()

TEST(TestPrintln, Basic) {
    EXPECT_EQ(
        CAPTURE_STDOUT(println()),
        "\n");
    EXPECT_EQ(
        CAPTURE_STDOUT(println(42.42)),
        "42.42\n");
    EXPECT_EQ(
        CAPTURE_STDOUT(println("a:", 1, "b:", 2)),
        "a: 1 b: 2\n");
}

TEST(TestPrintlnC, Basic) {
    EXPECT_EQ(
        CAPTURE_STDOUT(printlnC({1, 2, 4})),
        "class std::initializer_list<int>(1, 2, 4)\n");
    EXPECT_EQ(
        CAPTURE_STDOUT(printlnC(vector<int> {1, 2, 4})),
        "[1, 2, 4]\n");
    EXPECT_EQ(
        CAPTURE_STDOUT(printlnC(list<int> {1, 2, 4})),
        "class std::list<int,class std::allocator<int> >(1, 2, 4)\n");
    EXPECT_EQ(
        CAPTURE_STDOUT(printlnC(map<string, int>{{"hello", 1}, {"world", 2}})),
        "{hello: 1, world: 2}\n");
    EXPECT_EQ(
        CAPTURE_STDOUT(printlnC(set<char>{'a', 's', 'c', 'i', 'i'})),
        "{a, c, i, s}\n");
    EXPECT_EQ(
        CAPTURE_STDOUT(printlnC(multiset<char>{'a', 's', 'c', 'i', 'i'})),
        "{a, c, i, i, s}\n");
}

TEST(TestPrintPair, Basic) {
    EXPECT_EQ(
        CAPTURE_STDOUT(println(make_pair(3, "Q"))),
        "pair(3, Q)\n");
}
