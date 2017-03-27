//
// Created by dec on 30/10/16.
//

#ifndef MAPGEN_RWGENERATOR_H
#define MAPGEN_RWGENERATOR_H

#include "Map.h"
#include "Walker.h"

class RWGenerator {
private:
    const int maxWidth;
    const int maxHeight;
    std::vector <Walker> walkers;

    void stepWalkers();
    void buildMap();

public:
    RWGenerator(int width, int height);
    void generate(Map &map);
};


#endif //MAPGEN_RWGENERATOR_H
