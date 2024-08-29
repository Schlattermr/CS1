/**
 * This program performs several ad-hoc unit
 * tests on the color utils library.
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "colorUtils.h"

#define DELTA 0.0001

/**
 * This function returns true if the two given
 * values a, b are within DELTA of each other.
 */
int isClose(double a, double b);

int main(int argc, char **argv) {

  int r, g, b, c;
  int x = 10, y = 20, z = 30;
  int result;
  int expectedResult;
  double expectedD, actualD;
  int numPassed = 0;
  int numFailed = 0;

  c = 123;
  expectedD = 0.4823;
  printf("TESTING: rgbIntToFloat(%d): ", c);
  actualD = rgbIntToFloat(c);
  if(!isClose(expectedD, actualD)) {
    printf("FAILED: returned %f, expected %f\n", actualD, expectedD);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  c = 53;
  expectedD = 0.2078;
  printf("TESTING: rgbIntToFloat(%d): ", c);
  actualD = rgbIntToFloat(c);
  if(!isClose(expectedD, actualD)) {
    printf("FAILED: returned %f, expected %f\n", actualD, expectedD);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  printf("TESTING: max(%d,%d,%d): ", x, y, z);
  result = max(x, y, z);
  if(result != 30) {
    printf("FAILED: max returned %d, expected 30\n", result);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  printf("TESTING: max(%d,%d,%d): ", x, z, y);
  result = max(x, z, y);
  if(result != 30) {
    printf("FAILED: max returned %d, expected 30\n", result);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  printf("TESTING: max(%d,%d,%d): ", y, x, z);
  result = max(y, x, z);
  if(result != 30) {
    printf("FAILED: max returned %d, expected 30\n", result);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  printf("TESTING: max(%d,%d,%d): ", y, z, x);
  result = max(y, z, x);
  if(result != 30) {
    printf("FAILED: max returned %d, expected 30\n", result);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  printf("TESTING: max(%d,%d,%d): ", z, x, y);
  result = max(z, x, y);
  if(result != 30) {
    printf("FAILED: max returned %d, expected 30\n", result);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  printf("TESTING: max(%d,%d,%d): ", z, y, x);
  result = max(z, y, x);
  if(result != 30) {
    printf("FAILED: max returned %d, expected 30\n", result);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  printf("TESTING: max(%d,%d,%d): ", x, x, z);
  result = max(x, x, z);
  if(result != 30) {
    printf("FAILED: max returned %d, expected 30\n", result);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  printf("TESTING: max(%d,%d,%d): ", x, z, x);
  result = max(x, z, x);
  if(result != 30) {
    printf("FAILED: max returned %d, expected 30\n", result);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  printf("TESTING: max(%d,%d,%d): ", z, x, x);
  result = max(z, x, x);
  if(result != 30) {
    printf("FAILED: max returned %d, expected 30\n", result);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  printf("TESTING: max(%d,%d,%d): ", z, z, z);
  result = max(z, z, z);
  if(result != 30) {
    printf("FAILED: max returned %d, expected 30\n", result);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  r = 255, g = 0, b = 0;
  expectedResult = 85;
  printf("TESTING: toGrayScaleAverage(%d,%d,%d): ", r, g, b);
  result = toGrayScaleAverage(r, g, b);
  if(result != expectedResult) {
    printf("FAILED: toGrayScaleAverage returned %d, expected %d\n", result, expectedResult);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  r = 100, g = 39, b = 40;
  expectedResult = 60;
  printf("TESTING: toGrayScaleAverage(%d,%d,%d): ", r, g, b);
  result = toGrayScaleAverage(r, g, b);
  if(result != expectedResult) {
    printf("FAILED: toGrayScaleAverage returned %d, expected %d\n", result, expectedResult);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  printf("TESTING: min(%d,%d,%d): ", x, y, z);
  result = min(x, y, z);
  if(result != 10) {
    printf("FAILED: min returned %d, expected 10\n", result);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  r = 200, g = 123, b = 10;
  expectedResult = 105;
  printf("TESTING: toGrayScaleLightness(%d,%d,%d): ", r, g, b);
  result = toGrayScaleLightness(r, g, b);
  if(result != expectedResult) {
    printf("FAILED: toGrayScaleLightness returned %d, expected %d\n", result, expectedResult);
    numFailed++;
   } else {
    printf("PASSED\n");
    numPassed++;
   }

  r = 18, g = 100, b = 72;
  expectedResult = 81;
  printf("TESTING: toGrayScaleLuminosity(%d,%d,%d): ", r, g, b);
  result = toGrayScaleLuminosity(r, g, b);
  if(result != expectedResult) {
    printf("FAILED: toGrayScaleLuminosity returned %d, expected %d\n", result, expectedResult);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  r = 101, g = 201, b = 66;
  expectedResult = 207;
  printf("TESTING: toSepiaRed(%d,%d,%d): ", r, g, b);
  result = toSepiaRed(r, g, b);
  if(result != expectedResult) {
    printf("FAILED: toSepiaRed returned %d, expected %d\n", result, expectedResult);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  r = 222, g = 111, b = 54;
  expectedResult = 163;
  printf("TESTING: toSepiaGreen(%d,%d,%d): ", r, g, b);
  result = toSepiaGreen(r, g, b);
  if(result != expectedResult) {
    printf("FAILED: toSepiaGreen returned %d, expected %d\n", result, expectedResult);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  r = 38, g = 103, b = 245;
  expectedResult = 97;
  printf("TESTING: toSepiaBlue(%d,%d,%d): ", r, g, b);
  result = toSepiaBlue(r, g, b);
  if(result != expectedResult) {
    printf("FAILED: toSepiaBlue returned %d, expected %d\n", result, expectedResult);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  printf("Number Test Cases Passed: %6d\n", numPassed);
  printf("Number Test Cases Failed: %6d\n", numFailed);
  printf("Percent Passed:           %6.2f\n", 100.0 * numPassed / (numPassed + numFailed));

  return 0;

}

int isClose(double a, double b) {
  return (fabs(a-b) < DELTA);
}
