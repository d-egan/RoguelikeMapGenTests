//
// Created by dec on 20/10/16.
//

#ifndef MAPGEN_TILE_H
#define MAPGEN_TILE_H


#include <SFML/Graphics/Sprite.hpp>
#include <memory>
#include "SpriteType.h"

class Tile
{
private:
    bool walkable;
    bool debug;


public:

    Tile(SpriteType sprite);
    bool getWalkable();
    void setWall(SpriteType sprite);
    void setWalk(SpriteType sprite);
    void setDebug(SpriteType sprite);
    bool isDebug();

    SpriteType m_sprite;
};


#endif //MAPGEN_TILE_H
