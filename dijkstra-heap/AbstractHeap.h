#ifndef DIJKSTRA_HEAP_ABSTRACTHEAP_H
#define DIJKSTRA_HEAP_ABSTRACTHEAP_H

#include <map>
#include <vector>
#include "HeapNode.h"

class AbstractHeap {
protected:
    int size;
    std::vector<HeapNode*> *heap;
    std::map<int, int> *position;

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
     * Clears the position.
     */
    virtual void clear() = 0;

    /**
     * Pushes some element into the position.
     */
    virtual void simplePush(HeapNode *node) = 0;
    virtual void push(HeapNode *node) = 0;

    /**
     * Pops the top element from the position.
     * Returns the top element and after, removes it from the position.
     */
    virtual HeapNode pop() = 0;

    /**
     * Returns the top element of position.
     */
    virtual HeapNode top() = 0;

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
     * Prints the heap list.
     */
    void print() {
        std::cout << "Heap:" << std::endl;
        HeapNode *node;
        for(int i = getInitialIndex(); i <= getLastIndex(); i++) {
            node = heap->at((unsigned long) i);
            std::cout << node->getDistance() << "\t";
        }
        std::cout << std::endl;
        std::cout.flush();

        for(int i = getInitialIndex(); i <= getLastIndex(); i++) {
            node = heap->at((unsigned long) i);
            std::cout << node->getVertex() << "\t";
        }
        std::cout << std::endl;
        std::cout.flush();
    }
};


#endif //DIJKSTRA_HEAP_ABSTRACTHEAP_H
