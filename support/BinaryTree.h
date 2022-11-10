//
// Created by fyabc on 2021/12/3.
//

#ifndef LEETCODE_BINARYTREE_H
#define LEETCODE_BINARYTREE_H

#include <iostream>
#include <optional>
#include <queue>

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

    static TreeNodeT* fromVector(const std::vector<std::optional<T>>& content) {
        if (content.empty()) {
            return nullptr;
        }

        auto iter = content.begin();
        const auto& value = *iter;
        if (!value.has_value()) {
            throw logic_error("Failed to parse input");
        }
        auto* root = new TreeNodeT {value.value()};
        std::queue<TreeNodeT*> nodes;
        nodes.push(root);

        ++iter;
        while (iter != content.cend() && !nodes.empty()) {
            auto* current = nodes.back();
            nodes.pop();

            // left
            if (iter->has_value()) {
                auto left = new TreeNodeT {iter->value()};
                current->left = left;
                nodes.push(left);
            }

            ++iter;
            if (iter == content.cend()) {
                break;
            }

            // right
            if (iter->has_value()) {
                auto right = new TreeNodeT {iter->value()};
                current->right = right;
                nodes.push(right);
            }
            ++iter;
        }

        return root;
    }

    std::vector<std::optional<T>> toVector() const {
        std::vector<std::optional<T>> result;
        std::queue<const TreeNodeT*> nodes;
        nodes.push(this);

        while (!nodes.empty()) {
            auto* node = nodes.front();
            nodes.pop();
            if (node == nullptr) {
                result.push_back(std::nullopt);
                continue;
            }
            result.emplace_back(node->val);
            if (node->left == nullptr && node->right == nullptr) {
                continue;
            }
            nodes.push(node->left);
            nodes.push(node->right);
        }

        if (!result.empty() && !result.back().has_value()) {
            result.pop_back();
        }

        return result;
    }

    std::vector<T> toVector(const T& defaultValue) const {
        auto resultOpt = toVector();

        std::vector<T> result;

        std::transform(resultOpt.begin(), resultOpt.end(), std::back_inserter(result),
                       [&defaultValue](const std::optional<T> value) { return value.has_value() ? value.value() : defaultValue; });

        return result;
    }
};

template <typename T>
inline std::ostream& operator<<(std::ostream& os, TreeNodeT<T>* root) {
    root->print(os);
    return os;
}

using TreeNode = TreeNodeT<int>;

#endif //LEETCODE_BINARYTREE_H
