#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph {
public:
    int V;
    std::vector<std::vector<int>> adj;

    // Constructor
    Graph(const std::vector<std::vector<int>>& adjacencyMatrix);
};

#endif // GRAPH_H
