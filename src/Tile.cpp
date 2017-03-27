//
// Created by dec on 20/10/16.
//

#include "../include/Tile.h"

Tile::Tile(SpriteType sprite) : m_sprite(sprite), walkable{false}, debug{false}
{

}

bool Tile::getWalkable() { return walkable; }
bool Tile::isDebug() { return debug; }

void Tile::setWall(SpriteType sprite)
{
    walkable = false;
    m_sprite = sprite;
}

void Tile::setWalk(SpriteType sprite)
{
    walkable = true;
    m_sprite = sprite;
}
void Tile::setDebug(SpriteType sprite)
{
    debug = true;
    m_sprite = sprite;
}

