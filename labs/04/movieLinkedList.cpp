/*movieLinkedList.cpp - Place your implementation for the MovieLinkedList class in
 * here.
 * TODO: Add name and description
 */

#include <stdexcept> //Keep to use exceptions
//TODO: Hmm, where do I get the declaration of this class?

//These three libraries make it possible to 'play' the movie in the terminal
#include <cstdlib>
#include <iostream>
#include "/home/soni/public/cs35/moviePlayer/kbhit.h"


using namespace std;

//TODO: Implement class methods here










//////////////////////////////////////////////////////////////////////


/* playFrom - plays the movie by traversing the linked list of frames
 * Input: start - an integer representing which frame number to start 
 *                playing the movie from
 * Return: the last frame number played before the movie ends or
 *         user pauses
 *
 *
 * The general algorithm is to 
 * 1) skip forward to the start point.  start uses 0-based indexing,
 *     so the head is 0, the next frame is 1, etc.  
 * 2) Until the user hits a key to pause, move forward one frame at a 
 *     time and display its value
 * 3) Keep track of what frame number you are at, so you can return
 *     that back to the user.
**/
int MovieLinkedList::playFrom(int start){
  //If a class-user tries to play an non-existent frame, a
  //  run time error is thrown
  if (start < 0 || start >= this->size) {
    throw std::runtime_error("Attempted to playFrom out of bounds.");
  }
  

  FrameNode* curr = this->head; //refers to the current frame being looked at
  int currFrameNumber = 0;      //use to keep track how many frames into the 
                                // movie you have played

  //TODO: traverse forward to the start point (HINT: you may want a loop here)



  while(curr != NULL){
    system("clear");  //clears the screen between frames
                             
    //TODO: display current frame using a cout statement
    //TODO: move to the next frame node
    //TODO: update the frame number

    cout << "Hit ANY KEY to pause: ";
    if (kbhit())   //checks to see if the user entered anything
      break;
    
    usleep(1000000/15);
  }

  return currFrameNumber;
}

