#ifndef DIJKSTRA_HEAP_EDGE_H
#define DIJKSTRA_HEAP_EDGE_H

class Edge {
private:
    int destinationVertex;
    int weight;

public:
    Edge(int destinationVertex, int weight) : destinationVertex(destinationVertex), weight(weight) {};
    int getDestinationVertex(){ return destinationVertex; }
    int getWeight(){ return weight; }
};


#endif //DIJKSTRA_HEAP_EDGE_H
