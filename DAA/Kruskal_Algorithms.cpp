#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a graph
struct Graph {
    int V, E; // Number of vertices and edges
    vector<Edge> edges; // Array of edges
};

// Comparator function to sort edges based on their weights
bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Utility function to find the parent of a node
int findParent(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return findParent(parent, parent[i]);
}

// Utility function to perform union of two sets
void unionSets(int parent[], int x, int y) {
    int xset = findParent(parent, x);
    int yset = findParent(parent, y);
    parent[xset] = yset;
}

// Function to find the Minimum Spanning Tree using Kruskal's algorithm
void kruskalMST(Graph graph) {
    vector<Edge> result; // Stores the resultant MST
    int e = 0; // Index variable for sorted edges
    int i = 0; // Index variable for result[]

    // Sort all edges in non-decreasing order of their weight
    sort(graph.edges.begin(), graph.edges.end(), compare);

    // Allocate memory for creating V subsets
    int *parent = new int[graph.V];

    // Initialize all subsets as single element sets
    fill(parent, parent + graph.V, -1);

    // Number of edges to be taken is equal to V-1
    while (e < graph.V - 1 && i < graph.E) {
        // Pick the smallest edge
        Edge next_edge = graph.edges[i++];

        int x = findParent(parent, next_edge.src);
        int y = findParent(parent, next_edge.dest);

        // If including this edge does not cause cycle, include it in result and increment the index
        if (x != y) {
            result.push_back(next_edge);
            unionSets(parent, x, y);
            e++;
        }
    }

    // Print the MST
    cout << "Edges of Minimum Spanning Tree:" << endl;
    for (i = 0; i < result.size(); i++)
        cout << result[i].src << " - " << result[i].dest << " : " << result[i].weight << endl;

    delete[] parent;
}

int main() {
    Graph graph;
    graph.V = 4; // Number of vertices
    graph.E = 5; // Number of edges

    // Edge list
    graph.edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskalMST(graph);

    return 0;
}
