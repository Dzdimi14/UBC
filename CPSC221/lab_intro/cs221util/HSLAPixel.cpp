#include "HSLAPixel.h"


    double h, s, l, a;

    HSLAPixel :: HSLAPixel() {
        h = 1;
        s = 0;
        l = 1.0;
        a = 1;
    }

     HSLAPixel :: HSLAPixel(double hue, double saturation, double luminance) {
        h = hue;
        s = saturation;
        l = luminance;
    }

     HSLAPixel :: HSLAPixel(double hue, double saturation, double luminance, double alpha) {
        h = hue;
        s = saturation;
        l = luminance;
        a = alpha;
    }
