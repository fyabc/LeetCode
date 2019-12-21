#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-signed-bitwise"
//
// Created by v-yaf on 12/17/2019.
//

#include "support/IO.h"
#include "support/ForwardList.h"

#include <algorithm>
#include <bitset>
#include <iterator>
#include <vector>

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
                } else {
                    previousPositions[depth] = i;
                }
            } else {
                if (depth > 0) {
                    --depth;
                    int maxLenAtI = i - previousPositions[depth];
                    if (maxLenAtI > maxLen)
                        maxLen = maxLenAtI;
                } else {
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
        } else {
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
        auto[rangeBegin, rangeEnd] = equal_range(nums.begin(), nums.end(), target);
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
        bitset<9> flags;

        for (size_t i = 0; i < 9; ++i) {
            flags.reset();
            for (const auto& row: board) {
                char ch = row[i];
                if (ch == '.')
                    continue;
                if (flags[ch2i(ch)])
                    return false;
                flags[ch2i(ch)] = true;
            }
        }
        return true;
    }

    static bool checkGridRepetition(const vector<vector<char>>& board) {
        bitset<9> flags;

        for (size_t i = 0; i < 9; i += 3) {
            for (size_t j = 0; j < 9; j += 3) {
                flags.reset();
                for (size_t ii = 0; ii < 3; ++ii) {
                    for (size_t jj = 0; jj < 3; ++jj) {
                        char ch = board[i + ii][j + jj];
                        if (ch == '.')
                            continue;
                        if (flags[ch2i(ch)])
                            return false;
                        flags[ch2i(ch)] = true;
                    }
                }
            }
        }
        return true;
    }
};

class Solution37 {
    static constexpr int AllOne = (1 << 9) - 1;
    static unordered_map<int, char> Bit2Ch;
public:
    /**
     * Backtrack with bit operations.
     * @param board
     */
    inline static void solveSudoku(vector<vector<char>>& board) {
        vector<int> intBoard(81, 0);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char ch = board[i][j];
                if (ch != '.')
                    intBoard[9 * i + j] = 1 << ch2i(ch);
            }
        }
        solveSudokuBacktrack(intBoard);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                board[i][j] = Bit2Ch[intBoard[9 * i + j]];
            }
        }
    }

private:
    inline static int ch2i(char ch) { return ch - '1'; }

    inline static int pos(int i, int j) { return 9 * i + j; }

    static void solveSudokuBacktrack(vector<int>& intBoard) {
        // Collect all digit constraints.
        vector<int> rowConstraints(9, AllOne);
        vector<int> colConstraints(9, AllOne);
        vector<int> gridConstraints(9, AllOne);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                int digit = intBoard[pos(i, j)];
                if (digit != 0)
                    setConstraints(i, j, digit, rowConstraints, colConstraints, gridConstraints);
            }
        }

        // Collect all candidates.
        vector<pair<int, int>> emptyCells;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (intBoard[pos(i, j)] == 0)
                    emptyCells.emplace_back(i, j);
            }
        }

        backtrack(intBoard, emptyCells, 0, rowConstraints, colConstraints, gridConstraints);
    }

    static bool backtrack(vector<int>& intBoard, const vector<pair<int, int>>& emptyCells, int n,
                          vector<int>& rowConstraints, vector<int>& colConstraints, vector<int>& gridConstraints) {
        if (n >= emptyCells.size())
            return true;
        auto[i, j] = emptyCells[n];
        int allCandidates = candidates(i, j, rowConstraints, colConstraints, gridConstraints);

        while (allCandidates != 0) {
            int nextCandidates = allCandidates & (allCandidates - 1);
            int digit = allCandidates ^nextCandidates;
            allCandidates = nextCandidates;
            intBoard[pos(i, j)] = digit;
            setConstraints(i, j, digit, rowConstraints, colConstraints, gridConstraints);

            // Search next...
            if (backtrack(intBoard, emptyCells, n + 1, rowConstraints, colConstraints, gridConstraints))
                return true;
            // XOR twice to set back.
            setConstraints(i, j, digit, rowConstraints, colConstraints, gridConstraints);
        }
        return false;
    }

    /**
     * Given a new digit, update all constraints.
     * @param i
     * @param j
     * @param digit
     * @param rowConstraints
     * @param colConstraints
     * @param gridConstraints
     */
    inline static void setConstraints(int i, int j, int digit,
                                      vector<int>& rowConstraints, vector<int>& colConstraints,
                                      vector<int>& gridConstraints) {
        rowConstraints[i] ^= digit;
        colConstraints[j] ^= digit;
        gridConstraints[i / 3 * 3 + j / 3] ^= digit;
    }

    /**
     * Calculate all candidates from constraints.
     * @param i
     * @param j
     * @param rowConstraints
     * @param colConstraints
     * @param gridConstraints
     * @return
     */
    inline static int candidates(int i, int j,
                                 const vector<int>& rowConstraints, const vector<int>& colConstraints,
                                 const vector<int>& gridConstraints) {
        return rowConstraints[i] & colConstraints[j] & gridConstraints[i / 3 * 3 + j / 3];
    }

    /**
     * Another solution: use a heap to save all empty cells (with their candidates),
     * always pick cell with least candidates.
     * May be faster or not?
     * @param board
     */
    static void solveSudokuPQ(vector<vector<char>>& board) {}
};

