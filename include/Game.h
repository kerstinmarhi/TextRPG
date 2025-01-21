#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Dungeon.h"

class Game {
public:
    Game(); // constructor
    void start(); // start game

private:
    Player player; 
    Dungeon dungeon;
    void mainMenu(); 
    void explore(); 
};

#endif