//
// Created by fyabc on 2021/3/12.
//

#include "support/IO.h"

#include <algorithm>
#include <numeric>
#include <vector>
#include <unordered_map>

using namespace std;


class WC224Q2_Problem1726 {
    /**
     * WC224Q2_Problem1726: https://leetcode.com/contest/weekly-contest-224/problems/tuple-with-same-product/
     *
     * Solution: count all product values.
     */
public:
    static int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> products;

        for (int i = 0; i < nums.size() - 1; ++i) {
            auto ni = nums[i];
            for (int j = i + 1; j < nums.size(); ++j) {
                ++products[ni * nums[j]];
            }
        }

        // Result = sum(4n(n-1))
        auto result = 4 * accumulate(
            products.begin(), products.end(), 0,
            [](int sum, const pair<int, int>& item) {
                return sum + item.second * (item.second - 1);
            });

        return result;
    }
};


class WC224Q3_Problem1727 {
    /**
     * WC224Q3_Problem1727: https://leetcode.com/contest/weekly-contest-224/problems/largest-submatrix-with-rearrangements/
     *
     * Solution: calculate the height of each cell.
     */
public:
    static int largestSubmatrix(vector<vector<int>>& matrix) {
        // 1. Calculate "height" of each cell.
        for (int i = 1; i < matrix.size(); ++i) {
            auto& row = matrix[i];
            for (int j = 0; j < row.size(); ++j) {
                if (row[j] != 0) {
                    row[j] = matrix[i - 1][j] + 1;
                }
            }
        }

        int result = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            auto& row = matrix[i];
            sort(row.begin(), row.end());

            auto N = static_cast<int>(row.size());
            for (int j = 0; j < N; ++j) {
                int thisResult = (N - j) * row[j];
                if (thisResult > result) {
                    result = thisResult;
                }
            }
        }
        return result;
    }
};


class WC225Q2_Problem1737 {
    /**
     * WC225Q2_Problem1737: https://leetcode.com/contest/weekly-contest-225/problems/change-minimum-characters-to-satisfy-one-of-three-conditions/
     *
     * Solution: count all (a <= ch && b > ch) and (a > ch && b <= ch) and condition 3.
     */
public:
    static int minCharacters(const string& a, const string& b) {
        auto M = static_cast<int>(a.size()), N = static_cast<int>(b.size());
        auto totalSize = static_cast<int>(a.size() + b.size());

        vector<int> charCounter(charMax, 0), charCounterA(charMax, 0), charCounterB(charMax, 0);

        for (char ch : a) {
            ++charCounterA[char2Idx(ch)];
            ++charCounter[char2Idx(ch)];
        }
        for (char ch : b) {
            ++charCounterB[char2Idx(ch)];
            ++charCounter[char2Idx(ch)];
        }
        int cond3Steps = totalSize - *max_element(charCounter.begin(), charCounter.end());

        int cond1Steps = totalSize, cond2Steps = totalSize;
        int numLessEqualA = 0, numLessEqualB = 0;
        for (int i = 0; i < charMax - 1; ++i) {
            numLessEqualA += charCounterA[i];
            numLessEqualB += charCounterB[i];

            int newCond1Steps = numLessEqualB + (M - numLessEqualA);
            int newCond2Steps = numLessEqualA + (N - numLessEqualB);

            if (newCond1Steps < cond1Steps) {
                cond1Steps = newCond1Steps;
            }
            if (newCond2Steps < cond2Steps) {
                cond2Steps = newCond2Steps;
            }
        }

        return min({cond1Steps, cond2Steps, cond3Steps});
    }

private:
    static constexpr int charMax = 26;
    static constexpr size_t char2Idx(char ch) {
        return static_cast<size_t>(ch - 'a');
    }
};


class WC225Q3_Problem1738 {
    /**
     * WC225Q3_Problem1738: https://leetcode.com/contest/weekly-contest-225/problems/find-kth-largest-xor-coordinate-value/
     *
     * Solution: result[i,j] = result[i-1,j-1] ^ result[i-1,j] ^ result[i,j-1] ^ result[i,j]
     */
public:
    static int kthLargestValue(vector<vector<int>>& matrix, int k) {
        vector<int> values(matrix.size() * matrix[0].size());

        auto& row0 = matrix[0];
        values.push_back(row0[0]);

        for (int j = 1; j < row0.size(); ++j) {
            row0[j] = row0[j - 1] ^ row0[j];
            values.push_back(row0[j]);
        }

        for (int i = 1; i < matrix.size(); ++i) {
            auto& row = matrix[i];

            row[0] = matrix[i - 1][0] ^ row[0];
            values.push_back(row[0]);

            for (int j = 1; j < row.size(); ++j) {
                row[j] = matrix[i - 1][j - 1] ^ matrix[i - 1][j] ^ row[j - 1] ^ row[j];
                values.push_back(row[j]);
            }
        }

        if (k <= values.size() / 2) {
            auto nthIter = values.begin() + k - 1;
            nth_element(values.begin(), nthIter, values.end(), std::greater<int>());
            return *nthIter;
        } else {
            auto nthIter = values.begin() + values.size() - k;
            nth_element(values.begin(), nthIter, values.end());
            return *nthIter;
        }
    }
};