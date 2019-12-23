//
// Created by fyabc on 2019/12/21.
//

#include "gtest/gtest.h"
#include "support/IO.h"

#include <utility>

using namespace std;
using namespace leetcode;

#define CAPTURE_STDOUT(code) [&] {                  \
    testing::internal::CaptureStdout();             \
    code;                                           \
    return testing::internal::GetCapturedStdout();  \
}()

#define CAPTURE_STDERR(code) [&] {                  \
    testing::internal::CaptureStderr();             \
    code;                                           \
    return testing::internal::GetCapturedStderr();  \
}()

TEST(TestPrintlnV, Basic) {
    EXPECT_EQ(
        CAPTURE_STDOUT(printlnV()),
        "\n");
    EXPECT_EQ(
        CAPTURE_STDOUT(printlnV(42.42)),
        "42.42\n");
    EXPECT_EQ(
        CAPTURE_STDOUT(printlnV("a:", 1, "b:", 2)),
        "a: 1 b: 2\n");
}

TEST(TestPrint, Basic) {
    EXPECT_EQ(
        CAPTURE_STDOUT(print(10)),
        "10");
    EXPECT_EQ(
        CAPTURE_STDOUT(print(nullptr)),
        "nullptr");
    EXPECT_EQ(
        CAPTURE_STDOUT(print("Hello, world!")),
        "Hello, world!");
    EXPECT_EQ(
        CAPTURE_STDOUT(print("你好，世界！")),
        "你好，世界！");

    const char* cStr = "C string";
    EXPECT_EQ(
        CAPTURE_STDOUT(print(cStr)),
        "C string");

    EXPECT_EQ(
        CAPTURE_STDOUT(print(string("C++ string"))),
        "C++ string");
}

template <typename T>
struct MyContainer {
    vector<T> v;

    MyContainer(std::initializer_list<T> initializerList): v(initializerList) {}

    [[nodiscard]] auto begin() const { return v.begin(); }
    [[nodiscard]] auto end() const { return v.end(); }
};

TEST(TestPrint, Container) {
    int N[] = {1, 2, 4};
    EXPECT_EQ(
        CAPTURE_STDOUT(print(N)),
        "int [3](1, 2, 4)");

    EXPECT_EQ(
        CAPTURE_STDOUT(print({1, 2, 4})),
        "initlist(1, 2, 4)");
    EXPECT_EQ(
        CAPTURE_STDOUT(print(vector<int> {1, 2, 4})),
        "[1, 2, 4]");
    EXPECT_EQ(
        CAPTURE_STDOUT(print(list<int> {1, 2, 4})),
        "list[1, 2, 4]");
    EXPECT_EQ(
        CAPTURE_STDOUT(print(forward_list<int> {1, 2, 4})),
        "forward_list[1, 2, 4]");
    EXPECT_EQ(
        CAPTURE_STDOUT(print(map<string, int>{{"hello", 1}, {"world", 2}})),
        "{hello: 1, world: 2}");
    EXPECT_EQ(
        CAPTURE_STDOUT(print(set<char>{'a', 's', 'c', 'i', 'i'})),
        "{a, c, i, s}");
    EXPECT_EQ(
        CAPTURE_STDOUT(print(set<char>{})),
        "set()");
    EXPECT_EQ(
        CAPTURE_STDOUT(print(multiset<char>{'a', 's', 'c', 'i', 'i'})),
        "{a, c, i, i, s}");
    EXPECT_EQ(
        CAPTURE_STDOUT(print(MyContainer<int>{1, 2, 4})),
        "struct MyContainer<int>(1, 2, 4)");
}

TEST(TestPrint, NestedContainer) {
    EXPECT_EQ(
        CAPTURE_STDOUT(print(vector<vector<int>> {{1, 2}, {}, {3, 4, 5}})),
        "[[1, 2], [], [3, 4, 5]]");
    EXPECT_EQ(
        CAPTURE_STDOUT(print(map<char, vector<int>> {{'a', {1, 2}}, {'b', {}}, {'c', {3, 4, 5}}})),
        "{a: [1, 2], b: [], c: [3, 4, 5]}");
}

TEST(TestPrintOperators, Basic) {
    EXPECT_EQ(
        CAPTURE_STDOUT(cout << make_pair(3, "Q")),
        "pair(3, Q)");
}
