//
// Created by phelipealves on 7/7/16.
//

#ifndef DIJKSTRA_HEAP_COMPREMINHEAP_H
#define DIJKSTRA_HEAP_COMPREMINHEAP_H

#include "HeapNode.h"

class CompareMinHeap {

public:
    bool operator()(HeapNode & i, HeapNode & j) const;
};


#endif //DIJKSTRA_HEAP_COMPREMINHEAP_H
