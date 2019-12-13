//
// Created by v-yaf on 12/10/2019.
//

#pragma clang diagnostic push
#pragma ide diagnostic ignored "MemberFunctionCanBeStatic"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include "support/IO.h"
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>

using namespace std;

class Solution {
    /// Problem 1
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> numIdx;

        numIdx.reserve(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            numIdx.emplace_back(nums[i], i);
        }

        sort(numIdx.begin(), numIdx.end());

        for (int i = 0; i < numIdx.size(); ++i) {
            int a = numIdx[i].first, b = target - a;
            for (int j = i + 1; j < numIdx.size(); ++j) {
                if (numIdx[j].first == b) {
                    vector<int> result{numIdx[i].second, numIdx[j].second};
                    if (result[0] > result[1])
                        swap(result[0], result[1]);
                    return result;
                }
            }
        }

        // Unreachable code
        return {};
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
            ListNode* result = nullptr;
            for (auto&& item : container) {
                auto newNode = new ListNode(item);
                newNode->next = result;
                result = newNode;
            }
            return result;
        }

        inline static ListNode* from_init_list(const initializer_list<int>& initializerList) {
            return from_container_reversed(initializerList);
        }
    };

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = nullptr;
        ListNode* last = nullptr;

        int carryDigit = 0;

        while (l1 != nullptr && l2 != nullptr) {
            int digitSum = l1->val + l2->val + carryDigit;
            carryDigit = digitSum / 10;

            insertAtHead(result, last, new ListNode(digitSum % 10));

            l1 = l1->next;
            l2 = l2->next;
        }

        auto remain = l1 == nullptr ? l2 : l1;
        while (remain != nullptr) {
            int digitSum = remain->val + carryDigit;
            carryDigit = digitSum / 10;

            insertAtHead(result, last, new ListNode(digitSum % 10));

            remain = remain->next;
        }

        if (carryDigit > 0) {
            insertAtHead(result, last, new ListNode(carryDigit));
        }

        return result;
    }

private:
    void insertAtHead(ListNode*& list, ListNode*& last, ListNode* node) {
        if (list == nullptr) {
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
        unordered_map<char, int> charIndex;

        int n = static_cast<int>(s.length()), result = 0;

        for (int i = 0, j = 0; j < n; ++j) {
            auto iter = charIndex.find(s[j]);
            if (iter != charIndex.end()) {
                auto newI = iter->second + 1;
                for (auto ii = i; ii < newI; ++ii) {
                    charIndex.erase(s[ii]);
                }
                i = newI;
            } else {
                result = max(result, j - i + 1);
            }
            charIndex[s[j]] = j;
        }

        return result;
    }

    /// Problem 4
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty())
            return getSingleMedian(nums2);
        if (nums2.empty())
            return getSingleMedian(nums1);

        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }
        auto M = nums1.size(), N = nums2.size();
        bool odd = (M + N) % 2 == 1;
        vector<int>::size_type lo = 0, hi = M;

        while (lo < hi) {
            // Find partition (i, j)
            auto i = (lo + hi) / 2;         // 0 <= i <= M - 1
            auto j = (M + N + 1) / 2 - i;   // 1 <= j <= N

            if (nums2[j - 1] > nums1[i]) {
                // i too small
                lo = i + 1;
                continue;
            }

            if (i == 0 || j == N) {
                lo = hi = i;
                break;
            }

            if (nums1[i - 1] > nums2[j]) {
                // i too large
                hi = i - 1;
            }
            else {
                lo = hi = i;
            }
        }

        auto i = lo;
        auto j = (M + N + 1) / 2 - i;

        if (i == M - 1 && j > 0 && nums2[j - 1] > nums1[i]) {
            // nums1 too small
            i = M;
            j = (M + N + 1) / 2 - i;
            return getMedian(i, j, nums1, nums2, odd);
        }

        return getMedian(i, j, nums1, nums2, odd);
    }

private:
    inline double getMedian(vector<int>::size_type i, vector<int>::size_type j, vector<int>& nums1, vector<int>& nums2, bool odd) {
        double max_lo;
        if (i == 0)
            max_lo = static_cast<double>(nums2[j - 1]);
        else if (j == 0)
            max_lo = static_cast<double>(nums1[i - 1]);
        else
            max_lo = static_cast<double>(max(nums1[i - 1], nums2[j - 1]));

        if (odd) {
            return max_lo;
        }
        else {
            double min_hi;
            if (i == nums1.size())
                min_hi = static_cast<double>(nums2[j]);
            else if (j == nums2.size())
                min_hi = static_cast<double>(nums1[i]);
            else
                min_hi = static_cast<double>(min(nums1[i], nums2[j]));
            return (max_lo + min_hi) / 2.0;
        }
    }

    inline double getSingleMedian(vector<int>& nums) {
        auto N = nums.size();
        if (N % 2 != 0)
            return static_cast<double>(nums[N / 2]);
        else
            return static_cast<double>(nums[N / 2 - 1] + nums[N / 2]) / 2.0;
    }

    /// Problem 5
