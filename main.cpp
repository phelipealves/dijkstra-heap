// C / C++ program for Dijkstra's shortest path algorithm for adjacency
// list representation of graph

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <d-ary-heap/DAryHeap.h>

using namespace std;

// A structure to represent a node in adjacency list
struct AdjListNode
{
    int dest;
    int weight;
    struct AdjListNode* next;
};

// A structure to represent an adjacency liat
struct AdjList
{
    struct AdjListNode *head;  // pointer to head node of list
};

// A structure to represent a graph. A graph is an heap of adjacency lists.
// Size of heap will be V (number of vertices in graph)
struct Graph
{
    int V;
    struct AdjList* array;
};

// A utility function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest, int weight)
{
    struct AdjListNode* newNode =
            (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// A utility function that creates a graph of V vertices
struct Graph* createGraph(int V)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;

    // Create an heap of adjacency lists.  Size of heap will be V
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));

    // Initialize each adjacency list as empty by making head as NULL
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

// Adds an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest, int weight)
{
    // Add an edge from src to dest.  A new node is added to the adjacency
    // list of src.  The node is added at the begining
    struct AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since graph is undirected, add an edge from dest to src also
    newNode = newAdjListNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void printArr(int dist[], int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

// The main function that calulates distances of shortest paths from src to all
// vertices. It is a O(ELogV) function
void dijkstra(struct Graph* graph, int src)
{
    int V = graph->V;   // Get the number of vertices in graph
    int dist[V];        // dist values used to pick minimum weight edge in cut

    // minHeap represents set E
    DAryHeap heap(2);

    for (int v = 0; v < V; ++v) {
        dist[v] = INT_MAX;
        heap.simplePush(new HeapNode(v, dist[v]));
    }

    // Make dist value of src vertex as 0 so that it is extracted first
    // heap.simplePush(src,dist[src]);
    // minHeap->heap[src] = newMinHeapNode(src, dist[src]);
    dist[src] = 0;
    heap.setVertexDistance(src, dist[src]);

    // In the followin loop, min position contains all nodes
    // whose shortest distance is not yet finalized.
    while (!heap.isEmpty())
    {
        // Extract the vertex with minimum distance value
        HeapNode node = heap.pop();
        int u = node.getVertex(); // Store the extracted vertex number

        // Traverse through all adjacent vertices of u (the extracted
        // vertex) and update their distance values
        struct AdjListNode* pCrawl = graph->array[u].head;
        while (pCrawl != NULL)
        {
            int v = pCrawl->dest;

            // If shortest distance to v is not finalized yet, and distance to v
            // through u is less than its previously calculated distance
            if (heap.isVertexInHeap(v) && dist[u] != INT_MAX &&
                pCrawl->weight + dist[u] < dist[v])
            {
                dist[v] = dist[u] + pCrawl->weight;

                // update distance value in min position also
                heap.setVertexDistance(v, dist[v]);
            }
            pCrawl = pCrawl->next;
        }
    }

//
//    // print the calculated shortest distances
    printArr(dist, V);
    cout << "FINISHED" << endl;
    cout.flush();
}


// Driver program to test above functions
int main()
{
    // create the graph given in above fugure
    int V = 9;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 8, 7);

    dijkstra(graph, 0);

    return 0;
}


//#include <iostream>
//#include <MinHeap.h>
//#include <d-ary-heap/DAryHeap.h>
//
//using namespace std;
//
//int main() {
//    DAryHeap position(2);
//    MinHeap h(100);
//    int input[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
//    for (int i = 0; i < 32; ++i) {
//        position.push(input[i%16]);
//        h.insertKey(input[i]);
//    }
//    position.print();
//    h.print();
//
//    cout << position.treeHeight() << endl;
//
////    cout << position.pop() << endl;
////    position.print();
////    cout << position.pop() << endl;
////    position.print();
////    cout << position.pop() << endl;
////    position.print();
////    cout << position.pop() << endl;
////    position.print();
////    cout << position.pop() << endl;
////    position.print();
////    cout << position.pop() << endl;
////    position.print();
////    cout << position.pop() << endl;
////    position.print();
////    cout << position.pop() << endl;
////    position.print();
//
//    cout << "Finished";
//    cout.flush();
//
//    return 0;
//}