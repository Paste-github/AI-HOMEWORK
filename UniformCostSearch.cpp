#include "UniformCostSearch.h"
#include <iostream>
#include <queue>
#include <vector>

struct Node {
    int vertex, cost;
    bool operator>(const Node& other) const {
        return cost > other.cost;
    }
};

void uniformCostSearch(Graph& graph, int start, int goal) {
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;
    std::vector<int> dist(graph.V, INT_MAX);
    pq.push({ start, 0 });
    dist[start] = 0;

    while (!pq.empty()) {
        int v = pq.top().vertex;
        int d = pq.top().cost;
        pq.pop();

        if (v == goal) {
            std::cout << "Least-Cost Path Cost: " << d << std::endl;
            return;
        }

        for (int u = 0; u < graph.V; ++u) {
            if (graph.adj[v][u] != 0 && d + graph.adj[v][u] < dist[u]) {
                dist[u] = d + graph.adj[v][u];
                pq.push({ u, dist[u] });
            }
        }
    }
}
