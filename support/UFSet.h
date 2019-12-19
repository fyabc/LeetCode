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
    explicit UFSet(int N): id(new int[N]), sizes(new int[N]), count_(N) {
        std::iota(id, id + N, 0);
        std::fill(sizes, sizes + N, 1);
    }
    UFSet(const UFSet& other) = delete;
    ~UFSet() {
        delete[] id;
        delete[] sizes;
    }

    void union_(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);
        if (pRoot == qRoot) return;

        // Merge by rank.
        if (sizes[pRoot] > sizes[qRoot]) {
            id[qRoot] = pRoot;
            sizes[pRoot] += sizes[qRoot];
        }
        else {
            id[pRoot] = qRoot;
            sizes[qRoot] += sizes[pRoot];
        }
        --count_;
    }
    bool connected(int p, int q) {
        return find(p) == find(q);
    }
    int count() { return count_; }

private:
    int* id;
    int* sizes;
    int count_;

    int find(int p) {
        // Path compression.
        if (p != id[p]) {
            id[p] = find(id[p]);
        }
        return id[p];
    }
};

}

#endif //LEETCODE_UFSET_H
