//
// Created by bruno on 7/11/16.
//

#include "DAryHeap.h"

#define INT_MIN -1
#define FIRST_ELEMENT_INDEX 1
#define FIRST_CHILD 1

DAryHeap::DAryHeap(int dNumChild) {
    size = 0;
    this->dNumChild = dNumChild;
    heap = new std::vector<int>();

    // Insert first (not usable) elements
    for(int i = 0; i < FIRST_ELEMENT_INDEX; i++) {
        heap->push_back(INT_MIN);
    }
}

bool DAryHeap::isEmpty() {
    return size == 0;
}

void DAryHeap::clear() {
    size = 0;
}

void DAryHeap::push(int element) {
    heap->push_back(element);
    size++;
    heapifyUp(getLastElementIndex());
}

int DAryHeap::pop() {
    if (isEmpty()) {
        return INT_MIN;
    }

    int keyItem = heap->at(FIRST_ELEMENT_INDEX);

    heap->at(FIRST_ELEMENT_INDEX) = heap->at((unsigned long) getLastElementIndex());
    heap->at((unsigned long) getLastElementIndex()) = INT_MIN;
    size--;
    heapifyDown(FIRST_ELEMENT_INDEX);
    return keyItem;
}

int DAryHeap::top() {
    return heap->at(FIRST_ELEMENT_INDEX);
}

void DAryHeap::print() {
    std::cout << "DAry Heap = ";
    for(int i = FIRST_ELEMENT_INDEX; i <= getLastElementIndex(); i++) {
        std::cout << heap->at((unsigned long) i) << " ";
    }
    std::cout << "\n";
}

int DAryHeap::getLastElementIndex() {
    return (size + FIRST_ELEMENT_INDEX - 1);
}

int DAryHeap::parent(int elementIndex) {
    return (((elementIndex - 2) + dNumChild) / dNumChild) + (FIRST_ELEMENT_INDEX - 1);
}

int DAryHeap::kthChild(int elementIndex, int kChild) {
    return (dNumChild * (elementIndex - FIRST_ELEMENT_INDEX)) + kChild + FIRST_ELEMENT_INDEX;
}

void DAryHeap::heapifyUp(int elementIndex) {
    int tmp = heap->at((unsigned long) elementIndex);
    int parent;
    while (elementIndex > FIRST_ELEMENT_INDEX && tmp < heap->at((unsigned long) this->parent(elementIndex)))
    {
        parent = this->parent(elementIndex);
        heap->at((unsigned long) elementIndex) = heap->at((unsigned long) parent);
        elementIndex = parent;
    }
    heap->at((unsigned long) elementIndex) = tmp;
}

void DAryHeap::heapifyDown(int elementIndex) {
    int child;
    int tmp = heap->at((unsigned long) elementIndex);

    // While elementIndex have at least one child...
    while (kthChild(elementIndex, 1) <= getLastElementIndex())
    {
        child = minChild(elementIndex);
        if (heap->at((unsigned long) child) < tmp) {
            heap->at((unsigned long) elementIndex) = heap->at((unsigned long) child);
        } else {
            break;
        }
        elementIndex = child;
    }
    heap->at((unsigned long) elementIndex) = tmp;
}

int DAryHeap::minChild(int index) {
    int firstChild = kthChild(index, FIRST_CHILD);
    int bestChild = firstChild;
    for(int k = 1; ((k < dNumChild) && ((firstChild+k) <= getLastElementIndex())); k++) {
        if (heap->at((unsigned long) (firstChild+k)) < heap->at((unsigned long) bestChild)) {
            bestChild = firstChild + k;
        }
    }
    return bestChild;
}



























