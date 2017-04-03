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
#include <SFML/Graphics/RenderTexture.hpp>

class Map
{
    std::vector <Tile> tiles;
    int width, height;
    sf::Texture texture;

    std::vector<sf::Sprite> tileSheet;
    sf::RenderTexture mapTexture;
    sf::Sprite mapSprite; // sf::sprites actually hold a reference to the texture

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

    void createMapDrawable();
    void mapClear();
};


#endif //MAPGEN_MAP_H
