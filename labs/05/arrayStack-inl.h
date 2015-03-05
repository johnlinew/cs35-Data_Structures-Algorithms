// Inline implementation for arrayStack, will be used for DFS.
#include "stack.h"
#include"circularArrayList.h"
#include "arrayStack.h"
#include <stdexcept>
using namespace std;

template <typename T>
ArrayStack<T>::ArrayStack():Stack<T>() {

}
template <typename T>
ArrayStack<T>::~ArrayStack(){

}
//takes in an item of type T and inserts at the beginning of the stack
template <typename T>
void ArrayStack<T>::push(T item) {
 return items.insertAtHead(item);

  
}
//removes the first item in the stack and returns it 
template <typename T>
T ArrayStack<T>::pop() {
  return items.removeHead();

}
//returns the value of the first item in the stack
template <typename T>
T ArrayStack<T>::getTop() {
 return items.peekHead();
  
}
//returns the size of the stack
template <typename T>
int ArrayStack<T>::getSize() {
 return items.getSize();
  
}
//returns a bool saying whether or not the stack is empty
template <typename T>
bool ArrayStack<T>::isEmpty() {
 return items.isEmpty();
  
}



