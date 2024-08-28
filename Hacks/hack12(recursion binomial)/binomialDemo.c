/**
 * Author: Matt Schlatter
 * Date: 2022-11-17
 *
 * Tests functions from binomial.c and binomial.h
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include "binomial.h"

int main(int argc, char **argv) {
    if(argc != 3) {
        printf("Usage: ./a.out n k\n");
        exit(1);
    }

    int n = atoi(argv[1]);
    int k = atoi(argv[2]);

    if(n < 0 || k < 0) {
        printf("Please provide positive values\n");
        exit(1);
    }

    long **cache = (long **)malloc(sizeof(long) * (n + 1));
    for(int i=0; i<=n; i++) {
        cache[i] = (long *)malloc(sizeof(long) * (k + 1));
    }

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=k; j++) {
            cache[i][j] = -1;
        }
    }

    time_t start, end;
    start = time(NULL);
    long result2 = chooseMemoization(n, k, cache);
    end = time(NULL);

    int time = (end - start);

    printf("Computation Time: %d seconds\n", time);
    printf("Binomial Memoization Result: %ld\n", result2);

    freeTable(cache, n, k);

    return 0;
}