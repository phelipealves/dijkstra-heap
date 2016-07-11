#include <iostream>
#include <MinHeap.h>

using namespace std;

int main() {

//    MinHeap *m = new MinHeap(11);
//    m->insertKey(10);
//    m->insertKey(2);

    MinHeap h(11);
    h.insertKey(10);
    h.insertKey(45);
    h.insertKey(4);
    h.insertKey(9);
    h.insertKey(16);
    h.insertKey(1);

    int size = h.size();
    for (int i = 0; i < size ; ++i) {
        cout << " " << h.extractMin();
    }

    return 0;
}