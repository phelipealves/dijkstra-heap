#include "DAryHeap.h"

DAryHeap::DAryHeap(int dNumChild, Graph* graph) {
    this->dNumChild = dNumChild;

    int numVertices = graph->getNumVertices();
    this->heap = new std::vector<Vertex*>((unsigned long) (numVertices + INITIAL_INDEX + 1));
    this->positions = new std::vector<int>((unsigned long) (numVertices + 1));
    size = numVertices;
    initialVertexId = graph->getInitialVertex();

    // initialize heap based on vertices
    std::vector<Vertex*> *graphVertices = graph->getVertices();
    for(int i = 0; i < numVertices; i++) {
        (*heap)[i+getInitialIndex()] = (*graphVertices)[i];
        (*positions)[i] = i+getInitialIndex();
    }
}

int DAryHeap::parent(int elementIndex) {
    return (((elementIndex - 2) + dNumChild) / dNumChild) + (getInitialIndex() - 1);
}

int DAryHeap::kthChild(int elementIndex, int kChild) {
    return (dNumChild * (elementIndex - getInitialIndex())) + kChild + getInitialIndex();
}

int DAryHeap::getVertexPosition(int vertex) {
    return (*positions)[vertex-initialVertexId];
}

void DAryHeap::switchVerticesPositions(int vertex1, int vertex2) {
    int vertex1Pos = getVertexPosition(vertex1);
    int vertex2Pos = getVertexPosition(vertex2);
    (*positions)[vertex1-initialVertexId] = vertex2Pos;
    (*positions)[vertex2-initialVertexId] = vertex1Pos;

    Vertex *aux = (*heap)[vertex1Pos];
    (*heap)[vertex1Pos] = (*heap)[vertex2Pos];
    (*heap)[vertex2Pos] = aux;
}

void DAryHeap::heapifyUp(int vertex) {
    int vertexPosition = getVertexPosition(vertex);
    int parentPosition = this->parent(vertexPosition);
    Vertex* vertexObj = (*heap)[vertexPosition];
    Vertex* parentObj = (*heap)[parentPosition];

    while (vertexPosition > getInitialIndex() && Vertex::compareMinimum(vertexObj, parentObj))
    {
        switchVerticesPositions(parentObj->getId(), vertexObj->getId());
        vertexPosition = parentPosition;
        parentPosition = this->parent(vertexPosition);
        vertexObj = (*heap)[vertexPosition];
        parentObj = (*heap)[parentPosition];
    }
}

void DAryHeap::heapifyDown(int vertex) {
    int vertexPosition = getVertexPosition(vertex);
    Vertex* vertexObj = (*heap)[vertexPosition];
    int minChildPosition;
    Vertex* minChild;

    // While elementIndex have at least one child...
    while (kthChild(vertexPosition, FIRST_CHILD) <= getLastIndex())
    {
        minChildPosition = this->minChild(vertexPosition);
        minChild = (*heap)[minChildPosition];
        if(!Vertex::compareMinimum(minChild, vertexObj)) {
            break;
        }

        switchVerticesPositions(minChild->getId(), vertexObj->getId());
        vertexPosition = minChildPosition;
        vertexObj = (*heap)[vertexPosition];
    }
}

int DAryHeap::minChild(int index) {
    int firstChild = kthChild(index, FIRST_CHILD);
    int bestChild = firstChild;
    for(int k = 1; ((k < dNumChild) && ((firstChild+k) <= getLastIndex())); k++) {
        if (Vertex::compareMinimum((*heap)[(firstChild+k)], (*heap)[bestChild])) {
            bestChild = firstChild + k;
        }
    }
    return bestChild;
}

/** Override methods **/
int DAryHeap::getInitialIndex() {
    return INITIAL_INDEX;
}

int DAryHeap::getLastIndex() {
    return (size + getInitialIndex() - 1);
}

bool DAryHeap::isEmpty() {
    return size == 0;
}

Vertex* DAryHeap::pop() {
    if (isEmpty()) {
        return nullptr;
    }

    Vertex* topNode = (*heap)[getInitialIndex()];
    Vertex* lastNode = (*heap)[getLastIndex()];
    switchVerticesPositions(lastNode->getId(), topNode->getId());
    (*positions)[topNode->getId()-initialVertexId] = getInitialIndex() - 1;
    size--;

    if(!isEmpty()) {
        heapifyDown(lastNode->getId());
    }
    return topNode;
}

Vertex * DAryHeap::top() {
    return (*heap)[getInitialIndex()];
}

void DAryHeap::setVertexDistance(int vertex, int distance) {
    int vertexPosition = getVertexPosition(vertex);
    Vertex* node = (*heap)[vertexPosition];
    node->setDistance(distance);

    int minChildIndex = this->minChild(vertexPosition);
    if(minChildIndex <= getLastIndex() && Vertex::compareMinimum((*heap)[minChildIndex], node)) {
        heapifyDown(vertex);
    } else {
        heapifyUp(vertex);
    }
}

bool DAryHeap::isVertexInHeap(int vertex) {
    return (vertex >= initialVertexId && vertex < (initialVertexId + positions->size() - 1) &&
            (*positions)[vertex-initialVertexId] >= getInitialIndex());
}

int DAryHeap::getTreeHeight() {
    return (int)(isEmpty() ? -1 : (Utils::log_x(dNumChild - 1, dNumChild) + Utils::log_x(size, dNumChild)));
}

int DAryHeap::getSize() {
    return size;
}

void DAryHeap::insert(Vertex *vertex) {
    // is full heap
    if (heap->size() == size) {
        return;
    }

    (*heap)[size++] = vertex;
    heapifyUp(size);
}

void DAryHeap::simplePush(Vertex *node) {
    heap->push_back(node);
    size++;
    int nodePosition = getLastIndex();
    (*this->positions)[node->getId()] = nodePosition;
}

void DAryHeap::push(Vertex *node) {
    simplePush(node);
    heapifyUp(getLastIndex());
}

int DAryHeap::getTreeHeight(int size, int dNumChild) {
    return (int)((size == 0) ? -1 : (Utils::log_x(dNumChild - 1, dNumChild) + Utils::log_x(size, dNumChild)));
}

int DAryHeap::getDNumChild() {
    return dNumChild;
}

