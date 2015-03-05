#ifndef RANDARRAY_H
#define RANDARRAY_H

/* Print each element of the array of given size. */
template<typename T>
void printArray(T array[], int size);

/* Populate pre-allocated array of given size with numbers between
 * low and high-1, inclusive. */
void randArray(int array[], int size, int low, int high);

/* Returns true if int a is less than int b*/
bool lessInt(int a, int b);

/* Returns true if the int a is greater than the int b*/
bool greaterInt(int a, int b);

/* Populate pre-allocated array of given size with numbers between
 * low and high-1, inclusive. */
void randArray(float array[], int size);

/* Returns true if int a is less than int b*/
bool lessFloat(float a, float b);

/* Returns true if the int a is greater than the int b*/
bool greaterFloat(float a, float b);

#include "randArray-inl.h"

#endif
