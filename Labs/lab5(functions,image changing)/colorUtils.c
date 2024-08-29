#include <math.h>
#include "colorUtils.h"

double rgbIntToFloat(int c) {
  return (c / 255.0);
}

int max(int x, int y, int z) {
  int m = x > y ? x : y;
  m = m > z ? m : z;
  return m;
}

int toGrayScaleAverage(int r, int g, int b) {
  int average = round((r + g + b) / 3.0);
  return average;
}

int min(int x, int y, int z) {
  int m = x < y ? x : y;
  m = m < z ? m : z;
  return m;
}

int toGrayScaleLightness(int r, int g, int b) {
  return round((max(r,g,b) + min(r,g,b)) / 2);
}

int toGrayScaleLuminosity(int r, int g, int b) {
  int luminosity = round((0.21 * r) + (0.72 * g) + (0.07 * b));
  return luminosity;
}

int toSepiaRed(int r, int g, int b) {
  if(r > 255) {
    r = 255;
  } else if(g > 255) {
    g = 255;
  } else if(b > 255) {
    b = 255;
  }
  int redConverted = round((0.393 * r) + (0.769 * g) + (0.189 * b));
  return redConverted;
}

int toSepiaGreen(int r, int g, int b) {
  if(r > 255) {
    r = 255;
  } else if(g > 255) {
    g = 255;
  } else if(b > 255) {
    b = 255;
  }
  int greenConverted = round((0.349 * r) + (0.686 * g) + (0.168 * b));
  return greenConverted;
}

int toSepiaBlue(int r, int g, int b) {
  if(r > 255) {
    r = 255;
  } else if(g > 255) {
    g = 255;
  } else if(b > 255) {
    b = 255;
  }
  int blueConverted = round((0.272 * r) + (0.534 * g) + (0.131 * b));
  return blueConverted;
}
