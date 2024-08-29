
/**
 * Scales the given rgb integer component (on the
 * scale [0, 255]) to a floating point number on the
 * scale [0, 1].
 *
 * Note: this function is only included to demonstrate
 * how to unit test floating point values.  See the
 * colorUtilsTester.c for more.
 */
double rgbIntToFloat(int c);

/**
 * Returns the maximum value among the three
 * given integer values.
 */
int max(int x, int y, int z);

/**
 * Returns a gray-scaled RGB value of the three
 * given RGB values using the average technique.
 *
 */
int toGrayScaleAverage(int r, int g, int b);

/**
 * Returns the minimum value among the three
 * given integer values.
 */
int min(int x, int y, int z);

/**
 * Returns a gray-scaled RGB value of the three
 * given RGB values using the lightness technique.
 */
int toGrayScaleLightness(int r, int g, int b);

/**
 * Returns a gray-scaled RGB value of the three
 * given RGB values using the luminosity technique.
 */
int toGrayScaleLuminosity(int r, int g, int b);

/**
 * Calculates new red value for Sepia output with
 * 0.393r + 0.769g + 0.189b
*/
int toSepiaRed(int r, int g, int b);

/**
 * Calculates new green value for Sepia output with
 * 0.349r + 0.686g + 0.168b
 */
int toSepiaGreen(int r, int g, int b);

/**
 * Calculates new blue value for Sepia output with
 * 0.272r + 0.534g + 0.131b
 */
int toSepiaBlue(int r, int g, int b);