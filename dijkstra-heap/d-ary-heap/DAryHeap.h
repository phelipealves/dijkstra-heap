#ifndef DIJKSTRA_HEAP_DARYHEAP_H
#define DIJKSTRA_HEAP_DARYHEAP_H

#include <limits.h>
#include <iostream>
#include <HeapNode.h>
#include <Utils.h>
#include <AbstractHeap.h>

#define FIRST_ELEMENT_INDEX 1
#define FIRST_CHILD 1

class DAryHeap: public AbstractHeap
{
private:
    int dNumChild;

    /**
     * Initializes the heap.
     */
    void initialize();

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
    void heapifyUp(int elementIndex);

    /**
     * Downs some element to correctly position position.
     */
    void heapifyDown(int elementIndex);

    /**
     * Returns the minimum child of some element.
     */
    int minChild(int index);

    /**
     * Modes node to some position in heap.
     */
    void moveNodePosition(HeapNode *node, int position);

protected:
    /** Override methods **/
    virtual int getInitialIndex() override;

    virtual int getLastIndex() override;

public:
    /**
     * Constructor method.
     */
    DAryHeap(int dNumChild);

    /** Override methods **/
    virtual bool isEmpty() override;

    virtual void clear() override;

    virtual void simplePush(HeapNode *node) override;

    virtual void push(HeapNode *node) override;

    virtual HeapNode pop() override;

    virtual HeapNode top() override;

    virtual void setVertexDistance(int vertex, int distance) override;

    virtual bool isVertexInHeap(int vertex) override;

    virtual int getTreeHeight() override;
};


#endif //DIJKSTRA_HEAP_DARYHEAP_H
