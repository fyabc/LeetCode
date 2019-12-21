//
// Created by v-yaf on 12/6/2019.
//

#ifndef LEETCODE_UFSET_H
#define LEETCODE_UFSET_H

#include <algorithm>
#include <numeric>

namespace leetcode {

class UFSet {
public:
    explicit UFSet(int N) : id_(new int[N]), sizes_(new int[N]), count_(N) {
        std::iota(id_, id_ + N, 0);
        std::fill(sizes_, sizes_ + N, 1);
    }

    UFSet(const UFSet& other) = delete;

    ~UFSet() {
        delete[] id_;
        delete[] sizes_;
    }

    void union_(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);
        if (pRoot == qRoot) return;

        // Merge by rank.
        if (sizes_[pRoot] > sizes_[qRoot]) {
            id_[qRoot] = pRoot;
            sizes_[pRoot] += sizes_[qRoot];
        } else {
            id_[pRoot] = qRoot;
            sizes_[qRoot] += sizes_[pRoot];
        }
        --count_;
    }

    bool connected(int p, int q) {
        return find(p) == find(q);
    }

    int count() { return count_; }

private:
    int* id_;
    int* sizes_;
    int count_;

    int find(int p) {
        // Path compression.
        if (p != id_[p]) {
            id_[p] = find(id_[p]);
        }
        return id_[p];
    }
};

}

#endif //LEETCODE_UFSET_H
