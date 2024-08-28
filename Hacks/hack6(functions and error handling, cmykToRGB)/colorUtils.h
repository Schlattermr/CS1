/**\
 * Header files with prototypes and documentation
 * for functions used in colorUtils.c
 * All error codes defined below
 */
typedef enum {
    NO_ERROR,
    NULL_MEMORY,
    INVALID_R_VALUE,
    INVALID_G_VALUE,
    INVALID_B_VALUE,
    INVALID_C_VALUE,
    INVALID_M_VALUE,
    INVALID_Y_VALUE,
    INVALID_K_VALUE,
    DIVISION_BY_ZERO_ERROR,
} ErrorCode;

/**
 * Returns the maximum value among the three given values
 */
double max(double r, double g, double b);

/**
 * Converts from an RGB color model to a CMYK color model
 * by first scaling each RGB value to the CMYK [0,1] range
 *
 * r' = r/255
 * g' = g/255
 * b' = b/255
 *
 * And then using the following formulas
 *
 * k = max(r',g',b')
 * c = (1 - r' - k) / (1 - k)
 * m = (1 - g' - k) / (1 - k)
 * y = (1 - b' - k) / (1 - k)
 */
int rgbToCMYK(int r, int g, int b, double *c, double *m, double *y, double *k);

/**
 * Converts from a CMYK color model to a RGB color model
 * using the following formulas
 *
 * r = 255 * (1 - c) * (1 - k)
 * g = 255 * (1 - m) * (1 - k)
 * b = 255 * (1 - y) * (1 - k)
 */
int cmykToRGB(double c, double m, double y, double k, int *r, int *g, int *b);