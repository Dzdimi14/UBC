#ifndef HSLAPIXEL_H
#define HSLAPIXEL_H

class HSLAPixel {
public:
    double h, s, l, a;
    HSLAPixel();
    HSLAPixel(double h, double s, double l);
    HSLAPixel(double h, double s, double l, double a);
};
#endif
