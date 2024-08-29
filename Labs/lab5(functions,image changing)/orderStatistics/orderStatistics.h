/**
 * This function takes an array of strings and converts
 * them to an array of integers
 */
int * strToIntArray(char **strings, int numStrings);

/**
 * This function sorts an array of integers using
 * the insertion sort algorithm.
 */
void insertionSort(int *arr, int n);

/**
 * This function returns the i-th (i) order statistic of
 * the given integer array (arr) which has n elements
 */
int getOrderStatistic(int *arr, int n, int i);

/**
 * Returns the maximum value in the given array (arr)
 * of n elements.
 */
int getMax(int *arr, int n);
