#ifndef QUICKSORT_H_
#define QUICKSORT_H_

/*quickSort - Sort an array of n items.
 * @param a - array of type T
 * @param n - size of array
 * @param compare - function for comparing two elements of a
 * No return; side effect that a is sorted in order according to
 * compare operator
 */
template <typename T, typename CMP>
void quickSort(T a[], int n, CMP compare);

/*quickSort helper methods*/
template <typename T, typename CMP>
int partition(T a[], int left, int right, CMP compare);

template <typename T, typename CMP>
void quickSort(T a[], int left, int right, CMP compare);

template <typename T> 
void swap(T a[], int i, int j);

#include "quickSort-inl.h"

#endif
