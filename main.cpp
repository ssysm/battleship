/**
 * P10CPP_ShengmingYuan_ProjectBattleShip
 * @author Shengming Yuan
 */
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Map.h"
#include "GridHelper.h"

using namespace std;


int main() {
    srand(time(0));//seed random

    string input;
    bool turn = true,gameover = false;

    //create class instance
    Map map;
    GridHelper grid;

    //reset and randomize;
    map.resetGrid();
    map.randomize();

    map.printGrid();
    //While game is not over...
    do{
        if(turn)//Human Player
        {
            do{
                cout << "Enter A position";
                cin >> input;
                input = grid.processGridInput(input);
                if(!map.isBlockCleared(grid.asciiToNum(input[0]),grid.asciiToNum(input[1]),map.cpuGrid) && !map.isBlockCleared(grid.asciiToNum(input[0]),grid.asciiToNum(input[1]),map.playerGrid)){
                    cout << "Invalid Position" << endl;
                }
            }while (!map.isBlockCleared(grid.asciiToNum(input[0]),grid.asciiToNum(input[1]),map.cpuGrid) && !map.isBlockCleared(grid.asciiToNum(input[0]),grid.asciiToNum(input[1]),map.playerGrid));

            map.hitShip(grid.asciiToNum(input[0]),grid.asciiToNum(input[1]),map.playerGrid,map.cpuGrid);
            system("clear");
            cout << "Human Player Grid" << endl;
            map.printGrid();
            if(!map.checkWin(map.playerGrid))
                turn = !turn;
        }
        else//CPU
        {
            do {
                input = grid.CPUDecision();
            }while (!map.isBlockCleared(grid.asciiToNum(input[0]),grid.asciiToNum(input[1]),map.cpuGrid) && !map.isBlockCleared(grid.asciiToNum(input[0]),grid.asciiToNum(input[1]),map.playerGrid));
            map.hitShip(grid.asciiToNum(input[0]),grid.asciiToNum(input[1]),map.cpuGrid,map.playerGrid);
            system("clear");
            cout << "CPU Player Grid" << endl;
            //map.printCPUGrid(); __DEBUG__
            if(!map.checkWin(map.cpuGrid))
                turn = !turn;
        }

        if(map.checkWin(map.playerGrid) || map.checkWin(map.cpuGrid)){
            gameover = true;
        }
    }while(!gameover);

    //print both grid
    map.printGrid();
    map.printCPUGrid();

    //final
    if(turn){
        cout << "Human Player Won!" << endl;
    }else{
        cout << "CPU Player Won!" << endl;
    }

}