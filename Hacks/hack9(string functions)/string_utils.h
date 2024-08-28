/**
 * Replaces instances of a given character newChar with
 * a different character oldChar in a string s
 */
void replaceChar(char *s, char oldChar, char newChar);

/**
 * Creates a copy of a string s and replaces instances of a
 * given character newChar with a different character oldChar
 */
char *replaceCharCopy(const char *s, char oldChar, char newChar);

/**
 * Removes all instances of a certain character
 * c from a given string s
 */
void removeChar(char *s, char c);

/**
 * Creates a copy of a string s and removes all
 * instances of a given character c
 */
char *removeCharCopy(const char *s, char c);

/**
 * Takes given string s and splits it up into an array
 * of strings of length n. If there is not n amount of
 * characters remaining for the final string, the final
 * string will contain the remaining number of characters
 */
char **lengthSplit(const char *s, int n);