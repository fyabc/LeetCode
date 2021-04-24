//
// Created by fyabc on 2021/4/24.
//

#ifndef LEETCODE_GRAPH_H
#define LEETCODE_GRAPH_H

#include <vector>

namespace leetcode {

template <typename T>
class Graph {
    using IndexType = int;
    using WeightType = int;
    using NodeAdjType = std::pair<IndexType, WeightType>;   // (index, weight) pairs
public:

    Graph() = default;

    void addNode(const T& nodeValue) {
        nodeValues_.push_back(nodeValue);
        adj_.push_back({});
    }

    void addEdge(IndexType u, IndexType v, WeightType weight) {
        adj_[u].push_back({v, weight});
        adj_[v].push_back({u, weight});
    }

    std::vector<WeightType> dijkstra(IndexType start) const {
        // todo
    }

private:
    std::vector<T> nodeValues_;
    std::vector<std::vector<NodeAdjType>> adj_;
};

}

#endif //LEETCODE_GRAPH_H
