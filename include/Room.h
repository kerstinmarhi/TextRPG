#ifndef ROOM_H
#define ROOM_H

#include "Monster.h"
#include <memory>
#include <string>
#include <vector>

using namespace std;

class Player; // declaration forwarding

class Room {
public:
    Room(const string& name, const string& desc);
    // getter
    string getName() const;
    string getDescription() const;
    Monster* getMonster();
    bool getHasChest() const { return hasChest; }
    bool getChestLooted() const { return chestLooted; }
    bool getIsBossRoom() const { return isBossRoom; }
    // setter
    void setMonster(unique_ptr<Monster> m);
    void setHasChest(bool has) { hasChest = has; }
    void setIsBossRoom(bool boss) { isBossRoom = boss; }
    vector<Room*> getConnections();

    void addConnection(Room* room);
    void lootChest(Player& player);

private:
    string name;
    string description;
    std::unique_ptr<Monster> monster; // Instead of Monster* monster
    vector<Room*> connections;
    bool hasChest;
    bool chestLooted;
    bool isBossRoom;
};

#endif