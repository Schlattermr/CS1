/**
 * This program finds the ith order statistic of
 * a list of numbers provided via the command line.
 *
 * It uses insertion sort (a sorting algorithm) to
 * sort the list then finds i-th order elements in the
 * array.
 *
 */
#include <stdlib.h>
#include <stdio.h>

#include "orderStatistics.h"

int main(int argc, char **argv) {

  if (argc < 3) {
    printf("Usage: %s <ith order value> <list of unique numbers>\n", argv[0]);
    exit(1);
  }

  int ithOrder = atoi(argv[1]);
  int numElements = argc - 2;

  if(ithOrder < 1 || ithOrder > numElements) {
    printf("The ith order value must be between 1 and %d\n", numElements);
    exit(1);
  }

  int *numbers = strToIntArray(&argv[2], numElements);

  int ithElement = getOrderStatistic(numbers, numElements, ithOrder);

  printf("The %dth element is: %d\n", ithOrder, ithElement);

  return 0;
}

