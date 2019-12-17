//
// Created by v-yaf on 12/15/2019.
//

#include "support/IO.h"
#include "support/ForwardList.h"

#include <numeric>
#include <stack>

using namespace std;

class Solution11 {
public:
    /**
     * See https://leetcode.com/problems/container-with-most-water/solution/.
     * See prove at https://leetcode.com/problems/container-with-most-water/discuss/6089/Anyone-who-has-a-O(N)-algorithm/7268.
     * @param height
     * @return
     */
    static int maxArea(vector<int>& height) {
        vector<int>::size_type N = height.size(), lo = 0, hi = N - 1;
        int result = 0;

        while (lo < hi) {
            result = std::max(result, int(hi - lo) * std::min(height[hi], height[lo]));
            if (height[lo] < height[hi])
                ++lo;
            else
                --hi;
        }
        return result;
    }
};

class Solution12 {
    constexpr static const char* Hundreds[] = {
        "", "C", "CC", "CCC", "CD",
        "D", "DC", "DCC", "DCCC", "CM",
    };
    constexpr static const char* Tens[] = {
        "", "X", "XX", "XXX", "XL",
        "L", "LX", "LXX", "LXXX", "XC",
    };
    constexpr static const char* Ones[] = {
        "", "I", "II", "III", "IV",
        "V", "VI", "VII", "VIII", "IX",
    };
public:
    static string intToRoman(int num) {
        string result;

        int thousand = num / 1000;
        num %= 1000;

        result.append(thousand, 'M');

        int hundred = num / 100;
        num %= 100;

        result.append(Hundreds[hundred]);

        int ten = num / 10;
        num %= 10;

        result.append(Tens[ten]);

        result.append(Ones[num]);

        return result;
    }
};

class Solution13 {
    static unordered_map<char, int> Values;
public:
    static int romanToInt(const string& s) {
        auto N = s.size();
        int result = 0;
        for (string::size_type i = 0; i < N; ++i) {
            int thisValue = Values[s[i]];
            if (i < N - 1 && Values[s[i]] < Values[s[i + 1]])
                result -= thisValue;
            else
                result += thisValue;
        }
        return result;
    }
};

unordered_map<char, int> Solution13::Values = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000},
};

class Solution14 {
public:
    static string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";

        string::size_type minLength = numeric_limits<string::size_type>::max();
        for (const string& str: strs) {
            if (str.size() < minLength)
                minLength = str.size();
        }
        string::size_type i = 0;
        for (; i < minLength; ++i) {
            char ch = strs[0][i];
            for (const string& str: strs) {
                if (str[i] != ch)
                    return strs[0].substr(0, i);
            }
        }
        return strs[0].substr(0, minLength);
    }
};

class Solution15 {
public:
    /**
     * See https://zh.wikipedia.org/wiki/3SUM.
     * @param nums
     * @return
     */
    static vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        auto N = nums.size();

        if (N < 3 || nums.front() > 0 || nums.back() < 0)
            return {};

        for (vector<int>::size_type i = 0; i < N - 2; ++i) {
            int a = nums[i];
            if (a > 0) break;

            // Ensure the unique output. Idea from https://zhuanlan.zhihu.com/p/24681450.
            if (i > 0 && a == nums[i - 1])
                continue;

            vector<int>::size_type start = i + 1, end = N - 1;

            while (start < end) {
                auto b = nums[start], c = nums[end], s = a + b + c;

                if (c < 0) {
                    i = N - 2;
                    break;
                }

                if (s == 0) {
                    result.push_back({a, b, c});
                    // Continue search for all triplet combinations summing to zero.
                    // Ensure the unique output.
                    while (++start < end && nums[start - 1] == nums[start]);
                    while (--end > start && nums[end + 1] == nums[end]);
                }
                else if (s > 0) {
                    --end;
                }
                else {
                    ++start;
                }
            }
        }

        return result;
    }
};

class Solution16 {
public:
    static int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        auto N = nums.size();
        auto minDiff = numeric_limits<int>::max();
        auto result = 0;

