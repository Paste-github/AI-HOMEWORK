#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Graph.h"
#include "DFS.h"
#include "UniformCostSearch.h"
#include "AStarSearch.h"

using namespace std;

int main() {
    // Declare the input file
    ifstream fin("input.txt");
    if (!fin.is_open()) {
        cerr << "Error: Unable to open input file." << endl;
        return EXIT_FAILURE;
    }

    // Read the number of vertices from the input file
    int numVertices;
    fin >> numVertices;

    // Create a 2D vector to store the adjacency matrix
    vector<vector<int>> adjacencyMatrix(numVertices, vector<int>(numVertices, 0));

    // Read the adjacency matrix from the input file
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            fin >> adjacencyMatrix[i][j];
        }
    }

    // Close the input file
    fin.close();

    // Create a Graph object using the adjacency matrix
    Graph graph(adjacencyMatrix);

    // Perform DFS traversal
    vector<bool> visited(numVertices, false);
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
