/**
 * This program processes a CSV file of data on major league
 * baseball teams, sorts them according to win percentage and
 * prints them to the standard output.
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Frees the given (n x m) table
 */
void freeTable(char **table, int n, int m);

/**
 * A sorting function to sort the teams and their win percentages
 * using the selection sort algorithm which successively finds the
 * "maximum" element and places it at the front of the array
 */
void sortMLB(char **teams, double *winPerc, int numTeams);

/**
 * This function prints the given teams with win percentages
 * to the standard output.
 */
void printMLB(char **teams, double *winPerc, int numTeams);

int main(int argc, char **argv) {
  int const maxSize = 50;
  int const numTeams = 16;
  char filePath[] = "data/mlb_nl_2011.txt";
  char tempBuffer[100];

  int i;
  char **teams = (char **)malloc(sizeof(char *) * numTeams);
  double *winPercentages = (double *)malloc(sizeof(double) * numTeams);
  for (i = 0; i < numTeams; i++) {
    teams[i] = (char *)malloc(sizeof(char) * maxSize);
  }

  FILE *instream = fopen(filePath, "r");
  if (instream == NULL) {
    fprintf(stderr, "Unable to open file: %s\n", "data/mlb_nl_2011.txt");
    exit(1);
  }

  i = 0;
  while (fgets(tempBuffer, maxSize, instream) != NULL) {
    tempBuffer[strlen(tempBuffer) - 1] = '\0';
    char *teamToken = strtok(tempBuffer, " ");
    strcpy(teams[i], teamToken);
    char *winsToken = strtok(NULL, " ");
    char *lossesToken = strtok(NULL, " ");
    winPercentages[i] = ((double)atoi(winsToken) / (atoi(lossesToken) + atoi(winsToken)));
    i++;
  }
  fclose(instream);

  // sort them
  sortMLB(teams, winPercentages, numTeams);
  // print them out
  printMLB(teams, winPercentages, numTeams);

  freeTable(teams, numTeams, maxSize);
  free(winPercentages);

  return 0;
}

void sortMLB(char **teams, double *winPerc, int numTeams) {
  int i, j, max_index;
  char tmp_str[100];
  double tmp_dbl;
  // for each element i
  for (i = 0; i < numTeams - 1; i++) {
    max_index = i;
    // find the maximum element among elements i+1 thru n-2
    for (j = i + 1; j < numTeams; j++) {
      if (winPerc[max_index] < winPerc[j]) {
        max_index = j;
      }
    }
    // swap the ith element and the maximum element
    // in this case, elements from both arrays need to be swapped
    // at the same time; forgo swapping if it is in-place
    if(i != max_index) {
      tmp_dbl = winPerc[i];
      winPerc[i] = winPerc[max_index];
      winPerc[max_index] = tmp_dbl;
      strcpy(tmp_str, teams[i]);
      strcpy(teams[i], teams[max_index]);
      strcpy(teams[max_index], tmp_str);
    }
  }
}

void printMLB(char **teams, double *winPerc, int numTeams) {
  int i = 0;
  printf("%-12s %-10s\n", "TEAM", "WIN PERC");
  for (i = 0; i < numTeams; i++) {
    printf("%-12s %.3f%%\n", teams[i], winPerc[i] * 100.0);
  }
}

void freeTable(char **table, int n, int m) {
  if(table == NULL) {
    return;
  }
  for(int i=0; i<n; i++) {
    free(table[i]);
  }
  free(table);
}