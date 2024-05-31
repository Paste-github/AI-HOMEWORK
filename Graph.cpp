#include "Graph.h"

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V, std::vector<int>(V, 0));
}

void Graph::addEdge(int u, int v, int weight) {
    adj[u][v] = weight;
    adj[v][u] = weight; // For an undirected graph
}
