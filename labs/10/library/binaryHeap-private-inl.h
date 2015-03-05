#include<iostream>
#include<stdexcept>
using namespace std;

template<typename P, typename V>
void BinaryHeap<P,V>::expandCapacity(){
  int newCapacity = 2*capacity;
   Pair<P,V>* newArray = new Pair<P,V>[newCapacity];
   for (int i = 0; i < capacity; ++i) {
     newArray[i] = items[i];
   }
   delete [] items;
   items = newArray;
   capacity = newCapacity;
}


template <typename P, typename V>
void BinaryHeap<P,V>::bubbleUp(int current){
  if (current==0){
    return;
  }
  int parent= getParent(current);
  if (items[current].first < items[parent].first){
    swap(current,parent);
    bubbleUp(parent);
  }
  else{
    return;
  }
}




template <typename P, typename V>
void BinaryHeap<P,V>::bubbleDown(int current){
  int rightChild= getRight(current);
  int leftChild= getLeft(current);
  if (leftChild >= size){
    return;
  }
  
  if (items[current].first < items[rightChild].first && items[current].first < items[leftChild].first){
    return;
  }
  if (items[current].first > items[rightChild].first && items[current].first > items[leftChild].first) {
    if (items[rightChild].first > items[leftChild].first) {
      swap(leftChild, current);
      bubbleDown(leftChild);
    } else {
      swap(rightChild, current);
      bubbleDown(rightChild);
    }
  } else if (items[current].first > items[rightChild].first) {
    swap(rightChild, current);
    bubbleDown(rightChild);
  } else if (items[current].first > items[leftChild].first) {
    swap(leftChild, current);
    bubbleDown(leftChild);
  }

}

  



template <typename P, typename V> 
void BinaryHeap<P,V>::swap(int current, int index) {
  Pair<P,V> tmp=items[current];
  items[current] = items[index];
  items[index] = tmp;
}

template <typename P, typename V>
int BinaryHeap<P,V>::getParent(int current){
  return (current-1)/2;
}


template <typename P, typename V>
int BinaryHeap<P,V>::getRight(int current){
  return 2*current +2;
}

template <typename P, typename V>
int BinaryHeap<P,V>::getLeft(int current){
  return 2*current +1;
}
