#ifndef ROOM_H
#define ROOM_H

#include <string>
#include "Monster.h"
#include <vector>

using namespace std;

class Room {
public:
    Room(const string& name, const string& desc);
    //getter
    string getName() const;
    string getDescription() const;
    Monster* getMonster();
    //setter
    void setMonster(Monster* m);
    vector<Room*> getConnections();

    void addConnection(Room* room);
    

private:
    string name;
    string description;
    Monster* monster;
    vector<Room*> connections;
};


#endif