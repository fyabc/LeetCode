//
// Created by fyabc on 2019/12/21.
//

#include "support/ForwardList.h"
#include "support/IO.h"

#include <algorithm>
#include <istream>
#include <regex>

using namespace std;

class Solution61 {
public:
    static ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr)
            return head;

        auto p = head;
        int N = 0;
        ListNode* newTail, *tail;

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
    static const regex& getPatternFloatNumber() {
        static const regex PatternFloatNumber {R"(^\s*[+-]?(\d+(\.\d*)?|\.\d+)([eE][+-]?\d+)?\s*$)"};
        return PatternFloatNumber;
    }

public:
    inline static bool isNumber(const string& s) {
        return regex_match(s, getPatternFloatNumber());
    }
};

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
        auto split = groupWords(words, maxWidth);

        vector<string> result {};

        int start = 0;
        for (const auto& splitEnd : split) {
            // Get subwords
            vector<string> subwords(words.begin() + start, words.begin() + splitEnd);

            if (splitEnd == words.size()) {
                result.push_back(writeLastLine(subwords, maxWidth));
            } else {
                result.push_back(writeLine(subwords, maxWidth));
            }
            start = splitEnd;
        }

        return result;
    }

    static vector<int> groupWords(const vector<string>& words, int maxWidth) {
        int start = 0, totalLen = 0;
        vector<int> split {};

        int N = static_cast<int>(words.size());
        for (int end = 0; end < N; ++end) {
            int wordLen = static_cast<int>(words[end].size());

            totalLen += wordLen;
            if (end > start) {
                ++totalLen;
            }

            if (totalLen > maxWidth) {
                split.push_back(end);
                totalLen = wordLen;
                start = end;
            }
        }

        split.push_back(N);

        return split;
    }

    static string writeLine(const vector<string>& words, int maxWidth) {
        string result(maxWidth, ' ');

        if (words.size() == 1) {
            copy(words[0].begin(), words[0].end(), result.begin());
            return result;
        }

        int remainSpaces = maxWidth;
        for (const auto& word : words) {
            remainSpaces -= static_cast<int>(word.size());
        }
        auto rightSpace = remainSpaces / (words.size() - 1);
        vector<int> spaces(words.size() - 1, static_cast<int>(rightSpace));
        for (int i = 0; i < remainSpaces % spaces.size(); ++i) {
            ++spaces[i];
        }

        auto copyIter = result.begin();

        for (int i = 0; i < words.size(); ++i) {
            copy(words[i].begin(), words[i].end(), copyIter);

            if (i != words.size() - 1) {
                copyIter += static_cast<decltype(result)::difference_type>(words[i].size()) + spaces[i];
            }
        }

        return result;
    }

    static string writeLastLine(const vector<string>& words, int maxWidth) {
        string result(maxWidth, ' ');

        auto copyIter = result.begin();
        for (const auto& word : words) {
            copy(word.begin(), word.end(), copyIter);
            copyIter += static_cast<decltype(result)::difference_type>(word.size()) + 1;
        }

        return result;
    }
};


class Solution69 {
public:
    static int mySqrt(int x) {
        auto xLL = static_cast<int64_t>(x);
        int64_t lo = 0, hi = 1U << 16U;

        while (hi - lo > 1) {
            auto mid = (lo + hi) / 2, midSqr = mid * mid;
            if (xLL == midSqr) {
                return static_cast<int>(mid);
            } else if (xLL > midSqr) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }

        if (hi * hi <= xLL) {
            return static_cast<int>(hi);
        } else {
            return static_cast<int>(lo);
        }
    }
};


class Solution70 {
    /// f[n] = f[n-1] + f[n-2]
    /// f[1] = 1, f[2] = 2
    static constexpr int Table[] = {
        0,
        1, 2, 3, 5, 8, 13, 21, 34, 55, 89,
        144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946,
        17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269,
        2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986, 102334155, 165580141,
        267914296, 433494437, 701408733, 1134903170, 1836311903,
    };
public:
    static int climbStairs(int n) {
        return Table[n];
    }
};
