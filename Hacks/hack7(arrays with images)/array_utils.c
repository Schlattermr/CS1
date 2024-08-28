/**
 * Authors: Matt Schlatter and Jack Baldwin
 * Date: 2022/13/10
 *
 * This program contains many different functions
 * The first function determines if a value x is contained in an array
 * The second function determines if a value x is between values i and j in an array
 * The third function creates a padded copy of an array, if the new size is larger then zeros are added
 * and if the new size is smaller, the array is truncated
 * The fourth function reverses the order of an array
 * The fifth function creates a copy of an array and reverses the copy
*/


#include <stdlib.h>
#include <stdio.h>

#include "array_utils.h"

int contains(const int *arr, int size, int x) {
    if(arr == NULL) {
        return 0;
    }
    for(int i = 0; i < size; i++) {
        if(arr[i] == x) {
            return 1;
        }
    }
    return 0;
}

int containsWithin(const int *arr, int size, int x, int i, int j) {
    if(arr == NULL) {
        return 0;
    }
    for(int k = i; k >= i && k <= j; k++) {
        if(arr[k] == x) {
            return 1;
        }
    }
    return 0;
}

int * paddedCopy(const int *arr, int oldSize, int newSize) {
    if(arr == NULL) {
        return NULL;
    } else if(oldSize < 0) {
        return NULL;
    }
    int *newArr = (int *) malloc (sizeof(int) * newSize);
    if(newSize <= oldSize) {
        for(int i = 0; i < newSize; i++) {
            newArr[i] = arr[i];
        }
    } else if(newSize > oldSize) {
        for(int i = 0; i < newSize; i++) {
            if(i >= oldSize) {
                newArr[i] = 0;
            } else {
                newArr[i] = arr[i];
            }
        }
    }
    return newArr;
}

void reverse(int *arr, int size) {
    if(arr == NULL) {
        return;
    }
    int brr[size];
    for(int i = 0; i < size; i++) {
        brr[size - i - 1] = arr[i];
    }
    for(int i = 0; i < size; i++) {
        arr[i] = brr[i];
    }
    return;
}

int * reverseCopy(const int *arr, int size) {
    if(arr == NULL) {
        return NULL;
    }
    int *newArr = (int *) malloc (sizeof(int) * size);
    for(int i = 0; i < size; i++) {
        newArr[i] = arr[size - i -1];
    }
    return newArr;
}