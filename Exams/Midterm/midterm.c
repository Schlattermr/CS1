/**
 * Author: Matt Schlatter
 * Date: 2022/19/10
 *
 * This program defines three functions that
 * have prototypes and documentation in midterm.h
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "midterm.h"

int getCornStats(double radius, double height, double *volume, double *weight) {
    if(radius <= 0 || height <= 0 || volume == NULL || weight == NULL) {
        return INVALID_INPUT;
    }

    double cornWeight = 720.83;
    double tempVolume = (radius * radius * M_PI * height);
    double tempWeight = tempVolume * cornWeight;
    *volume = tempVolume;
    *weight = tempWeight;

    return NO_ERROR;
}

int fizzBuzzSum(const int *arr, int n, int *huskerTotal, int *mavTotal) {
    if(arr == NULL || n <= 0 || huskerTotal == NULL || mavTotal == NULL) {
        return INVALID_INPUT;
    }

    int tempHuskerTotal = 0;
    int tempMavTotal = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] % 15 == 0) {
            tempHuskerTotal += arr[i];
            tempMavTotal += arr[i];
        } else if(arr[i] % 5 == 0) {
            tempMavTotal += arr[i];
        } else if(arr[i] % 3 == 0) {
            tempHuskerTotal += arr[i];
        }
    }
    *huskerTotal = tempHuskerTotal;
    *mavTotal = tempMavTotal;

    return NO_ERROR;
}

int *merge(const int *a, int n, const int *b, int m) {
    if(a == NULL || b == NULL || m <= 0 || n <= 0) {
        return NULL;
    }

    int mergedSize = n + m;
    int *mergedArray = (int *) malloc (sizeof(int) * mergedSize);

    for(int i = 0; i < mergedSize; i++) {
        mergedArray[i] = 0;
    }

    int j = 0; //for b array incrementation
    for(int i = 0; i < mergedSize; i++) {
        if(i < n) {
            mergedArray[i] = a[i];
        } else if(i >= n) {
            mergedArray[i] = b[j];
            j++;
        }
    }

    return mergedArray;
}

void printArray(const int *arr, int n) {
    if(arr == NULL) {
        printf("[null]\n");
        return;
    }
    printf("[ ");
    for(int i=0; i<n-1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d ]\n", arr[n-1]);
    return;
}
