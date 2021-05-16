//
// Created by fyabc on 2019/12/21.
//

#include "support/Debugging.h"
#include "support/ForwardList.h"

#include <vector>
#include <stack>

using namespace std;


class Solution81 {
public:
    /**
     * Similar to Problem 33, but may contain duplicates.
     * We directly copy the algorithm (with slightly change).
     * @param nums
     * @param target
     * @return
     */
    static bool search(vector<int>& nums, int target) {
        auto index = searchInRotatedDup(nums, target, 0, static_cast<int>(nums.size()) - 1);
        return (index != -1);
    }

private:
    static int searchInRotatedDup(vector<int>& nums, int target, int lo, int hi) {
        if (lo > hi)
            return -1;

        int mid = (lo + hi) / 2;
        int left = nums[lo], right = nums[hi], pivot = nums[mid];

        if (target == pivot)
            return mid;
        if (pivot < right) {
            if (target > pivot && target <= right)
                return binarySearch(nums, target, mid + 1, hi);
            else
                return searchInRotatedDup(nums, target, lo, mid - 1);
        } else if (pivot > right) {
            if (target < pivot && target >= left)
                return binarySearch(nums, target, lo, mid - 1);
            else
                return searchInRotatedDup(nums, target, mid + 1, hi);
        } else {
            // [NOTE]: If pivot == right, we can only discard the right element.
            return searchInRotatedDup(nums, target, lo, hi - 1);
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

class Solution82 {
    static constexpr int INF = -1000000;
public:
    static ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        int preValue = INF;
        bool repeat = false;
        auto current = head;

        ListNode* resultHead = nullptr, *resultTail = nullptr;

        while (current != nullptr) {
            if (current->val != preValue) {
                if (!repeat && preValue != INF) {
                    appendNode(preValue, resultHead, resultTail);
                }
                repeat = false;
            } else {
                repeat = true;
            }

            preValue = current->val;
            current = current->next;
        }

        if (!repeat && preValue != INF) {
            appendNode(preValue, resultHead, resultTail);
        }

        return resultHead;
    }

private:
    static void appendNode(int value, ListNode*& resultHead, ListNode*& resultTail) {
        if (resultTail == nullptr) {
            resultHead = new ListNode {value};
            resultTail = resultHead;
            return;
        }
        resultTail->next = new ListNode {value};
        resultTail = resultTail->next;
    }
};

class Solution83 {
public:
    static ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode* resultHead = nullptr, *resultTail = nullptr;
        auto current = head;

        while (current != nullptr) {
            if (resultTail == nullptr || current->val != resultTail->val) {
                appendNode(current->val, resultHead, resultTail);
            }
            current = current->next;
        }

        return resultHead;
    }

private:
    static void appendNode(int value, ListNode*& resultHead, ListNode*& resultTail) {
        if (resultTail == nullptr) {
            resultHead = new ListNode {value};
            resultTail = resultHead;
            return;
        }
        resultTail->next = new ListNode {value};
        resultTail = resultTail->next;
    }
};

class Solution84 {
    /**
     * Stack-based solution.
     *
     * Main idea:
     *  let s[i] means max area ends with i.
     *  if h[i] >= h[i-1], s[i] must contain s[i-1];
     *  else, s[i] must search left until another j that h[j] <= h[i].
     *
     * for i in range(n):
     *      if h[i] >= h[stack.top()]: <push this into stack>
     *      else: <pop until h[i] >= h[stack.top()], and calculate areas related to popped heights>
     *
     * NOTES:
     *  1) heights in this stack will always in increase order;
     *  2) h[stack[i+1]] <= h[stack[i]+1], h[stack[i]+2], ..., h[stack[i+1]-1]
     */
public:
    static int largestRectangleArea(vector<int>& heights) {
        stack<int> increasedHeights;    // heights in this stack will always in increase order.
        int maxArea = 0;

        heights.push_back(0);   // end sentinel

        int i = 0;
        while (i < heights.size()) {
            int h = heights[i];
            if (increasedHeights.empty() || heights[increasedHeights.top()] <= h) {
                increasedHeights.push(i);
                ++i;
            } else {
                // Collect current areas
                int prev = increasedHeights.top();
                increasedHeights.pop();
                int prevH = heights[prev];
                int leftBorder = increasedHeights.empty() ? 0 : increasedHeights.top() + 1;
                int width = i - leftBorder; // Border: [leftBorder, i-1]
                maxArea = max(maxArea, width * prevH);
            }
        }

        return maxArea;
    }
};

class Solution85 {
    /**
     * A simple solution based on Problem 84.
     */
public:
    static int maximalRectangle(vector<vector<char>>& matrix) {
        auto M = static_cast<int>(matrix.size());
        if (M == 0) {
            return 0;
        }
        auto N = static_cast<int>(matrix[0].size());
        if (N == 0) {
            return 0;
        }

        int maxArea = 0;
        vector<vector<int>> heights (M, vector<int>(N, 0));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == 0) {
                    heights[i][j] = matrix[i][j] == '0' ? 0 : 1;
                } else {
                    heights[i][j] = matrix[i][j] == '0' ? 0 : heights[i-1][j] + 1;
                }
            }
        }

        for (int i = 0; i < M; ++i) {
            maxArea = max(maxArea, Solution84::largestRectangleArea(heights[i]));
        }

        return maxArea;
    }
};

