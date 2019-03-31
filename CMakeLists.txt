cmake_minimum_required(VERSION 3.13)
project(BattleShip)

set(CMAKE_CXX_STANDARD 14)

add_executable(BattleShip main.cpp Map.cpp GridHelper.cpp)