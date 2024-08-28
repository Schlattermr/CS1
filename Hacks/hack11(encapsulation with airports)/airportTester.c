/**
 * Author: Matt Schlatter
 * Date: 2022-11-09
 *
 * Tests functions defined in airport.c
 * three times each
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "airport.h"

int main(int argc, char **argv) {

    int numPassed = 0;
    int numFailed = 0;

    //createAirport and initAirport test 1
    char *gpsId1 = (char *)malloc(sizeof(char) * 7);
    char *type1 = (char *)malloc(sizeof(char) * 4);
    char *name1 = (char *)malloc(sizeof(char) * 4);
    char *city1 = (char *)malloc(sizeof(char) * 7);
    char *country1 = (char *)malloc(sizeof(char) * 4);
    strcpy(gpsId1, "gpsId1");
    strcpy(type1, "big");
    strcpy(name1, "DIA");
    double latitude1 = 39.856100;
    double longitude1 = -104.673700;
    int elevationFeet1 = 5430;
    strcpy(city1, "Denver");
    strcpy(country1, "USA");
    Airport *dia = createAirport(gpsId1, type1, name1, latitude1,
                                 longitude1, elevationFeet1, city1,
                                 country1);
    if((strcmp(gpsId1, dia->gpsId)) == 0 &&
       (strcmp(type1, dia->type)) == 0 &&
       (strcmp(name1, dia->name)) == 0 &&
       latitude1 == dia->latitude &&
       longitude1 == dia->longitude &&
       elevationFeet1 == dia->elevationFeet &&
       (strcmp(city1, dia->city)) == 0 &&
       (strcmp(country1, dia->country)) == 0) {
        numPassed++;
    } else {
        numFailed++;
    }

    //airportToString test 1
    char airportStringActual[1000];
    char airportStringExpected[1000];
    strcpy(airportStringExpected, "gpsId1,big,DIA,39.856100,-104.673700,5430,Denver,USA");
    strcpy(airportStringActual, airportToString(dia));
    if((strcmp(airportStringActual, airportStringExpected)) == 0) {
        numPassed++;
    } else {
        numFailed++;
    }
    strcpy(airportStringActual, "");
    strcpy(airportStringExpected, "");
    free(gpsId1);
    free(type1);
    free(name1);
    free(city1);
    free(country1);

    //createAirport and initAirport test 2
    char *gpsId2 = (char *)malloc(sizeof(char) * 7);
    char *type2 = (char *)malloc(sizeof(char) * 4);
    char *name2 = (char *)malloc(sizeof(char) * 4);
    char *city2 = (char *)malloc(sizeof(char) * 12);
    char *country2 = (char *)malloc(sizeof(char) * 4);
    strcpy(gpsId2, "gpsId2");
    strcpy(type2, "big");
    strcpy(name2, "LAX");
    double latitude2 = 33.941600;
    double longitude2 = -118.408500;
    int elevationFeet2 = 128;
    strcpy(city2, "Los Angeles");
    strcpy(country2, "USA");
    Airport *lax = createAirport(gpsId2, type2, name2, latitude2,
                               longitude2, elevationFeet2, city2,
                               country2);
    if((strcmp(gpsId2, lax->gpsId)) == 0 &&
       (strcmp(type2, lax->type)) == 0 &&
       (strcmp(name2, lax->name)) == 0 &&
       latitude2 == lax->latitude &&
       longitude2 == lax->longitude &&
       elevationFeet2 == lax->elevationFeet &&
       (strcmp(city2, lax->city)) == 0 &&
       (strcmp(country2, lax->country)) == 0) {
        numPassed++;
    } else {
        numFailed++;
    }

    //airportToString test 2
    strcpy(airportStringExpected, "gpsId2,big,LAX,33.941600,-118.408500,128,Los Angeles,USA");
    strcpy(airportStringActual, airportToString(lax));
    if((strcmp(airportStringActual, airportStringExpected)) == 0) {
        numPassed++;
    } else {
        numFailed++;
    }
    strcpy(airportStringActual, "");
    strcpy(airportStringExpected, "");
    free(gpsId2);
    free(type2);
    free(name2);
    free(city2);
    free(country2);

    //createAirport and initAirport test 3
    char *gpsId3 = (char *)malloc(sizeof(char) * 7);
    char *type3 = (char *)malloc(sizeof(char) * 4);
    char *name3 = (char *)malloc(sizeof(char) * 4);
    char *city3 = (char *)malloc(sizeof(char) * 10);
    char *country3 = (char *)malloc(sizeof(char) * 4);
    strcpy(gpsId3, "gpsId3");
    strcpy(type3, "big");
    strcpy(name3, "CPT");
    double latitude3 = -33.971500;
    double longitude3 = 18.602100;
    double elevationFeet3 = 151;
    strcpy(city3, "Cape Town");
    strcpy(country3, "ZAF");
    Airport *cpt = createAirport(gpsId3, type3, name3, latitude3,
                                 longitude3, elevationFeet3, city3,
                                 country3);
    if((strcmp(gpsId3, cpt->gpsId)) == 0 &&
       (strcmp(type3, cpt->type)) == 0 &&
       (strcmp(name3, cpt->name)) == 0 &&
       latitude3 == cpt->latitude &&
       longitude3 == cpt->longitude &&
       elevationFeet3 == cpt->elevationFeet &&
       (strcmp(city3, cpt->city)) == 0 &&
       (strcmp(country3, cpt->country)) == 0) {
        numPassed++;
    } else {
        numFailed++;
    }

    //airportToString test 3
    strcpy(airportStringExpected, "gpsId3,big,CPT,-33.971500,18.602100,151,Cape Town,ZAF");
    strcpy(airportStringActual, airportToString(cpt));
    if((strcmp(airportStringActual, airportStringExpected)) == 0) {
        numPassed++;
    } else {
        numFailed++;
    }
    free(gpsId3);
    free(type3);
    free(name3);
    free(city3);
    free(country3);

    //getAirDistance test 1
    double tolerance = 0.0001;
    double expectedAirDistance = 1384.923519;
    double actualAirDistance = getAirDistance(dia, lax);
    if((fabs(expectedAirDistance - actualAirDistance)) < tolerance) {
        numPassed++;
    } else {
        numFailed++;
        printf("Got: %f\nWanted: %f\n", actualAirDistance, expectedAirDistance);
    }

    //getAirDistance test 2
    expectedAirDistance = 16080.200590;
    actualAirDistance = getAirDistance(lax, cpt);
    if((fabs(expectedAirDistance - actualAirDistance)) < tolerance) {
        numPassed++;
    } else {
        numFailed++;
        printf("Got: %f\nWanted: %f\n", actualAirDistance, expectedAirDistance);
    }

    //getAirDistance test 3
    expectedAirDistance = 15013.960060;
    actualAirDistance = getAirDistance(cpt, dia);
    if((fabs(expectedAirDistance - actualAirDistance)) < tolerance) {
        numPassed++;
    } else {
        numFailed++;
        printf("Got: %f\nWanted: %f\n", actualAirDistance, expectedAirDistance);
    }

    free(dia->gpsId);
    free(dia->type);
    free(dia->name);
    free(dia->city);
    free(dia->country);
    free(dia);

    free(lax->gpsId);
    free(lax->type);
    free(lax->name);
    free(lax->city);
    free(lax->country);
    free(lax);

    free(cpt->gpsId);
    free(cpt->type);
    free(cpt->name);
    free(cpt->city);
    free(cpt->country);
    free(cpt);

    printf("Percent Passed: %.2f\n", ((double)numPassed / (numPassed + numFailed)) * 100);
    printf("Percent Failed: %.2f\n", ((double)numFailed / (numPassed + numFailed)) * 100);

    return 0;
}