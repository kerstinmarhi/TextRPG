#include "../include/Dungeon.h"
#include <iostream>
using namespace std;

Dungeon::Dungeon() {
    generateRooms();
}

void Dungeon::generateRooms() {
    // add Rooms to dungeon
    rooms.emplace_back("Eingangshalle");
    rooms.emplace_back("Schatzkammer");
    rooms.emplace_back("Bossraum");
}

void Dungeon::explore() {
    cout << "You explore the dungeon..." << endl;
    for (const auto& room : rooms) {
        cout << "Room: " << room.getName() << endl;
    }
}
