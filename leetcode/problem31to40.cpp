//
// Created by v-yaf on 12/17/2019.
//

#include "support/IO.h"
#include "support/ForwardList.h"

#include <bitset>
#include <vector>
#include <algorithm>

using namespace std;

class Solution31 {
public:
    /**
     * Algorithm:
     *              |----------> 1. find longest descent postfix and the corresponding element x (2 here)
     *  [5, 0, *2*, 4, 3, 1]
     *
     *                |--------> 2. find first element y that larger than x (3 here)
     *  [5, 0, 2, 4, *3*, 1]
     *
     *              |------------> 3. swap x and y, then reverse the longest descent postfix.
     *  [5, 0, <3>, 1, <2>, 4]
     *
     * @param nums
     */
    static void nextPermutation(vector<int>& nums) {
        if (nums.empty())
            return;

        auto N = nums.size();

        int i = static_cast<int>(N) - 2;

        for (; i >= 0; --i) {
            if (nums[i] < nums[i + 1])
                break;
        }

        if (i >= 0) {
            int x = nums[i];
            int j = static_cast<int>(N) - 1;
            for (; j > i; --j) {
                if (nums[j] > nums[i])
                    break;
            }
            swap(nums[i], nums[j]);
        }

        reverse(nums.begin() + i + 1, nums.end());
    }
};

class Solution32 {
public:
    /**
     * previousPositions[depth] contains the most left position of the ">= depth" range.
     *
     * i - previousPositions[depth] is the longest length of valid parentheses that ends with i.
     *
     * when meet '(' or excess ')', previousPositions will be updated.
     *
     * @param s
     * @return
     */
    static int longestValidParentheses(const string& s) {
        if (s.empty())
            return 0;

        int maxLen = 0, depth = 0;
        vector<int> previousPositions;
        previousPositions.reserve(s.size());
        previousPositions.push_back(-1);

        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            if (ch == '(') {
                ++depth;
                if (depth >= previousPositions.size()) {
                    previousPositions.push_back(i);
                }
                else {
                    previousPositions[depth] = i;
                }
            }
            else {
                if (depth > 0) {
                    --depth;
                    int maxLenAtI = i - previousPositions[depth];
                    if (maxLenAtI > maxLen)
                        maxLen = maxLenAtI;
                }
                else {
                    previousPositions[0] = i;
                }
            }
        }
        return maxLen;
    }
};

class Solution33 {
public:
    /**
     * Similar to binary search.
     * Two situations: the target in an ordered range (binarySearch) or in a smaller rotated range (searchInRotated).
     * @param nums
     * @param target
     * @return
     */
    static int search(vector<int>& nums, int target) {
        return searchInRotated(nums, target, 0, static_cast<int>(nums.size()) - 1);
    }

private:
    static int searchInRotated(vector<int>& nums, int target, int lo, int hi) {
        if (lo > hi)
            return -1;

        int mid = (lo + hi) / 2;
        int left = nums[lo], right = nums[hi], pivot = nums[mid];
        if (target == pivot)
            return mid;
        if (pivot <= right) {
            if (target > pivot && target <= right)
                return binarySearch(nums, target, mid + 1, hi);
            else
                return searchInRotated(nums, target, lo, mid - 1);
        }
        else {
            if (target < pivot && target >= left)
                return binarySearch(nums, target, lo, mid - 1);
            else
                return searchInRotated(nums, target, mid + 1, hi);
        }
    }
    static int binarySearch(vector<int>& nums, int target, int lo, int hi) {
        while (lo <= hi) {
            int mid = (lo + hi) / 2, pivot = nums[mid];
            if (target == pivot)
                return mid;

            if (target > pivot)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return -1;
    }
};

class Solution34 {
public:
    static vector<int> searchRange(vector<int>& nums, int target) {
        auto [rangeBegin, rangeEnd] = equal_range(nums.begin(), nums.end(), target);
        if (rangeBegin == rangeEnd)
            return {-1, -1};
        return {static_cast<int>(rangeBegin - nums.begin()), static_cast<int>(rangeEnd - nums.begin() - 1)};
    }
};

class Solution35 {
public:
    static int searchInsert(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        return static_cast<int>(it - nums.begin());
    }
};

class Solution36 {
public:
    static bool isValidSudoku(vector<vector<char>>& board) {
        for (const auto& row: board)
            if (!checkRowRepetition(row))
                return false;
        if (!checkColumnRepetition(board))
            return false;
        return checkGridRepetition(board);
    }

private:
    inline static int ch2i(char ch) { return ch - '1'; }

    static bool checkRowRepetition(const vector<char>& row) {
        bitset<9> flags;
        for (char ch: row) {
            if (ch == '.')
                continue;
            if (flags[ch2i(ch)])
                return false;
            flags[ch2i(ch)] = true;
        }
        return true;
    }

    static bool checkColumnRepetition(const vector<vector<char>>& board) {
        return true;
    }
    static bool checkGridRepetition(const vector<vector<char>>& board) {
        return true;
    }
};
