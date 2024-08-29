c
# CSCE 155E
## Lab 5.0 Worksheet

Name(s) and Login(s):

Matthew Schlatter - Mschlatt

1. Identify three functions you've used prior to this lab and
identify the return type, the function identifier (name) and
its parameter types.

For example, the math library's `pow` function has the following
characteristics:
  * Return Type: `double`
  * Function Name: `pow`
  * Parameter Type(s): `(double, double)`


  * Return Type: `int`
  * Function Name: `main`
  * Parameter Type(s): `(int, char)`

  * Return Type: `double`
  * Function Name: `sqrt`
  * Parameter Type(s): `(double)`


2. Open all the files and review the code to answer the following
questions.

  a) Identify all of the user-defined functions in the program
  along with the functions' return types and the number of parameters
  they accept.

  orderStatistics.c
    Return Type: void
    Function Name: insertionSort
    Parameter Type(s): (int, int)

    Return Type: int *
    Function Name: strToIntArray
    Parameter Type(s): (char, int)

    Return Type: int
    Function Name: getOrderStatistic
    Parameter Type(s): (int, int, int)

    Return Type: int
    Function Name: GetMax
    Parameter Type(s): (int, int)

  b) Among the functions `main`, `strToIntArray`, `insertionSort`,
  and `getOrderStatistic`: identify which function calls which
  other function(s).

    getOrderStatistic

  c) How might you implement the following function?  Hint: it
  should only be a one-liner.
  ```c
  int getMin(int *arr, int n) {
    return getOrderStatistic(arr, n, n-1);
  }
  ```

  d) Prototypes and documentation were placed in the header file
  and function definitions were placed into a separate source file.
  Identify at least one advantage of this approach.

    The definitions are less cluttered and more easily readable and understandable
    by others.
