#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "weather.h"

WeatherData *loadDataFromFile(const char *fileName, int *numPoints) {
    if(fileName == NULL || numPoints == NULL) {
        return NULL;
    }

    char buffer[1000];
    FILE *f = fopen(fileName, "r");
    if(f == NULL) {
        return NULL;
    }

    //first line indicates the number of records
    fgets(buffer, 1000, f);
    int n = atoi(buffer);
    *numPoints = n;
    WeatherData *data = (WeatherData *) malloc( sizeof(WeatherData) * n);
    for(int i = 0; i < n; i++) {
        fgets(buffer, 1000, f);
        strncpy(data[i].dateTimeStamp, buffer, 16);
        data[i].dateTimeStamp[16] = '\0';
        data[i].temperature = atof(&buffer[17]);
    }

    fclose(f);

    return data;
}

double findMeanTemp(WeatherData *a, int n) {
    if(a == NULL || n <= 0) {
        return 0;
    }

    double mean = 0;
    for(int i=0; i<n; i++) {
        mean += a[i].temperature;
    }
    mean /= n;

    return mean;
}

int weatherDataByDate(const void* a, const void* b) {
    const WeatherData *w1 = (const WeatherData *)a;
    const WeatherData *w2 = (const WeatherData *)b;

    return strcmp(w1->dateTimeStamp, w2->dateTimeStamp);
}

int weatherDataByTemperature(const void* a, const void* b) {
    const WeatherData *w1 = (const WeatherData *)a;
    const WeatherData *w2 = (const WeatherData *)b;

    if(w1->temperature < w2->temperature) {
        return -1;
    } else if(w1->temperature > w2->temperature) {
        return 1;
    } else {
        return 0;
    }
}