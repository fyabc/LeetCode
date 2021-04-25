//
// Created by fyabc on 2021/2/16.
//

#include "gtest/gtest.h"
#include "support/String.h"

using namespace std;
using namespace leetcode;

TEST(StringTest, TestDefaultSplit) {
    string s1 = "dog cat cat dog";
    vector<string> v1 = {"dog", "cat", "cat", "dog"};

    EXPECT_EQ(split(s1), v1);

    string s2 = "  this   is  a sentence ";
    vector<string> v2 = {"this", "is", "a", "sentence"};

    EXPECT_EQ(split(s2), v2);

    string s3 = " a ";
    vector<string> v3 = {"a"};
    EXPECT_EQ(split(s3), v3);

    EXPECT_EQ(split(""), vector<string> {});
}

TEST(StringTest, TestSplitDelim) {
    string s1 = "/home/Bob/workspace";
    vector<string> v1 = {"", "home", "Bob", "workspace"};

    EXPECT_EQ(split(s1, '/'), v1);
    EXPECT_EQ(split(s1, "/"), v1);
    EXPECT_THROW(split(s1, ""), invalid_argument);

    EXPECT_EQ(split("abc", "abc"), vector<string> (2, ""));
    EXPECT_EQ(split("abc", "def"), vector<string> {"abc"});

    vector<string> v2 {"", "bc"};
    EXPECT_EQ(split("abc", "a"), v2);

    EXPECT_EQ(split("", "abc"), vector<string> {""});
}

TEST(StringTest, TestJoin) {
    EXPECT_EQ(join({}, "--"), "");
    EXPECT_EQ(join({"a"}, "--"), "a");
    EXPECT_EQ(join({"a", "b"}, "--"), "a--b");
    EXPECT_EQ(join({"a", "b", "c"}, "--"), "a--b--c");
    EXPECT_EQ(join({"a", "b", "c"}, ""), "abc");
}
