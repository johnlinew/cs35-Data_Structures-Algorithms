//maze class implementation that will be searched through 
#include <iostream>
#include <string>
#include "arrayStack.h"
#include "maze.h"
#include "circularArrayList.h"

using namespace std;
//constructor taking in two integers for rows and columns
Maze::Maze(int numRows, int numColumns) {
  this->numRows = numRows;
  this->numColumns = numColumns;
  this->grid = new Position*[numRows];
  for (int i = 0; i < numRows; i++) {//sets x and y values of positions
    grid[i] = new Position[numColumns];
    for (int j = 0; j < numColumns; j++) {
      grid[i][j].setX(i);
      grid[i][j].setY(j);
    }
  }
}

Maze::~Maze() {
  for (int j = 0; j < this->numRows; j++) {
    delete[] grid[j];
  }
  delete[] grid;
}
//returns an integer representing number of rows
int Maze::getRows() {
  return numRows;
}
//returns an integer representing number of columns
int Maze::getColumns() {
  return numColumns;
}
//returns a position pointer at inputted x and y 
Position* Maze::getPos(int x, int y) {
  return &grid[x][y];
}
//returns pointer to starting position
Position* Maze::getStart() {
  return &grid[0][0];
}
//returns a boolean if the inputted position is the exit
bool Maze::isExit(Position* p) {
  if (p->getX() == numRows-1 && p->getY() == numColumns-1) 
    return true;
  return false;
}
//prints out a representation of the maze. 1 for wall 0 for clear and * if on path.
void Maze::print() {
  cout << " start --> ";
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numColumns; j++) {
      if (grid[i][j].isWall()) {
        cout << "1 ";
      } else if (grid[i][j].isPath()) {
        cout << "* ";
      } else {
        cout << "0 ";
      }
    }
    if (i == numRows-1) {
      cout << "<-- finish " << endl;
    } else {
      cout << endl;
      cout << "           ";
    }
  }
}


//resets all the positions in the maze
void Maze::reset(){
  for (int j = 0; j < numColumns; j++) {
   for (int i = 0; i < numRows; i++) {
     grid[i][j].reset();
   }
  }
}
// takes in a position, finds its neighbors and puts them into a list which it returns
List<Position*>* Maze::getNeighbors(Position* p) {
  List<Position*>* list= new CircularArrayList<Position*>();
  //checks right
  if (p->getX()+1<numRows && !(this->getPos(p->getX()+1,p->getY()))->isWall()) {
    list->insertAtHead(this->getPos(p->getX()+1,p->getY()));
  }//checks left
  if (p->getX()-1>=0 && !(this->getPos(p->getX()-1,p->getY()))->isWall()) {
    list->insertAtHead(this->getPos(p->getX()-1,p->getY()));
  }//checks north
  if (p->getY()+1<numColumns && !(this->getPos(p->getX(),p->getY())+1)->isWall()) {
    list->insertAtHead(this->getPos(p->getX(),p->getY()+1));
  }//checks south
  if (p->getY()-1>=0 && !(this->getPos(p->getX(),p->getY())-1)->isWall()) {
    list->insertAtHead(this->getPos(p->getX(),p->getY())-1);
  }
  return list;

}
//takes in two integers representing cooordinates and puts a wall at that place
void Maze::setWall(int row, int column){
  grid[column-1][row-1].setWall();
}
//prints every position in the path the DFS or BFS found.
void Maze::reportPath() {
  Position* temp = this->getPos(numRows-1, numColumns-1);
  ArrayStack<Position*> arrStack;
  int pathLength = 1;
  while (temp->getPrevious() != NULL) {//fills arrStack up with every coordinate in path 
    temp->setPath();
    arrStack.push(temp);
    pathLength++;
    temp = temp->getPrevious();
  }
  cout << "The path has a length of " << pathLength << "." << endl;
  cout << "Path:  " << endl;
  cout << "(0, 0)  ";
  while (!arrStack.isEmpty()) {//pops off positions from stack and displays them.
    arrStack.pop()->print();
  }
  cout << endl;
  this->print();
}

