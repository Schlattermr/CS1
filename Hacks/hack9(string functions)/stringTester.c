/**
 * Author: Matt Schlatter
 * Date: 2022/10/31
 *
 * Tests functions from string_utils.h and string_utils.c
 * three times each
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "string_utils.h"

int main(int argc, char **argv) {

    char s[1000] = "My nume is Muff";
    char oldChar = 'u';
    char newChar = 'q';
    int numPassed = 0;
    int numFailed = 0;

    //testing replaceChar
    char *expectedResult = "My nqme is Mqff";
    char *actualResult = s;
    replaceChar(s, oldChar, newChar);
    if(strcmp(actualResult, expectedResult) == 0) {
        numPassed++;
    } else {
        printf("expected: |%s| actual |%s|\n", expectedResult, actualResult);
        numFailed++;
    }

    oldChar = 'q';
    newChar = 'a';
    expectedResult = "My name is Maff";
    replaceChar(s, oldChar, newChar);
    if(strcmp(actualResult, expectedResult) == 0) {
        numPassed++;
    } else {
        printf("expected: |%s| actual |%s|\n", expectedResult, actualResult);
        numFailed++;
    }

    oldChar = 'f';
    newChar = 't';
    expectedResult = "My name is Matt";
    replaceChar(s, oldChar, newChar);
    if(strcmp(actualResult, expectedResult) == 0) {
        numPassed++;
    } else {
        printf("expected: |%s| actual |%s|\n", expectedResult, actualResult);
        numFailed++;
    }

    //testing replaceCharCopy
    strcpy(s, "Slippery banana peels");
    oldChar = 'a';
    newChar = 'u';
    expectedResult = "Slippery bununu peels";
    char copyS[1000];
    strcpy(copyS, replaceCharCopy(s, oldChar, newChar));
    actualResult = copyS;
    if(strcmp(actualResult, expectedResult) == 0) {
        numPassed++;
    } else {
        printf("expected: |%s| actual |%s|\n", expectedResult, actualResult);
        numFailed++;
    }

    oldChar = 'e';
    newChar = 'a';
    expectedResult = "Slippary banana paals";
    strcpy(copyS, replaceCharCopy(s, oldChar, newChar));
    actualResult = copyS;
    if(strcmp(actualResult, expectedResult) == 0) {
        numPassed++;
    } else {
        printf("expected: |%s| actual |%s|\n", expectedResult, actualResult);
        numFailed++;
    }

    oldChar = 'a';
    newChar = 'o';
    expectedResult = "Slippery bonono peels";
    strcpy(copyS, replaceCharCopy(s, oldChar, newChar));
    actualResult = copyS;
    if(strcmp(actualResult, expectedResult) == 0) {
        numPassed++;
    } else {
        printf("expected: |%s| actual |%s|\n", expectedResult, actualResult);
        numFailed++;
    }

    //testing removeChar
    char c = 'e';
    expectedResult = "Slippry banana pls";
    removeChar(s, c);
    actualResult = s;
    if(strcmp(actualResult, expectedResult) == 0) {
        numPassed++;
    } else {
        printf("expected: |%s| actual |%s|\n", expectedResult, actualResult);
        numFailed++;
    }

    c = 'a';
    expectedResult = "Slippry bnn pls";
    removeChar(s, c);
    actualResult = s;
    if(strcmp(actualResult, expectedResult) == 0) {
        numPassed++;
    } else {
        printf("expected: |%s| actual |%s|\n", expectedResult, actualResult);
        numFailed++;
    }

    c = 'p';
    expectedResult = "Sliry bnn ls";
    removeChar(s, c);
    actualResult = s;
    if(strcmp(actualResult, expectedResult) == 0) {
        numPassed++;
    } else {
        printf("expected: |%s| actual |%s|\n", expectedResult, actualResult);
        numFailed++;
    }

    //testing removeCharCopy
    strcpy(s, "Slippery banana peels are dangerous");
    c = ' ';
    strcpy(copyS, removeCharCopy(s, c));
    expectedResult = "Slipperybananapeelsaredangerous";
    actualResult = copyS;
    if(strcmp(actualResult, expectedResult) == 0) {
        numPassed++;
    } else {
        printf("expected: |%s| actual |%s|\n", expectedResult, actualResult);
        numFailed++;
    }

    c = 'e';
    strcpy(copyS, removeCharCopy(s, c));
    expectedResult = "Slippry banana pls ar dangrous";
    actualResult = copyS;
    if(strcmp(actualResult, expectedResult) == 0) {
        numPassed++;
    } else {
        printf("expected: |%s| actual |%s|\n", expectedResult, actualResult);
        numFailed++;
    }

    c = 'a';
    strcpy(copyS, removeCharCopy(s, c));
    expectedResult = "Slippery bnn peels re dngerous";
    actualResult = copyS;
    if(strcmp(actualResult, expectedResult) == 0) {
        numPassed++;
    } else {
        printf("expected: |%s| actual |%s|\n", expectedResult, actualResult);
        numFailed++;
    }

    // char test[100] = "Hello there, I am Matt";
    // int n = 3;
    // char **split = (char **)malloc(sizeof(char *) * );
    // strcpy(split, lengthSplit(test));
    // for


    printf("%s\n", s);

    printf("Passed %.2f%% of student test cases\n", ((double)numPassed / (numPassed + numFailed)) * 100);

    return 0;
}