#include <cstdlib> 
#include <iostream>
#include "randArray.h"

using namespace std;


/* Print each element of the array of given size. */
template <typename T>
void printArray(T array[], int size){
  cout << "[";
  if (size > 0) {
    cout << array[0];
  }
  for(int i = 1; i < size; i++){
    cout << " " << array[i];
  }
  cout << "]" << endl;
}

/* Populate pre-allocated array of given size with numbers between
 * low and high-1, inclusive. */
void randArray(int array[], int size, int low, int high){
  for (int i = 0; i < size; ++i){
    int range = high - low;
    array[i] = (rand() % range) + low;
  }
}

/* Populate pre-allocated array of floats given size with numbers between
 * 0 and 1*/
void randArray(float array[], int size){
  for (int i = 0; i < size; ++i){
    array[i] = float(rand())/RAND_MAX;
  }
}
/* lessInt - comparison function to return whether the first parameter
 *  is less than the second parameter */
bool lessInt(int a, int b){
  return a < b;
}

//TODO: implement greaterInt

//TODO: implement comparison operators for floats

