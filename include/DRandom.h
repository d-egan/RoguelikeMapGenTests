//
// Created by dec on 17/11/16.
//

#ifndef MAPGEN_DRANDOM_H
#define MAPGEN_DRANDOM_H

/*
 * Wrapping a random generator
 * This will allow me test different generators for the whole project
 */

class DRandom {
private:

public:
    int getInt(int range);
    int getInt(int start, int end);
};


#endif //MAPGEN_DRANDOM_H
