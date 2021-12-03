//
// Created by fyabc on 2021/12/3.
//

#ifndef LEETCODE_BINARYTREE_H
#define LEETCODE_BINARYTREE_H

#include <iostream>

/**
 * Definition for singly-linked binary tree.
 */
template <typename T>
struct TreeNodeT {
    T val;
    TreeNodeT* left;
    TreeNodeT* right;

    explicit TreeNodeT(const T& x): val(x), left(nullptr), right(nullptr) {}
    TreeNodeT(const T& x, TreeNodeT* left, TreeNodeT* right): val(x), left(left), right(right) {}

    void print(std::ostream& os = std::cout) const {
        os << '{' << val;
        if (left != nullptr || right != nullptr) {
            os << ' ';
            if (left == nullptr) {
                os << "nil";
            } else {
                left->print(os);
            }
            os << ' ';
            if (right == nullptr) {
                os << "nil";
            } else {
                right->print(os);
            }
        }
        os << '}';
    }
};

template <typename T>
inline std::ostream& operator<<(std::ostream& os, TreeNodeT<T>* root) {
    root->print(os);
    return os;
}

using TreeNode = TreeNodeT<int>;

#endif //LEETCODE_BINARYTREE_H
