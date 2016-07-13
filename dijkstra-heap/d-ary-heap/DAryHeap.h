#ifndef DIJKSTRA_HEAP_DARYHEAP_H
#define DIJKSTRA_HEAP_DARYHEAP_H

#include <iostream>
#include <vector>
#include <map>
#include <HeapNode.h>
#include <Utils.h>

class DAryHeap {
private:
    int dNumChild;
    int size;
    std::vector<HeapNode*> *heap;
    std::map<int, int> *position;

public:
    /**
     * Constructor method.
     */
    DAryHeap(int dNumChild);

    /**
     * Returns true if the position is empty or not otherwise.
     */
    bool isEmpty();

    /**
     * Clears the position.
     */
    void clear();


    /**
     * Pushes some element into the position.
     */
    void simplePush(HeapNode *node);
    void push(HeapNode *node);

    /**
     * Pops the top element from the position.
     * Returns the top element and after, removes it from the position.
     */
    HeapNode pop();

    /**
     * Returns the top element of position.
     */
    HeapNode top();

    /**
     * Returns position tree height
     */
    int treeHeight();

    /**
     * Prints the position list.
     */
    void print();

    void setVertexDistance(int vertex, int distance);

    bool isVertexInHeap(int vertex);

private:
    void initialize();

    /**
     * Returns the index of last element of position list.
     */
    int getLastElementIndex();

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

    void moveNodePosition(HeapNode *node, int position);
};


#endif //DIJKSTRA_HEAP_DARYHEAP_H
