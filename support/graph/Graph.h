//
// Created by fyabc on 2021/4/24.
//

#ifndef LEETCODE_GRAPH_H
#define LEETCODE_GRAPH_H

#include <iterator>
#include <vector>
#include <queue>

namespace leetcode::graph {

template <typename T, typename WT = int>
class Graph {
public:
    // Types and constants.
    using IndexType = int;
    using WeightType = WT;
    using NodeAdjType = std::pair<IndexType, WeightType>;   // (index, weight) pairs

    static constexpr WeightType MAX_WEIGHT = std::numeric_limits<WeightType>::max();

private:
    using NodeValuesContainerType = std::vector<T>;
    using AdjContainerType = std::vector<std::vector<NodeAdjType>>;

    class GraphEdgeIterator {
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = std::tuple<IndexType, IndexType, WeightType>;
        using pointer = value_type*;
        using reference = value_type&;

        GraphEdgeIterator(const Graph& graph, IndexType u, IndexType vIdx): graph_(graph), u_(u), vIdx_(vIdx) {
            // Forward to first valid position.
            nextValidEdge(false);
        }

        value_type operator*() const {
            const auto& vw = graph_.adj_[u_][vIdx_];
            return std::make_tuple(u_, vw.first, vw.second);
        }

        GraphEdgeIterator& operator++() {
            nextValidEdge(true);
            return *this;
        }

        GraphEdgeIterator operator++(int) {
            GraphEdgeIterator tmp {*this};

            nextValidEdge(true);

            return tmp;
        }

        friend bool operator==(const GraphEdgeIterator& lhs, const GraphEdgeIterator& rhs) {
            return &lhs.graph_ == &rhs.graph_ && lhs.u_ == rhs.u_ && lhs.vIdx_ == rhs.vIdx_;
        }
        friend bool operator!=(const GraphEdgeIterator& lhs, const GraphEdgeIterator& rhs) {
            return !(lhs == rhs);
        }

    private:
        [[nodiscard]] IndexType getV() const {
            return graph_.adj_[u_][vIdx_].first;
        }

        [[nodiscard]] IndexType getWeight() const {
            return graph_.adj_[u_][vIdx_].second;
        }

        [[nodiscard]] bool valid() const {
            auto result =
                (u_ < graph_.numNodes() && vIdx_ < graph_.adj_[u_].size() && (graph_.directed() || u_ <= getV()))
                || (u_ == graph_.numNodes() && vIdx_ == 0);

            return result;
        }

        void stepNext() {
            ++vIdx_;
            if (vIdx_ >= graph_.adj_[u_].size()) {
                ++u_;
                vIdx_ = 0;
            }
        }

        void nextValidEdge(bool stepFirst) {
            if (stepFirst) {
                stepNext();
            }
            while (!valid()) {
                stepNext();
            }
        }

        const Graph& graph_;
        IndexType u_;
        IndexType vIdx_;
    };

    class GraphEdgeView {
    public:
        explicit GraphEdgeView(const Graph& graph): graph_(graph) {}

        auto begin() const {
            return GraphEdgeIterator(graph_, 0, 0);
        }

        auto end() const {
            return GraphEdgeIterator(graph_, graph_.numNodes(), 0);
        }

    private:
        const Graph& graph_;
    };

public:
    // *-tors.
    Graph() = default;

    Graph(const std::vector<T>& nodeValues, const std::vector<std::tuple<IndexType, IndexType, WeightType>>& edges, bool directed = false)
        : directed_(directed) {
        for (const auto& nodeValue: nodeValues) {
            addNode(nodeValue);
        }
        for (const auto& edge: edges) {
            addEdge(std::get<0>(edge), std::get<1>(edge), std::get<2>(edge));
        }
    }

    // Getters.
    [[nodiscard]] bool directed() const { return directed_; }

    [[nodiscard]] auto numNodes() const {
        return static_cast<IndexType>(nodeValues_.size());
    }

    // Iterating methods.
    const auto& nodeValues() const {
        return nodeValues_;
    }

    auto edgesView() const {
        return GraphEdgeView(*this);
    }

    // Add nodes or edges.
    void addNode(const T& nodeValue) {
        nodeValues_.push_back(nodeValue);
        adj_.emplace_back();
    }

    void addEdge(IndexType u, IndexType v, WeightType weight) {
        adj_[u].emplace_back(v, weight);
        if (!directed_) {
            adj_[v].emplace_back(u, weight);
        }
    }

private:
    static void relaxDistance(std::vector<WeightType>& distances, IndexType u, IndexType v, WeightType weight) {
        if (distances[v] > distances[u] + weight) {
            distances[v] = distances[u] + weight;
        }
    }

public:
    // Graph algorithms.
    [[nodiscard]] std::vector<WeightType> dijkstra(IndexType start) const {
        auto zeroDistance = static_cast<WeightType>(0);
        std::vector<WeightType> distances(numNodes(), MAX_WEIGHT);
        distances[start] = zeroDistance;

        std::vector<bool> visited(numNodes(), false);

        using QueueKeyType = std::pair<WeightType, IndexType>;
        auto cmp = [](const QueueKeyType& u, const QueueKeyType& v) {
            return u.first > v.first; };
        // {distance, index}
        std::priority_queue<QueueKeyType, std::vector<QueueKeyType>, decltype(cmp)> priorityQueue(cmp);
        priorityQueue.emplace(zeroDistance, start);

        while (!priorityQueue.empty()) {
            auto di = priorityQueue.top();
            auto u = di.second;
            priorityQueue.pop();

            if (visited[u]) {
                continue;
            }

            visited[u] = true;

            for (const auto& vw: adj_[u]) {
                auto v = vw.first;
                auto w = vw.second;
                if (!visited[v]) {
                    relaxDistance(distances, u, v, w);
                    priorityQueue.emplace(distances[v], v);
                }
            }
        }

        return distances;
    }

private:
    bool directed_ = false;
    NodeValuesContainerType nodeValues_;
    AdjContainerType adj_;
};

}

#endif //LEETCODE_GRAPH_H
