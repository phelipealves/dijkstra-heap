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
    position = new std::map<int, int>();
    heap = new std::vector<HeapNode*>();
    initialize();
}

void DAryHeap::initialize() {
    // Insert firsts (not usable) elements
    for(int i = 0; i < FIRST_ELEMENT_INDEX; i++) {
        heap->push_back(new HeapNode(INT_MIN, INT_MIN));
    }
}

bool DAryHeap::isEmpty() {
    return size == 0;
}

void DAryHeap::clear() {
    size = 0;
    position->clear();
    heap->clear();
    initialize();
}

void DAryHeap::simplePush(HeapNode *node) {
    heap->push_back(node);
    size++;
    int nodePosition = getLastElementIndex();
    (*this->position)[node->getVertex()] = nodePosition;
}

void DAryHeap::push(HeapNode *node) {
    simplePush(node);
    heapifyUp(getLastElementIndex());
}

HeapNode DAryHeap::pop() {
    if (isEmpty()) {
        return HeapNode(INT_MIN, INT_MIN);
    }

    HeapNode* topNode = heap->at(FIRST_ELEMENT_INDEX);
    HeapNode* lastNode = heap->at((unsigned long) getLastElementIndex());
    moveNodePosition(lastNode, FIRST_ELEMENT_INDEX);

    heap->erase(heap->begin()+getLastElementIndex());
    position->erase(topNode->getVertex());
    size--;
    heapifyDown(FIRST_ELEMENT_INDEX);
    return *topNode;
}

HeapNode DAryHeap::top() {
    return *heap->at(FIRST_ELEMENT_INDEX);
}

void DAryHeap::print() {
    std::cout << "DAry Heap:" << std::endl;
    HeapNode *node;
    for(int i = FIRST_ELEMENT_INDEX; i <= getLastElementIndex(); i++) {
        node = heap->at((unsigned long) i);
        std::cout << node->getDistance() << "\t";
    }
    std::cout << std::endl;
    std::cout.flush();

    for(int i = FIRST_ELEMENT_INDEX; i <= getLastElementIndex(); i++) {
        node = heap->at((unsigned long) i);
        std::cout << node->getVertex() << "\t";
    }
    std::cout << std::endl;
    std::cout.flush();
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
    if(isEmpty()) {
        return;
    }

    HeapNode* tmp = heap->at((unsigned long) elementIndex);
    HeapNode* parent = heap->at((unsigned long) this->parent(elementIndex));
    int auxPosition;

    while (elementIndex > FIRST_ELEMENT_INDEX && HeapNode::compareMinimum(*tmp, *parent))
    {
        auxPosition = position->at(parent->getVertex());
        moveNodePosition(parent, elementIndex);
        elementIndex = auxPosition;

        auxPosition = this->parent(auxPosition);
        if(auxPosition < FIRST_ELEMENT_INDEX) {
            break;
        }
        parent = heap->at((unsigned long) auxPosition);
    }
    moveNodePosition(tmp, elementIndex);
}

void DAryHeap::heapifyDown(int elementIndex) {
    if(isEmpty())  {
        return;
    }

    HeapNode* tmp = heap->at((unsigned long) elementIndex);
    HeapNode* minChild;
    int minChildIndex;

    // While elementIndex have at least one child...
    while (kthChild(elementIndex, 1) <= getLastElementIndex())
    {
        minChildIndex = this->minChild(elementIndex);
        minChild = heap->at((unsigned long) minChildIndex);
        if (HeapNode::compareMinimum(*minChild, *tmp)) {
            moveNodePosition(minChild, elementIndex);
        } else {
            break;
        }
        elementIndex = minChildIndex;
    }
    moveNodePosition(tmp, elementIndex);
}

int DAryHeap::minChild(int index) {
    int firstChild = kthChild(index, FIRST_CHILD);
    int bestChild = firstChild;
    for(int k = 1; ((k < dNumChild) && ((firstChild+k) <= getLastElementIndex())); k++) {
        if (HeapNode::compareMinimum(*heap->at((unsigned long) (firstChild+k)),
                                     *heap->at((unsigned long) bestChild))) {
            bestChild = firstChild + k;
        }
    }
    return bestChild;
}

int DAryHeap::treeHeight() {
    return (int)(isEmpty() ? -1 : (Utils::log_x(dNumChild - 1, dNumChild) + Utils::log_x(size, dNumChild)));
}

void DAryHeap::moveNodePosition(HeapNode *node, int position) {
    heap->at((unsigned long) position) = node;
    (*this->position)[node->getVertex()] = position;
}

void DAryHeap::setVertexDistance(int vertex, int distance) {
    // Get the index of v in  heap array
    int vertexPosition = position->at(vertex);

    // Get the node and update its dist value
    HeapNode* node = heap->at((unsigned long) vertexPosition);
    node->setDistance(distance);
    int minChildIndex = this->minChild(vertexPosition);
    if(minChildIndex <= getLastElementIndex() &&
            HeapNode::compareMinimum(*heap->at((unsigned long) minChildIndex), *node)) {
        heapifyDown(vertexPosition);
    } else {
        heapifyUp(vertexPosition);
    }
}

bool DAryHeap::isVertexInHeap(int vertex) {
    return position->count(vertex) == 1;
}