unordered_map<int, char> Solution37::Bit2Ch = {
    {1,   '1'},
    {2,   '2'},
    {4,   '3'},
    {8,   '4'},
    {16,  '5'},
    {32,  '6'},
    {64,  '7'},
    {128, '8'},
    {256, '9'},
};

class Solution38 {
#include "leetcode/problem38numbers.h"

public:
    inline static string countAndSay(int n) {
#define S38_PRINT_TABLE
#ifdef S38_PRINT_TABLE
        return Table[n];
#else
        return countAndSay2(n);
#endif
    }

    static string countAndSay2(int n) {
        string s = "1";
        for (int i = 2; i <= n; ++i) {
            char current = '\0';
            string newS;
            int count = 0;
            for (char ch: s) {
                if (ch == current)
                    ++count;
                else {
                    if (current != '\0') {
                        newS.push_back(i2ch(count));
                        newS.push_back(current);
                    }
                    current = ch;
                    count = 1;
                }
            }
            newS.push_back(i2ch(count));
            newS.push_back(current);
            s = newS;
        }
        return s;
    }

private:
    static char i2ch(int i) { return static_cast<char>(48 + i); }
};

class Solution39 {
public:
    static vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> result;
        vector<int> solution;

        dfs(result, candidates, solution, 0, 0, target);

        return result;
    }

private:
    /**
     * DFS.
     *
     * @param result
     * @param candidates
     * @param lowest: The index of the lowest candidate.
     * @param current
     * @param target
     */
    static void dfs(vector<vector<int>>& result, const vector<int>& candidates, vector<int>& solution,
                    int lowest, int current, int target) {
        if (current == target) {
            result.push_back(solution);
            return;
        }
        for (int i = lowest; i < candidates.size(); ++i) {
            int val = candidates[i];
            if (val + current > target)
                break;
            solution.push_back(val);
            dfs(result, candidates, solution, i, val + current, target);
            solution.pop_back();
        }
    }
};

class Solution40 {
public:
    static vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> result;
        vector<int> solution;

        dfs(result, candidates, solution, 0, 0, target);

        return result;
    }

private:
    /**
     * DFS. Add check to avoid duplication.
     *
     * @param result
     * @param candidates
     * @param solution
     * @param lowest
     * @param current
     * @param target
     */
    static void dfs(vector<vector<int>>& result, const vector<int>& candidates, vector<int>& solution,
                    int lowest, int current, int target) {
        if (current == target) {
            result.push_back(solution);
            return;
        }
        for (int i = lowest; i < candidates.size(); ++i) {
            int val = candidates[i];

            // [NOTE]: If meet same value and the previous is processed, just discard this.
            if (i > lowest && val == candidates[i - 1])
                continue;
            if (val + current > target)
                break;
            solution.push_back(val);
            dfs(result, candidates, solution, i + 1, val + current, target);
            solution.pop_back();
        }
    }
};

#pragma clang diagnostic pop
