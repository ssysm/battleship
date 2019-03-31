//
// Created by apple on 2019-02-24.
//

#ifndef BATTLESHIP_GRIDHELPER_H
#define BATTLESHIP_GRIDHELPER_H


#include <string>

class GridHelper{
public:
    std::string processGridInput(std::string input);
    std::string CPUDecision();
    int asciiToNum(char a);

private:
    char numToAlpha(int n);
    char numToAscii(int n);
};

#endif //BATTLESHIP_GRIDHELPER_H