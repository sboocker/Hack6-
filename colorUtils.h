//Created by Sam Boocker and Amur al harthi for Hack 6, CSCE 155E

#include <stdio.h>
#include <stdlib.h>

/*
 * This converts an RGB color model to CMYK.
 */
int rgbToCMYK(int r, int g, int b, double *c, double *m, double *y, double *k);

/*
 * This converts a CMYK to an RGB color model.
 */
int cmykToRGB(double c, double m, double y, double k, int *r, int *g, int *b);

/*
 * This converts an RGB color model to grayscale.
 */
int toGrayScale(int *r, int *g, int *b, Mode m);

typedef enum {
  AVERAGE = 0,
  LIGHTNESS,
  LUMINOSITY,
} Mode;

typedef enum {
  NO_ERROR = 0,
  ERROR,
} Error;
