// Position class used to represent x and y coordinates of a maze, whther they have been visited or not, and saves the position was that came previously.
#include <iostream>
#include <string>
#include "position.h"

using namespace std;
// constructor if nothing entered as parameters. 
Position::Position() {
  x = -1;
  y = -1;
  previous=NULL;
  visited = false;
}
//alternative constructor which takes in two integers for x and y coord.
Position::Position(int inX, int inY) {
  x = inX;
  y = inY;
  previous=NULL;
  visited = false;
}
//returns int representing position's x coordinate
int Position::getX() {
  return x;
}
//returns int representing position's y coordinate
int Position::getY() {
  return y;
}
//returns a pointer to the previous position
Position* Position::getPrevious(){
  return previous;
}
//returns a bool saying whether the position has been visited or not 
bool Position::isVisited(){

  return visited;
}
//returns a bool saying whether the position is a wall
bool Position::isWall(){
  return wall;
}
//returns a bool saying whether the position is a wall
bool Position::isPath(){
  return path;
}
//prints x and y coordinates of a position in the form of a coord. pair
void Position::print(){
  cout<<"("<<x<<", "<<y<<")  " ;

}
//sets the wall boolean associated with a position as true
void Position::setWall(){
  wall=true;
}
//sets the visited boolean associated with a position as true
void Position::setVisited(){
  visited=true;
}


//sets the visited boolean associated with a position as true
void Position::setPath(){
  path=true;
}
// takes in an integer and sets the x coordinate for a position to that value
void Position::setX(int newX){
  x=newX;
}
// takes in an integer and sets the y coordinate for a position to that value 
void Position::setY(int newY){
  y=newY;
}
//takes in a position pointer and sets previous to that pointer
void Position::setPrevious(Position* p){
  previous=p;
}
//sets the boolean visited to equal false 
void Position::reset(){
  visited=false;
  path = false;
  wall = false;
}

