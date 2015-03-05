#include <iostream>
#include <cstdlib>     // Needed for pseudo-random number generator.
#include <sys/time.h>   // Needed for pseudo-random number generator.

#include "quickSort.h"
#include "randArray.h"

using namespace std;

void sortIntAscending(int size);

//TODO: after getting quick sort working, implement the following two methods
//void sortIntDescending(int size);
//void sortFloat(int size);

int main() {
  srand(time(NULL)); //Seeds random generator with current time
  int n;
  cout << "Please enter a size for the array:  ";
  cin >> n;
  

  sortIntAscending(n);
  //TODO: Implement and call other tests
}

/** Test for sorting integers in ascending order **/
void sortIntAscending(int size){
  int* nums = new int[size];
  randArray(nums,size,0,100);
  cout << endl; 
  cout << "Initial random array of integers:  " << endl;
  printArray(nums, size);
  
  cout << endl;

  quickSort(nums, size, lessInt);
  cout << "Sorted (ascending) array of integers:  " <<endl;
  printArray(nums, size);
  
  delete nums;
}

//Implement other sort tests for sorting in descending order and sorting
//floats
