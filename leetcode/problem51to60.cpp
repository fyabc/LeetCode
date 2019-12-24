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

        int xMin = 0, xMax = static_cast<int>(M) - 1, yMin = 0, yMax = static_cast<int>(N) - 1;

        while (xMin <= xMax && yMin <= yMax) {
            writeCycle(xMin, xMax, yMin, yMax, matrix, result);
            ++xMin, --xMax, ++yMin, --yMax;
        }

        return result;
    }

private:
    inline static void writeCycle(int xMin, int xMax, int yMin, int yMax,
                                  vector<vector<int>>& matrix, vector<int>& result) {
        for (int j = yMin; j <= yMax; ++j)
            result.push_back(matrix[xMin][j]);
        for (int i = xMin + 1; i <= xMax; ++i)
            result.push_back(matrix[i][yMax]);
        if (xMax != xMin) {
            for (int j = yMax - 1; j >= yMin; --j)
                result.push_back(matrix[xMax][j]);
        }
        if (yMax != yMin) {
            for (int i = xMax - 1; i > xMin; --i)
                result.push_back(matrix[i][yMin]);
        }
    }
};

class Solution55 {
public:
    static bool canJump(vector<int>& nums) {
        int N = static_cast<int>(nums.size());

        vector<int> jumpSources(N);
        iota(jumpSources.begin(), jumpSources.end(), 0);

        int currentRightMost = 0;
        for (int i = 0; i < N - 1; ++i) {
            if (currentRightMost < i)
                return false;
            int newRight = min(nums[i] + i, N - 1);
            if (newRight > currentRightMost) {
                for (int j = currentRightMost + 1; j <= newRight; ++j)
                    jumpSources[j] = i;
                currentRightMost = newRight;
                if (currentRightMost >= N - 1)
                    return true;
            }
        }
        return (currentRightMost >= N - 1);
    }
};

class Solution56 {
public:
    static vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return {};

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        vector<int> current = move(intervals[0]);

        int i = 1;
        while (i < intervals.size()) {
            while (i < intervals.size() && intervals[i][0] <= current[1]) {
                current[1] = max(current[1], intervals[i][1]);
                ++i;
            }
            result.push_back(move(current));
            if (i >= intervals.size())
                return result;
            current = move(intervals[i]);
            ++i;
        }
        result.push_back(move(current));

        return result;
    }
};

class Solution57 {
    static auto intervalBinarySearch(vector<vector<int>>& intervals, int value,
                                     vector<int>::size_type lo, vector<int>::size_type hi) {
        while (hi - lo > 1) {
            auto mid = (lo + hi) / 2;
            int pivot = getValue(intervals, mid);
            if (value == pivot) {
                return make_pair(mid, mid);
            } else if (value < pivot) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        return make_pair(lo, hi);
    }
public:
    /**
     * Apply binary search on the left and right of the new interval.
     *
     * @param intervals
     * @param newInterval
     * @return
     */
    static vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty())
            return {newInterval};
        auto N = intervals.size();
        int left = newInterval[0], right = newInterval[1];
        int mergeL, mergeR;
        vector<int> mergedInterval {left, right};

        if (left > intervals[N - 1][1]) {
            mergeL = mergeR = static_cast<int>(N);
        } else if (right < intervals[0][0]) {
            mergeL = mergeR = -1;
        } else {
            if (left <= intervals[0][0]) {
                mergeL = 0U;
            } else {
                auto hiL = intervalBinarySearch(intervals, left, 0, 2 * N - 1).second;
                mergeL = static_cast<int>(hiL >> 1U);
                if ((hiL & 1U) == 1U) {
                    // in an interval, extend left
                    mergedInterval[0] = intervals[mergeL][0];
                }
            }

            if (right >= intervals.back()[1]) {
                mergeR = static_cast<int>(N) - 1;
            } else {
                // An optimization: search from left position, not from 0.
                auto loR = intervalBinarySearch(intervals, right, max(0, 2 * mergeL - 2), 2 * N - 1).first;
                mergeR = static_cast<int>(loR >> 1U);
                if ((loR & 1U) == 0U) {
                    // in an interval, extend right
                    mergedInterval[1] = intervals[mergeR][1];
                }
            }
        }

        vector<vector<int>> result;
        result.reserve(max(0, mergeL));
        for (int i = 0; i < mergeL; ++i)
            result.push_back(move(intervals[i]));
        result.push_back(move(mergedInterval));
        for (int i = mergeR + 1; i < N; ++i)
            result.push_back(move(intervals[i]));

        return result;
    }

private:
    inline static int getValue(vector<vector<int>>& intervals, vector<int>::size_type index) {
        return intervals[index >> 1U][index & 1U];
    }
};

class Solution58 {
public:
    static int lengthOfLastWord(const string& s) {
        int N = static_cast<int>(s.size());
        int i = N - 1;
        for (; i >= 0 && s[i] == ' '; --i);
        if (i < 0)
            return 0;
        int length = 0;
        for (; i >= 0 && s[i] != ' '; --i, ++length);
        return length;
    }
};

class Solution59 {
public:
    static vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        int xMin = 0, xMax = n - 1, yMin = 0, yMax = n - 1;
        int start = 1;

        while (xMin <= xMax && yMin <= yMax) {
            writeCycle(xMin, xMax, yMin, yMax, result, start);
            ++xMin, --xMax, ++yMin, --yMax;
        }

        return result;
    }

private:
    static void writeCycle(int xMin, int xMax, int yMin, int yMax,
                           vector<vector<int>>& matrix, int& start) {
        for (int j = yMin; j <= yMax; ++j)
            matrix[xMin][j] = start++;
        for (int i = xMin + 1; i <= xMax; ++i)
            matrix[i][yMax] = start++;
        // No need to check xMax != xMin, yMax != yMin here.
        for (int j = yMax - 1; j >= yMin; --j)
            matrix[xMax][j] = start++;
        for (int i = xMax - 1; i > xMin; --i)
            matrix[i][yMin] = start++;
    }
};

class Solution60 {
    static constexpr int Factorials[] = {
        1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800,
    };
public:
    static string getPermutation(int n, int k) {
        int i = n - 1;
        string result;
        vector<char> chars(n);
        iota(chars.begin(), chars.end(), '1');

        while (true) {
            int value = k / Factorials[i];
            if (k % Factorials[i] != 0)
                ++value;
            result.push_back(chars[value - 1]);
            chars.erase(chars.begin() + value - 1);

            k %= Factorials[i];
            if (k == 0) {
                result.append(chars.rbegin(), chars.rend());
                break;
            }
            --i;
        }
        return result;
    }
};
