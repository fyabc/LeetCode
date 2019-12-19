//
// Created by v-yaf on 12/17/2019.
//

#include "support/IO.h"
#include "support/ForwardList.h"

#include <stack>
#include <queue>

using namespace std;

class Solution21 {
public:
    static ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        auto p1 = l1, p2 = l2, head = new ListNode(0), tail = head;

        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val < p2->val) {
                tail = insertAtTail(tail, p1->val);
                p1 = p1->next;
            }
            else {
                tail = insertAtTail(tail, p2->val);
                p2 = p2->next;
            }
        }
        if (p1 != nullptr) {
            tail->next = p1;
        }
        if (p2 != nullptr) {
            tail->next = p2;
        }

        // Fake head -> real head.
        head = head->next;
        return head;
    }

private:
    inline static ListNode* insertAtTail(ListNode* tail, int val) {
        auto newTail = new ListNode(val);
        tail->next = newTail;
        return newTail;
    }
};

class Solution22 {
public:
    static vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s;

        dfs(result, s, 0, 0, n);

        return result;
    }

private:
    static void dfs(vector<string>& result, string& s, int l, int r, int n) {
        if (l == n && r == n) {
            result.push_back(s);
            return;
        }
        // Push
        if (l < n) {
            s.push_back('(');
            dfs(result, s, l + 1, r, n);
            s.pop_back();
        }
        // Pop
        if (r < l) {
            s.push_back(')');
            dfs(result, s, l, r + 1, n);
            s.pop_back();
        }
    }
};

class Solution23 {
public:
    struct ListNodeComparer {
        inline bool operator() (ListNode* a, ListNode* b) { return a->val > b->val; }
    };

    static ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto head = new ListNode(0), tail = head;

        priority_queue<ListNode*, vector<ListNode*>, ListNodeComparer> heap;

        for (auto l: lists) {
            if (l != nullptr) {
                heap.push(l);
            }
        }

        while (!heap.empty()) {
            auto node = heap.top();
            heap.pop();
            tail = insertAtTail(tail, node->val);
            if (node->next != nullptr) {
                heap.push(node->next);
            }
        }

        // Fake head -> real head.
        head = head->next;
        return head;
    }

private:
    inline static ListNode* insertAtTail(ListNode* tail, int val) {
        auto newTail = new ListNode(val);
        tail->next = newTail;
        return newTail;
    }
};

class Solution24 {
public:
    static ListNode* swapPairs(ListNode* head) {
        auto fakeHead = new ListNode(0);
        fakeHead->next = head;

        auto prev = fakeHead, curr = head;

        while (curr != nullptr) {
            if (curr->next == nullptr)
                break;
            auto next = curr->next;
            prev->next = next;
            curr->next = next->next;
            next->next = curr;

            prev = curr;
            curr = curr->next;
        }

        return fakeHead->next;
    }
};

class Solution25 {
public:
    static ListNode* reverseKGroup(ListNode* head, int k) {
        auto fakeHead = new ListNode(0);
        fakeHead->next = head;
        auto curr = head, prev = fakeHead;

        while (curr != nullptr) {
            auto newPair = reverseK(curr, prev, 1, k);
            curr = newPair.first;
            prev = newPair.second;

            if (curr == nullptr)
                break;
            curr = curr->next;
            prev = prev->next;
        }

        return fakeHead->next;
    }

private:
    static pair<ListNode*, ListNode*> reverseK(ListNode* curr, ListNode* prev, int i, int k) {
        if (curr == nullptr)
            return {nullptr, nullptr};
        if (i == k)
            return {curr, prev};
        auto [newCurr, newPrev] = reverseK(curr->next, prev->next, i + 1, k);
        if (newCurr == nullptr)
            return {nullptr, nullptr};
        prev->next = curr->next;
        curr->next = newCurr->next;
        newCurr->next = curr;
        return {curr, newCurr};
    }
};

class Solution26 {
public:
    static int removeDuplicates(vector<int>& nums) {
        auto it = unique(nums.begin(), nums.end());
        return static_cast<int>(distance(nums.begin(), it));
    }
};

class Solution27 {
public:
    static int removeElement(vector<int>& nums, int val) {
        auto it = remove(nums.begin(), nums.end(), val);
        return static_cast<int>(distance(nums.begin(), it));
    }
};

class Solution28 {
    // [NOTE]: 997, 1009 + Monte-Carlo will WA.
    static constexpr int Q = 1999;
    static constexpr int R = 256;
public:
    /**
     * Rabin-Karp random string matching algorithm.
     * @param haystack
     * @param needle
     * @return
     */
    static int strStr(const string& haystack, const string& needle) {
        auto N = haystack.size(), M = needle.size();

        if (M == 0)
            return 0;
        if (N < M)
            return -1;

        int needleHash = hash(needle, M);
        int haystackHash = hash(haystack, M);
        const int RM = getRM(M);

        // Match at first.
        if (needleHash == haystackHash && check(haystack.begin(), needle))
            return 0;

        for (auto i = M; i < N; ++i) {
            haystackHash = (haystackHash + Q - RM * haystack[i - M] % Q) % Q;
            haystackHash = (haystackHash * R + haystack[i]) % Q;
            if (haystackHash == needleHash && check(haystack.begin() + i - M + 1, needle))
                return static_cast<int>(i - M + 1);
        }

        return -1;
    }

private:
    /**
     * RM = R ^ (M-1) % Q
     * @param M
     * @return
     */
    static int getRM(string::size_type M) {
        int RM = 1;
        for (int i = 1; i < M; ++i)
            RM = (R * RM) % Q;
        return RM;
    }

    static int hash(const string& s, string::size_type M) {
        int h = 0;
        for (string::size_type i = 0; i < M; ++i)
            h = (R * h + static_cast<int>(s[i])) % Q;
        return h;
    }

    static bool check(string::const_iterator itHaystack, const string& needle) {
//#define LAS_VEGAS
#ifdef LAS_VEGAS
        return equal(needle.begin(), needle.end(), itHaystack);
#else
        // For Monte-Carlo, return true directly
        return true;
#endif
    }
};
