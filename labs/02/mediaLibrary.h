/*Class declaration the MediaLibrary. Handles a collection of various 
 * media types and provides an interface for user interaction.  You should not
 * modify this file except to add private helper methods in the declaration
 * if needed.  You may not add additional data or public methods.
 */
#ifndef _MEDIA_LIBRARY_H_
#define _MEDIA_LIBRARY_H_

#include "media.h"

class MediaLibrary {
  private:
    Media* media[50];
    int numFiles;

    //Internal methods.  These menus can only be invoked from
    //within the class definition
    void printMenu();
    void openMediaMenu();
    void printInfoMenu();
    void listMedia();
    void listBooks();
    void listVideos();
    void listPictures();

  public:
    MediaLibrary(string libraryFile);  //Constructor
    int getNumFiles();
    void run();                        //Main loop for interaction
};
#endif
