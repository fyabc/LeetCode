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
        int p_root = find(p);
        int q_root = find(q);
        if (p_root == q_root) return;

        // Merge by rank.
        if (sizes[p_root] > sizes[q_root]) {
            id[q_root] = p_root;
            sizes[p_root] += sizes[q_root];
        }
        else {
            id[p_root] = q_root;
            sizes[q_root] += sizes[p_root];
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
