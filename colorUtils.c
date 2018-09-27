#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "colorUtils.h"

int rgbToCMYK(int r, int g, int b, double *c, double *m, double *y, double *k) {
  if(r > 255 || r < 0) {
    return ERROR;
  }
  else if(g > 255 || g < 0) {
    return ERROR;
  }
  else if(b > 255 || b < 0) {
    return ERROR;
  }
  else {

  double red = (r / 255.0);
  double green = (g / 255.0);
  double blue = (b / 255.0);
  double max;

  if(red >= green && red >= blue) {
      max = red;
    }
  else if (green >= red && green >= blue){
      max = green;
    }
  else if(blue >= red && blue >= green) {
    max = blue;
  }

  if(k == NULL || c == NULL || m == NULL || y == NULL) {
    return ERROR;
  }

  *k = (1 - max);
  *c = ((1.0 - red - *k) / (1.0 - *k));
  *m = ((1 - green - *k) / (1 - *k));
  *y = ((1 - blue - *k) / (1 - *k));

return NO_ERROR;
}}

int cmykToRGB(double c, double m, double y, double k, int *r, int *g, int *b) {
  if(k == 1) {
    return ERROR;
  }
  else if(r == NULL || g == NULL || b == NULL) {
    return ERROR;
  }
  else {

  *r = ((1 - c) * (1 - k));
  *g = ((1 - m) * (1 - k));
  *b = ((1 - y) * (1 - k));

return NO_ERROR;
}}

int toGrayScale(int *r, int *g, int *b, Mode m) {

  double max, min;

  if(r == NULL || g == NULL || b == NULL) {
    return ERROR;
  }

  else if (m == LUMINOSITY) {
    *r = round((*r + *g + *b) / 3.0);
    *b = round((*r + *g + *b) / 3.0);
    *g = round((*r + *g + *b) / 3.0);

    return NO_ERROR;
  }

  else if(m == LIGHTNESS) {
    if(*r >= *g && *r >= *b) {
      max = *r;
    }
    else if(*g >= *r && *g >= *b){
      max = *g;
    }
    else if(*b >= *r && *b >= *g) {
      max = *b;
    }
    else if(*r <= *g && *r <= *b) {
      min = *r;
    }
    else if(*g <= *r && *g <= *b){
      min = *g;
    }
    else if(*b <= *r && *b <= *g) {
      min = *b;
    }

  *r = round((max + min) / 2.0);
  *g = round((max + min) / 2.0);
  *b = round((max + min) / 2.0);

  return NO_ERROR;
  }

  else if(m == LUMINOSITY) {
  *r = round((.21 * *r) + (.72 * *g) + (.07 * *b));
  *g = round((.21 * *r) + (.72 * *g) + (.07 * *b));
  *b = round((.21 * *r) + (.72 * *g) + (.07 * *b));

  return NO_ERROR;
  }

return NO_ERROR;
}
