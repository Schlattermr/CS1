/**
 * Author: Matt Schlatter
 * Date: 2022-11-11
 *
 * A collection of utility functions used for Exam 2
 */

/**
 * Returns a deep copy of the given string
 */
char * deepStringCopy(const char *str);

/**
 * Returns the contents of a file as an array of
 * strings, with each new string being on a new line.
 * Endline characters are not included and the size of
 * the new strings will be used through numLines
 */
char **getFileLines(const char *filePath, int *numLines);

/**
 * Frees the given table
 */
void freeTable(char **table, int height);

/**
 * Reverses elements of an array
*/
void reverse(char *s, int size);