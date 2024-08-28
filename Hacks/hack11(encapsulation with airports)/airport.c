/**
 * Author: Matt Schlatter
 * Date: 2022-11-09
 *
 * Defines functions from airport.h
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "airport.h"

char *deepStringCopy(const char *source) {
    if(source == NULL) {
        return NULL;
    }

    char *deepCpy = (char *) malloc ((strlen(source) + 1) * sizeof(char));
    strcpy(deepCpy, source);

    return deepCpy;
}

double degreesToRadians(double degrees) {
    return (degrees / 180) * M_PI;
}

void printAirport(const Airport *a) {
    if(a == NULL) {
        return;
    }

    printf("GPS ID: %s\n", a->gpsId);
    printf("Type: %s\n", a->type);
    printf("Name: %s\n", a->name);
    printf("Latitude: %f\n", a->latitude);
    printf("Longitude: %f\n", a->longitude);
    printf("Elevation (feet): %d\n", a->elevationFeet);
    printf("City: %s\n", a->city);
    printf("Country: %s\n", a->countryAbbrv);

    return;
}

Airport *createAirport(const char *gpsId, const char *type, const char *name,
                       double latitude, double longitude, int elevationFeet,
                       const char *city, const char *country) {
    if(gpsId == NULL || type == NULL || name == NULL ||
            latitude < -90 || latitude >90 ||
            longitude < -180 || longitude > 180 ||
            elevationFeet < -1266 || city == NULL || country == NULL) {
            //lowest elevation airport (Bar Yehuda Airfield)
        return NULL;
    }

    Airport *a = (Airport *)malloc(sizeof(Airport));
    initAirport(a, gpsId, type, name, latitude, longitude, elevationFeet, city, country);
    return a;
}

void initAirport(Airport *a, const char *gpsId, const char *type,const char *name,
                 double latitude, double longitude, int elevationFeet,
                 const char *city, const char *country) {
    if(a == NULL) {
        return;
    }

    a->gpsId = deepStringCopy(gpsId);
    a->type = deepStringCopy(type);
    a->name = deepStringCopy(name);
    a->latitude = latitude;
    a->longitude = longitude;
    a->elevationFeet = elevationFeet;
    a->city = deepStringCopy(city);
    a->country = deepStringCopy(country);

    return;
}

char *airportToString(const Airport *a) {
    if(a == NULL) {
        return NULL;
    }

    char temp[1000];

    sprintf(temp, "%s,%s,%s,%f,%f,%d,%s,%s", a->gpsId, a->type, a->name, a->latitude,
            a->longitude, a->elevationFeet, a->city, a->country);

    char *airportString = (char *)malloc(sizeof(char) * (strlen(temp) + 1));
    strcpy(airportString, temp);

    return airportString;
}

double getAirDistance(const Airport *origin, const Airport *destination) {
    if(origin == NULL || destination == NULL) {
        return 0;
    }
    const int earthRadius = 6371; //kilometers, average

    double originLatRads = degreesToRadians(origin->latitude);
    double originLongRads = degreesToRadians(origin->longitude);
    double destLatRads = degreesToRadians(destination->latitude);
    double destLongRads = degreesToRadians(destination->longitude);

    //Spherical Law of Cosines
    double airDistance = (acos((sin(originLatRads) * sin(destLatRads)) +
                         (cos(originLatRads) * cos(destLatRads) * cos(destLongRads -
                          originLongRads)))) * earthRadius;

    return airDistance;
}

double getEstimatedTravelTime(const Airport *stops,
                              int size,
                              double aveKmsPerHour,
                              double aveLayoverTimeHrs) {
    if(stops == NULL || size < 0 || aveKmsPerHour < 0 || aveLayoverTimeHrs < 0) {
        return 0;
    }

    double estimatedHours = 0;
    double totalDistance = 0;
    //i = 1 because origin location is [0] so [i - 1] must equal [0]
    for(int i=1; i<size; i++) {
        totalDistance += getAirDistance(&stops[i - 1], &stops[i]);
    }
                                                                //no layover at start and end of trip
    estimatedHours = (totalDistance / aveKmsPerHour) + (aveLayoverTimeHrs * (size - 2));

    return estimatedHours;
}