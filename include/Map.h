//
// Created by dec on 20/10/16.
//

#ifndef MAPGEN_MAP_H
#define MAPGEN_MAP_H

#include <vector>
#include "Tile.h"

class Map {
    std::vector <Tile> tiles;
    int width, height;

public:
    Map(int width, int height);

    bool isWall(int x, int y);
    void setWall(int x, int y);

    bool isDebug(int x, int y);
    void render();

    int getWidth();
    int getHeight();

    void dig(int x1, int y1, int w, int h);
    void markPart(int x1, int y1, int w, int h);
    void digCorridor(int x1, int y1, int x2, int y2);
};


#endif //MAPGEN_MAP_H
