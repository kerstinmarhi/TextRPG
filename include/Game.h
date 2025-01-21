#ifndef GAME_H
#define GAME_H

#include "Player.h"

class Game {
public:
    Game(); // constructor
    void start(); // start game

private:
    Player player; 
    void mainMenu(); 
    void explore(); 
};

#endif