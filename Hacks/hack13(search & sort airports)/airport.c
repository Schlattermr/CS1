/**
 * Author: Matt Schlatter
 * Date: 2022-12-01
 *
 * Defines functions from airport.h
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

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

    printf("%8s, %15s, %40s, %5.6f, %5.6f, %4d, %12s, %s\n", a->gpsId, a->type, a->name, a->latitude, a->longitude, a->elevationFeet, a->city, a->countryAbbrv);

    return;
}

Airport *createAirport(const char *gpsId, const char *type, const char *name,
                       double latitude, double longitude, int elevationFeet,
                       const char *city, const char *countryAbbrv) {
    if(gpsId == NULL || type == NULL || name == NULL ||
            latitude < -90 || latitude > 90 ||
            longitude < -180 || longitude > 180 ||
            elevationFeet < -1266 || city == NULL || countryAbbrv == NULL) {
            //lowest elevation airport (Bar Yehuda Airfield)
        return NULL;
    }

    Airport *a = (Airport *)malloc(sizeof(Airport));
    initAirport(a, gpsId, type, name, latitude, longitude, elevationFeet, city, countryAbbrv);
    return a;
}

void initAirport(Airport *a, const char *gpsId, const char *type, const char *name,
                 double latitude, double longitude, int elevationFeet,
                 const char *city, const char *countryAbbrv) {
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
    a->countryAbbrv = deepStringCopy(countryAbbrv);

    return;
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

int cmpByGPSId(const void* a, const void* b) {
    const Airport *a1 = (const Airport *)a;
    const Airport *a2 = (const Airport *)b;
    return strcmp(a1->gpsId, a2->gpsId);
}

int cmpByType(const void* a, const void* b) {
    const Airport *a1 = (const Airport *)a;
    const Airport *a2 = (const Airport *)b;
    return strcmp(a1->type, a2->type);
}

int cmpByName(const void* a, const void* b) {
    const Airport *a1 = (const Airport *)a;
    const Airport *a2 = (const Airport *)b;
    return strcmp(a1->name, a2->name);
}

int cmpByNameDesc(const void* a, const void* b) {
    const Airport *a1 = (const Airport *)a;
    const Airport *a2 = (const Airport *)b;
    return strcmp(a2->name, a1->name);
}

int cmpByCountryAbbrvCity(const void* a, const void* b) {
    const Airport *a1 = (const Airport *)a;
    const Airport *a2 = (const Airport *)b;
    if (strcmp(a1->countryAbbrv, a2->countryAbbrv) == 0) {
    return strcmp(a1->city, a2->city);
  } else {
    return strcmp(a1->countryAbbrv, a2->countryAbbrv);
  }
}

int cmpByLatitude(const void* a, const void* b) {
    const Airport *a1 = (const Airport *)a;
    const Airport *a2 = (const Airport *)b;

    if(a1->latitude < a2->latitude) {
        return -1;
    } else if(a1->latitude > a2->latitude) {
        return 1;
    } else {
        return 0;
    }
}

int cmpByLongitude(const void* a, const void* b) {
    const Airport *a1 = (const Airport *)a;
    const Airport *a2 = (const Airport *)b;

    if(a1->longitude < a2->longitude) {
        return -1;
    } else if(a1->longitude > a2->longitude) {
        return 1;
    } else {
        return 0;
    }
}

int cmpByLincolnDistance(const void* a, const void* b) {
    const Airport *a1 = (const Airport *)a;
    const Airport *a2 = (const Airport *)b;

    Airport *lincoln = createAirport("gpsId0", "medium", "LNK", 40.850700, -96.758100, 1219, "Lincoln", "US");
    double distance1 = getAirDistance(lincoln, a1);
    double distance2 = getAirDistance(lincoln, a2);

    if(distance1 < distance2) {
        return -1;
    } else if(distance1 > distance2) {
        return 1;
    } else {
        return 0;
    }
}

void generateReports(Airport *airports, int n) {
    if(airports == NULL || n <= 0) {
        return;
    }

    printf("\nOriginal Order\n");
    printf(" GPS ID |           TYPE |                                    NAME | LATITUDE | LONGITUDE | ELEV FT | CITY | COUNTRY\n");
    for(int i=0; i<n; i++) {
        printAirport(&airports[i]);
    }

    printf("\nSorted by GPS ID\n");
    qsort(airports, n, sizeof(Airport), cmpByGPSId);
    printf(" GPS ID |           TYPE |                                    NAME | LATITUDE | LONGITUDE | ELEV FT | CITY | COUNTRY\n");
    for(int i=0; i<n; i++) {
        printAirport(&airports[i]);
    }

    printf("\nSorted by Type\n");
    qsort(airports, n, sizeof(Airport), cmpByType);
    printf(" GPS ID |           TYPE |                                    NAME | LATITUDE | LONGITUDE | ELEV FT | CITY | COUNTRY\n");
    for(int i=0; i<n; i++) {
        printAirport(&airports[i]);
    }

    printf("\nSorted by Name\n");
    qsort(airports, n, sizeof(Airport), cmpByName);
    printf(" GPS ID |           TYPE |                                    NAME | LATITUDE | LONGITUDE | ELEV FT | CITY | COUNTRY\n");
    for(int i=0; i<n; i++) {
        printAirport(&airports[i]);
    }

    printf("\nSorted by Name in Descending Order\n");
    qsort(airports, n, sizeof(Airport), cmpByNameDesc);
    printf(" GPS ID |           TYPE |                                    NAME | LATITUDE | LONGITUDE | ELEV FT | CITY | COUNTRY\n");
    for(int i=0; i<n; i++) {
        printAirport(&airports[i]);
    }

    printf("\nSorted by Latitude\n");
    qsort(airports, n, sizeof(Airport), cmpByLatitude);
    printf(" GPS ID |           TYPE |                                    NAME | LATITUDE | LONGITUDE | ELEV FT | CITY | COUNTRY\n");
    for(int i=0; i<n; i++) {
        printAirport(&airports[i]);
    }

    printf("\nSorted by Longitude\n");
    qsort(airports, n, sizeof(Airport), cmpByLongitude);
    printf(" GPS ID |           TYPE |                                    NAME | LATITUDE | LONGITUDE | ELEV FT | CITY | COUNTRY\n");
    for(int i=0; i<n; i++) {
        printAirport(&airports[i]);
    }

    printf("\nSorted by Country Abbreviation then City\n");
    qsort(airports, n, sizeof(Airport), cmpByCountryAbbrvCity);
    printf(" GPS ID |           TYPE |                                    NAME | LATITUDE | LONGITUDE | ELEV FT | CITY | COUNTRY\n");
    for(int i=0; i<n; i++) {
        printAirport(&airports[i]);
    }

    printf("\nSorted by Distance from Lincoln\n");
    qsort(airports, n, sizeof(Airport), cmpByLincolnDistance);
    printf(" GPS ID |           TYPE |                                    NAME | LATITUDE | LONGITUDE | ELEV FT | CITY | COUNTRY\n");
    for(int i=0; i<n; i++) {
        printAirport(&airports[i]);
    }

    printf("\nAirport closest to Lincoln: ");
    printAirport(&airports[0]);

    qsort(airports, n, sizeof(Airport), cmpByLongitude);
    printf("Airport at Geographic E-W Median: ");
    printAirport(&airports[(n/2)]);

    qsort(airports, n, sizeof(Airport), cmpByName);
    Airport nyKey;
    initAirport(&nyKey, "", "", "", 0, 0, 0, "New York", "US");
    Airport *nyAirport = bsearch(&nyKey, airports, n, sizeof(Airport), cmpByName);
    if(nyAirport == NULL) {
        printf("No such airport in \"New York\" was found.\n");
    } else {
        printf("Airport in New York, US: ");
        printAirport(nyAirport);
    }

    qsort(airports, n, sizeof(Airport), cmpByType);
    Airport largeKey;
    initAirport(&largeKey, "", "large_airport", "", 0, 0, 0, "", "");
    Airport *largeAirport = bsearch(&largeKey, airports, n, sizeof(Airport), cmpByType);
    if(largeAirport == NULL) {
        printf("No such \"large_airport\" was found.\n");
    } else {
        printf("Large airport: ");
        printAirport(largeAirport);
    }

    return;
}