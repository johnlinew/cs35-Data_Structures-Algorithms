#ifndef ARRAYQUEUE_H_
#define ARRAYQUEUE_H_
#include "queue.h"
#include "circularArrayList.h"

template <typename T>
class ArrayQueue : public Queue<T> {
  private:
    CircularArrayList<T> items;
  public:
    ArrayQueue();
    ~ArrayQueue();
    void enqueue(T item);
    T dequeue();
    T getFront();
    int getSize();
    bool isEmpty();

    
};

#include "arrayQueue-inl.h"

#endif

