/**
 * Author: Matt Schlatter
 * Date: 2022-11-11
 *
 * Reads input from given file in the command line
 * If the integer on a given line is divisible by 15,
 * the number will be added to the huskers and mavericks
 * total score. If divisible by 5, it will only be added
 * to the mavericks score, and if divisible by 3, it will
 * only be added to the huskers score
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "utils.h"

int main(int argc, char **argv) {
    if(argc !=2) {
        fprintf(stderr, "Usage: %s fileName\n", argv[0]);
        exit(1);
    }

    char *input = argv[1];
    FILE *inputFile = fopen(input, "r");
    if(inputFile == NULL) {
        fprintf(stderr, "Unable to open %s\n", input);
    }

    int huskerScore = 0;
    int mavScore = 0;
    int numLines = 0;
    int currentNum = 0;
    char **fileLines = getFileLines(input, &numLines);

    //first line is not part of data
    for(int i=1; i<numLines; i++) {
        currentNum = atoi(fileLines[i]);
        if((currentNum % 15) == 0) {
            huskerScore += currentNum;
            mavScore += currentNum;
        } else if((currentNum % 5) == 0) {
            mavScore += currentNum;
        } else if((currentNum % 3) == 0) {
            huskerScore += currentNum;
        }
    }

    fprintf(stderr, "Huskers total:   %4d\n", huskerScore);
    fprintf(stderr, "Mavericks total: %4d\n", mavScore);

    freeTable(fileLines, numLines);
    fclose(inputFile);

    return 0;
}