class Solution86 {
public:
    static ListNode* partition(ListNode* head, int x) {
        using namespace leetcode;

        ListNode* head1 = nullptr, *tail1 = nullptr;
        ListNode* head2 = nullptr, *tail2 = nullptr;
        ListNode* current = head;

        while (current != nullptr) {
            int value = current->val;
            if (value < x) {
                fwList_Append(value, head1, tail1);
            } else {
                fwList_Append(value, head2, tail2);
            }
            current = current->next;
        }

        fwList_Concat(head1, tail1, head2);

        return head1;
    }
};

class Solution87 {
    /**
     * Recursion with Memorization.
     *
     * memory[i, j, len] == true: s1[i:i+len] matches s2[j:j+len].
     */
public:
    struct Hasher {
        size_t operator()(const tuple<int, int, int>& key) const {
            return hash<int>()(get<0>(key)) ^ hash<int>()(get<1>(key)) ^ hash<int>()(get<2>(key));
        }
    };

    static bool isScramble(const string& s1, const string& s2) {
        unordered_map<tuple<int, int, int>, bool, Hasher> memory;

        return search(0, 0, static_cast<int>(s1.size()), s1, s2, memory);
    }

private:
    static bool search(int begin1, int begin2, int len,
                       const string& s1, const string& s2,
                       unordered_map<tuple<int, int, int>, bool, Hasher>& memory) {
        if (len == 1) {
            bool result = s1[begin1] == s2[begin2];
            return result;
        }

        auto memoryItr = memory.find(make_tuple(begin1, begin2, len));
        if (memoryItr != memory.end()) {
            return memoryItr->second;
        }

        auto result = false;
        for (int newLen = 1; newLen < len; ++newLen) {
            // match (no swap)
            if (search(begin1, begin2, newLen, s1, s2, memory) &&
                search(begin1 + newLen, begin2 + newLen, len - newLen, s1, s2, memory)) {
                result = true;
                break;
            }

            // match (swap)
            if (search(begin1, begin2 + len - newLen, newLen, s1, s2, memory) &&
                search(begin1 + newLen, begin2, len - newLen, s1, s2, memory)) {
                result = true;
                break;
            }
        }

        memory[make_tuple(begin1, begin2, len)] = result;
        return result;
    }
};

class Solution88 {
public:
    static void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, outPos = m + n - 1;
        while (i >= 0 || j >= 0) {
            if (i < 0) {
                nums1[outPos] = nums2[j];
                --outPos;
                --j;
                continue;
            }
            if (j < 0) {
                nums1[outPos] = nums1[i];
                --outPos;
                --i;
                continue;
            }
            if (nums1[i] < nums2[j]) {
                nums1[outPos] = nums2[j];
                --outPos;
                --j;
            } else {
                nums1[outPos] = nums1[i];
                --outPos;
                --i;
            }
        }
    }
};
