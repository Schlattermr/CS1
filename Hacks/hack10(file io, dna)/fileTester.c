/**
 * Tests functions
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "file_utils.h"

int main(int argc, char **argv) {

    char *filePath = "testStrings.txt";
    char *fileContents = (getFileContents(filePath));

    printf("|%s|\n", fileContents);
    free(fileContents);

    int numLines = 0;
    int numColumns = 0;
    char **fileSplit = getFileLines(filePath, &numLines);
    for(int i=0; i<numLines; i++) {
        printf("|%s|\n", fileSplit[i]);
        numColumns++;
    }
    numColumns /= (numLines - 1);
    freeTable(fileSplit, numLines, numColumns);

    return 0;
}