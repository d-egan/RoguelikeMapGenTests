//
// Created by dec on 25/10/16.
//

#include <iostream>
#include "Part.h"
// Switch order to xpos, ypox, width, height
Part::Part(int x, int y, int w, int h) : topLeftX(x), topLeftY(y), width(w), height(h) { }

int Part::getWidth() { return width;}

int Part::getHeight() { return height; }

int Part::getTopLeftX() { return topLeftX; }

int Part::getTopLeftY() { return topLeftY; }