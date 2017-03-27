//
// Created by dec on 05/01/17.
//

#ifndef MAPGEN_DIGGER_H
#define MAPGEN_DIGGER_H


class Walker {
private:
    int posX, posY;
    int minX, maxX, minY, maxY;

public:
    Walker();
    void step();

};


#endif //MAPGEN_DIGGER_H
