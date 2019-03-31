//
// Created by apple on 2019-02-24.
//

#include "GridHelper.h"
#include <string>

/**
 * Process User input and return a xy cord.
 * @param str Grid Label
 * @return xy
 */
std::string GridHelper::processGridInput(std::string str){
    std::string temp;
    temp = str;
    if(isalpha(str[0])){
        temp[1] = str[0];
    }
    if(isdigit(str[1])){
        temp[0] = str[1];
    }

    temp[1] = char(temp[1]-65+48);
    return temp;
}

std::string GridHelper::CPUDecision() {
    std::string decision;
    int x,y;
    x = rand() % 10,y=rand()%10;
    decision[0] = numToAscii(x);
    decision[1] = numToAlpha(y);
    return decision;
}

/**
 * Convert letter input to pure number in array index
 * @param a ASCii Key
 * @return Array Index from 'A'
 */
int GridHelper::asciiToNum(char a) {
    return int(a) - 48;
}

char GridHelper::numToAscii(int n) {
    return char(n+48);
}

char GridHelper::numToAlpha(int n) {
    return char(n+65);
}
