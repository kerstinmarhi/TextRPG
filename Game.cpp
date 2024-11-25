#include "Game.h"
#include <iostream>

Game::Game(const string& playerName) 
    : player(playerName, 100, 10), dungeon(player), isOver(false) {}

void Game::start() {
    cout << "Willkommen im Dungeon-Abenteuer, " << player.getName() << "!\n";
    cout << "Dein Ziel ist es, den Dungeon zu überleben und zu beenden.\n";
    dungeon.createDungeon();  // Dungeon erstellen
    displayStatus();
}

void Game::processInput() {
    string command;
    cout << "\nWas möchtest du tun? (Bewege dich mit 'weiter', benutze Item mit 'item', verlasse das Spiel mit 'exit')\n";
    cin >> command;

    if (command == "weiter") {
        dungeon.moveToNextRoom();  // Gehe zum nächsten Raum
        update();
    } 
    else if (command == "item") {
        player.listInventory();  // Zeige Inventar des Spielers an
        cout << "Welches Item möchtest du benutzen? Gib die Nummer ein: ";
        int index;
        cin >> index;
        player.useItem(index - 1);  // Item aus dem Inventar benutzen
        update();
    }
    else if (command == "exit") {
        endGame();  // Spiel beenden
    }
    else {
        cout << "Unbekannter Befehl. Versuche es noch einmal.\n";
    }
}

void Game::update() {
    // Überprüfen, ob der Dungeon abgeschlossen ist
    if (dungeon.isDungeonCompleted()) {
        cout << "Du hast den Dungeon abgeschlossen!\n";
        endGame();
    }

    // Überprüfen, ob der Spieler tot ist (wenn er keine HP mehr hat)
    if (!player.isAlive()) {
        cout << "Du bist gestorben. Das Spiel ist vorbei.\n";
        endGame();
    }

    // Zeige Status des Spiels an
    displayStatus();
}

void Game::displayStatus() {
    cout << "\n--- Aktueller Status ---\n";
    cout << "Name: " << player.getName() << "\n";
    cout << "Level: " << player.getLevel() << " (XP: " << player.getExperience() << "/" << player.getExperienceForNextLevel() << ")\n";
    cout << "HP: " << player.getHp() << "/" << player.getMaxHp() << "\n";
    cout << "Aktueller Raum: " << (dungeon.isDungeonCompleted() ? "Dungeon abgeschlossen" : "In einem neuen Raum") << "\n";
}

bool Game::isGameOver() const {
    return isOver;
}

void Game::setGameOver(bool isGameOver){
    isOver = isGameOver;
}

void Game::endGame() {
    setGameOver(true);
    cout << "Spiel beendet. Danke für das Spielen!\n";
}
