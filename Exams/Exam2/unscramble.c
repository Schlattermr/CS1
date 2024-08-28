/**
 * Author: Matt Schlatter
 * Date: 2022-11-11
 *
 * Reverses the order of characters in each line
 * of a given file and reverses the print order
 * of the lines of a given file
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "utils.h"

int main(int argc, char **argv) {
    if(argc !=3) {
        fprintf(stderr, "Usage: %s inputFile outputFile\n", argv[0]);
        exit(1);
    }

    char *input = argv[1];
    char *output = argv[2];
    FILE *inputFile = fopen(input, "r");
    if(inputFile == NULL) {
        fprintf(stderr, "Unable to open %s\n", input);
    }
    FILE *outputFile = fopen(output, "w");
    if(outputFile == NULL) {
        fprintf(stderr, "Unable to open %s\n", output);
    }

    int numLines = 0;
    int lineLength = 0;
    char **fileLines = getFileLines(input, &numLines);
    char **buffer = (char **)malloc(sizeof(char *) * numLines);

    for(int i=0; i<numLines; i++) {
        lineLength = strlen(fileLines[i]) + 1;
        reverse(fileLines[i], lineLength);
        buffer[i] = (char *)malloc(sizeof(char) * (lineLength + 1));
        strcpy(buffer[i], fileLines[i]);
    }

    for(int i=numLines-1; i>-1; i--) {
        fprintf(outputFile, "%s\n", buffer[i]);
    }

    freeTable(fileLines, numLines);
    freeTable(buffer, numLines);
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}