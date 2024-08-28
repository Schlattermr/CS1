#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "utils.h"

char *deepStringCopy(const char *str) {
    char *copy = (char *) malloc(sizeof(char) * (strlen(str)+1));
    strcpy(copy, str);

    return copy;
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
    for(char c=fgetc(fileToCopy); c != EOF; c = fgetc(fileToCopy)) {
        if(c == '\n') {
            tempNumLines += 1;
        }
    }
    rewind(fileToCopy);
    *numLines = tempNumLines;

    char **fileLines = (char **)malloc(sizeof(char*) * (tempNumLines + 1));
    char buffer[fileLength + 1];
    char c = fgetc(fileToCopy);
    int i = 0;
    int j = 0;
    while(true) {
        if(c == EOF) {
            break;
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

void freeTable(char **table, int numLines) {
    if(table == NULL) {
        return;
    }

    for(int i = 0; i < numLines; i++) {
        free(table[i]);
    }

    free(table);
}

void reverse(char *s, int size) {
    if(s == NULL) {
        return;
    }

    char *temp = (char *)malloc(sizeof(char) * (size + 1));
    for(int i=0; i<size - 1; i++) {
        temp[size - i - 2] = s[i];
    }
    temp[size - 1] = '\0';

    for(int i=0; i<size; i++) {
        s[i] = temp[i];
    }

    free(temp);

    return;
}
