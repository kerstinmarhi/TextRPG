#ifndef DUNGEON_H
#define DUNGEON_H

#include <vector>
#include "Room.h"

class Dungeon {
public:
    Dungeon();
    void explore();

private:
    std::vector<Room> rooms;
    void generateRooms();
};

#endif
