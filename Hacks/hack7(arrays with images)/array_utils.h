/**
 * Determines if integer x is contained
 * within the array arr
*/
int contains(const int *arr, int size, int x);

/**
 * Determines if integer x is contained
 * within the parameters of i and j
 * in array arr
*/
int containsWithin(const int *arr, int size, int x, int i, int j);

/**
 * Copies elements of one array to another
 * array. If the new array has a smaller
 * size, then only the first elements from the
 * old array are copied over. if the new array
 * has a bigger size, it will be padded with 0's.
*/
int * paddedCopy(const int *arr, int oldSize, int newSize);

/**
 * Reverses elements of an array
*/
void reverse(int *arr, int size);

/**
 * Copies and returns new copy of reversed array
*/
int * reverseCopy(const int *arr, int size);