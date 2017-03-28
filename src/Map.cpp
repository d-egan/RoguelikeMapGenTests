//
// Created by dec on 20/10/16.
//
#include "../include/Tile.h"
#include <vector>
#include <iostream>
#include "../include/Map.h"

Map::Map(int width, int height) : width(width), height(height)
{
    if(!texture.loadFromFile("assets/minirogue-all.png"))
    {

    }

    for(int y=0; y<13; y++)
    {
        for(int x=0; x<16; x++)
        {
            tileSheet.push_back(sf::Sprite(texture));
            tileSheet.back().setTextureRect(sf::IntRect(x*8,y*8,8,8));
        }
    }

    tiles.assign(width*height, Tile(SpriteType::WALL));
}

void Map::render(sf::RenderWindow & rw)
{
    for (int y=0; y < height; y++)
    {
        for (int x=0; x < width; x++)
        {
            //tiles[x+(y*width)].m_sprite->setPosition(x*8,y*8);
            int ind = static_cast<int>(tiles[x+(y*width)].m_sprite);
            tileSheet[ind].setPosition(x*8,y*8);

            rw.draw(tileSheet[ind]);
        }
    }
}

bool Map::isWall(int x, int y)
{
    return !tiles[x+(y*width)].getWalkable();
}

void Map::setWall(int x, int y)
{
    tiles[x+(y*width)].setWall(SpriteType::WALL);

}

bool Map::isDebug(int x, int y)
{
    return tiles[x+(y*width)].isDebug();
}

int Map::getWidth()
{
    return width;
}

int Map::getHeight()
{
    return height;
}

void Map::dig(int x1, int y1, int w, int h)
{
    // remove calculations
    int widthEnd = x1 + w;
    int heightEnd = y1 + h;
    for (int x=x1; x < widthEnd; x++) {
        for (int y=y1; y < heightEnd; y++) {
            //std::cout << "Digging from: " << x+(y*width) << std::endl;
            tiles[x+(y*width)].setWalk(SpriteType::FLOOR);
        }
    }
}

void Map::markPart(int x1, int y1, int w, int h)
{
    int widthEnd = x1 + w;
    int heightEnd = y1 + h;

    for (int x=x1; x < widthEnd; x++) {
        for (int y=y1; y < heightEnd; y++) {
            if ((y == y1 || y == heightEnd-1) || ((x==x1) || (x==widthEnd-1))) {
                tiles[x + (y * width)].setDebug(SpriteType::DEBUG);
            }
        }
    }
}

void Map::digCorridor(int x1, int y1, int x2, int y2)
{

}

void Map::mapClear()
{
    tiles.assign(width*height, Tile(SpriteType::WALL));
}