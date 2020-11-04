/**
 * @file filler.cpp
 * Implementation of functions in the filler namespace.
 *
 */
//#include "filler.h"

animation filler::fillDotDFS(PNG& img, int x, int y, HSLAPixel fillColor,
                                int dotGrid,int dotSize, double tolerance, int frameFreq)
{
    /**
     * @todo Your code here!
     */
     dotColorPicker a(fillColor, dotGrid, dotSize);
     return fill<Stack>(img, x, y, a, dotGrid, dotSize);

}

animation filler::fillBorderDFS(PNG& img, int x, int y,
                                    HSLAPixel borderColor, double tolerance, int frameFreq)
{
    /**
     * @todo Your code here!
     */
     borderColorPicker a(borderColor, img, tolerance, borderColor);
     return fill<Stack>(img, x, y, a, tolerance, frameFreq);

}

animation filler::fillRainDFS(PNG& img, int x, int y,
                                    long double freq, double tolerance, int frameFreq)
{

/* example, implemented for you! */
    rainbowColorPicker a(freq);
    return fill<Stack>(img, x, y, a, tolerance, frameFreq);
}

animation filler::fillDotBFS(PNG& img, int x, int y, HSLAPixel fillColor,
                                int dotGrid,int dotSize, double tolerance, int frameFreq)
{
    /**
     * @todo Your code here!
     */
     dotColorPicker a(fillColor, dotGrid, dotSize);
     return fill<Queue>(img, x, y, a, dotGrid, dotSize);

}

animation filler::fillBorderBFS(PNG& img, int x, int y,
                                    HSLAPixel borderColor, double tolerance, int frameFreq)
{
    /**
     * @todo Your code here!
     */
     borderColorPicker a(borderColor, img, tolerance, borderColor);
     return fill<Queue>(img, x, y, a, tolerance, frameFreq);

}

animation filler::fillRainBFS(PNG& img, int x, int y,
                                    long double freq, double tolerance, int frameFreq)
{
/* example, completed for you! */
    rainbowColorPicker a(freq);
    return fill<Queue>(img, x, y, a, tolerance, frameFreq);
}


animation filler::fillCustomDFS(PNG& img, int x, int y, HSLAPixel gridColor, int gridSpacing,
                                            double tolerance, int frameFreq) {
        customColorPicker a(gridColor, gridSpacing);
        return fill<Stack>(img, x, y, a, tolerance, frameFreq);
}
animation filler::fillCustomBFS(PNG& img, int x, int y, HSLAPixel gridColor, int gridSpacing,
                                            double tolerance, int frameFreq) {
        customColorPicker a(gridColor, gridSpacing);
        return fill<Queue>(img, x, y, a, tolerance, frameFreq);
}


Point::Point(int width, int height, bool p){
	x = width;
	y = height;
	processed = p;
}

