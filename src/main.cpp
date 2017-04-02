#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/Map.h"
#include "../include/Part.h"
#include "../include/BSPGenerator.h"

int main()
{
    srand(time(NULL));
    std::cout << "Hello, World!" << std::endl;

    sf::RenderWindow rw{sf::VideoMode(800, 640, 32), "Map Gen Tests"};
    //rw.setSize(sf::Vector2<unsigned int>(512,1000));
    rw.setFramerateLimit(60);

    Map bspMap(100, 80);

    std::cout << "Maps address: " << &bspMap << std::endl;
    BSPGenerator bsp(6, 20);
    bsp.generate(bspMap);



    while ( rw.isOpen() )
    {
        sf::Event e;
        while(rw.pollEvent(e))
        {
            if (e.type == sf::Event::EventType::Closed)
                rw.close();

            if (e.type == sf::Event::KeyReleased)
            {
                if (e.key.code == sf::Keyboard::R)
                {
                    bspMap.mapClear();
                    bsp.generate(bspMap);
                }
            }
        }

        rw.clear();
        bspMap.render(rw);
        rw.display();

    }


    return 0;

}