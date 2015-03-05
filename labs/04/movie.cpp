#include <iostream>
#include <fstream>
#include "movie.h"
#include "movieLinkedList.h"

using namespace std;

/**
 * getChoice - prints the menu of options and returns the user's choice
 * Input: None
 * Return: an integer between 0 and 9 representing the user's choice
 *
 * This has been implemented for you
 */
int getChoice(){
  cout << endl;
  cout << "(0) Get Movie Status" << endl;
  cout << "(1) Play Movie" << endl;
  cout << "(2) Stop Movie" << endl;
  cout << "(3) Fast Forward" << endl;
  cout << "(4) Rewind" << endl;
  cout << "(5) Cut Trailers (delete 1 second from start of movie)" << endl;
  cout << "(6) Cut Credits (delete 1 second from end of movie)" << endl;
  cout << "(7) Delete Current Scene (1 second from current point in movie)" << endl;
  cout << "(8) Reverse Movie" << endl;
  cout << "(9) Exit" << endl;
  cout << endl;

  int choice;

  cout << "Enter choice: ";
  cin >> choice;
  cout << endl;
  while(choice < 0 || choice > 9){
    cout << "Invalid choice, try again: " ;
    cin >> choice;
    cout << endl;
  }

  return choice;
}

/*loadFilm() - reads in a series of frames and creates
 * a MovieLinkedList representation of the sequence 
 * Input: movieList - a pointer to the MovieLinkedList to store the film
 * Return: true if the loading process was successful
 *
 * This has been mostly implemented, complete the TODO below
 */
bool loadFilm(MovieList* movieList, string fileName){
  cout << "\nLoading " << fileName << "..." << endl;
  string frame = "";
  ifstream filein(fileName.c_str());
  if (!filein.is_open()){
    return false;
  }

  int count;         //The file is compressed.  Count is how long
                     // each frame stays on the screen
  filein >> count;
  
  while(!filein.eof()){
    frame = "";
    
    //This reads in the whole image as one frame
    char c;
    for(int i=0; i<14; i++){
      do{
        c = filein.get();
        if(filein.eof())
          return false;
        frame+=c;
      }while(c != '\n');
    }
    
    //TODO: add the frame to the movieList.  There should
    //   be count copies of the frame (e.g., a count of 5 means
    //   that you should add 5 copies of the frame to the list)

    filein >> count;
  }
  filein.close();
  cout << "File Loading Complete" << endl << endl;
  return true;
}

