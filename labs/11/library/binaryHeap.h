#ifndef BINARYHEAP_H_
#define BINARYHEAP_H_
#include "pair.h"
#include "priorityQueue.h" 
template <typename P, typename V>
class BinaryHeap: public PriorityQueue<P,V>{
  private:
    int size;
    int capacity;
    Pair<P,V>* items;
  
  
  public:
    BinaryHeap();
    ~BinaryHeap();
    void insert(P priority, V value);
    V removeMin();
    V getMin();
    P getMinPriority();
    int getSize();
    bool isEmpty();

  private:
    void expandCapacity();
    void bubbleUp(int current);//Void?
    void bubbleDown(int current);
    void swap (int current, int index);
    int getParent(int current);
    int getRight(int current);
    int getLeft(int current);

};


#include "binaryHeap-inl.h"
#include "binaryHeap-private-inl.h"


#endif
