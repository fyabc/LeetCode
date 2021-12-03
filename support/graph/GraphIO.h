//
// Created by fyabc on 2021/4/25.
//

#ifndef LEETCODE_GRAPHIO_H
#define LEETCODE_GRAPHIO_H

#include "support/graph/Graph.h"

#include <iostream>
#include <sstream>
#include <string>

namespace leetcode::graph {

template <typename T>
std::string toString(const Graph<T>& graph) {
    using IndexType = typename Graph<T>::IndexType;
    using WeightType = typename Graph<T>::WeightType;

    std::ostringstream os;
    os << "Graph {\n";

    IndexType index = 0;
    for (const auto& nodeValue: graph.nodeValues()) {
        os << "\t" << index << " [value=" << nodeValue << "]\n";
        ++index;
    }

    os << '\n';

    const char* edgeRep = graph.directed() ? " -> " : " -- ";

    for (const auto& edge: graph.edgesView()) {
        os << "\t" << std::get<0>(edge) << edgeRep << std::get<1>(edge) << " [weight=" << std::get<2>(edge) << "]\n";
    }

    os << "}";

    return os.str();
}

template <typename T>
std::ostream& operator<< (std::ostream& os, const Graph<T>& graph) {
    os << toString(graph);
    return os;
}

}

#endif //LEETCODE_GRAPHIO_H
