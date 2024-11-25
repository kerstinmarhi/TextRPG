#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include "Monster.h"
#include "Item.h"
#include "Player.h"

using namespace std;

class Room {
private:
    vector<Monster> monsters;
    vector<Item> items;
    string puzzleAnswer;

public:
    Room();
    void addMonster(const Monster& monster);
    void addItem(const Item& item);
    void enterRoom(Player& player);
    void describeRoom();
    bool solvePuzzle(const string& answer);
};

#endif