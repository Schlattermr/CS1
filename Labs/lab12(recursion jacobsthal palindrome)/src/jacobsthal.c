#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**
 * Recursively runs the Jacobsthal function
 * If n = 0, function returns 0
 * if n = 1, function returns 1
 * Else, function adds previous value plus
 * two times the value twice behind
 */
long long runJacobsthal(int n);

/**
 * This program computes the n-th Jacobsthal number using recursion.
 * It also reports how long the program takes to execute.
 *
 */
int main(int argc, char **argv) {

  if (argc != 2) {
    fprintf(stderr, "Usage: %s n\n", argv[0]);
    exit(1);
  }
  int n = atoi(argv[1]);

  time_t start, end;
  start = time(NULL);
  long long result = runJacobsthal(n);
  end = time(NULL);

  int time = (end - start);

  printf("Jacobsthal(%d) = %lld\n", n, result);

  printf("Computation Time: %d seconds\n", time);

  return 0;
}

long long runJacobsthal(int n) {

  if(n == 0) {
    return 0LL;
  } else if(n == 1) {
    return 1LL;
  } else {
    return runJacobsthal(n - 1) + (2 * runJacobsthal(n - 2));
  }
}