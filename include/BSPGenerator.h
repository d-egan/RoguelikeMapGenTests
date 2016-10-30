//
// Created by dec on 25/10/16.
//

#ifndef MAPGEN_BSPGENERATOR_H
#define MAPGEN_BSPGENERATOR_H


#include "Map.h"
#include "Part.h"

class BSPGenerator {
private:
    const int minRoomSize, maxRoomSize;
    void binaryPart(std::vector<Part> &pVec, int i);

    int lastRoomX, lastRoomY;

public:
    BSPGenerator(int minRoom, int maxRoom);
    void generate(Map &map);
    void digRooms(Map &map, std::vector<Part> &vPec);
    void digOneRoom();
    void digCorridor();
};


#endif //MAPGEN_BSPGENERATOR_H
