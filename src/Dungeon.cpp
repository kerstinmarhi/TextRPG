#include "../include/Dungeon.h"
#include <iostream>
using namespace std;

Dungeon::Dungeon() {
    generateRooms();
}

void Dungeon::generateRooms() {
    // adds rooms to dungeon
    rooms.emplace_back("Eingangshalle", "Der Eingang zu einem mysteriösen Dungeon.");
    rooms.emplace_back("Schatzkammer", "Ein Raum voller glänzender Schätze und Edelsteine.");
    rooms.emplace_back("Bossraum", "Ein düsterer Raum, in dem eine große Gefahr lauert.");
}


void Dungeon::explore() {
    cout << "You explore the dungeon..." << endl;
    for (const auto& room : rooms) {
        cout << "Room: " << room.getName() << endl;
    }
}
