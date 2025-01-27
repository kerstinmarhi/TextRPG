#ifndef ROOM_H
#define ROOM_H

#include <string>
#include "Monster.h"
#include <vector>

using namespace std;

class Room {
public:
    Room(const string& name, std::string desc, Monster& monster);
    string getName() const;
    std::string getDescription() const;
    void setMonster(Monster* m);
    Monster* getMonster();
    void addConnection(Room* room);
    std::vector<Room*> getConnections();

private:
    string name;
    std::string description;
    Monster* monster;
    std::vector<Room*> connections;
};


#endif