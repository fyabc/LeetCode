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
    /// Use the first row and the first column as flags.
    /// Use m[0, 0] to mark the first row, and use `firstColumnMarked` to mark the first column.
    /// See https://leetcode.com/problems/set-matrix-zeroes/solution/ solution 2 for more details.
public:
    static void setZeroes(vector<vector<int>>& matrix) {
        auto M = static_cast<int>(matrix.size()), N = static_cast<int>(matrix[0].size());
        bool firstColumnMarked = false;

        for (int i = 0; i < M; ++i) {
            if (matrix[i][0] == 0) {
                firstColumnMarked = true;
            }
            for (int j = 1; j < N; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < M; ++i) {
            for (int j = 1; j < N; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (matrix[0][0] == 0) {
            for (int j = 0; j < N; ++j) {
                matrix[0][j] = 0;
            }
        }

        if (firstColumnMarked) {
            for (int i = 0; i < M; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};


class Solution74 {
public:
    static bool searchMatrix(vector<vector<int>>& matrix, int target) {
        auto M = static_cast<int>(matrix.size()), N = static_cast<int>(matrix[0].size());

        auto _g = [&matrix, &N](int i) { return matrix[i / N][i % N]; };

        int lo = 0, hi = M * N - 1;

        while (lo <= hi) {
            auto mid = (lo + hi) / 2;
            auto midValue = _g(mid);

            if (midValue == target) {
                return true;
            } else if (midValue > target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return false;
    }
};


class Solution75 {
public:
    static void sortColors(vector<int>& nums) {
        int num0 = 0, num1 = 0, num2 = 0;

        for (const int num : nums) {
            switch (num) {
                case 0:
                    ++num0;
                    break;
                case 1:
                    ++num1;
                    break;
                case 2:
                    ++num2;
                    break;
                default:
                    break;
            }
        }

        int i = 0;
        for (int j = 0; j < num0; ++i, ++j) {
            nums[i] = 0;
        }
        for (int j = 0; j < num1; ++i, ++j) {
            nums[i] = 1;
        }
        for (int j = 0; j < num2; ++i, ++j) {
            nums[i] = 2;
        }
    }
};


class Solution76 {
public:
    static string minWindow(const string& s, const string& t) {
        unordered_map<char, int> counter;   // t characters counter
        for (char ch : t) {
            counter.emplace(ch, 0);
        }
        vector<pair<int, char>> tCharsInS;
        for (int i = 0; i < s.size(); ++i) {
            auto ch = s[i];
            if (counter.find(ch) != counter.end()) {
                tCharsInS.emplace_back(i, ch);
            }
        }

        leetcode::print(counter);
        leetcode::printlnV();
        leetcode::print(tCharsInS);
        leetcode::printlnV();

        int left = 0, right = 0;

        while (right < s.size()) {
            // TODO
        }

        return s.substr(left, right - left);
    }
};
