//
// Created by fyabc on 2021/4/24.
//

#include "gtest/gtest.h"
#include "support/IO.h"
#include "support/graph/Graph.h"
#include "support/graph/GraphIO.h"

using namespace std;
namespace lg = leetcode::graph;

TEST(TestGraph, Basic) {

}

TEST(TestGraph, IO) {
    lg::Graph<string> graph {
        {"a", "b", "c", "d", "e"},
        {
            {1, 3, 8},
            {0, 2, 10},
            {1, 2, 5},
            {0, 1, 7},
            {3, 4, 3},
            {1, 4, 6},
            {0, 3, 11},
        }
    };

    EXPECT_EQ(lg::toString(graph), "Graph {\n"
                                   "\t0 [value=a]\n"
                                   "\t1 [value=b]\n"
                                   "\t2 [value=c]\n"
                                   "\t3 [value=d]\n"
                                   "\t4 [value=e]\n"
                                   "\n"
                                   "\t0 -- 2 [weight=10]\n"
                                   "\t0 -- 1 [weight=7]\n"
                                   "\t0 -- 3 [weight=11]\n"
                                   "\t1 -- 3 [weight=8]\n"
                                   "\t1 -- 2 [weight=5]\n"
                                   "\t1 -- 4 [weight=6]\n"
                                   "\t3 -- 4 [weight=3]\n"
                                   "}");

    vector<vector<int>> myEdges;
    for (const auto& edge: graph.edgesView()) {
        myEdges.push_back(vector<int> {std::get<0>(edge), std::get<1>(edge), std::get<2>(edge)});
    }

    vector<vector<int>> v2 {{0, 2, 10}, {0, 1, 7}, {0, 3, 11}, {1, 3, 8}, {1, 2, 5}, {1, 4, 6}, {3, 4, 3}};
    EXPECT_EQ(myEdges, v2);

    auto minDistancesTo0 = graph.dijkstra(0);
    vector<int> v3 {0, 7, 10, 11, 13};
    EXPECT_EQ(minDistancesTo0, v3);
}
