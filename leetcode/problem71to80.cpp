//
// Created by fyabc on 2019/12/21.
//

#include "support/IO.h"

#include <istream>
#include <algorithm>

using namespace std;


class Solution71 {
public:
    static string simplifyPath(const string& path) {
        vector<string> pathItems;
        istringstream is(path);
        string s;

        while (getline(is, s, '/')) {
            pathItems.push_back(s);
        }

        vector<string> finalPathItems;
        for (const auto& pathItem : pathItems) {
            if (pathItem.empty() || pathItem == ".") {
                // Do nothing
            } else if (pathItem == "..") {
                if (!finalPathItems.empty()) {
                    finalPathItems.pop_back();
                }
            } else {
                finalPathItems.push_back(pathItem);
            }
        }

        string result;
        for (const auto& finalPathItem : finalPathItems) {
            result.append("/");
            result.append(finalPathItem);
        }
        if (finalPathItems.empty()) {
            result = "/";
        }

        return result;
    }
};


class Solution72 {
    /// Method: dynamic programming
    /// See https://zh.wikipedia.org/wiki/%E8%90%8A%E6%96%87%E6%96%AF%E5%9D%A6%E8%B7%9D%E9%9B%A2 for the equation.
public:
    static int minDistance(const string& word1, const string& word2) {
        auto len1 = word1.size(), len2 = word2.size();
        vector<int> table((len1 + 1) * (len2 + 1), 0);
        auto _p = [&len1](int i, int j) { return i * (len1 + 1) + j; };

        for (int i = 0; i <= len2; ++i) {
            table[_p(i, 0)] = i;
        }
        for (int j = 0; j <= len1; ++j) {
            table[_p(0, j)] = j;
        }

        for (int i = 1; i <= len2; ++i) {
            for (int j = 1; j <= len1; ++j) {
                int cost = word1[j - 1] == word2[i - 1] ? 0 : 1;
                table[_p(i, j)] = std::min({
                    table[_p(i - 1, j)] + 1, // delete
                    table[_p(i, j - 1)] + 1, // insert
                    table[_p(i - 1, j - 1)] + cost, // replace
                });
            }
        }

        auto result = table[_p(len2, len1)];

        return result;
    }
};


class Solution73 {
public:

};
