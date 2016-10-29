//
// Created by dec on 25/10/16.
//

#ifndef MAPGEN_PARTITION_H
#define MAPGEN_PARTITION_H


class Part {
private:
    int width, height;
    int topLeftX, topLeftY;

public:
    Part(int x, int y, int w, int h);

    int getWidth();
    int getHeight();
    int getTopLeftX();
    int getTopLeftY();

};


#endif //MAPGEN_PARTITION_H
