/**
 * Author: Matt Schlatter
 * Date: 2022-12-12
 *
 * Sorts datasets by date/time and temperature, as well as
 * produces error reports with missing or inconsistent data
 * between the two given datasets
 *
 * For temperature, the minimum, max, and mean are data points are printed
 * For date/time, the earliest and most recent data points are printed
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "weather.h"

int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <first file> <second file>\n", argv[0]);
        exit(1);
    }

    int n;
    WeatherData* datasetA = loadDataFromFile(argv[1], &n);
    if(datasetA == NULL) {
        printf("ERROR: Could not open file '%s'!\n", argv[1]);
        exit(1);
    } else {
        printf("Loaded %d data points from dataset A\n", n);
    }

    int m;
    WeatherData* datasetB = loadDataFromFile(argv[2], &m);
    if(datasetB == NULL) {
        printf("ERROR: Could not open file '%s'!\n", argv[2]);
        exit(1);
    } else {
        printf("Loaded %d data points from dataset B\n", m);
    }

    qsort(datasetA, n, sizeof(WeatherData), weatherDataByTemperature);
    double datasetAMean = findMeanTemp(datasetA, n);
    printf("Temperature Reports (Dataset A)\n");
    printf("-==-==-==-==-==-==-==-==-==-==-==-==-\n");
    printf("Minimum: %3.2f\n", datasetA[0].temperature);
    printf("Mean:    %3.2f\n", datasetAMean);
    printf("Maximum: %3.2f\n\n", datasetA[n - 1].temperature);

    qsort(datasetA, n, sizeof(WeatherData), weatherDataByDate);
    printf("Data Reports (Dataset A)\n");
    printf("-==-==-==-==-==-==-==-==-==-==-==-==-\n");
    printf("Earliest:    %3.2f (%s)\n", datasetA[0].temperature, datasetA[0].dateTimeStamp);
    printf("Most Recent: %3.2f (%s)\n\n", datasetA[n - 1].temperature, datasetA[n - 1].dateTimeStamp);

    qsort(datasetB, m, sizeof(WeatherData), weatherDataByDate);
    WeatherData key;
    key.dateTimeStamp[0] = '\0';
    WeatherData *checker = NULL;
    printf("Inconsistent/Missing Data Reports\n");
    printf("-==-==-==-==-==-==-==-==-==-==-==-==-\n");
    for(int i=0; i<n; i++) {
        strcpy(key.dateTimeStamp, datasetA[i].dateTimeStamp);
        checker = bsearch(&key, datasetB, m, sizeof(WeatherData), weatherDataByDate);
        if(checker == NULL) {
            printf("Missing Data:      %.2f (%s)\n", datasetA[i].temperature, datasetA[i].dateTimeStamp);
        } else if(strcmp(datasetA[i].dateTimeStamp, datasetB[i].dateTimeStamp) == 0) {
            double tempDifference = fabs(datasetA[i].temperature - datasetB[i].temperature);
            if(tempDifference > 0.001) {
                printf("Inconsistent Data: %.2f vs. %.2f (%s)\n", datasetA[i].temperature, datasetB[i].temperature, datasetA[i].dateTimeStamp);
            }
        }
    }

    free(datasetA);
    free(datasetB);

    return 0;
}