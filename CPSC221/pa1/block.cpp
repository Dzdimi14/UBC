#include "block.h"
#include <vector>
#include <iostream>
using namespace cs221util;
using namespace std;

/* Returns the width of the current block */
int Block::width() const {
    
        return data.size();

}

/* Returns the height of the current block */
int Block::height() const {

         return data[0].size();

}

/**
* From im, grabs the vertical strip of pixels whose upper left corner
* is at position (column,0), and whose width is width.
**/

void Block:: build(PNG& im, int column, int width){

    for (unsigned int i = column; i < ((unsigned int)column + width); i++) {

        //std::vector<cs221util::HSLAPixel> p;
        vector<HSLAPixel> p;
        //p = data[i];
        for (unsigned k = 0; k < im.height(); k++) {
            HSLAPixel* pixel = im.getPixel(i,k);
            p.push_back(*pixel);
        }

        data.push_back(p);
    }
}

/* Draws the current block at position (column,0) in im */
void Block::render(PNG & im, int column) const {

    for (unsigned i = 0; i < width(); i++){
        for (unsigned j = 0; j < im.height(); j++) {
            HSLAPixel* p = im.getPixel(i + column, j);
            *p = data[i][j];
        }
    }

}

/**
* This function changes the saturation of every pixel
* in the block to 0, which removes the color, leaving grey.
**/
void Block::greyscale() {
  for (unsigned i = 0; i < width(); i++) {
      for (unsigned int k = 0; k < height(); k++) {
          data[i][k].s = 0;
      }
  }
}

/**
* Returns the avg saturation value of a pixel in the block
* (eg: 0 for a greyscale image)
**/
double Block::avgSaturation() const{

  double total = 0;
  double size = 0;
  for(unsigned i = 0; i < width(); i++) {
      for (unsigned k = 0; k < height(); k++){
          total += data[i][k].s;
          size++;
      }

  }

  return total/size;

  return 0;
}
