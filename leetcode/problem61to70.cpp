//
// Created by fyabc on 2019/12/21.
//

#include "support/ForwardList.h"
#include "support/IO.h"

#include <algorithm>
#include <bitset>
#include <regex>

using namespace std;

class Solution61 {
public:
    static ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr)
            return head;

        auto p = head;
        int N = 0;
        ListNode* newTail = nullptr, *tail = nullptr;

        for (; p != nullptr; p = p->next, ++N)
            tail = p;

        k %= N;
        if (k == 0)
            return head;

        newTail = head;
        for (int i = 0; i < N - k - 1; ++i)
            newTail = newTail->next;

        auto newHead = newTail->next;

        tail->next = head;
        newTail->next = nullptr;

        return newHead;
    }
};


class Solution62 {
public:
    static int uniquePaths(int m, int n) {
        return combination(m + n - 2, max(m - 1, n - 1));
    }

private:
    static int combination(int m, int n) {
        long long r = 1;
        for (long long i = n + 1; i <= m; ++i) {
            r *= i;
            r /= (i - n);
        }
        return static_cast<int>(r);
    }
};

class Solution63 {
public:
    static int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty())
            return 0;
        if (obstacleGrid[0].empty())
            return 0;

        auto M = obstacleGrid.size(), N = obstacleGrid[0].size();

        vector<long long> rowValues(N, 0);

        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (obstacleGrid[i][j] == 1)
                    rowValues[j] = 0;
                else {
                    if (i == 0) {
                        if (j == 0)
                            rowValues[j] = 1;
                        else
                            rowValues[j] = rowValues[j - 1];
                    } else {
                        if (j == 0) {
                            // Do nothing
                        } else
                            rowValues[j] += rowValues[j - 1];
                    }
                }
            }
        }

        return static_cast<int>(rowValues[N - 1]);
    }
};

class Solution64 {
public:
    static int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;
        if (grid[0].empty())
            return 0;

        auto M = grid.size(), N = grid[0].size();

        vector<int> rowValues(N, 0);

        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == 0) {
                    if (j == 0)
                        rowValues[j] = grid[i][j];
                    else
                        rowValues[j] = rowValues[j - 1] + grid[i][j];
                } else {
                    if (j == 0)
                        rowValues[j] += grid[i][j];
                    else
                        rowValues[j] = min(rowValues[j], rowValues[j - 1]) + grid[i][j];
                }
            }
        }

        return rowValues[N - 1];
    }
};

class Solution65 {
    static const regex PatternFloatNumber;
public:
    inline static bool isNumber(const string& s) {
        return regex_match(s, PatternFloatNumber);
    }
};

const regex Solution65::PatternFloatNumber {R"(^\s*[+-]?(\d+(\.\d*)?|\.\d+)([eE][+-]?\d+)?\s*$)"};

class Solution66 {
public:
    static vector<int> plusOne(vector<int>& digits) {
        int N = static_cast<int>(digits.size());
        int v = 1;
        for (int i = N - 1; i >= 0; --i) {
            digits[i] += v;
            if (digits[i] >= 10) {
                digits[i] = 0;
                v = 1;
            } else {
                v = 0;
                break;
            }
        }
        if (v != 0) {
            digits.insert(digits.begin(), v);
        }
        return digits;
    }
};


class Solution67 {
    static constexpr char Int2Char[] = {'0', '1'};
public:
    static string addBinary(const string& a, const string& b) {
        auto M = a.size(), N = b.size();
        string result(max(M, N) + 1, '0');
        int v = 0;
        for (int i = 0; i < result.size(); ++i) {
            int val = ch2i(i >= M ? '0' : a[M - 1 - i]) + ch2i(i >= N ? '0' : b[N - 1 - i]) + v;
            if (val >= 2) {
                val -= 2;
                v = 1;
            } else
                v = 0;
            result[i] = Int2Char[val];
        }
        auto it = result.rbegin();
        while (*it == '0') ++it;
        if (it == result.rend())
            return "0";
        return string(it, result.rend());
    }

private:
    static int ch2i(char ch) {
        return ch - '0';
    }
};

class Solution68 {
public:
    static vector<string> fullJustify(vector<string>& words, int maxWidth) {
        return {};
    }
};
