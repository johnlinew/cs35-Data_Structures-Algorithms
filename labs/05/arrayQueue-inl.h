//inline implementation for arrayQueue. This will be used in BFS.
#include "queue.h"
#include"circularArrayList.h"
#include "arrayQueue.h"
#include <stdexcept>
using namespace std;

template <typename T>
ArrayQueue<T>::ArrayQueue() :Queue<T>() {

}
template <typename T>
ArrayQueue<T>::~ArrayQueue(){

}
//takes in an item of type T and inserts at end of queue
template <typename T>
void ArrayQueue<T>::enqueue(T item) {
 items.insertAtTail(item);

  
}
//removes first item in queue
template <typename T>
T ArrayQueue<T>::dequeue() {
  return items.removeHead();

}
//returns the value of the first item in queue
template <typename T>
T ArrayQueue<T>::getFront() {
  return items.peekHead();
}
//returns the size of the queue
template <typename T>
int ArrayQueue<T>::getSize() {
 return items.getSize();
  
}
//returns a bool if the queue is empty or not
template <typename T>
bool ArrayQueue<T>::isEmpty() {
 return items.isEmpty();
  
}