public:
    /**
     * Assume that len(s) <= 1000.
     *
     * Algorithm: Manacher algorithm
     *  See in <https://segmentfault.com/a/1190000003914228>.
     *
     * Time complexity: O(n)
     *
     * @param s
     * @return
     */
    string longestPalindrome(const string& s) {
        string extended(2 * s.length() + 1, '\1');

        // Array of palindrome radius.
        vector<int> pRadius(extended.length(), 0);

        // Value of max palindrome radius and which it is.
        int maxRadius = -1, maxRadiusIndex = -1;
        // Value of max right of visited palindromes and its symmetry axis.
        int maxRight = 0, maxRightPos = 0;

        // Create extended string.
        auto sIt = s.begin();
        for (auto eIt = extended.begin() + 1; sIt != s.end(); ++sIt, eIt += 2) {
            *eIt = *sIt;
        }

        for (int i = 0; i < extended.length(); ++i) {
            // Initialize pRadius[i]
            if (i < maxRight) {
                pRadius[i] = min(pRadius[2 * maxRightPos - i], maxRight - i);
            } else {
                pRadius[i] = 1;
            }

            // Try to extend pRadius[i]
            int pRadiusI = pRadius[i];
            while (i - pRadiusI >= 0 && i + pRadiusI < extended.length()
                   && extended[i - pRadiusI] == extended[i + pRadiusI])
                ++pRadiusI;
            pRadius[i] = pRadiusI;

            // Update maxRight and maxRightPos
            if (pRadiusI + i - 1 > maxRight) {
                maxRight = pRadiusI + i - 1;
                maxRightPos = i;
            }

            // Update maxRadius and maxRadiusIndex
            if (pRadiusI > maxRadius) {
                maxRadius = pRadiusI;
                maxRadiusIndex = i;
            }
        }

        // Extract result string from extended string.
        string result(maxRadius - 1, '\0');

        for (auto rIt = result.begin(), eIt = extended.begin() + maxRadiusIndex - maxRadius + 2;
             rIt != result.end(); ++rIt, eIt += 2)
            *rIt = *eIt;

        return result;
    }

    /// Problem 6
public:
    string convert(const string& s, int numRows) {
        if (numRows == 1)
            return s;
        auto n = s.size();
        string result(n, '\0');

        int m = 2 * numRows - 2, halfM = numRows - 1;
        auto rIt = result.begin();

        for (int i = 0; i < n; i += m) {
            *rIt++ = s[i];
        }
        for (int j = 1; j < halfM; ++j) {
            for (int i = j, iRev = m - j; i < n; i += m, iRev += m) {
                *rIt++ = s[i];
                if (iRev < n)
                    *rIt++ = s[iRev];
            }
        }
        for (int i = halfM; i < n; i += m) {
            *rIt++ = s[i];
        }

        return result;
    }

    /// Problem 7
public:
    int reverse(int x) {
        auto xLong = static_cast<long long>(x);
        bool neg = xLong < 0;

        if (neg)
            xLong = -xLong;
        auto xStr = to_string(xLong);

        if (neg)
            xStr.push_back('-');

        std::reverse(xStr.begin(), xStr.end());

        auto result = strtoll(xStr.c_str(), nullptr, 10);

        if (result > numeric_limits<int>::max() || result < numeric_limits<int>::min()) {
            return 0;
        }
        return static_cast<int>(result);
    }

    /// Problem 8
public:
    int myAtoi(const string& str) {
        long long result = strtoll(str.c_str(), nullptr, 10);
        if (result > numeric_limits<int>::max())
            return numeric_limits<int>::max();
        if (result < numeric_limits<int>::min())
            return numeric_limits<int>::min();
        return static_cast<int>(result);
    }

    /// Problem 9
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        if (x == 0)
            return true;
        vector<int> digits;
        digits.reserve(32);

        while (x > 0) {
            digits.push_back(x % 10);
            x /= 10;
        }

        int i = 0, j = digits.size() - 1;
        for (; i <= j; ++i, --j) {
            if (digits[i] != digits[j])
                break;
        }

        return i >= j;
    }

    /// Problem 10
public:
    bool isMatch(const string& s, const string& p) {
        return false;
    }
};

#pragma clang diagnostic pop
