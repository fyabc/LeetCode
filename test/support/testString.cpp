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

    string s4;
    vector<string> v4 = {};

    EXPECT_EQ(split(s4), v4);
}

TEST(StringTest, TestSplitDelim) {
    string s1 = "/home/";

    // TODO
}
