#include "borderColorPicker.h"
/**
 * borderColorPicker: a functor that determines the color that should be used
 * given an x and a y coordinate. If the given position is near a border of
 * the fill, then it should be colored with the given color. Otherwise, its color
 * should not change.
 *
 * The following criteria should be used to determine if a position p is near
 * a border: if p is within distance 3 of any cell that will be outside the
 * fill, then the pixel at position p should be colored with the given color.
 *
 * You will use Euclidian distance to judge proximity. That means if p is at
 * location (x,y), its distance to a point at location (a,b) is
 * squareRoot([(x-a)^2 + (y-b)^2]). Note that you should not ever have to
 * compute the square root to solve this problem.
 *
 **/
borderColorPicker::borderColorPicker(HSLAPixel fillColor, PNG & img, double tolerance,HSLAPixel center)
{

/* your code here */
    color = fillColor;
    im = img;
    tol = tolerance;
    ctr = center;

}

HSLAPixel borderColorPicker::operator()(int x, int y)
{
    if ((x <= im.width()) && (y <= im.height())) {




        cout << "x " << x << "  " << "y " << y << endl;
        HSLAPixel* p;
        p = im.getPixel(x, y);
        double cDist = p->dist(ctr);
        cout << "we made it" << endl;
        int bxl = im.width() - 3;
        int byt = im.height() - 3;


        if ((cDist + 3 <= tol || cDist - 3 <= tol)){
                return color;
            }


    }

    //either color dist HSLAPdist is over tol or outside border of image to be border
    //Any pixel that is within 3 euclidean distance of a pixel that is outside the fill
    //area is considered a border pixel.



}
