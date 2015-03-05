#include<iostream>
#include<stdexcept>
using namespace std;

template <typename P, typename V>
BinaryHeap<P,V>::BinaryHeap() {
  size=0;
  capacity=10;
  items=new Pair<P,V>[10];
}
template<typename P, typename V>
BinaryHeap<P,V>::~BinaryHeap() {
  delete [] items;
}

template<typename P, typename V>
void BinaryHeap<P,V>::insert(P priority, V value){
 if(size==capacity){
    expandCapacity();
 }
  
  items[size].first= priority;
  items[size].second= value;
  size++;
  bubbleUp(size-1); 
}

template<typename P, typename V>
V BinaryHeap<P,V>::removeMin(){
  V val=items[0].second;
  items[0]=items[size-1];
  size--;
  bubbleDown(0);
  //cout<<"remove min"<<endl;
  return val;
}

template<typename P, typename V>
V BinaryHeap<P,V>::getMin(){
  return items[0].second;
}

template <typename P, typename V>
P BinaryHeap<P,V>::getMinPriority(){
  return items[0].first;
}

template <typename P, typename V>
int BinaryHeap<P,V>::getSize(){
  return size;
}

template <typename P, typename V>
bool BinaryHeap<P,V>::isEmpty(){
  if (size==0){
    return true;
  }
  return false; 
}