template <template <class T> class OrderingStructure>
animation filler::fill(PNG& img, int x, int y, colorPicker& fillColor,
                       double tolerance, int frameFreq)
{
    /**
     * @todo You need to implement this function!
     *
     * This is the basic description of a flood-fill algorithm: Every fill
     * algorithm requires an ordering structure, which is passed to this
     * function via its template parameter. For a breadth-first-search
     * fill, that structure is a Queue, for a depth-first-search, that
     * structure is a Stack. To begin the algorithm, you simply place the
     * given point in the ordering structure(OS), marking it processed
     * (the way you mark it is a design decision you'll make yourself).
     * We have a choice to either change the color, if appropriate, when we
     * add the point to the OS, or when we take it off. In our test cases,
     * we have assumed that you will change the color when a point is added
     * to the structure.
     * Until the structure is empty, you do the following:
     *
     * 1.     Remove a point from the ordering structure, and then...
     *
     *        1.    add its unprocessed neighbors whose color values are
     *              within (or equal to) tolerance distance from the center,
     *              to the ordering structure.
     *        2.    use the colorPicker to set the new color of the point.
     *        3.    mark the point as processed.
     *        4.    if it is an appropriate frame, send the current PNG to the
     *              animation (as described below).
    *
     * 2.     When implementing your breadth-first-search and
     *        depth-first-search fills, you will need to explore neighboring
     *        pixels in some order.
     *
     *        For this assignment, each pixel p has 4 neighbors, consisting of
     *        the 4 pixels who share an edge p. (We leave it to
     *        you to describe those 4 pixel locations, relative to the location
     *        of p.)
     *
     *        While the order in which you examine neighbors does not matter
     *        for a proper fill, you must use the same order as we do for
     *        your animations to come out like ours!
     *
     *        The order you should put
     *        neighboring pixels **ONTO** the queue or stack is as follows:
     *        ** UP(-y), LEFT(-x), DOWN(+y), RIGHT(+x)**
     *
     *        If you do them in a different order, your fill may
     *        still work correctly, but your animations will be different
     *        from the grading scripts!
     *
     *        IMPORTANT NOTE: *UP*
     *        here means towards the top of the image, so since an image has
     *        smaller y coordinates at the top, this is in the *negative y*
     *        direction. Similarly, *DOWN* means in the *positive y*
     *        direction.
     *
     * 3.     For every k pixels filled, **starting at the kth pixel**, you
     *        must add a frame to the animation, where k = frameFreq.
     *
     *        For example, if frameFreq is 4, then after the 4th pixel has
     *        been filled you should add a frame to the animation, then again
     *        after the 8th pixel, etc.  You must only add frames for the
     *        number of pixels that have been filled, not the number that
     *        have been checked. So if frameFreq is set to 1, a pixel should
     *        be filled every frame.
     * 4.     Finally, as you leave the function, send one last frame to the
     *        animation. This frame will be the final result of the fill, and
     *        it will be the one we test against.
     */

    /* your code here */
    OrderingStructure<Point> myOS;

    /* declare and initialize imgBlock */
    vector< vector<Point>> imgBlock;
    for (int i = (int)img.height(); i < (int)(img.height() + img.width()); i++) {
        vector<Point> row;
        for (unsigned long j = 0; j < ((&img)->height()); j++) {
            Point temp(i, j, false);
            Point *p = & temp;
            row.push_back(*p);
            }
            imgBlock.push_back(row);
        }

Point start(x, y, false);

int acc = 0;
animation animage;
animage.addFrame(img);

HSLAPixel * pixel = img.getPixel(start.x, start.y);
HSLAPixel startPixel = *pixel;
*pixel = fillColor(start.x, start.y);

/* colour starting point */
// if ( (x <= (int)img.width() && x >=0 ) && (y <= (int)img.height() && y >= 0)
        // && !start.processed){
start.processed = true;
myOS.add(start);

imgBlock[start.x][start.y] = start;

acc = acc + 1;
if (acc >= frameFreq){
    animage.addFrame(img);
    acc = acc - frameFreq;
}


while (!myOS.isEmpty()){
    //cout << "start of loop" << endl;
    Point top = myOS.remove();
    //if (!top.processed){
        //top.processed = true;
        //imgBlock[top.x][top.y] = top;
    //}

        /* add right */
        //cout << top.x << endl;
        //cout << top.y << endl;
        if ( (top.x + 1 <= (int) img.width()) && (top.y <= (int) img.height()) ){
            Point * currentRight = & (imgBlock[top.x+1][top.y]);
            //cout << (*currentRight).processed << endl;

            if (!(*currentRight).processed
                && (startPixel.dist(*img.getPixel(top.x+1, top.y))) <= tolerance) {
                //cout << "unprocessed right pixel in tolerance!" << endl;

                (*currentRight).processed = true;
                (*currentRight).x = top.x +1;
                (*currentRight).y = top.y;
                myOS.add(*currentRight);

                HSLAPixel* rightP = img.getPixel(top.x+1, top.y);
                *rightP = fillColor(top.x+1, top.y);

                imgBlock[top.x+1][top.y] = *currentRight;
                //cout << "imgBlock added next right!" << endl;


                acc = acc + 1;
                if (acc >= frameFreq){
                    //cout << "frame frequency reached" << endl;
                    animage.addFrame(img);
                    //cout << "frame added!" << endl;
                    acc = 0;
                }
            }
        }

        /* add down */
        if ( (top.x <= (int) img.width()) && (top.y + 1 <= (int) img.height()) ){
            Point * currentDown = & (imgBlock[top.x][top.y+1]);

            if (!(*currentDown).processed
                && (startPixel.dist(*img.getPixel(top.x, top.y+1))) <= tolerance) {
                //	cout << "unprocessed down pixel in tolerance!" << endl;

                (*currentDown).processed = true;
                (*currentDown).x = top.x;
                (*currentDown).y = top.y+1;
                myOS.add(*currentDown);

                HSLAPixel* downP = img.getPixel(top.x, top.y+1);
                *downP = fillColor(top.x, top.y+1);

                imgBlock[top.x][top.y+1] = *currentDown;

                acc = acc + 1;
                if (acc >= frameFreq){
                    //cout << "frame frequency reached" << endl;
                    animage.addFrame(img);
                    acc = 0;
                }
            }
        }

        /* add left */
        if ( (top.x - 1 <= (int) img.width()) && (top.y <= (int) img.height()) ){
            Point * currentLeft = & (imgBlock[top.x-1][top.y]);

            if (!(*currentLeft).processed
                && (startPixel.dist(*img.getPixel(top.x-1, top.y))) <= tolerance) {
                //	cout << "unprocessed left pixel in tolerance!" << endl;

                (*currentLeft).processed = true;
                (*currentLeft).x = top.x -1;
                (*currentLeft).y = top.y;
                myOS.add(*currentLeft);

                HSLAPixel* leftP = img.getPixel(top.x-1, top.y);
                *leftP = fillColor(top.x-1, top.y);

                imgBlock[top.x-1][top.y] = *currentLeft;

                acc = acc + 1;
                if (acc >= frameFreq){
                    //cout << "frame frequency reached" << endl;
                    animage.addFrame(img);
                    acc = 0;
                }
            }
        }

        /* add up */
        if ( (top.x <= (int) img.width()) && (top.y - 1 <= (int) img.height()) ){
            Point * currentUp = & (imgBlock[top.x][top.y-1]);

            if (!(*currentUp).processed
                && (startPixel.dist(*img.getPixel(top.x, top.y-1))) <= tolerance) {
                //	cout << "unprocessed up pixel in tolerance!" << endl;

                (*currentUp).processed = true;
                (*currentUp).x = top.x;
                (*currentUp).y = top.y-1;
                myOS.add(*currentUp);

                HSLAPixel* upP = img.getPixel(top.x, top.y-1);
                *upP = fillColor(top.x, top.y-1);

                imgBlock[top.x][top.y-1] = *currentUp;

                acc = acc + 1;
                if (acc >= frameFreq){
                    //cout << "frame frequency reached" << endl;
                    animage.addFrame(img);
                    acc = 0;
                }
            }
        }
    //}
}
animage.addFrame(img);
return animage;

}
