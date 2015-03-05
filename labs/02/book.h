#ifndef _BOOK_H_
#define _BOOK_H_

#include "media.h"
#include <fstream>
using std::string;

class Book : public Media {
  //TODO: Declare book class here
};

bool printPage(string bookLocation,int lineStart);
#endif
