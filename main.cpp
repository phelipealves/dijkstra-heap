#include <iostream>
#include <MinHeap.h>
#include <d-ary-heap/DAryHeap.h>

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
    cout << "\n";

    DAryHeap heap(10,4);
    heap.print();
    heap.push(10);
    heap.push(45);
    heap.push(4);
    heap.push(9);
    heap.push(16);
    heap.push(1);
    heap.print();

    cout << heap.pop() << "\n";
    heap.print();
    cout << heap.pop() << "\n";
    heap.print();
    cout << heap.pop() << "\n";
    heap.print();
    cout << heap.pop() << "\n";
    heap.print();
    cout << heap.pop() << "\n";
    heap.print();
    cout << heap.pop() << "\n";
    heap.print();

    cout << "Finished";
}