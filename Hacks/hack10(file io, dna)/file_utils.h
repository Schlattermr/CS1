/**
 * Returns entire contents of a given file as
 * a single string with any endline characters preserved
 */
char *getFileContents(const char *filePath);

/**
 * Returns the contents of a file as an array of
 * strings, with each new string being on a new line.
 * Endline characters are not included and the size of
 * the new strings will be used through numLines
 */
char **getFileLines(const char *filePath, int *numLines);

/**
 * Counts and returns the number of characters per line
 * in a given file
 */
int countCharsInLine(FILE *file);

/**
 * Removes all instances of a certain character
 * c from a given string s
 */
void removeChar(char *s, char c);

/**
 * Replaces instances of a given character newChar with
 * a different character oldChar in a string s
 */
void replaceChar(char *s, char oldChar, char newChar);