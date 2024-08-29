#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**
 * Computes the n-th Jacobsthal number using an iterative
 * method
 */
long long jacobsthalIterative(int n);

/**
 * Recursively runs the Jacobsthal function using an memoization method
 * If n = 0, function returns 0
 * if n = 1, function returns 1
 * Else, function adds previous value plus two times the value two spots behind
 */
long long jacobsthalMemoization(int n, long long *cache);

/**
 * This program computes the n-th Jacobsthal number using recursion.
 * It also reports how long the program takes to execute.
 */
int main(int argc, char **argv) {

    if (argc != 2) {
        fprintf(stderr, "Usage: %s n\n", argv[0]);
        exit(1);
    }
    int n = atoi(argv[1]);

    long long *cache = (long long *)malloc(sizeof(long long int) * (n + 1));

    cache[0] = 0;
    cache[1] = 1;
    for(int i=2; i<=n; i++) {
        cache[i] = 0;
    }

    time_t start, end;
    start = time(NULL);
    long long iterativeResult = jacobsthalIterative(n);
    long long memoizationResult = jacobsthalMemoization(n, cache);
    end = time(NULL);

    int time = (end - start);

    printf("Iterative:   Jacobsthal(%d) = %lld\n", n, iterativeResult);
    printf("Memoization: Jacobsthal(%d) = %lld\n", n, memoizationResult);

    printf("Total Computation Time: %d seconds\n", time);

    free(cache);

    return 0;
}

long long jacobsthalMemoization(int n, long long *cache) {

    if(n <= 1) {
        return n;
    } else if(cache[n] != 0) {
        return cache[n];
    } else {
        long long a = jacobsthalMemoization((n - 1), cache);
        long long b = 2 * jacobsthalMemoization((n - 2), cache);
        long long result = a + b;
        cache[n] = result;

        return result;
    }
}

long long jacobsthalIterative(int n) {
  
    if(n <= 1) {
        return n;
    }
    long long prev = 0;
    long long curr = 1;
    for(int i=2; i<=n; i++) {
        long long t = 2 * prev + curr;
        prev = curr;
        curr = t;
    }
    return curr;
}