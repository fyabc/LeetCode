//
// Created by fyabc on 2019/12/21.
//

#include "support/Debugging.h"
#include "support/ForwardList.h"

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
public:
    static ListNode* reverseBetween(ListNode* head, int left, int right) {
        // TODO
        return nullptr;
    }
};
