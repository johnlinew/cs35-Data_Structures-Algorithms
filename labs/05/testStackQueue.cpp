#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>

#include <assert.h>
#include "circularArrayList.h"
#include "stack.h"
#include "arrayStack.h"
#include "arrayQueue.h"
#include "position.h"
#include "maze.h"

using namespace std;


int main(){
  ArrayStack<int> test;
  for (int i=0; i<11;i++){
    test.push(i+1);
  }
  test.push(12);
  cout<< test.pop()<<endl;
  cout<< test.getTop()<<endl;
  for (int i=0; i<11;i++){
    test.push(i+12);
  }
  test.push(23);
cout<< test.pop()<<endl;
  cout<< test.getTop()<<endl;

  for (int i=0; i<11;i++){
    test.pop();
   }

cout<<test.getTop()<<endl;
cout<<test.getSize()<<endl;
cout<<test.isEmpty()<<endl;

cout<<"queue test"<<endl;
ArrayQueue<int> test2;
  for (int i=0; i<11;i++){
    test2.enqueue(i+1);
  }
  test2.enqueue(12);
  cout<< test2.dequeue()<<endl;
  cout<< test2.getFront()<<endl;
  for (int i=0; i<11;i++){
    test2.enqueue(i+12);
  }
  test2.enqueue(23);
cout<< test2.dequeue()<<endl;
  cout<< test2.getFront()<<endl;

  for (int i=0; i<11;i++){
    test2.dequeue();
   }

cout<<test2.getFront()<<endl;
cout<<test2.getSize()<<endl;
cout<<test2.isEmpty()<<endl;

Position pos(1,2);

cout<<pos.getX()<<"=x "<<pos.getY()<<"=y "<<endl;

Maze maaze(3,7);
maaze.setWall(3,3);
maaze.setWall(2,4);
maaze.print();
List<Position*>* list = new CircularArrayList<Position*>();
list = maaze.getNeighbors(maaze.getPos(1,1));
cout << list->removeHead()->getX() << " = X" << endl;
cout << list->removeHead()->getX() << " = X" << endl;
cout << list->removeHead()->getX() << " = X" << endl;
cout << list->removeHead()->getX() << " = X" << endl;

cout << maaze.getNeighbors(maaze.getPos(1,0)) << endl;
cout << maaze.getNeighbors(maaze.getPos(1,2)) << endl;
cout << maaze.getNeighbors(maaze.getPos(2,3)) << endl;

  return 0;
}
