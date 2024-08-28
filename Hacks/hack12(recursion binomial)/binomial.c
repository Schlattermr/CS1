/**
 * Author: Matt Schlatter
 * Date: 2022-11-17
 *
 * Defines functions in binomial.h
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "binomial.h"

void freeTable(long **table, int n, int k) {
    if(table == NULL) {
        return;
    }

    n += 1;
    k += 1;

    for(int i = 0; i < n; i++) {
        free(table[i]);
    }
    free(table);
}

long choose(int n, int k) {

    if(k == 0 || n == k) {
        return 1L;
    } else {
        return choose(n - 1, k) + choose(n - 1, k - 1);
    }
}

long chooseMemoization(int n, int k, long **cache) {

    if(k == n || k == 0) {
        return 1L;
    } else if(cache[n][k] != -1) {
        return cache[n][k];
    } else {
        long result = chooseMemoization(n - 1, k, cache) + chooseMemoization(n - 1, k - 1, cache);
        cache[n][k] = result;

        return result;
    }
}