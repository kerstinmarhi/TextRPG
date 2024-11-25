#ifndef DUNGEON_H
#define DUNGEON_H

#include <vector>
#include <string>
#include "Room.h"
#include "Player.h"

using namespace std;

class Dungeon {
private:
    std::vector<Room> rooms;   // Sammlung aller Räume
    Player& player;            // Referenz auf den Spieler
    int currentRoomIndex;      // Index des aktuellen Raums

public:
    Dungeon(Player& player);
    void createDungeon();      // Dungeon erstellen
    void describeCurrentRoom(); // Aktuellen Raum beschreiben
    void moveToNextRoom();     // Zum nächsten Raum wechseln
    void enterRoom();          // Raum betreten und Interaktion starten
    bool isDungeonCompleted() const; // Prüfen, ob der Dungeon abgeschlossen wurde
};

#endif
