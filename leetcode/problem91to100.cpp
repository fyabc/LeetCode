//
// Created by fyabc on 2019/12/21.
//

#include "support/Debugging.h"
#include "support/ForwardList.h"
#include "support/BinaryTree.h"

#include <vector>

using namespace std;


class Solution91 {
    /**
     * DP.
     */
public:
    static int numDecodings(const string& s) {
        auto N = static_cast<int>(s.size());

        vector<int> DP(N + 1, 0);
        DP[0] = 1;
        DP[1] = canFit1(s[0]);

        for (int i = 2; i <= N; ++i) {
            if (canFit1(s[i - 1])) {
                DP[i] += DP[i - 1];
            }
            if (canFit2(s[i - 2], s[i - 1])) {
                DP[i] += DP[i - 2];
            }
        }

        return DP[N];
    }

private:
    static inline bool canFit1(char c) {
        return c != '0';
    }

    static inline bool canFit2(char c1, char c2) {
        return c1 == '1' || (c1 == '2' && c2 <= '6');
    }
};

class Solution92 {
    /**
     * Reverse node in-place.
     */
public:
    static ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* cur = head, *prev = nullptr;

        while (left > 1) {
            prev = cur;
            cur = cur->next;
            --left;
            --right;
        }

        // The two pointers that will fix the final connections.
        ListNode* tail = cur, *con = prev, *tmp = nullptr;

        while (right) {
            tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
            --right;
        }

        if (con != nullptr) {
            con->next = prev;
        } else {
            head = prev;
        }
        tail->next = cur;

        return head;
    }
};

class Solution93 {
    /**
     * DP (Memorized DFS).
     */
public:
    static vector<string> restoreIpAddresses(const string& s) {
        auto N = static_cast<int>(s.size());

        vector<int> tmp = {-1, -1, -1};
        vector<vector<int>> DP(N, tmp);

        vector<string> results;
        vector<int> current;

        DFS(s, current, 0, DP, results);

        return results;
    }

    static void DFS(const string& s, vector<int>& current, int pos, vector<vector<int>>& DP, vector<string>& results) {
        if (pos >= s.size()) {
            return;
        }
        if (current.size() == 3) {
            // Check last part
            if (checkValid(s, pos, static_cast<int>(s.size()) - pos, DP)) {
                // Success
                results.push_back(makeResult(s, current));
            }
            return;
        }
        for (int i = 1; i < 4; ++i) {
            if (checkValid(s, pos, i, DP)) {
                current.push_back(pos + i);
                DFS(s, current, pos + i, DP, results);
                current.pop_back();
            }
        }
    }

    static string makeResult(const string& s, const vector<int>& current) {
        return s.substr(0, current[0]) + "." + s.substr(current[0], current[1] - current[0]) +
            "." + s.substr(current[1], current[2] - current[1]) + "." + s.substr(current[2]);
    }

    static bool checkValid(const string& s, int l, int n, vector<vector<int>>& DP) {
        if (n >= 4 || n <= 0 || l + n > s.size()) {
            return false;
        }
        int cachedResult = DP[l][n - 1];
        if (cachedResult == -1) {
            cachedResult = DP[l][n - 1] = valid(s, l, n);
        }
        return cachedResult == 1;
    }

private:
    /**
     * Check if s[l:r] is a valid number between 0 ~ 255.
     * @param s
     * @param l: start position.
     * @param n: number of digits.
     * @return
     */
    inline static bool valid(const string& s, int l, int n) {
        if (n >= 4 || n <= 0 || l + n > s.size()) {
            return false;
        }
        if (n == 1) {
            return true;
        }
        if (n == 2) {
            return s[l] != '0';
        }
        return s[l] == '1' || (
            s[l] == '2' && (
                s[l + 1] < '5' || (
                    s[l + 1] == '5' && s[l + 2] < '6'
                    )));
    }
};

class Solution94 {
public:
    static vector<int> inorderTraversal(TreeNode* root) {
//#define PROBLEM94ITERATIVE
#ifdef PROBLEM94ITERATIVE
        return inorderTraversalIter(root);
#else
        vector<int> result;

        if (root == nullptr) {
            return result;
        }

        doInorderTraversal(root, result);

        return result;
#endif
    }

private:
    static void doInorderTraversal(TreeNode* root, vector<int>& result) {
        if (root->left != nullptr) {
            doInorderTraversal(root->left, result);
        }
        result.push_back(root->val);
        if (root->right != nullptr) {
            doInorderTraversal(root->right, result);
        }
    }

public:
    /**
     * Iterative version (Morris method, threaded binary tree).
     * See <https://leetcode.com/problems/binary-tree-inorder-traversal/solution/> for more details.
     * @param root
     * @return
     */
    static vector<int> inorderTraversalIter(TreeNode* root) {
        vector<int> result;

        if (root == nullptr) {
            return result;
        }

        TreeNode* cur = root, *prev;

        while (cur != nullptr) {
            if (cur->left == nullptr) {
                // Left most node.
                result.push_back(cur->val);
                cur = cur->right;
            } else {
                // prev is the rightmost node of the left subtree (prev node)
                prev = cur->left;
                while (prev->right != nullptr) {
                    prev = prev->right;
                }
                prev->right = cur;      // put cur after the pre node
                TreeNode* tmp = cur;    // store cur node
                cur = cur->left;        // move cur to the top of the new tree
                tmp->left = nullptr;    // original cur left be null, avoid infinite loops
            }
        }

        return result;
    }
};
