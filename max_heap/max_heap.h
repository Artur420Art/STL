#ifndef max_heap
#define max_heap
#include <iostream>
#include <vector>

class Heap {
private:
    std::vector<int> heap;
    int parent(const int& index);
    int leftChild(const int& index);
    int rightChild(const int& index);
    void heapify(int index);
    void swap(int x, int y);

public:
    void insert(int value);
    void erase();
    Heap();
    void print();
    int extractMax();
    void decrisKey(int index, int value);
};

#endif //max_heap