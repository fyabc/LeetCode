//
// Created by fyabc on 2019/12/21.
//

#include "support/IO.h"

#include <algorithm>
#include <numeric>
#include <vector>
#include <cmath>

using namespace std;

class Solution41 {
public:
    static int firstMissingPositive(vector<int>& nums) {
//#define S41_SLOW_SOLUTION
#ifdef S41_SLOW_SOLUTION
        return slowSolution(nums);
#else
        return fastSolution(nums);
#endif
    }

private:
    /**
     * Fast solution based on buckets.
     * See https://blog.csdn.net/feliciafay/article/details/42290231.
     *
     * NOTE:
     *  Runtime = 4ms, faster than 66.50%
     *  Memory = 8.8MB, less than 50%
     *  See https://leetcode.com/submissions/detail/287803161/.
     *
     * @param nums
     * @return
     */
    static int fastSolution(vector<int>& nums) {
        int N = static_cast<int>(nums.size()), i = 0;
        while (i < N) {
            int num = nums[i];
            // The last two condition to avoid endless loop
            if (num > 0 && num <= N && num - 1 != i && nums[num - 1] != num)
                // Swap num to index [num - 1].
                swap(nums[i], nums[num - 1]);
            else
                ++i;
        }
        for (int j = 0; j < N; ++j) {
            if (nums[j] != j + 1)
                return j + 1;
        }
        return N + 1;
    }

    /**
     * Slow solution based on sort.
     *
     * NOTE:
     *  Runtime = 0ms, faster than 100%
     *  Memory = 8.8MB, less than 50%
     *  See https://leetcode.com/submissions/detail/287796222/.
     *
     * @param nums
     * @return
     */
    static int slowSolution(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int prev = 0;
        for (int num: nums) {
            if (num <= 0)
                continue;
            if (num > prev + 1)
                return prev + 1;
            prev = num;
        }
        return prev + 1;
    }
};

class Solution42 {
public:
    /**
     * Algorithm:
     *  1. Find the max element index M;
     *  2. Scan from left and right to M, accumulate water count.
     *
     * @param height
     * @return
     */
    static int trap(vector<int>& height) {
        if (height.size() <= 1)
            return 0;

        int water = 0;
        int maxPos = static_cast<int>(max_element(height.begin(), height.end()) - height.begin());

        int maxHL = 0;
        for (int l = 0; l != maxPos; ++l) {
            int h = height[l];
            if (h > maxHL)
                maxHL = h;
            else
                water += (maxHL - h);
        }
        int maxHR = 0;
        for (int r = static_cast<int>(height.size()) - 1; r != maxPos; --r) {
            int h = height[r];
            if (h > maxHR)
                maxHR = h;
            else
                water += (maxHR - h);
        }
        return water;
    }
};

class Solution43 {
    struct BigInteger {
        vector<int> digits;

        BigInteger() = default;

        explicit BigInteger(const string& s) {
            for (char ch: s)
                digits.push_back(ch2i(ch));
            reverse(digits.begin(), digits.end());
        }

        void normalize() {
            int carry = 0;
            for (int& digit : digits) {
                digit += carry;
                carry = digit / 10;
                digit %= 10;
            }
            while (carry > 0) {
                digits.push_back(carry / 10);
                carry %= 10;
            }
        }

        string toString() const {
            string result;
            bool leadingZero = true;
            for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
                int digit = *it;
                if (digit != 0)
                    leadingZero = false;
                if (!leadingZero)
                    result.push_back(i2ch(digit));
            }
            if (result.empty())
                result.push_back('0');
            return result;
        }
    };

public:
    static string multiply(const string& num1, const string& num2) {
        BigInteger a{num1}, b{num2}, c;

        c.digits.resize(a.digits.size() + b.digits.size());

        for (int i = 0; i < a.digits.size(); ++i) {
            for (int j = 0; j < b.digits.size(); ++j) {
                c.digits[i + j] += a.digits[i] * b.digits[j];
            }
        }

        c.normalize();

        return c.toString();
    }

private:
    inline static int ch2i(char ch) { return ch - '0'; }

    inline static char i2ch(int i) { return static_cast<char>('0' + i); }
};

