//
// Created by fyabc on 2019/12/21.
//

#include "support/IO.h"

#include <istream>
#include <algorithm>
#include <numeric>

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

        auto result = table[_p(static_cast<int>(len2), static_cast<int>(len1))];

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
    /**
     * Slicing in a filtered window.
     */
public:
    static string minWindow(const string& s, const string& t) {
        // t chars counter
        unordered_map<char, int> counter;
        for (char ch : t) {
            ++counter[ch];
        }
        auto numUniqueChars = static_cast<int>(counter.size());

        // Positions of t chars in s
        vector<pair<int, char>> tCharsInS;
        for (int i = 0; i < s.size(); ++i) {
            auto ch = s[i];
            if (counter.find(ch) != counter.end()) {
                tCharsInS.emplace_back(i, ch);
            }
        }

        int left = 0, right = 0;
        int minWindowSize = -1, minStartPos = 0, minEndPos = 0;
        int numCoveredChars = 0;
        unordered_map<char, int> windowCounter;

        while (right < tCharsInS.size()) {
            auto rightCh = tCharsInS[right].second;

            ++windowCounter[rightCh];

            if (windowCounter[rightCh] == counter[rightCh]) {
                ++numCoveredChars;
            }

            // If current window cover all characters, record it, then move left cursor.
            while (left <= right && numCoveredChars == numUniqueChars) {
                auto leftCh = tCharsInS[left].second;
                auto startPos = tCharsInS[left].first, endPos = tCharsInS[right].first;

                if (minWindowSize == -1 || endPos - startPos + 1 < minWindowSize) {
                    minWindowSize = endPos - startPos + 1;
                    minStartPos = startPos;
                    minEndPos = endPos;
                }

                --windowCounter[leftCh];
                if (windowCounter[leftCh] < counter[leftCh]) {
                    --numCoveredChars;
                }
                ++left;
            }

            ++right;
        }

        if (minWindowSize == -1) {
            return "";
        } else {
            return s.substr(minStartPos, minEndPos - minStartPos + 1);
        }
    }
};

class Solution77 {
public:
    static vector<vector<int>> combine(int n, int k) {
        vector<int> numbers(k);
        iota(numbers.begin(), numbers.end(), n - k + 1);

        vector<vector<int>> result;
        auto hasNext = true;
        while (hasNext) {
            result.push_back(numbers);
            hasNext = nextCombination(numbers);
        }

        return result;
    }

private:
    static bool nextCombination(vector<int>& numbers) {
        int i = 0;
        while (i < numbers.size() && numbers[i] == i + 1) {
            ++i;
        }
        if (i == numbers.size()) {
            // no next
            return false;
        }
        int newValue = numbers[i] - 1;
        for (int j = i; j >= 0; --j) {
            numbers[j] = newValue--;
        }

        return true;
    }
};

class Solution78 {
public:
    static vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;

        vector<bool> used(nums.size(), false);

        auto hasNext = true;
        while (hasNext) {
            result.emplace_back();
            auto& last = result.back();
            for (int i = 0; i < nums.size(); ++i) {
                if (used[i]) {
                    last.push_back(nums[i]);
                }
            }
            hasNext = nextSubset(used);
        }

        return result;
    }

private:
    static bool nextSubset(vector<bool>& used) {
        int i = 0;
        while (i < used.size() && used[i]) {
            ++i;
        }

        if (i == used.size()) {
            // no next
            return false;
        }

        used[i] = true;
        for (int j = i - 1; j >= 0; --j) {
            used[j] = false;
        }

        return true;
    }
};

class Solution79 {
public:
    static bool exist(vector<vector<char>>& board, const string& word) {
        auto M = static_cast<int>(board.size()), N = static_cast<int>(board[0].size());
        vector<vector<bool>> visited(M, vector<bool>(N, false));

        vector<pair<int, int>> startPositions;

        char _ch = word[0];
        for (int i = 0; i < M; ++i) {
            const auto& row = board[i];
            for (int j = 0; j < N; ++j) {
                if (row[j] == _ch) {
                    startPositions.emplace_back(i, j);
                }
            }
        }

        for (const auto& startPos: startPositions) {
            if (DFS(startPos.first, startPos.second, 1, visited, board, M, N, word)) {
                return true;
            }
        }

        return false;
    }

private:
    static bool DFS(int i, int j, int wordPos,
                    vector<vector<bool>>& visited, vector<vector<char>>& board, int M, int N, const string& word) {
        if (wordPos == word.size()) {
            return true;
        }

        visited[i][j] = true;

        char ch = word[wordPos];

        if (i > 0 && board[i - 1][j] == ch && !visited[i - 1][j]) {
            if (DFS(i - 1, j, wordPos + 1, visited, board, M, N, word)) {
                return true;
            }
        }
        if (j > 0 && board[i][j - 1] == ch && !visited[i][j - 1]) {
            if (DFS(i, j - 1, wordPos + 1, visited, board, M, N, word)) {
                return true;
            }
        }
        if (i < M - 1 && board[i + 1][j] == ch && !visited[i + 1][j]) {
            if (DFS(i + 1, j, wordPos + 1, visited, board, M, N, word)) {
                return true;
            }
        }
        if (j < N - 1 && board[i][j + 1] == ch && !visited[i][j + 1]) {
            if (DFS(i, j + 1, wordPos + 1, visited, board, M, N, word)) {
                return true;
            }
        }

        visited[i][j] = false;

        return false;
    }
};

class Solution80 {
public:
    static int removeDuplicates(vector<int>& nums) {
        auto beginIt = nums.begin(), endIt = nums.end();

        // TODO

        return 0;
    }
};
