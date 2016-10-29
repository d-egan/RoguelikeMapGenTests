//
// Created by dec on 20/10/16.
//

#ifndef MAPGEN_TILE_H
#define MAPGEN_TILE_H


class Tile {
private:
    bool walkable;
    bool debug;
public:

    Tile();
    bool getWalkable();
    void setWall();
    void setWalk();
    void setDebug();
    bool isDebug();
};


#endif //MAPGEN_TILE_H
