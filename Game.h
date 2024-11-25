#ifndef GAME_H
#define GAME_H

#include "Classes/Player.h"
#include "Classes/Dungeon.h"
#include "Classes/Quest.h"

using namespace std;

class Game {
private:
    Player player;        // Der Spieler
    Dungeon dungeon;      // Das Dungeon
    bool isOver;      // Spielstatus (ob das Spiel vorbei ist oder nicht)

public:
    Game(const string& playerName);  // Konstruktor zum Starten des Spiels
    void start();        // Spiel starten
    void processInput(); // Eingabe des Spielers verarbeiten
    void update();       // Spiel-Status aktualisieren (z.B. Dungeon betreten, kämpfen)
    void displayStatus(); // Aktuellen Status anzeigen (z.B. HP, Level, etc.)
    bool isGameOver() const; // Rückgabe, ob das Spiel vorbei ist
    void setGameOver(bool);
    void endGame();         // Das Spiel beenden (z.B. bei Tod des Spielers oder wenn Dungeon abgeschlossen)
};

#endif
