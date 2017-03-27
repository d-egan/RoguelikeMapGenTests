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

    Map bspMap(100, 80);

    std::cout << "Maps address: " << &bspMap << std::endl;
    BSPGenerator bsp(6, 20);
    bsp.generate(bspMap);

    sf::Event e;

    while ( rw.isOpen() )
    {
        while(rw.pollEvent(e))
        {
            if (e.type == sf::Event::EventType::Closed)
                rw.close();

            if (e.type == sf::Event::KeyReleased)
            {
                if (e.key.code == sf::Keyboard::R)
                {
                    bsp.generate(bspMap);
                    std::cout << "the escape key was pressed" << std::endl;
                    std::cout << "control:" << e.key.control << std::endl;
                    std::cout << "alt:" << e.key.alt << std::endl;
                    std::cout << "shift:" << e.key.shift << std::endl;
                    std::cout << "system:" << e.key.system << std::endl;
                }
            }

            rw.clear();
            bspMap.render(rw);
            rw.display();



        }
    }


    return 0;

}