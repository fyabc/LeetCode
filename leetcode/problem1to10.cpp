//
// Created by v-yaf on 12/10/2019.
//

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>

using namespace std;

class Solution {
    /// Problem 1
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> num_idx;

        for (int i = 0; i < nums.size(); ++i) {
            num_idx.emplace_back(nums[i], i);
        }

        sort(num_idx.begin(), num_idx.end());

        for (int i = 0; i < num_idx.size(); ++i) {
            int a = num_idx[i].first, b = target - a;
            for (int j = i + 1; j < num_idx.size(); ++j) {
                if (num_idx[j].first == b) {
                    vector<int> result{num_idx[i].second, num_idx[j].second};
                    if (result[0] > result[1])
                        swap(result[0], result[1]);
                    return result;
                }
            }
        }
    }

    /// Problem 2

    struct ListNode {
        int val;
        ListNode *next;
        explicit ListNode(int x) : val(x), next(nullptr) {}

        /**
         * Create list from container elements in reversed order.
         * @tparam ContainerType
         * @param container
         * @return
         */
        template <typename ContainerType>
        static ListNode* from_container_reversed(const ContainerType& container) {
            ListNode* result = NULL;
            for (auto&& item : container) {
                auto new_node = new ListNode(item);
                new_node->next = result;
                result = new_node;
            }
            return result;
        }

        inline static ListNode* from_init_list(const initializer_list<int>& init_list) {
            return from_container_reversed(init_list);
        }
    };

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = NULL;
        ListNode* last = NULL;

        int carry_digit = 0;

        while (l1 != NULL && l2 != NULL) {
            int digit_sum = l1->val + l2->val + carry_digit;
            carry_digit = digit_sum / 10;

            insert_at_head(result, last, new ListNode(digit_sum % 10));

            l1 = l1->next;
            l2 = l2->next;
        }

        auto remain = l1 == NULL ? l2 : l1;
        while (remain != NULL) {
            int digit_sum = remain->val + carry_digit;
            carry_digit = digit_sum / 10;

            insert_at_head(result, last, new ListNode(digit_sum % 10));

            remain = remain->next;
        }

        if (carry_digit > 0) {
            insert_at_head(result, last, new ListNode(carry_digit));
        }

        return result;
    }

private:
    void insert_at_head(ListNode*& list, ListNode*& last, ListNode* node) {
        if (list == NULL) {
            list = last = node;
            return;
        }

        last->next = node;
        last = node;
    }

    /// Problem 3
public:
    /**
     * Algorithm: Use map as a slide window
     *  0. Define a map `char_index` of slide window [i, j). (i = j = 0 at first)
     *      Map: character `c` -> the index of `c` in the slide window.
     *  1. Move upper bound (`j`) until `s[j]` in keys of `char_index`;
     *  2. Update result if `j - i` larger than current result;
     *  3. Move lower bound (`i`) to `char_index[s[j]] + 1`,
     *     now the slide window still doesn't contains same character;
     *  4. Move until hit right bound (`j == len(s)`), then return result.
     * @param s
     * @return
     */
    int lengthOfLongestSubstring(const string& s) {
        unordered_map<char, int> char_index;

        int n = static_cast<int>(s.length()), result = 0;

        for (int i = 0, j = 0; j < n; ++j) {
            auto iter = char_index.find(s[j]);
            if (iter != char_index.end()) {
                auto new_i = iter->second + 1;
                for (auto ii = i; ii < new_i; ++ii) {
                    char_index.erase(s[ii]);
                }
                i = new_i;
            } else {
                result = max(result, j - i + 1);
            }
            char_index[s[j]] = j;
        }

        return result;
    }

    /// Problem 4
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int lo = numeric_limits<int>::min(), hi = numeric_limits<int>::max();
    }
};
