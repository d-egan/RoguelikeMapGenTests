//
// Created by dec on 20/10/16.
//
#include "include/Tile.h"
#include <vector>
#include <stdlib.h>
#include <iostream>
#include "libtcod.hpp"
#include "include/Map.h"



Map::Map(int width, int height) : width(width), height(height){

    tiles.assign(width*height, Tile());
}

void Map::render() {
    static const TCODColor darkWall(0, 0, 100);
    static const TCODColor darkGround(50, 50, 150);
    static const TCODColor realRed(250, 0, 35);

    for (int x=0; x < width; x++) {
        for (int y=0; y < height; y++) {
            TCODConsole::root->setCharBackground( x, y,
                isDebug(x,y) ? realRed : isWall(x,y) ? darkWall : darkGround) ;
        }
    }
}

bool Map::isWall(int x, int y) {
    return !tiles[x+(y*width)].getWalkable();
}

void Map::setWall(int x, int y) {
    tiles[x+(y*width)].setWall();
}

bool Map::isDebug(int x, int y) {
    return tiles[x+(y*width)].isDebug();
}

int Map::getWidth() {
    return width;
}

int Map::getHeight() {
    return height;
}

void Map::dig(int x1, int y1, int w, int h) {
    // remove calculations
    int widthEnd = x1 + w;
    int heightEnd = y1 + h;
    for (int x=x1; x < widthEnd; x++) {
        for (int y=y1; y < heightEnd; y++) {
            //std::cout << "Digging from: " << x+(y*width) << std::endl;
            tiles[x+(y*width)].setWalk();
        }
    }
}

void Map::markPart(int x1, int y1, int w, int h) {
    int widthEnd = x1 + w;
    int heightEnd = y1 + h;

    for (int x=x1; x < widthEnd; x++) {
        for (int y=y1; y < heightEnd; y++) {
            if ((y == y1 || y == heightEnd-1) || ((x==x1) || (x==widthEnd-1))) {
                tiles[x + (y * width)].setDebug();
            }
        }
    }

}