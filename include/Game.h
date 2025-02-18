#ifndef GAME_H
#define GAME_H

#include "Dungeon.h"
#include "Player.h"
#include "Room.h"
#include <memory>
#include <vector>

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
    void resetGame();
};

#endif