class Solution44 {
public:
    /**
     * DP.
     *
     *  dp[i, j] indicates if s[:i] and p[:j] match.
     *  dp[i+1, j+1] == true iff:
     *      (dp[i, j] == true and match(s[i], p[j])) or
     *      (p[j] == '*' and dp[i, j+1] == true) or
     *      (p[j] == '*' and dp[i+1, j] == true)
     *
     * @param s
     * @param p
     * @return
     */
    static bool isMatch(const string& s, const string& p) {
        auto M = s.size(), N = p.size();
        bool* dp = new bool[(M + 1) * (N + 1)];
        fill(dp, dp + ((M + 1) * (N + 1)), false);
        dp[0] = true;

        for (int j = 0; j < N; ++j) {
            if (p[j] != '*')
                break;
            dp[pos(0, j + 1, N)] = true;
        }

        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                char si = s[i], pj = p[j];

                if (pj == '*')
                    dp[pos(i + 1, j + 1, N)] = dp[pos(i, j, N)] || dp[pos(i, j + 1, N)] || dp[pos(i + 1, j, N)];
                else {
                    bool firstMatch = (si == pj || pj == '?');
                    dp[pos(i + 1, j + 1, N)] = dp[pos(i, j, N)] && firstMatch;
                }
            }
        }

        bool result = dp[M * N + M + N];
        delete[] dp;

        return result;
    }

private:
    inline static string::size_type pos(int m, int n, string::size_type N) {
        return m * (N + 1) + n;
    }
};

class Solution45 {
public:
    /**
     * Scan from left to right to calculate the jump sources of each position.
     * `jumpSources[i]' means the most left position that can jump to `i'.
     *
     * Then jump from the last index back to the first to count steps.
     *
     * @param nums
     * @return
     */
    static int jump(vector<int>& nums) {
        int N = static_cast<int>(nums.size());

        vector<int> jumpSources(N);
        iota(jumpSources.begin(), jumpSources.end(), 0);

        int currentRightMost = 0;
        for (int i = 0; i < N; ++i) {
            int newRight = min(nums[i] + i, N - 1);
            if (newRight > currentRightMost) {
                for (int j = currentRightMost + 1; j <= newRight; ++j)
                    jumpSources[j] = i;
                currentRightMost = newRight;
                if (currentRightMost >= N - 1)
                    break;
            }
        }

        int pos = N - 1, count = 0;
        while (pos > 0) {
            pos = jumpSources[pos];
            ++count;
        }
        return count;
    }
};

class Solution46 {
public:
    /**
     * See solution 31.
     *
     * @param nums
     * @return
     */
    static vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty())
            return {{}};
        if (nums.size() == 1)
            return {nums};

        sort(nums.begin(), nums.end());
        int N = static_cast<int>(nums.size());

        vector<vector<int>> result;

        for (;;) {
            result.push_back(nums);

            int i = N - 2;

            for (; i >= 0; --i) {
                if (nums[i] < nums[i + 1])
                    break;
            }

            if (i >= 0) {
                int x = nums[i];
                int j = N - 1;
                for (; j > i; --j) {
                    if (nums[j] > nums[i])
                        break;
                }
                swap(nums[i], nums[j]);
            } else
                break;

            reverse(nums.begin() + i + 1, nums.end());
        }

        return result;
    }
};

class Solution47 {
public:
    inline static vector<vector<int>> permuteUnique(vector<int>& nums) {
        return Solution46::permute(nums);
    }
};

class Solution48 {
public:
    static void rotate(vector<vector<int>>& matrix) {
        auto N = matrix.size(), H = N / 2;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < H; ++j) {
                permute4(matrix[i][j], matrix[j][N - 1 - i],
                         matrix[N - 1 - i][N - 1 - j], matrix[N - 1 - j][i]);
            }
        }
        if (N % 2 != 0) {
            for (int i = 0; i < H; ++i) {
                permute4(matrix[i][H], matrix[H][N - 1 - i], matrix[N - 1 - i][H], matrix[H][i]);
            }
        }
    }

private:
    inline static void permute4(int& a, int& b, int& c, int& d) {
        int t = d;
        d = c;
        c = b;
        b = a;
        a = t;
    }
};

class Solution49 {
public:
    static vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;

        // Faster than use char multiset as keys.
        unordered_map<string, decltype(result.size())> table;

        for (const string& s: strs) {
            string s1 {s};
            sort(s1.begin(), s1.end());
            auto it = table.find(s1);
            if (it == table.end()) {
                table.insert(it, make_pair(std::move(s1), result.size()));
                result.push_back({s});
            } else {
                result[it->second].push_back(s);
            }
        }

        return result;
    }
};

class Solution50 {
    static constexpr unsigned long long BitMask = 1ULL << (8 * sizeof(unsigned long long) - 1);
public:
    static double myPow(double x, int n) {
        auto n2 = static_cast<long long>(n);
        if (n2 < 0) {
            x = 1.0 / x;
            n2 = -n2;
        }
        auto n2u = static_cast<unsigned long long>(n2);

        double result = 1.0;

        for (auto mask = BitMask; mask != 0; mask >>= 1U) {
            if (result != 1.0)
                result *= result;
            if (n2u & mask)
                result *= x;
        }

        return result;
    }

    static double myPowFast(double x, int n) {
        return pow(x, n);
    }
};
