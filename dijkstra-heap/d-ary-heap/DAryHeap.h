#ifndef DIJKSTRA_HEAP_DARYHEAP_H
#define DIJKSTRA_HEAP_DARYHEAP_H

#include <limits.h>
#include <iostream>
#include <Utils.h>
#include <AbstractHeap.h>
#include <graph/Vertex.h>
#include <graph/Graph.h>

#define INITIAL_INDEX 1
#define FIRST_CHILD 1

class DAryHeap: public AbstractHeap
{
private:
    int dNumChild;
    int initialVertexId;

    /**
     * Returns the index of parent element.
     */
    int parent(int elementIndex);

    /**
     * Returns the index of k child of element.
     */
    int kthChild(int elementIndex, int kChild);

    /**
     * Ups some element to correctly position position.
     */
    void heapifyUp(int vertex);

    /**
     * Downs some element to correctly position position.
     */
    void heapifyDown(int vertex);

    /**
     * Returns the minimum child of some element.
     */
    int minChild(int index);

    /**
     * Switch vertices positions
     */
    void switchVerticesPositions(int vertex1, int vertex2);

    /**
     * Gets the vertex position in heap.
     */
    int getVertexPosition(int vertex);

protected:
    /** Override methods **/
    virtual int getInitialIndex() override;

    virtual int getLastIndex() override;

public:
    /**
     * Constructor method.
     */
    DAryHeap(int dNumChild, Graph* graph);

    /** Override methods **/
    virtual bool isEmpty() override;

    virtual Vertex* pop() override;

    virtual Vertex* top() override;

    virtual void setVertexDistance(int vertex, int distance) override;

    virtual bool isVertexInHeap(int vertex) override;

    virtual int getTreeHeight() override;

    virtual int getSize() override;
};


#endif //DIJKSTRA_HEAP_DARYHEAP_H
