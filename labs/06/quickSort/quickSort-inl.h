#include<cstdlib>

/* quickSort - Sort an array of n items
 * @param a- array of type T
 * @param n - size of array
 * @param compare - function for comparing two elements of a
 * No return; side effect that a is sorted in order according to
 * compare operator
 */
template <typename T, typename CMP>
void quickSort(T a[], int n, CMP compare){
  quickSort(a, 0, n-1,compare);     // Calls the quickSort helper function,
                                    // which sorts a given range of an array.
}


/**
 * quickSort - internal quicksort helper
 * function that quickSorts an array within the given start-end (inclusive)
 * range.
 * @param a, array to sort
 * @param start, end - the (inclusive) range of indices of a to sort
 * @param compare - function for comparing two elements of a
 * No return; side effect that a[start:end] is sorted
 */
template <typename T, typename CMP>
void quickSort(T a[], int start, int end, CMP compare) {
  if (end > start) {
    int p = partition(a, start, end, compare);
    quickSort(a, start, end, compare);
    quickSort(a, p+1, end, compare);
  }
}


/** 
 * partition:  Given an array and bounds start and end (inclusive), 
 * partition part of the array around a randomly-chosen pivot item.
 * @param a, array to sort
 * @param start, end - the (inclusive) range of indices of a to sort
 * @param compare - function for comparing two elements of a
 * @return The final location of the pivot in the partitioned array.
 * a[start:end] is modified to be partitioned about the pivot
 */
template <typename T, typename CMP>
int partition(T a[], int start, int end, CMP compare) {
  //TODO: Pick random pivot, swap to end position
  int left = start;
  int right = end-1;
  
  int range = end-start+1;
  int pivot = (rand()%range);
  pivot += start;
  cout << "INDEX of PIVOT = " << pivot << endl;
  //TODO: Set the pivot value and left/right index
  swap(a, pivot, end);
  //TODO: Run partition
  while (left <= right) {
    if (compare(a[left], a[pivot])) {
      left++;
    } else if (!compare(a[right], a[pivot])) {
      right--;
    } else {
      swap(a, left, right);
    }
  }
  //TODO: return the pivot location 
  return pivot;
}           


/**
 * swap:  Given an array a and two positions in the array, swaps the items
 * in those positions in the array.
 *
 * Returns:  nothing, but changes the array as a side effect.
 */
template <typename T> void swap(T a[], int i, int j) {
  T tmp(a[i]);
  a[i] = a[j];
  a[j] = tmp;
}
