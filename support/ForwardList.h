//
// Created by v-yaf on 12/17/2019.
//

#ifndef LEETCODE_FORWARDLIST_H
#define LEETCODE_FORWARDLIST_H

#include <vector>
#include <initializer_list>
#include <iostream>

/**
 * Definition for singly-linked list.
 */
template <typename T>
struct ListNodeT {
    T val;
    ListNodeT* next;

    explicit ListNodeT(const T& x) : val(x), next(nullptr) {}

    ListNodeT(const T& x, ListNodeT* next): val(x), next(next) {}

    template <typename ContainerType>
    static ListNodeT* fromContainer(const ContainerType& container) {
        ListNodeT* result = nullptr;
        for (auto it = std::rbegin(container); it != std::rend(container); ++it) {
            auto newNode = new ListNodeT(*it);
            newNode->next = result;
            result = newNode;
        }
        return result;
    }

    inline static ListNodeT* fromInitList(const std::initializer_list<T>& initializerList) {
        return fromContainer(initializerList);
    }

    void print(std::ostream& os = std::cout) const {
        auto ptr = this;
        while (ptr->next != nullptr) {
            os << ptr->val << " -> ";
            ptr = ptr->next;
        }
        os << ptr->val << std::endl;
    }

    [[nodiscard]] std::vector<int> toVector() const {
        auto ptr = this;
        std::vector<int> result;
        while (ptr != nullptr) {
            result.push_back(ptr->val);
            ptr = ptr->next;
        }
        return result;
    }
};

template <typename T>
inline std::ostream& operator<<(std::ostream& os, ListNodeT<T>* head) {
    head->print(os);
    return os;
}

using ListNode = ListNodeT<int>;

/// Forward list utilities, used for leetcode (so implemented as non-member functions).
namespace leetcode {

bool fwList_Equal(const ListNode* a, const ListNode* b);

ListNode* fwList_GetTail(const ListNode* head);
void fwList_Append(int value, ListNode*& head, ListNode*& tail);

}

#endif //LEETCODE_FORWARDLIST_H
