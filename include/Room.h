#ifndef ROOM_H
#define ROOM_H

#include <string>
#include "Monster.h"
#include <vector>

class Room {
private:
    std::string description;
    Monster* monster;
    std::vector<Room*> connections;

public:
    Room(std::string desc);
    std::string getDescription() const;
    void setMonster(Monster* m);
    Monster* getMonster();
    void addConnection(Room* room);
    std::vector<Room*> getConnections();
};

#endif