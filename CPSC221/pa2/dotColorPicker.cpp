#include "dotColorPicker.h"


dotColorPicker::dotColorPicker(HSLAPixel fillColor, int dotGrid,int dotSize)
{
    color = fillColor;
    spacing = dotGrid;
    size = dotSize;
}

HSLAPixel dotColorPicker::operator()(int x, int y)
{

/* Your code here */
/**
 * Picks the color for pixel (x, y).
* If the distance from point (x,y) to a grid point is less than
* dotSize, then return fillColor,
 * otherwise, it return white.
*
* Grid points are the points where x == y == 0 mod dotGrid.
* Distances between pixel locations are calculated using a
* Euclidian metric, but because we don't like computing square
* roots, we compare squared distances. Based on these
* observations you should be able to devise a fairly simple
* computation to use to determine if an (x,y) point is within
* a dot. Note that if dotSize is a little more than dotGrid, the
* entire fill region will be colored with the dot color.
 *
 * @param x The x coordinate to pick a color for.
 * @param y The y coordinat to pick a color for.
 * @return The color chosen for (x, y).
 */
/* The following code just returns a white pixel. */

    // dist from xy to dot center


    int xm = x % spacing;
    int ym = y % spacing;

    if (xm < spacing/2 || ym < spacing/2){
        xm = spacing - xm;
        ym = spacing - ym;
    }
    int dist2 = (xm * xm) + (ym * ym);
    if (dist2 < (size * size)) {
        return color;
    } else {
        HSLAPixel ret;
        ret.h = 0.; ret.s = 0.; ret.l = 1.;
        return ret;
    }







}
