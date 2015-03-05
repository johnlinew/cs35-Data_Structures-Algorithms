/* testLinkedList.cpp
 *  Description: this program will help you test out your FrameNode class
 *  and then your linked list class as you develop it
 */

#include<iostream>
#include "frameNode.h"

using namespace std;

int main(){

  FrameNode* first;
  string frame;

  //Read in frame from the user and create first node
  frame = "Scene 1";
  first = new FrameNode(frame);

  //Did it work? let's print out the FrameNode value
  
  cout << "First frame: " << first->getValue() << endl;

  //Now create a few more values, and manually link up your nodes
  //See if you can traverse your manually created list of nodes

  //TODO: test your movieLinkedList implementation thoroughly


}
