#ifndef DIJKSTRA_HEAP_ABSTRACTHEAP_H
#define DIJKSTRA_HEAP_ABSTRACTHEAP_H

#include <map>
#include <vector>
#include "graph/Vertex.h"

class AbstractHeap {
protected:
    int size;
    std::vector<Vertex*> *heap;
    std::vector<int> *positions;

    /**
     * Returns the index of first element in heap.
     */
    virtual int getInitialIndex() = 0;

    /**
     * Returns the index of last element in heap.
     */
    virtual int getLastIndex() = 0;

public:
    /**
     * Returns true if the position is empty or not otherwise.
     */
    virtual bool isEmpty() = 0;

    /**
     * Pops the top element from the position.
     * Returns the top element and after, removes it from the position.
     */
    virtual Vertex* pop() = 0;

    /**
     * Returns the top element of position.
     */
    virtual Vertex* top() = 0;

    /**
     * Insert a new vertex
     */
    virtual void insert(Vertex* vertex) = 0;

    /**
     * Sets the vertex distance.
     */
    virtual void setVertexDistance(int vertex, int distance) = 0;

    /**
     * Checks if some Vertex is in the Heap.
     */
    virtual bool isVertexInHeap(int vertex) = 0;

    /**
     * Returns position tree height
     */
    virtual int getTreeHeight() = 0;

    /**
     * Returns heap size
     */
    virtual int getSize() = 0;

    virtual void simplePush(Vertex *node) = 0;

    virtual void push(Vertex *node) = 0;
};


#endif //DIJKSTRA_HEAP_ABSTRACTHEAP_H
