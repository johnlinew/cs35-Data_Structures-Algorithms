/*frameNode.cpp
 * Description:  Implementation of the node object for linked list 
 * representation of a movie.  FrameNode stores a frame as a string
 *
 * This class should not be modified
 */

#include "frameNode.h"

/*FrameNode(inVal) - constructor for FrameNode.  Sets FrameNode value to
 * parameter inVal and the next pointer to NULL.  
 * Input: inVal, a string representing the frame to store
 */
FrameNode::FrameNode(string inVal) {
  this->value = inVal;
  this->next = NULL;
}

/*~FrameNode() - destructor for FrameNode class
 */
FrameNode::~FrameNode() {/*Do Nothing*/}

/*getValue() - accessor method for the value stored in the FrameNode */
string FrameNode::getValue() {
  return this->value;
}
    
/*getNext() - accessor method to obtain pointer to next FrameNode */
FrameNode* FrameNode::getNext() {
  return this->next;
}
    
/*setNext() - setter function to establish the next pointer
 * Input: inNext, a pointer the next FrameNode
 */
void FrameNode::setNext(FrameNode* inNext) {
  this->next = inNext;
}

    
