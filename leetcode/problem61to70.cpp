//
// Created by fyabc on 2019/12/21.
//

#include "support/ForwardList.h"
#include "support/IO.h"

using namespace std;

class Solution61 {
public:
    static ListNode* rotateRight(ListNode* head, int k) {
        auto p = head;
        int N = 0;
        ListNode* newHead = nullptr, *last = nullptr;

        leetcode::printlnV();
        for (; p != nullptr; p = p->next, ++N) {
            last = p;
            leetcode::printlnV("At:", N, "val:", p->val);
            if (N == k)
                newHead = p;
        }

        leetcode::printlnV("N:", N);

        return nullptr;
    }
};
