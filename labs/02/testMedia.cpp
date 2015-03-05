/*This program tests implemented Media classes.  You should add 
 * to the basic test below to thoroughly test each class before
 * moving forward
 */
#include <iostream>
#include "media.h"
#include "picture.h"
#include <string>

using namespace std;

int main(){

  Picture testImage("Cake","../01/input/cake.ppm","PPM");

  testImage.printInfo();

  //TODO: Add additional tests here for Picture class
  
  //TODO: Test other Media subclasses

  //TODO: Test polymorphic behavior of Media object e.g.
  //   Media media = new Picture(...);
  
  


  return 0;
}
