#ifndef DUNGEON_H
#define DUNGEON_H

#include "Room.h"
#include <memory>
#include <vector>

class Dungeon {
public:
    Dungeon();
    void explore();
    void initializeRooms();
    Room* getStartingRoom() const;

private:
    std::vector<std::unique_ptr<Room>> rooms;
    void generateRooms();
};

#endif
