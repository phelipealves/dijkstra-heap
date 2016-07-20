#ifndef DIJKSTRA_HEAP_VERTEX_H
#define DIJKSTRA_HEAP_VERTEX_H

#include <vector>
#include <climits>
#include "Edge.h"

class Vertex {
private:
    int id;
    int distance;
    std::vector<Edge*> *edges;

public:
    Vertex(int id) {
        this->id = id;
        this->distance = INT_MAX;
        edges = new std::vector<Edge*>();
    }

    int getId(){ return id; }
    int getDistance(){ return distance; }
    void setDistance(int distance){ this->distance = distance; }
    std::vector<Edge*>* getEdges(){ return edges; }

    static bool compareMinimum(Vertex* a, Vertex* b) {
        return a->getDistance() < b->getDistance();
    }
};

#endif //DIJKSTRA_HEAP_VERTEX_H
