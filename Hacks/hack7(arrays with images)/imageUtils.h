/**
 * A structure that represents a single pixel value using
 * the RGB (red-blue-green) color model.  Each integer
 * value is in the range [0, 255].
 */
typedef struct {
  int red;
  int green;
  int blue;
} Pixel;

/**
 * Loads an image file specified by the given file path/name.
 * The height and width are indicated in the two pass-by-reference variables.
 * The image is returned as a two-dimensional array of Pixel values
 * of dimension (height x width) where the pixel at [0][0] corresponds to
 * the top-left most pixel value.
 */
Pixel **loadImage(const char *filePath, int *height, int *width);

/**
 * Saves the given image (which is assumed to have the same format as in
 * loadImage() and is of the given height x width) to the file specified
 * by the given path/name.
 */
void saveImage(const char *filePath, Pixel **image, int height, int width);

/**
 * Makes an exact copy of the given image using a deep copy array
 * for a 2-D array type
 */
Pixel ** copyImage(Pixel **image, int height, int width);

/**
 * Flips given image horizontally by taking the copy image and
 * changing the width value of it, but keeping the height value
 * the same as the orginal image copy
 */
void flipHorizontal(Pixel **image, int height, int width);

/**
 * Flips given image vertically by taking the copy image and
 * changing the height value of it, but keeping the width value
 * the same as the original image copy
 */
void flipVertical(Pixel **image, int height, int width);

/**
 * Rotates the given image clockwise 90 degrees by sswaping the
 * width and height values of the orignal copy
 */
Pixel ** rotateClockwise(Pixel **image, int height, int width);

/**
 * Frees the given (height x width) table
 */
void freeTable(Pixel **table, int height, int width);