        for (vector<int>::size_type i = 0; i < N - 2; ++i) {
            int a = nums[i];

            vector<int>::size_type start = i + 1, end = N - 1;

            while (start < end) {
                auto b = nums[start], c = nums[end], s = a + b + c, diff = std::abs(s - target);
                if (diff < minDiff) {
                    minDiff = diff;
                    result = s;
                }
                else if (s > target) {
                    --end;
                }
                else {
                    ++start;
                }
            }
        }

        return result;
    }
};

class Solution17 {
public:
    static vector<string> letterCombinations(const string& digits) {
        if (digits.empty())
            return {};

        vector<string> result;

        string current;
        letterCombinationsI(digits.begin(), digits.end(), current, result);

        return result;
    }

private:
    static const string Table[];
    static void letterCombinationsI(
        string::const_iterator digitsIt, string::const_iterator digitsEnd,
        string& current, vector<string>& result) {
        if (digitsIt == digitsEnd) {
            result.push_back(current);
            return;
        }
        int digit = static_cast<int>(*digitsIt) - 48;
        ++digitsIt;
        for (char ch: Table[digit]) {
            current.push_back(ch);
            letterCombinationsI(digitsIt, digitsEnd, current, result);
            current.pop_back();
        }
    }
};

const string Solution17::Table[] = {
    "",     // index 0
    "", "abc", "def",
    "ghi", "jkl", "mno",
    "pqrs", "tuv", "wxyz",
};

class Solution18 {
public:
    static vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        auto N = nums.size();

        if (N < 4 || nums.front() > 0 || nums.back() < 0)
            return {};

        for (vector<int>::size_type i = 0; i < N - 3; ++i) {
            int a = nums[i];
            if (a * 4 > target) break;

            threeSumInternal(nums, target, a, i, result);
        }

        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());

        return result;
    }

private:
    static void threeSumInternal(vector<int>& nums, int target,
        int a, vector<int>::size_type i, vector<vector<int>>& result) {
        auto N = nums.size();
        for (vector<int>::size_type j = i + 1; j < N - 2; ++j) {
            int b = nums[j];

            vector<int>::size_type start = j + 1, end = N - 1;

            while (start < end) {
                auto c = nums[start], d = nums[end], s = a + b + c + d;

                if (d * 4 < target) {
                    j = N - 2;
                    break;
                }

                if (s == target) {
                    result.push_back({a, b, c, d});
                    // Continue search for all triplet combinations summing to zero.
                    // Ensure the unique output.
                    while (++start < end && nums[start - 1] == nums[start]);
                    while (--end > start && nums[end + 1] == nums[end]);
                }
                else if (s > target) {
                    --end;
                }
                else {
                    ++start;
                }
            }
        }
    }
};

class Solution19 {
public:
    static ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = getLength(head);

        if (n == length) {
            // Remove the head.
            head = head->next;
            return head;
        }

        auto ptr = head;
        for (int i = 0; i < length - n - 1; ++i)
            ptr = ptr->next;

        ptr->next = ptr->next->next;
        return head;
    }

private:
    static int getLength(ListNode* head) {
        int length = 0;
        for (auto ptr = head; ptr != nullptr; ptr = ptr->next)
            ++length;
        return length;
    }
};

class Solution20 {
public:
    static bool isValid(const string& s) {
        std::stack<char> parentheses;
        for (char ch: s) {
            if (isOpen(ch))
                parentheses.push(ch);
            else {
                if (parentheses.empty())
                    return false;
                if (match(parentheses.top(), ch)) {
                    parentheses.pop();
                }
                else {
                    return false;
                }
            }
        }
        return parentheses.empty();
    }

private:
    inline static bool isOpen(char ch) {
        return ch == '(' || ch == '[' || ch == '{';
    }
    inline static bool match(char l, char r) {
        return (l == '(' && r == ')') || (l == '[' && r == ']') || (l == '{' && r == '}');
    }
};
