#include <iostream>
#include "mediaLibrary.h"
#include "media.h"
#include "picture.h"
#include "video.h"
#include "book.h"
#include <fstream>

using namespace std;
/* Constructor - loads Media objects from file
 * @param libraryFile - file containing description of all media elements
 *   to load in library
 */
MediaLibrary::MediaLibrary(string libraryFile) {
  ifstream input(libraryFile.c_str());
  if(!input.is_open()){
    cerr << "Library not found" << endl;
    numFiles = 0;
  }
  //TODO: finish reading file, loading Media objects into media array
}

/* run - The main loop for the MediaLibrary.  Prompts user with
 * several options and runs the corresponding request until the user 
 * chooses to quit.  No parameters or return values.
 */
void MediaLibrary::run() {
  bool stop = false;
  int option = -1;

  while(!stop) {
    printMenu();
    cin >> option;
    if(option < 1 || option > 7) {
      cout << "I'm sorry I don't understand you." << endl;
    }
    else {
      cout << endl;
      if(option == 1) {
	listMedia(); 
      } else if(option == 2) {
        listBooks();
      } else if(option == 3) {
        listPictures();
      } else if(option == 4) {
        listVideos();
      } else if (option == 5) {
	openMediaMenu();
      } else if (option == 6) {
	printInfoMenu();
      }	else if (option == 7) {
	cout << "Closing Library" << endl;
	stop = true;
      }
    }
  }
}

/* printMenu - prints all main menu options for user
 */
void MediaLibrary::printMenu() {
  cout << endl << "What would you like to do?" << endl;
  cout << "  (1) List All Media Files" << endl;
  cout << "  (2) List Book Files" << endl;
  cout << "  (3) List Picture Files" << endl;
  cout << "  (4) List Video Files" << endl;
  cout << "  (5) Open Media" << endl;
  cout << "  (6) Get Detailed Information about Media" << endl;
  cout << "  (7) Quit" << endl;
  cout << "Choose (1-7): ";
}

//TODO: Implement all remaining class methods
