#pragma once

#include <string>/
/*
Level;
GameFild;
fourDeckShip;
threeDeckShip; 
doubleDeckShip; 
singleDeckShip; 
*/

/* rows, columns, cellWidth, cellHeight; - GameField data */
/* typeShip(4, 3, 2, 1), initRowShip, initColumnShip, Direction(Horizontal-0, vertical-1); - Ship */

/*(Ship length typeShip) + (initRowShip, initCoumnShip)  * - ship creating/

// Level Example
/*
1;
12, 12, 25, 25;
4, 5, 5, 0;
3, 1, 2, 1;
2, 7, 1, 0;
1, 12, 12, 0
*/

class LevelLoader {
public:
    static void loadLevel(std::string str);
};
