//
// Created by fyabc on 2019/12/21.
//

#include "support/IO.h"

#include <algorithm>
#include <vector>

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

        [[nodiscard]] string toString() const {
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
        BigInteger a {num1}, b {num2}, c;

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
    static bool isMatch(const string& s, const string& p) {
        auto M = s.size(), N = p.size();
        // dp[i, j] indicates if s[:i] and p[:j] match.
        bool* dp = new bool[(M + 1) * (N + 1)];
        fill(dp, dp + ((M + 1) * (N + 1)), false);
        dp[0] = true;

        for (int i = -1; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
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
