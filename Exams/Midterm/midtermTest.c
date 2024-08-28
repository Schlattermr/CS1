#include <stdlib.h>
#include <stdio.h>

#include "midterm.h"

int main(int argc, char **argv) {
  double radius = 5;
  double height = 20;
  double volume, weight;
  getCornStats(radius, height, &volume, &weight);
  printf("volume = %f\n", volume);
  printf("weight = %f\n", weight);

  int n = 7;
  int a[] = {2, 9, 4, 25, 57, 45, 53};
  int m = 5;
  int b[] = {9, 0, 2, 1, 0};

  int huskerTotal, mavTotal;
  fizzBuzzSum(a, n, &huskerTotal, &mavTotal);
  printf("huskerTotal = %d\n", huskerTotal);
  printf("mavTotal = %d\n", mavTotal);

  int *c = merge(a, n, b, m);
  printArray(c, n+m);

  return 0;
}
