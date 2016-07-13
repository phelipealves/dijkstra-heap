#include "DAryHeap.h"

DAryHeap::DAryHeap(int dNumChild) {
    size = 0;
    this->dNumChild = dNumChild;
    position = new std::map<int, int>();
    heap = new std::vector<HeapNode*>();
    initialize();
}

void DAryHeap::initialize() {
    // Insert firsts (not usable) elements
    for(int i = 0; i < getInitialIndex(); i++) {
        heap->push_back(new HeapNode(INT_MIN, INT_MIN));
    }
}

int DAryHeap::parent(int elementIndex) {
    return (((elementIndex - 2) + dNumChild) / dNumChild) + (getInitialIndex() - 1);
}

int DAryHeap::kthChild(int elementIndex, int kChild) {
    return (dNumChild * (elementIndex - getInitialIndex())) + kChild + getInitialIndex();
}

void DAryHeap::heapifyUp(int elementIndex) {
    if(isEmpty()) {
        return;
    }

    HeapNode* tmp = heap->at((unsigned long) elementIndex);
    HeapNode* parent = heap->at((unsigned long) this->parent(elementIndex));
    int auxPosition;

    while (elementIndex > getInitialIndex() && HeapNode::compareMinimum(*tmp, *parent))
    {
        auxPosition = position->at(parent->getVertex());
        moveNodePosition(parent, elementIndex);
        elementIndex = auxPosition;

        auxPosition = this->parent(auxPosition);
        if(auxPosition < getInitialIndex()) {
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
    while (kthChild(elementIndex, 1) <= getLastIndex())
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
    for(int k = 1; ((k < dNumChild) && ((firstChild+k) <= getLastIndex())); k++) {
        if (HeapNode::compareMinimum(*heap->at((unsigned long) (firstChild+k)),
                                     *heap->at((unsigned long) bestChild))) {
            bestChild = firstChild + k;
        }
    }
    return bestChild;
}

void DAryHeap::moveNodePosition(HeapNode *node, int position) {
    heap->at((unsigned long) position) = node;
    (*this->position)[node->getVertex()] = position;
}

/** Override methods **/
int DAryHeap::getInitialIndex() {
    return FIRST_ELEMENT_INDEX;
}

int DAryHeap::getLastIndex() {
    return (size + getInitialIndex() - 1);
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
    int nodePosition = getLastIndex();
    (*this->position)[node->getVertex()] = nodePosition;
}

void DAryHeap::push(HeapNode *node) {
    simplePush(node);
    heapifyUp(getLastIndex());
}

HeapNode DAryHeap::pop() {
    if (isEmpty()) {
        return HeapNode(INT_MIN, INT_MIN);
    }

    HeapNode* topNode = heap->at((unsigned long) getInitialIndex());
    HeapNode* lastNode = heap->at((unsigned long) getLastIndex());
    moveNodePosition(lastNode, getInitialIndex());

    heap->erase(heap->begin()+ getLastIndex());
    position->erase(topNode->getVertex());
    size--;
    heapifyDown(getInitialIndex());
    return *topNode;
}

HeapNode DAryHeap::top() {
    return *heap->at((unsigned long) getInitialIndex());
}

void DAryHeap::setVertexDistance(int vertex, int distance) {
    // Get the index of v in  heap array
    int vertexPosition = position->at(vertex);

    // Get the node and update its dist value
    HeapNode* node = heap->at((unsigned long) vertexPosition);
    node->setDistance(distance);
    int minChildIndex = this->minChild(vertexPosition);
    if(minChildIndex <= getLastIndex() &&
       HeapNode::compareMinimum(*heap->at((unsigned long) minChildIndex), *node)) {
        heapifyDown(vertexPosition);
    } else {
        heapifyUp(vertexPosition);
    }
}

bool DAryHeap::isVertexInHeap(int vertex) {
    return position->count(vertex) == 1;
}

int DAryHeap::getTreeHeight() {
    return (int)(isEmpty() ? -1 : (Utils::log_x(dNumChild - 1, dNumChild) + Utils::log_x(size, dNumChild)));
}
