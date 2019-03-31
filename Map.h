//
// Created by apple on 2019-02-23.
//

#ifndef BATTLESHIP_MAP_H
#define BATTLESHIP_MAP_H

class Map {
public:
    char playerGrid[10][10] = {};//Grid Map
    char cpuGrid[10][10] = {};

    void resetGrid();
    void printGrid();
    void printCPUGrid();

    void randomize();

    void placeShip(char ships, int size, char (&grid)[10][10]);

    bool hitShip(int x, int y,char (&myGrid)[10][10], char (&oppoGrid)[10][10]);
    bool checkWin(char (&grid)[10][10]);
    bool isBlockCleared(int x, int y, char (&grid)[10][10]);

private:
    bool checkVerticalClearence(int x, int y, int size);
    bool checkHoriClearence(int x, int y, int size);
    bool isShipHit(int x, int y, char(&grid)[10][10]);
    bool isBlockBlank(int x, int y, char(&grid)[10][10]);

};

#endif //BATTLESHIP_MAP_H