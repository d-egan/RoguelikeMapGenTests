//
// Created by dec on 20/10/16.
//

#ifndef MAPGEN_MAP_H
#define MAPGEN_MAP_H

#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Tile.h"
#include <array>

class Map
{
    std::vector <Tile> tiles;
    int width, height;
    sf::Texture texture;
    sf::Sprite sprite;
    //std::array<sf::Sprite>
    std::vector<sf::Sprite> tileSheet;

public:
    Map(int width, int height);

    bool isWall(int x, int y);
    void setWall(int x, int y);

    bool isDebug(int x, int y);
    void render(sf::RenderWindow & rw);

    int getWidth();
    int getHeight();

    void dig(int x1, int y1, int w, int h);
    void markPart(int x1, int y1, int w, int h);
    void digCorridor(int x1, int y1, int x2, int y2);
};


#endif //MAPGEN_MAP_H
