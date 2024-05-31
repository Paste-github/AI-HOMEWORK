#include "AStarSearch.h"
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

struct Node {
    int vertex, cost, heuristic;
    bool operator>(const Node& other) const {
        return (cost + heuristic) > (other.cost + other.heuristic);
    }
};

int heuristic(int current, int goal) {
    // Dummy heuristic function, replace with an actual heuristic
    return std::abs(goal - current);
}

void aStarSearch(Graph& graph, int start, int goal) {
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;
    std::vector<int> dist(graph.V, INT_MAX);
    pq.push({ start, 0, heuristic(start, goal) });
    dist[start] = 0;

    while (!pq.empty()) {
        int v = pq.top().vertex;
        int d = pq.top().cost;
        pq.pop();

        if (v == goal) {
            std::cout << "A* Path Cost: " << d << std::endl;
            return;
        }

        for (int u = 0; u < graph.V; ++u) {
            if (graph.adj[v][u] != 0 && d + graph.adj[v][u] < dist[u]) {
                dist[u] = d + graph.adj[v][u];
                pq.push({ u, dist[u], heuristic(u, goal) });
            }
        }
    }
}
