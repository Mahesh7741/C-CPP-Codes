#include <iostream>

using namespace std;

// A structure to represent an adjacency list node
struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};

// A structure to represent an adjacency list
struct AdjList {
    struct AdjListNode* head; // pointer to head node of list
};

// A structure to represent a graph. A graph is an array of adjacency lists
// Size of array will be V (number of vertices in graph)
struct Graph {
    int V;
    struct AdjList* array;
};

// A utility function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest) {
    struct AdjListNode* newNode = new AdjListNode;
    newNode->dest = dest;
    newNode->next = nullptr;
    return newNode;
}

// A utility function that creates a graph of V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = new Graph;
    graph->V = V;

    // Create an array of adjacency lists.  Size of array will be V
    graph->array = new AdjList[V];

    // Initialize each adjacency list as empty by making head as nullptr
    for (int i = 0; i < V; ++i)
        graph->array[i].head = nullptr;

    return graph;
}

// Adds an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest.  A new node is added to the adjacency list of src.
    // The node is added at the beginning
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since graph is undirected, add an edge from dest to src also
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// A utility function to print the adjacency list representation of graph
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->V; ++v) {
        struct AdjListNode* pCrawl = graph->array[v].head;
        cout << "\n Adjacency list of vertex " << v << "\n head ";
        while (pCrawl) {
            cout << "-> " << pCrawl->dest;
            pCrawl = pCrawl->next;
        }
        cout << endl;
    }
}

// A utility function to implement Breadth First Search traversal of a graph
void BFS(struct Graph* graph, int start) {
    // Mark all the vertices as not visited
    bool* visited = new bool[graph->V];
    for (int i = 0; i < graph->V; ++i)
        visited[i] = false;

    // Create a queue for BFS
    int* queue = new int[graph->V];
    int front = 0, rear = 0;

    // Mark the current node as visited and enqueue it
    visited[start] = true;
    queue[rear++] = start;

    while (front != rear) {
        // Dequeue a vertex from queue and print it
        start = queue[front++];
        cout << start << " ";

        // Get all adjacent vertices of the dequeued vertex s
        // If an adjacent vertex has not been visited, then mark it visited and enqueue it
        struct AdjListNode* pCrawl = graph->array[start].head;
        while (pCrawl) {
            if (!visited[pCrawl->dest]) {
                visited[pCrawl->dest] = true;
                queue[rear++] = pCrawl->dest;
            }
            pCrawl = pCrawl->next;
        }
    }
    delete[] visited;
    delete[] queue;
}

// A utility function to implement Depth First Search traversal of a graph
void DFSUtil(struct Graph* graph, int v, bool visited[]) {
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent to this vertex
    struct AdjListNode* pCrawl = graph->array[v].head;
    while (pCrawl) {
        if (!visited[pCrawl->dest])
            DFSUtil(graph, pCrawl->dest, visited);
        pCrawl = pCrawl->next;
    }
}

void DFS(struct Graph* graph, int start) {
    // Mark all the vertices as not visited
    bool* visited = new bool[graph->V];
    for (int i = 0; i < graph->V; ++i)
        visited[i] = false;

    // Call the recursive helper function to print DFS traversal
    DFSUtil(graph, start, visited);

    delete[] visited;
}

int main() {
    // Create a graph given in the example
    int V = 4;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    cout << "BFS starting from vertex 2: ";
    BFS(graph, 2);
    cout << endl;

    cout << "DFS starting from vertex 2: ";
    DFS(graph, 2);
    cout << endl;

    return 0;
}
