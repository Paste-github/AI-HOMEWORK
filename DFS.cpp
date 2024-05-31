#include <iostream>
#include "DFS.h"

void DFS(Graph& graph, int v, std::vector<bool>& visited) {
    visited[v] = true;
    std::cout << v << " ";

    for (int u = 0; u < graph.V; ++u) {
        if (graph.adj[v][u] != 0 && !visited[u]) {
            DFS(graph, u, visited);
        }
    }
}
