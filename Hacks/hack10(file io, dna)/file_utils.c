/**
 * Author: Matt Schlatter
 * Date: 2022-11-03
 *
 * Defines functions from file_utils.h
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "file_utils.h"

void replaceChar(char *s, char oldChar, char newChar) {
    if(s == NULL) {
        return;
    }
    int n = strlen(s);
    for(int i=0; i<n; i++) {
        if(s[i] == oldChar) {
            s[i] = newChar;
        }
    }
    s[n] = '\0';
    return;
}

void removeChar(char *s, char c) {
    if(s == NULL) {
        return;
    }

    int n = strlen(s);
    char *temp = (char *) malloc (sizeof(char) * (n + 1));
    int j = 0;

    for(int i=0; i<n; i++) {
        if(s[i] != c) {
            temp[j] = s[i];
            j++;
        }
    }
    temp[j] = '\0';
    strcpy(s, temp);
    free(temp);

    return;
}

int countCharsInLine(FILE *file) {
    if(file == NULL) {
        return 1;
    }

    int numOfChars = 0;
    char c;
    while((c = fgetc(file)) != '\n') {
        if(c == EOF) {
            break;
        }
        numOfChars += 1;
        printf("%c\n", c);
    }

    return numOfChars;
}

char *getFileContents(const char *filePath) {
    if(filePath == NULL) {
        return NULL;
    }

    FILE *fileToCopy = fopen(filePath, "r");
    if(fileToCopy == NULL) {
        return NULL;
    }

    //finds total number of characters in given file
    fseek(fileToCopy, 0, SEEK_END);
    int fileLength = ftell(fileToCopy);
    fseek(fileToCopy, 0, SEEK_SET);

    char *copiedContents = (char *)malloc(sizeof(char) * (fileLength + 1));

    char c;
    int i = 0;
    while((c = fgetc(fileToCopy)) != EOF) {
        copiedContents[i] = c;
        i++;
    }
    copiedContents[fileLength] = '\0';
    fclose(fileToCopy);

    return copiedContents;
}

char **getFileLines(const char *filePath, int *numLines) {
    if(filePath == NULL || numLines == NULL) {
        return NULL;
    }

    FILE *fileToCopy = fopen(filePath, "r");
    if(fileToCopy == NULL) {
        return NULL;
    }

    fseek(fileToCopy, 0, SEEK_END);
    int fileLength = ftell(fileToCopy);
    fseek(fileToCopy, 0, SEEK_SET);

    int tempNumLines = 0;
    for(char c = fgetc(fileToCopy); c != EOF; c = fgetc(fileToCopy)) {
        if(c == '\n') {
            tempNumLines += 1;
        }
    }
    rewind(fileToCopy);
    *numLines = tempNumLines;

    char **fileLines = (char **)malloc(sizeof(char*) * (*numLines + 1));
    char buffer[fileLength + 1];
    char c = fgetc(fileToCopy);
    int i = 0;
    int j = 0;
    while(true) {
        if(c == EOF) {
            break; //to break otherwise infinite loop
        } else if(c == '\n') {
            buffer[j] = '\0';
            fileLines[i] = (char *)malloc(sizeof(char) * (j + 1));
            strcpy(fileLines[i], buffer);
            strcpy(buffer, "");
            j = 0;
            i++;
        } else {
            buffer[j] = c;
            j++;
        }
        c = fgetc(fileToCopy);
    }
    fclose(fileToCopy);

    return fileLines;
}
