/**\
 * Header files with prototypes and documentation
 * for functions used in midterm.c
 * Error codes defined below
 */
typedef enum {
    NO_ERROR,
    INVALID_INPUT,
} ErrorCode;
/**
 * Returns weight and volume of corn through pass-by-reference
 * variables
 *
 * Volume is calculated by the equation
 * radius * radius * M_PI * height
 * and given as cubic meters
 *
 * Weight is calculated by the equation
 * volume * cornWeight
 * where cornWeight is given as 720.83 kg/m^3
 */
int getCornStats(double radius, double height, double *volume, double *weight);
/**
 * Adds arr[i] to huskerTotal if arr[i] is divisible by 3
 * Adds arr[i] to mavTotal if arr[i] is divisible by 5
 * Adds arr[i] to both huskerTotal and mavTotal if arr[i] is divisible by 15
 */
int fizzBuzzSum(const int *arr, int n, int *huskerTotal, int *mavTota);
/**
 * Merges two arrays a and b and returns a longer
 * array containing values of both arrays in the
 * order of a array values first the b array values
 */
int *merge(const int *a, int n, const int *b, int m);
/**
 * This function has been provided for you
 */
void printArray(const int *arr, int n);