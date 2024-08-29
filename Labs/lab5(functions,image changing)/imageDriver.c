/**
 * This program converts an input image to gray
 * scale or sepia depending on the provided
 * command line inputs.
 */
#include <stdlib.h>
#include <stdio.h>

#include "imageUtils.h"

int main(int argc, char **argv) {

  char *inputFile = NULL;
  char *outputFile = NULL;
  int mode = 1;
  if(argc == 3 || argc == 4) {
    inputFile = argv[1];
    outputFile = argv[2];
    if(argc == 4) {
      mode = atoi(argv[3]);
    }
  } else {
    fprintf(stderr, "Usage: %s inputFileName outputFileName [mode]\n", argv[0]);
    fprintf(stderr, "       mode: 1 = Average (default), 2 = Lightness, 3 = Luminosity, 4 = Sepia]\n");
    fprintf(stderr, "\n");
    fprintf(stderr, "Example: \n");
    fprintf(stderr, "  %s memorialStadium.jpg memorialStadiumSepia.jpg 4\n", argv[0]);
    exit(1);
  }

  int h, w;
  Pixel **image = loadImage(inputFile, &h, &w);
  if(mode == 1) {
    imageToGrayScaleAverage(image, h, w);
  } else if(mode == 2) {
    imageToGrayScaleLightness(image, h, w);
  } else if(mode == 3) {
    imageToGrayScaleLuminosity(image, h, w);
  } else if(mode == 4) {
    imageToSepia(image, h, w);
  } else {
    fprintf(stderr, "Invalid mode\n");
  }
  saveImage(outputFile, image, h, w);

  return 0;
}
