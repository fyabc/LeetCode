//
// Created by fyabc on 2019/12/21.
//

#include <algorithm>
#include <numeric>

using namespace std;

class Solution51 {
public:
    static vector<vector<string>> solveNQueens(int n) {
        vector<int> vec(n, -1);
        vector<vector<string>> result;

        backtrack(vec, result, 0, n);

        return result;
    }

private:
    static void backtrack(vector<int>& vec, vector<vector<string>>& result, int depth, int n) {
        if (depth == n) {
            result.push_back(solutionFromVector(vec, n));
            return;
        }

        for (int pos = 0; pos < n; ++pos) {
            bool hasConflict = false;
            vec[depth] = pos;
            for (int j = 0; j < depth; ++j) {
                if (conflict(depth, j, vec)) {
                    hasConflict = true;
                    break;
                }
            }
            if (hasConflict)
                continue;
            backtrack(vec, result, depth + 1, n);
        }
    }

    inline static bool conflict(int i, int j, vector<int>& vec) {
        auto pi = vec[i], pj = vec[j];
        return (pi == pj || abs(i - j) == abs(pi - pj));
    }

    static vector<string> solutionFromVector(const vector<int>& vec, int n) {
        vector<string> result;
        for (int pos: vec) {
            string s(n, '.');
            s[pos] = 'Q';
            result.push_back(move(s));
        }
        return result;
    }
};

class Solution52 {
public:
    static int totalNQueens(int n) {
        vector<int> vec(n, -1);
        int result = 0;

        backtrack(vec, result, 0, n);
        return result;
    }

private:
    static void backtrack(vector<int>& vec, int& result, int depth, int n) {
        if (depth == n) {
            ++result;
            return;
        }

        for (int pos = 0; pos < n; ++pos) {
            bool hasConflict = false;
            vec[depth] = pos;
            for (int j = 0; j < depth; ++j) {
                if (conflict(depth, j, vec)) {
                    hasConflict = true;
                    break;
                }
            }
            if (hasConflict)
                continue;
            backtrack(vec, result, depth + 1, n);
        }
    }

    inline static bool conflict(int i, int j, vector<int>& vec) {
        auto pi = vec[i], pj = vec[j];
        return (pi == pj || abs(i - j) == abs(pi - pj));
    }
};

class Solution53 {
public:

#define S53_USE_DP

#ifdef S53_USE_DP
    /**
     * DP.
     *
     *  maxSumEndsWithI = max(sum(nums[x..i]) for x in 0..i).
     *
     * State transition equation:
     *  maxSumEndsWith[i] = {
     *      nums[i], if maxSumEndsWith[i - 1] <= 0;
     *      nums[i] + maxSumEndsWith[i - 1], else.
     *  }
     *
     * @param nums
     * @return
     */
    static int maxSubArray(vector<int>& nums) {
        if (nums.empty())
            return numeric_limits<int>::min();

        auto N = nums.size();
        int result = nums[0], maxSumEndsWithI = nums[0];

        for (int i = 1; i < N; ++i) {
            if (maxSumEndsWithI <= 0)
                maxSumEndsWithI = nums[i];
            else
                maxSumEndsWithI += nums[i];
            if (maxSumEndsWithI > result)
                result = maxSumEndsWithI;
        }

        return result;
    }
#else
    /**
     * Divide and conquer.
     *
     * maxSum(lo, hi) = max(maxSum(lo, mid), maxSum(mid, hi), maxSumLeftEndsWith(mid) + maxSumRightStartsWith(mid+1))
     *
     * @param nums
     * @return
     */
    static int maxSubArray(vector<int>& nums) {
        if (nums.empty())
            return numeric_limits<int>::min();

        auto N = nums.size();
        return dfs(nums, 0, static_cast<int>(N) - 1);
    }

private:
    static int dfs(vector<int>& nums, int lo, int hi) {
        if (lo > hi)
            return 0;
        if (lo == hi)
            return nums[lo];
        int mid = (lo + hi) / 2;

        int leftMaxSum = nums[mid], leftSum = 0;
        for (int i = mid; i >= lo; --i) {
            leftSum += nums[i];
            if (leftSum > leftMaxSum)
                leftMaxSum = leftSum;
        }

        int rightMaxSum = nums[mid + 1], rightSum = 0;
        for (int j = mid + 1; j <= hi; ++j) {
            rightSum += nums[j];
            if (rightSum > rightMaxSum)
                rightMaxSum = rightSum;
        }

        int acrossMaxSum = leftMaxSum + rightMaxSum;

        return max(max(dfs(nums, lo, mid), dfs(nums, mid + 1, hi)), acrossMaxSum);
    }

#endif
};

class Solution54 {
public:
    static vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return {};
        if (matrix[0].empty())
            return {};

        auto M = matrix.size(), N = matrix[0].size();

        vector<int> result;

        return result;
    }
};
