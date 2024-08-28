/**
 * Author: Matt Schlatter
 * Date: 2022-11-07
 *
 * Converts given DNA sequence to proteins by
 * converting the DNA to RNA and RNA to proteins
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "file_utils.h"
#include "protein_utils.h"

int main(int argc, char **argv) {

    if(argc != 3) {
        printf("Execution should include input text file and output text file\n");
        exit(1);
    }

    char *dnaInputFile = argv[1];
    FILE *dnaInput = fopen(dnaInputFile, "r");
    char *proteinOutputFile = argv[2];

    fseek(dnaInput, 0, SEEK_END);
    int fileLength = ftell(dnaInput);
    fseek(dnaInput, 0, SEEK_SET);
    fclose(dnaInput);

    char *dna = (char *)malloc(sizeof(char) * (fileLength + 1));
    strcpy(dna, getFileContents(dnaInputFile));

    if(dna == NULL) {
        printf("Unable to open input file\n");
        exit(1);
    }
    int n = strlen(dna);

    removeChar(dna, ' ');
    removeChar(dna, '\t');
    removeChar(dna, '\n');
    replaceChar(dna, 'T', 'U');

    char **rna = (char **) malloc(sizeof(char *) * n);
    int charsSoFar = 0;
    int numOfRnas = (n / 3);
    for(int i=0; i<numOfRnas; i++) {
        rna[i] = (char *) malloc(sizeof(char) * 4);
        for(int j=0; j<3; j++) {
            rna[i][j] = dna[charsSoFar];
            charsSoFar++;
        }
        rna[i][3] = '\0';
    }

    FILE *output = fopen(proteinOutputFile, "w");
    if(output == NULL) {
        printf("Unable to open output file\n");
        exit(1);
    }

    char currentProtein;
    for(int i=0; i<numOfRnas; i++) {
        currentProtein = rnaToProtein(rna[i]);
        if(currentProtein == 'x') {
            break; //breaks loop for premature end to protein sequencing (UAA, UAG, UGA)
        }
        fprintf(output, "%c", currentProtein);
    }
    fclose(output);

    for(int i=0; i<numOfRnas; i++) {
        free(rna[i]);
    }
    free(rna);
    free(dna);

    return 0;
}