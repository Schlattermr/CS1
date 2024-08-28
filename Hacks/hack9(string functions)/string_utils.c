/**
 * Authors: Matt Schlatter
 * Date: 2022/27/10
 *
 * Program defines prototypes from string_utils.h
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "string_utils.h"

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

char *replaceCharCopy(const char *s, char oldChar, char newChar) {
    if(s == NULL) {
        return NULL;
    }
    int n = strlen(s);
    int i = 0;
    char *copyS = (char *) malloc (sizeof(char) * (n + 1));
    strcpy(copyS, s);

    for(i=0; i<n; i++) {
        if(s[i] != oldChar) {
            copyS[i] = s[i];
        } else {
            copyS[i] = newChar;
        }
    }
    copyS[n] = '\0';
    return copyS;
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

char *removeCharCopy(const char *s, char c) {
    if(s == NULL) {
        return NULL;
    }
    int n = strlen(s);
    char *copyS = (char *) malloc (sizeof(char) * (n + 1));
    strcpy(copyS, s);

    removeChar(copyS, c);

    return copyS;
}

char **lengthSplit(const char *s, int newSize) {
    if(s == NULL || newSize <= 0) {
        return NULL;
    }
    int fullSize = strlen(s);
    int counter = 0;
    int charsPerSplit = (fullSize / newSize);
    int numOfSplits = charsPerSplit;
    char copy[fullSize + 1];
    strcpy(copy, s);
    char *buffer = (char *)malloc(sizeof(char) * (newSize + 1));

    char **split = (char **) malloc (sizeof(char *) * (numOfSplits + 1));
    for(int i=0; i<numOfSplits; i++) {
        split[i] = (char *) malloc (sizeof(char) * (charsPerSplit + 1));
    }

    for(int i=0; i<numOfSplits; i++) {
        // if(i == n) {
        //     for(int j=0; j<=lenOfLastSplit; j++) {
        //         if(j == lenOfLastSplit) {
        //             buffer[j] = '\0';
        //             strcpy(split[i], buffer);
        //             strcpy(buffer, "");
        //         }
        //         buffer[j] = copy[counter];
        //         counter++;
        //     }
        // }
        for(int j=0; j<=charsPerSplit; j++) {
            if(j == charsPerSplit || counter == fullSize) {
                buffer[j] = '\0';
                strcpy(split[i], buffer);
                strcpy(buffer, "");
            }
            buffer[j] = copy[counter];
            counter++;
        }
    }
    free(buffer);

    return split;
}