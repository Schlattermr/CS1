/**
 * Authors: Jack Baldwin and Matt Schlatter
 * Date: 2022/06/10
 *
 * Defines functions from colorUtils.h with error handling to convert
 * RGB values to CMYK values and vice versa
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <math.h>
#include <cmocka.h>
#include <time.h>

#include "colorUtils.h"

double max(double r, double g, double b) {
  return (r > g) ? (r > b ? r : b) : (g > b ? g : b);
}

int rgbToCMYK(int r, int g, int b, double *c, double *m, double *y, double *k) {
    if(c == NULL || m == NULL || y == NULL || k == NULL) {
        return NULL_MEMORY;
    } else if(r > 255 || r < 0) {
        return INVALID_R_VALUE;
    } else if(g > 255 || g < 0) {
        return INVALID_G_VALUE;
    } else if(b > 255 || b < 0) {
        return INVALID_B_VALUE;
    } else if(r == 0 && g == 0 && b == 0) {
        return DIVISION_BY_ZERO_ERROR;
    }

    double newR = r / 255.0;
    double newG = g / 255.0;
    double newB = b / 255.0;
    double tempK = 1 - (max(newR,newG,newB));
    double tempC = (1 - newR - tempK) / (1 - tempK);
    double tempM = (1 - newG - tempK) / (1 - tempK);
    double tempY = (1 - newB - tempK) / (1 - tempK);
    *k = tempK;
    *c = tempC;
    *m = tempM;
    *y = tempY;

    return NO_ERROR;
}

int cmykToRGB(double c, double m, double y, double k, int *r, int *g, int *b) {
    if(r == NULL || g == NULL || b == NULL) {
        return NULL_MEMORY;
    } else if(c < 0.0 || c > 1.0) {
        return INVALID_C_VALUE;
    } else if(m < 0.0 || m > 1.0) {
        return INVALID_M_VALUE;
    } else if(y < 0.0 || y > 1.0) {
        return INVALID_Y_VALUE;
    } else if(k < 0.0 || k > 1.0) {
        return INVALID_K_VALUE;
    } else if(c == 0.0 && m == 0.0 && y == 0.0 && k == 1.0) {
        return DIVISION_BY_ZERO_ERROR;
    }

    *r = round(255 * (1 - c) * (1 - k));
    *g = round(255 * (1 - m) * (1 - k));
    *b = round(255 * (1 - y) * (1 - k));

    return NO_ERROR;
}