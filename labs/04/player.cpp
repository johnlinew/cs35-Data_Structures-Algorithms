/* player.cpp - a main program for watching an ASCIImation movie
 * Name:
 */

//Place include files here
#include "movieList.h"
#include "movieLinkedList.h"
#include "movie.h"
#include <iostream>
#include <fstream>
using namespace std;

//You should not need to add any function to this file.  Any 
//function related to movie play should go in movie.h/cpp

int main(){
  string filename;

  /*This part handles finding/loading the file.  You do not
   *  need to change this
   */

  cout << "Enter file name: ";
  cin >> filename;

  MovieLinkedList* movieReel = new MovieLinkedList;
  if (!loadFilm(movieReel, filename)){
    cerr << "Error loading file...Exiting" << endl;
    return 1;
  }

  //Prompt the user with the menu and get choices
  //  until they exit
  int option = getChoice();

  while(option != 9){
    //TODO: Respond to menu options.  Feel free to change while-loop
    //condition

    option = getChoice();
  }
  return 0;
}
