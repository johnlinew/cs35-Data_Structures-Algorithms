#include <iostream>

#include "book.h"
#include "media.h"


using namespace std;

//TODO: Implement Book class here


/* prints one page (10 lines) of an ebook
 * @param bookLocation - string containing the location of the book
 * @param lineStart - where the page to print is located in the file
 * @return - true if the file has any lines remaining, false if the book
 *           was completed
 */
bool printPage(string bookLocation, int lineStart){
  if(lineStart < 0){
    cout << "Error: illegal line number, starting from 0" << endl;
    lineStart = 0;
  }
  ifstream book(bookLocation.c_str());

  char line[256];
  
  //Ignore all lines before the starting point
  for(int i = 0; i < lineStart; i++){
    book.getline(line, 256);
  }

  cout << endl;
  for(int i = 0; i < 10 && !book.eof(); i++){
    book.getline(line,256);
    cout << line << endl;
  }
  
  cout << endl;
  bool endReached = !book.eof();
  book.close();
  return endReached;
}
