#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Room.h"
#include <vector>
#include "Dungeon.h"
#include <memory>


class Game {
private:
    std::vector<std::unique_ptr<Room>> rooms;
    Room* currentRoom;
    Player player; 
    Dungeon dungeon;

public:
    Game();
    ~Game();
    void start();
    void mainMenu(); 
    void explore(); 
    void initializeRooms();
    void combat(Monster* monster);

};

#endif