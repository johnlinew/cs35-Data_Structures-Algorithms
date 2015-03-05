/* Implementation of the Media class.  This file has been completed for you but you
   are responsible for understand all of the details.
 */
#include <iostream>
#include "media.h"

using namespace std;

/* Constructor
 * @param _name - string for what the Media file should be titled
 * @param _type - string containing the type of Media file.  
 * @param _location - location of file.  Subclass will define
                  expected value e.g., URL, server location, etc.
 */
Media::Media(string _name, string _type, string _location) {
  name = _name;
  type = _type;
  location = _location;
}

Media::~Media() { /* do nothing */ }

/* Accessor methods */
string Media::getName() {
  return name;
}

string Media::getType() {
  return type;
}

string Media::getLocation() {
  return location;
}

/* printDetails - prints detailed data about instance.  Subclass
 *  implementation should call this parent version first before
 *  outputting additional information
 */
void Media::printInfo() {
  cout << "Name: " << this->getName() << endl;  //this operator is similar to self in Python
  cout << "Type: " << this->getType() << endl;
  cout << "Location: " << this->getLocation() << endl;
}
