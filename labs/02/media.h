/* Declaration of Media class - an abstract class encapsulating
 * digital media.  This class cannot be instantiated, but can
 * be inherited to created various types of media objects
 */
#ifndef _MEDIA_H_
#define _MEDIA_H_

#include <string>
using std::string;

class Media {
 private:
  string name;
  string type;
  string location;

 public:
  //One constructor that initializes all data members
  Media(string _name, string _type, string _location);
  virtual ~Media();
  
  //Accessor methods
  string getName();
  string getType();
  string getLocation();

  //Virtual functions that should be implemented by subclass
  //There is no default load implementation.  This must be implemented
  // by the subclass
  virtual void open() = 0;
  virtual void printInfo();
};

#endif
