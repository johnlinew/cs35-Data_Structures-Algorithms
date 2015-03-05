// Implement your maze-solving program here.  Your solution should
// solve the maze twice, once using depth-first search and once using
// breadth-first search.  Be sure to use good top-down design principles
// Camden Wagner 10/22/13
#include <iostream>
#include "circularArrayList.h"
#include "stack.h"
#include "arrayStack.h"
#include "arrayQueue.h"
#include "position.h"
#include "maze.h"

//Add include files

using namespace std;
void depthFirstSearch(Maze* maze);
void breadthFirstSearch(Maze* maze2);
int main() {

  int rows, cols;
  int wallNum;
  cout << "How many rows are in the maze?  ";
  cin >> rows;
  cout << "How many columns are in the maze?  ";
  cin >> cols;
  Maze* maze = new Maze(rows, cols);
  Maze* maze2 = new Maze(rows, cols);
  cout << "How many walls does this maze have?  ";
  cin >> wallNum;
  cout << "Please enter the row and column position for each one of the " << wallNum << " walls: " << endl;
  for (int i = 0; i < wallNum; i++) {
    int xPos, yPos;
    cin >> xPos >> yPos;
    if (xPos == rows-1 && yPos == cols-1)
      throw runtime_error("You cannot add a wall to the location of the maze end.");
    maze->setWall(yPos+1, xPos+1);
    maze2->setWall(yPos+1, xPos+1);
  }
  cout << endl;
  maze->print();
  cout << endl;

  depthFirstSearch(maze);
  breadthFirstSearch(maze2);
  delete maze;
  delete maze2;

  return 0;

}//executes depth first search using a stack. takes in a maze 
void depthFirstSearch(Maze* maze){

  cout << "Searching with stack... ";
  ArrayStack<Position*> arrStack;
  arrStack.push(maze->getPos(0,0));
  maze->getPos(0,0)->setVisited();
  maze->getPos(0,0)->setPath();
  bool PATH_FOUND;
  Position* current;
  while (!arrStack.isEmpty()) {
    current = arrStack.pop();
    if (maze->isExit(current)) {
      PATH_FOUND = true;
      break;
    }
    List<Position*>* list = maze->getNeighbors(current);
    int listSize=list->getSize();
    for (int i = 0; i < listSize; i++) {
      if (!(list->peekHead()->isVisited())) {
        (list->peekHead())->setVisited();
        (list->peekHead())->setPrevious(current);
        arrStack.push(list->peekHead());
        list->removeHead();
      } else {
        list->removeHead();
      }
    }
    delete list;
  }
  if (PATH_FOUND) {
    cout << "found a path." << endl;
    maze->reportPath();
  } else {
    cout << "no path was found." << endl;
  }
}

//executes breadth first search using a queue. Takes in a maze
void breadthFirstSearch(Maze* maze2) {

  cout << "Searching with queue... ";

  ArrayQueue<Position*> arrQueue;
  arrQueue.enqueue(maze2->getPos(0,0));
  maze2->getPos(0,0)->setVisited();
  maze2->getPos(0,0)->setPath();
  bool PATH_FOUND2;
  Position* current2;
  while (!arrQueue.isEmpty()) { 
    current2 = arrQueue.dequeue();
    if (maze2->isExit(current2)) {
      PATH_FOUND2 = true;
      break;
    }
    List<Position*>* list = maze2->getNeighbors(current2);
    int listSize=list->getSize();
    for (int i = 0; i < listSize; i++) {
      if (!(list->peekHead()->isVisited())) {
        (list->peekHead())->setVisited();
        (list->peekHead())->setPrevious(current2);
        arrQueue.enqueue(list->peekHead());
        list->removeHead();
      } else {
        list->removeHead();
      }
    }
    delete list;
  }
  if (PATH_FOUND2) {
    cout << "found a path." << endl;
    maze2->reportPath();
  } else {
    cout << "no path was found." << endl;
  }
}
