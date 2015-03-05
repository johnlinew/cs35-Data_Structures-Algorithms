/*frameNode.h
 *Description: Declaration of the FrameNode class.  A FrameNode object stores
 * a single movie frame (as a string) and a pointer to the next FrameNode
 *
 *You should not modify this file
 */
#ifndef FRAMENODE_H
#define FRAMENODE_H

#include<stdlib.h> //To use NULL
#include<stdexcept>//To throw a runtime exception
#include <string>
using namespace std;

class FrameNode {
  private:
    string value;
    FrameNode* next;

  public:
    FrameNode(string inVal);  
    ~FrameNode();

    string getValue();
    FrameNode* getNext();
    void setNext(FrameNode* inNext);
};
#endif
