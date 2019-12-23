//
// Created by fyabc on 2019/12/21.
//

#include <algorithm>

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
    static int maxSubArray(vector<int>& nums) {
        return 0;
    }
};
