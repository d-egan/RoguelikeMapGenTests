//
// Created by dec on 20/10/16.
//

#include "../include/Tile.h"

Tile::Tile() {
    walkable = false;
    debug = false;
}

bool Tile::getWalkable() { return walkable; }
bool Tile::isDebug() { return debug; }

void Tile::setWall() { walkable = false; }

void Tile::setWalk() { walkable = true; }
void Tile::setDebug() { debug = true; }

