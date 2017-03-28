//
// Created by dec on 25/10/16.
//

#include <stdlib.h>
#include <iostream>
#include "../include/BSPGenerator.h"
#include "../include/Part.h"

BSPGenerator::BSPGenerator(int minRoom, int maxRoom) : minRoomSize(minRoom), maxRoomSize(maxRoom)
{

}

void BSPGenerator::generate(Map &map)
{

    //TODO Replace with actual tree data structure
    std::vector <Part> parts;
    parts.push_back(Part(0, 0, map.getWidth(), map.getHeight()));

    std::cout << "Maps address in generator: " << &map << std::endl;


    //TODO Use recursive function
    for (int i = 0; i < 4; i++) {
        for (int z = parts.size() - 1; z >= 0; z--)
        {
            binaryPart(parts, z);
            std::cout << "Size of parts: " << parts.size() << std::endl;
        }
    }
    // Passing reference again? Possibly not good?
    digRooms(map, parts);

}

void BSPGenerator::binaryPart(std::vector <Part> &pVec, int i)
{

    //TODO Replace rand()

    int randomInt = rand();

    int splitDir = randomInt %2;

    if (splitDir)
    {

        int variance = (rand() % int((pVec.at(i).getWidth() * .4)));
        variance -= pVec.at(i).getWidth() * .2;

        std::cout << "Variance HP: " << variance << std::endl;

        int splitPos = int(pVec.at(i).getWidth()*.5);
        std::cout << "Split pos X : " << splitPos << std::endl;

        splitPos += pVec.at(i).getTopLeftX() + variance;
        std::cout << "Split pos X : " << splitPos << std::endl;

        if ((splitPos - pVec.at(i).getTopLeftX()) < minRoomSize + 2 || (pVec.at(i).getWidth() + pVec.at(i).getTopLeftX()) - splitPos < minRoomSize ) return;

        // FIX THIS MESS
        // What if uneven
        Part a(pVec.at(i).getTopLeftX(), pVec.at(i).getTopLeftY(), splitPos - pVec.at(i).getTopLeftX(), pVec.at(i).getHeight());
        Part b(splitPos, pVec.at(i).getTopLeftY(), pVec.at(i).getWidth() - (splitPos - pVec.at(i).getTopLeftX()), pVec.at(i).getHeight());

        //Part a(pVec.at(i).getX1(), pVec.at(i).getY1,
        //


        // Fix ordering
        pVec.erase(pVec.begin() + i);
        pVec.push_back(a);
        pVec.push_back(b);


    } else {
        std::cout << "Vertical Partition" << std::endl;

        std::cout << "Height     : :" << pVec.at(i).getHeight() << std::endl;
        int variance = (rand() % int((pVec.at(i).getHeight() * .4)));
        variance -= pVec.at(i).getHeight() * .2;
        std::cout << "Varience VP: " << variance << std::endl;


        int splitPos = int(pVec.at(i).getHeight()*.5);
        std::cout << "Split pos Y : " << splitPos << std::endl;

        splitPos += pVec.at(i).getTopLeftY() + variance;
        std::cout << "Split pos Y : " << splitPos << std::endl;

        if ((splitPos - pVec.at(i).getTopLeftY()) < minRoomSize + 2 || (pVec.at(i).getHeight() + pVec.at(i).getTopLeftY()) - splitPos < minRoomSize) return; // Fix this mess

        Part a(pVec.at(i).getTopLeftX(), pVec.at(i).getTopLeftY(), pVec.at(i).getWidth(), splitPos - pVec.at(i).getTopLeftY());
        Part b(pVec.at(i).getTopLeftX(), splitPos, pVec.at(i).getWidth(), pVec.at(i).getHeight() - (splitPos - pVec.at(i).getTopLeftY()));

        pVec.erase(pVec.begin() + i);
        pVec.push_back(a);
        pVec.push_back(b);
    }
}

void BSPGenerator::digRooms(Map &map, std::vector<Part> &vPec)
{
    // Fix vector of parts naming

    // Is there a more efficient way to make these calls
    for(int i = 0; i < vPec.size(); i++)
    {

        map.markPart(vPec.at(i).getTopLeftX(), vPec.at(i).getTopLeftY(), vPec.at(i).getWidth(), vPec.at(i).getHeight());

        int x1{1}, x2{1}, y1{1}, y2{1};
        int xDif, yDif;

        xDif = int((vPec.at(i).getWidth() - minRoomSize) *.5);
        yDif = int((vPec.at(i).getHeight() - minRoomSize) *.5); // Are odd numbers a problem yet

        std::cout << "Width: " << vPec.at(i).getWidth() << std::endl;
        std::cout << "Height: " << vPec.at(i).getHeight() << std::endl;
        std::cout << "xDif: " << xDif << std::endl;
        std::cout << "yDif: " << yDif << std::endl;
        std::cout << "Min Room: " << minRoomSize << std::endl;
        if (xDif != 0)
        {
            x1 = rand() % xDif;
            x2 = rand() % xDif;
        }
        if (yDif != 0)
        {
            y1 = rand() % yDif;
            y2 = rand() % yDif;
        }

        //TODO Fix random adding and subtracting
        map.dig(vPec.at(i).getTopLeftX() + x1+1, vPec.at(i).getTopLeftY() + y1+1, vPec.at(i).getWidth() - (x1 +x2)-2, vPec.at(i).getHeight() - (y1 + y2)-2);

        if (i != 0)
        {
            map.digCorridor(lastRoomX, lastRoomY, vPec.at(i).getTopLeftX() + vPec.at(i).getWidth() * .5, vPec.at(i).getTopLeftY() + vPec.at(i).getHeight() * .5 );
        }

        lastRoomX = int(vPec.at(i).getTopLeftX() + vPec.at(i).getWidth() * .5);
        lastRoomY = int(vPec.at(i).getTopLeftY() + vPec.at(i).getHeight() * .5);

    }
}
