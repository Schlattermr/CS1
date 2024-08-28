/**
 * Authors: Jack Baldwin and Matt Schlatter
 * Date: 2022/29/09
 *
 * Tests functions in utils.c
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "utils.h"

int main(int argc, char **argv) {

    int numPassed = 0;
    int numFailed = 0;
    double tolerance = 0.0001;

    double degrees = 150.0;
    double expectedValue = ((5 * M_PI) / 6);
    double result = degreesToRadians(degrees);
    printf("TESTING: degreesToRadians(%f)\n", degrees);
    if(result == expectedValue) {
        printf("PASSED, actual output %f = expected output %f\n", result, expectedValue);
        numPassed++;
    } else {
        printf("FAILED, degreesToRadians gave %f and not %f\n", result, expectedValue);
        numFailed++;
    }

    degrees = 30.0;
    expectedValue = (M_PI / 6);
    result = degreesToRadians(degrees);
    printf("TESTING: degreesToRadians(%f)\n", degrees);
    if(result == expectedValue) {
        printf("PASSED, actual output %f = expected output %f\n", result, expectedValue);
        numPassed++;
    } else {
        printf("FAILED, degreesToRadians gave %f and not %f\n", result, expectedValue);
        numFailed++;
    }

    degrees = 225.0;
    expectedValue = (5 * M_PI / 4);
    result = degreesToRadians(degrees);
    printf("TESTING: degreesToRadians(%f)\n", degrees);
    if(result == expectedValue) {
        printf("PASSED, actual output %f = expected output %f\n", result, expectedValue);
        numPassed++;
    } else {
        printf("FAILED, degreesToRadians gave %f and not %f\n", result, expectedValue);
        numFailed++;
    }

    double originLatitude = -45.00;
    double originLongitude = 45.00;
    double destinationLatitude = -30.00;
    double destinationLongitude = 30.00;
    result = getAirDistance(originLatitude, originLongitude, destinationLatitude, destinationLongitude);
    expectedValue = 2121.664172;
    printf("TESTING: getAirDistance(%f, %f, %f, %f)\n", originLatitude, originLongitude, destinationLatitude, destinationLongitude);
    if(fabs(result - expectedValue) < tolerance) {
        printf("PASSED, actual output %f = expected output %f\n", result, expectedValue);
        numPassed++;
    } else {
        printf("FAILED, getAirDistance gave %f and not %f\n", result, expectedValue);
        numFailed++;
    }

    originLatitude = -40.00;
    originLongitude = -40.00;
    destinationLatitude = 40.00;
    destinationLongitude = 40.00;
    result = getAirDistance(originLatitude, originLongitude, destinationLatitude, destinationLongitude);
    expectedValue = 12024.183857;
    printf("TESTING: getAirDistance(%f, %f, %f, %f)\n", originLatitude, originLongitude, destinationLatitude, destinationLongitude);
    if(fabs(result - expectedValue) < tolerance) {
        printf("PASSED, actual output %f = expected output %f\n", result, expectedValue);
        numPassed++;
    } else {
        printf("FAILED, getAirDistance gave %f and not %f\n", result, expectedValue);
        numFailed++;
    }

    originLatitude = 89.00;
    originLongitude = 100.00;
    destinationLatitude = -89.00;
    destinationLongitude = -100.00;
    result = getAirDistance(originLatitude, originLongitude, destinationLatitude, destinationLongitude);
    expectedValue = 19976.471105;
    printf("TESTING: getAirDistance(%f, %f, %f, %f)\n", originLatitude, originLongitude, destinationLatitude, destinationLongitude);
    if(fabs(result - expectedValue) < tolerance) {
        printf("PASSED, actual output %f = expected output %f\n", result, expectedValue);
        numPassed++;
    } else {
        printf("FAILED, getAirDistance gave %f and not %f\n", result, expectedValue);
        numFailed++;
    }

    double percentC = 0.19;
    double normalTime = 2;
    result = lorentzTimeDilation(normalTime, percentC);
    expectedValue = 2.037108;
    printf("TESTING: lorentzTimeDilation(%f, %.2f)\n", normalTime, percentC);
    if(fabs(result - expectedValue) < tolerance) {
        printf("PASSED, actual output %f = expected output %f\n", result, expectedValue);
    } else {
        printf("FAILED, lorentzTimeDilation gave %f and not %f\n", result, expectedValue);
        numFailed++;
    }

    percentC = 0.69;
    normalTime = 420;
    result = lorentzTimeDilation(normalTime, percentC);
    expectedValue = 580.263283;
    printf("TESTING: lorentzTimeDilation(%f, %.2f)\n", normalTime, percentC);
    if(fabs(result - expectedValue) < tolerance) {
        printf("PASSED, actual output %f = expected output %f\n", result, expectedValue);
        numPassed++;
    } else {
        printf("FAILED, lorentzTimeDilation gave %f and not %f\n", result, expectedValue);
        numFailed++;
    }

    percentC = 0.87;
    normalTime = 5;
    result = lorentzTimeDilation(normalTime, percentC);
    expectedValue = 10.140924;
    printf("TESTING: lorentzTimeDilation(%f, %.2f)\n", normalTime, percentC);
    if(fabs(result - expectedValue) < tolerance) {
        printf("PASSED, actual output %f = expected output %f\n", result, expectedValue);
        numPassed++;
    } else {
        printf("FAILED, lorentzTimeDilation gave %f and not %f\n", result, expectedValue);
        numFailed++;
    }

    printf("Number of Tests Passed: %d\n", numPassed);
    printf("Number of Tests Failed: %d\n", numFailed);
    printf("Percentage Passed: %.2f%%\n", (((double) numPassed + (double) numFailed) / numPassed) * 100);

    return 0;
}