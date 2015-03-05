/* movieList.h - defines movieList interface.  You SHOULD NOT modify this file
 */

#ifndef MOVIELIST_H_
#define MOVIELIST_H_
#include <string>
using std::string;

/**
 * A MovieList is an abstract (a.k.a. pure virtual) class specifying 
 * the interface for a representation of a movie as a list of frames
 * You should not modify this file.
 */
class MovieList {
  public:
    virtual ~MovieList() { /* do nothing */ };
    virtual int getSize() = 0;              // Get number of items in list.
    virtual bool isEmpty() = 0;             // True if list contains no items.
    virtual string peekHead() = 0;          // Returns item at front of list.
    virtual string peekTail() = 0;          // Returns item at back of list.
    virtual string get(int i) = 0;          // Returns item in ith position.
                                         
    virtual void insertAtHead(string value) = 0;// Prepends item to front of list.
    virtual void insertAtTail(string value) = 0;// Appends item to back of list.
    virtual string removeHead() = 0;            // Removes and returns front item.
    virtual string removeTail() = 0;            // Removes and returns back item.
    virtual string remove(int i) = 0;          // Deletes the ith frame from the movie

    //Special to this linked list task
    virtual int playFrom(int start) = 0;        // Displays the movie frame-by-frame from starting point
};

#endif  // MOVIELIST_H_
