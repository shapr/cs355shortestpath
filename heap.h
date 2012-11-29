#ifndef HEAP_H
#define HEAP_H

class BHeap{
      int * array;
      int size;
      int heapsize;
      public:
             BHeap();
             BHeap(int arraySize);
             int parent(int index);
             int left(int index);
             int right(int index);
             void insert(int data);
             void remove();
             void print();
};
#endif
