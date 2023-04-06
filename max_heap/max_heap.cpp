#include "max_heap.h"
int Heap::parent(const int& i) {
    return (i - 1) / 2;  
}
int Heap::leftChild(const int& i) {
    return 2 * i + 1;
}

int Heap::rightChild(const int& i) {
    return 2 * i + 2;
}
void Heap::swap(int x, int y) {
        int temp = heap[x];
        heap[x] = heap[y];
        heap[y] = temp;
}
void Heap::heapify(int i) {
    int largest = i;
    int l = leftChild(i);
    int r = rightChild(i);

    if (l < heap.size() && heap[largest] < heap[l]) {
        largest = l;
    }
    if (r < heap.size() && heap[largest] < heap[r]) {
        largest = r;
    }
    if (largest != i) {
        std::swap (heap[i], heap[largest]);
        heapify(largest);
    }

}
Heap::Heap() {
    
}

void Heap::insert(int value) {
    this->heap.push_back(value);
    int i = heap.size() - 1;

    while (i >= 0 && heap[i] > heap[parent(i)]) {
        swap(i, parent(i));
        i = parent(i);
    }
}
void Heap::erase() {
    if (heap.size() == 0) {
        return;
    }
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    heapify(0);
}
void Heap::print() {
    for (auto x : heap) {
        std::cout << x << " ";
    }
}
int Heap::extractMax() {
    if (heap.size() == 0) {
        return -1;
    }
    int max = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    heapify(0);
    return max;
}

void Heap::decrisKey(int index, int value) {
    
}