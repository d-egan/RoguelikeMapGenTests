#include <iostream>
#include <stdlib.h>
#include "libtcod.hpp"
#include "../include/Map.h"
#include "../include/Part.h"
#include "../include/BSPGenerator.h"

int main() {
    srand(time(NULL));
    std::cout << "Hello, World!" << std::endl;
    TCODConsole::initRoot(100, 80, "Map Gen Test", false, TCOD_RENDERER_GLSL);
    Map bspMap(100, 80);

    std::cout << "Maps address: " << &bspMap << std::endl;
    BSPGenerator bsp(6, 20);
    bsp.generate(bspMap);


    while ( !TCODConsole::isWindowClosed() ) {
        TCOD_key_t key;
        TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS, &key, NULL);
        switch (key.vk) {
            case TCODK_UP : std::cout << "Nice" << std::endl; break;
        }
        bspMap.render();
        TCODConsole::flush();
    }
    return 0;

}