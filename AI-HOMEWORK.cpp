#include <iostream>
#include <vector>
#include "Graph.h"
#include "DFS.h"
#include "UniformCostSearch.h"
#include "AStarSearch.h"

using namespace std;

int main() {
    // Create a graph with 5 vertices
    Graph graph(5);
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 20);
    graph.addEdge(1, 3, 30);
    graph.addEdge(1, 4, 40);
    graph.addEdge(2, 3, 50);
    graph.addEdge(3, 4, 60);

    // Perform DFS traversal
    vector<bool> visited(graph.V, false);
    cout << "Depth-First Search traversal starting from vertex 0: ";
    DFS(graph, 0, visited);
    cout << endl;

    // Perform Uniform Cost Search
    cout << "Uniform Cost Search from vertex 0 to vertex 4: ";
    uniformCostSearch(graph, 0, 4);

    // Perform A* Search
    cout << "A* Search from vertex 0 to vertex 4: ";
    aStarSearch(graph, 0, 4);

    return 0;
}
