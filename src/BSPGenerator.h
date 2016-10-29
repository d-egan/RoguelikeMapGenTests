//
// Created by dec on 25/10/16.
//

#ifndef MAPGEN_BSPGENERATOR_H
#define MAPGEN_BSPGENERATOR_H


#include "../include/Map.h"
#include "Part.h"

class BSPGenerator {
private:
    const int minRoomSize, maxRoomSize;
    void binaryPart(std::vector<Part> &pVec, int i);

public:
    BSPGenerator(int minRoom, int maxRoom);
    void generate(Map &map); // Fix spelling
    void digRooms(Map &map, std::vector<Part> &vPec);
    void digOneRoom();
};


#endif //MAPGEN_BSPGENERATOR_H
