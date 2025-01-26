#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Room.h"
#include <vector>

class Game {
private:
    Player player;
    std::vector<Room*> rooms;
    Room* currentRoom;
    void mainMenu();
    void explore();
    void initializeRooms();
    void combat(Monster* monster);

public:
    Game();
    ~Game();
    void start();
};

#endif