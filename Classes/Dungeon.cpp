#include "Dungeon.h"
#include "Room.h"
#include <iostream>

Dungeon::Dungeon(Player& player) : player(player), currentRoomIndex(0) {}

void Dungeon::createDungeon() {
    // Beispielräume erstellen, dies könnte zufällig oder dynamisch geschehen
    Room room1;
    room1.addMonster(Monster("Goblin", 30, 5));
    room1.addItem(Item("Heiltrank", ItemType::Potion, 20));
    rooms.push_back(room1);

    Room room2;
    room2.addMonster(Monster("Skelett", 50, 10));
    room2.addItem(Item("Starker Zaubertrank", ItemType::Potion, 50));
    rooms.push_back(room2);

    // Weitere Räume können hier hinzugefügt werden
}

void Dungeon::describeCurrentRoom() {
    if (currentRoomIndex < rooms.size()) {
        rooms[currentRoomIndex].describeRoom();  // Ruft die Beschreibung des aktuellen Raums auf
    }
}

void Dungeon::moveToNextRoom() {
    if (currentRoomIndex + 1 < rooms.size()) {
        currentRoomIndex++;
        describeCurrentRoom();
    } else {
        cout << "Du hast den Dungeon abgeschlossen!" << std::endl;
    }
}

void Dungeon::enterRoom() {
    if (currentRoomIndex < rooms.size()) {
        rooms[currentRoomIndex].enterRoom(player);
    }
}

bool Dungeon::isDungeonCompleted() const {
    return currentRoomIndex == rooms.size();
}
