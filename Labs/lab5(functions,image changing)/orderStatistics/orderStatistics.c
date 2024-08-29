#include <stdlib.h>

#include "orderStatistics.h"

void insertionSort(int *array, int size) {
  int value;
  for(int i=1; i<size; i++) {
    value = array[i];
    int j = i;
    while(j > 0 && array[j-1] > value) {
      array[j] = array[j-1];
      j--;
    }
    array[j] = value;
  }
}

int * strToIntArray(char **strings, int numStrings) {
  int *result = (int *) malloc(sizeof(int) * numStrings);
  for(int i=0; i<numStrings; i++) {
    result[i] = atoi(strings[i]);
  }
  return result;
}

int getOrderStatistic(int *arr, int n, int i) {
  insertionSort(arr, n);
  return arr[i-1];
}

int getMax(int *arr, int n) {
  return getOrderStatistic(arr, n, n-1);
}
