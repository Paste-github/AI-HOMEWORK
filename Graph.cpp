#include "Graph.h"

// Constructor definition
Graph::Graph(const std::vector<std::vector<int>>& adjacencyMatrix) : adj(adjacencyMatrix), V(adjacencyMatrix.size()) {}
