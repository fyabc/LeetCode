//
// Created by t-yafan on 5/9/2021.
//

#include "support/ForwardList.h"

namespace leetcode {

bool fwList_Equal(const ListNode* a, const ListNode* b) {
    const ListNode* aCur = a, *bCur = b;
    while (aCur != nullptr && bCur != nullptr) {
        if (aCur->val != bCur->val) {
            return false;
        }
        aCur = aCur->next;
        bCur = bCur->next;
    }

    if (aCur == nullptr && bCur == nullptr) {
        return true;
    }

    return false;
}

ListNode* fwList_GetTail(const ListNode* head) {
    auto* result = const_cast<ListNode*>(head);
    if (result == nullptr) {
        return result;
    }

    while (result->next != nullptr) {
        result = result->next;
    }

    return result;
}

void fwList_Append(int value, ListNode*& head, ListNode*& tail) {
    if (tail == nullptr) {
        head = new ListNode {value};
        tail = head;
        return;
    }
    tail->next = new ListNode {value};
    tail = tail->next;
}

}
