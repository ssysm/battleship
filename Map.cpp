//
// Created by apple on 2019-02-23.
//
#include "Map.h"
#include <iostream>

/**
 * Reset Map Grid
 */
void Map::resetGrid() {
    for(int x =0; x < 10; x++){
        for(int y=0; y < 10; y++){
            Map::cpuGrid[x][y] = '_';
            Map::playerGrid[x][y] = '_';
        }
    }
}

/**
 * Print out Player grid
 */
void Map::printGrid() {
    std::cout << "  ";
    for(int a = 65; a <= 74; a++){
        std::cout << char(a) << "|";
    }
    std::cout << std::endl;
    for(int x =0; x < 10; x++){
        std::cout << x << "|";
        for(int y=0; y < 10; y++){
            std::cout << Map::playerGrid[x][y] << "|";
        }
        std::cout << std::endl;
    }
}

/**
 * Print out CPU grid
 * @debug
 */
void Map::printCPUGrid() {
    std::cout << "  ";
    for(int a = 65; a <= 74; a++){
        std::cout << char(a) << "|";
    }
    std::cout << std::endl;
    for(int x =0; x < 10; x++){
        std::cout << x << "|";
        for(int y=0; y < 10; y++){
            std::cout << Map::cpuGrid[x][y] << "|";
        }
        std::cout << std::endl;
    }
}

/**
 * One method randomazation of the grid
 */
void Map::randomize() {
    placeShip('A',5,Map::playerGrid);
    placeShip('B',4,Map::playerGrid);
    placeShip('C',3,Map::playerGrid);
    placeShip('S',3,Map::playerGrid);
    placeShip('D',2,Map::playerGrid);

    placeShip('A',5,Map::cpuGrid);
    placeShip('B',4,Map::cpuGrid);
    placeShip('C',3,Map::cpuGrid);
    placeShip('S',3,Map::cpuGrid);
    placeShip('D',2,Map::cpuGrid);
}

/**
 * Place Ship randomly on the grid
 * @param ships Ship character
 * @param size Ship size
 * @param grid Grid Array
 */
void Map::placeShip(char ships, int size,char (&grid)[10][10]) {
    bool isVertical ;
    isVertical= bool(rand() % 2);
    int x,y;
    x = rand() % 10, y = rand() % 10;

    //Make sure is in boundary
    if(x+size > 10)
        x -= size;
    if(y+size > 10)
        y -= size;

    if(isVertical) {
        if (checkVerticalClearence(x, y, size)) {
            for (int tempy = y; tempy < (y + size); tempy++) {
                grid[x][tempy] = ships;
            }
        } else {
            placeShip(ships, size, grid);
        }
    }else{
        if(checkHoriClearence(x,y,size)){
            for(int tempx = x; tempx < x+size; tempx++){
                grid[tempx][y] = ships;
            }
        }else{
            placeShip(ships,size,grid);
        }
    }
}

/**
 * Hit Ship on the grid
 * @param x X-axis
 * @param y Y-axis
 * @param myGrid My Grid use to display hit status
 * @param oppoGrid Target Grid
 * @return hited or missed/invaild move
 */
bool Map::hitShip(int x, int y, char (&myGrid)[10][10], char (&oppoGrid)[10][10]) {
    if(isShipHit(x,y,oppoGrid))
        return false;
    else{
        if(isBlockCleared(x,y,oppoGrid) && isBlockCleared(x,y,myGrid)) {
            oppoGrid[x][y] = 'O';
            myGrid[x][y] = 'O';
            return false;
        }else if(isBlockCleared(x,y,myGrid)){
            myGrid[x][y] = '/';
            oppoGrid[x][y] = 'X';
            return true;
        }
    }
}

/**
 * Check if ship was hitted with 'X' or 'O'
 * @param x X-axis
 * @param y Y-axis
 * @param grid target grid
 * @return Hitted?
 */
bool Map::isShipHit(int x, int y, char (&grid)[10][10]) {
    return grid[x][y] == 'X' || grid[x][y] == 'O';
}

/**
 * Check if one of the block speific is blank
 * @param x X-axis
 * @param y Y-axis
 * @param grid target grid
 * @return Blank?
 */
bool Map::isBlockBlank(int x, int y, char (&grid)[10][10]) {
    return grid[x][y] == '_';
}

bool Map::isBlockCleared(int x, int y, char (&grid)[10][10]) {
    return isBlockBlank(x,y,grid) && !isShipHit(x,y,grid);
}

/**
 * Make sure Horiztal. have room for a ship
 * Use linear search method, from top to bottom
 * @param x ship start x
 * @param y ship start y
 * @param size ship size
 * @return Cleared or not
 */
bool Map::checkHoriClearence(int x, int y, int size) {
    for(int tempx = x; tempx < x+size; tempx++){
        if(Map::playerGrid[tempx][y] != '_' || Map::cpuGrid[tempx][y] != '_'){
            return false;
        }
    }
    return true;
}

/**
 * Make sure vertical have room for a ship
 * Use linear search method, from right to left
 * @param x ship start x
 * @param y ship start y
 * @param size ship size
 * @return Cleared or not
 */
bool Map::checkVerticalClearence(int x, int y, int size) {
    for(int tempy = y; tempy < (y+size); tempy++){
        if(Map::playerGrid[x][tempy] != '_' || Map::cpuGrid[x][tempy] != '_'){
            return false;
        }
    }
    return true;
}

bool Map::checkWin(char (&grid)[10][10]) {
    int shipCounter = 0;
    for (auto &x : grid) {
        for (char y : x) {
            if(y == '/')
                shipCounter++;
        }
    }
    return shipCounter == 17;
}