#include "Room.h"
#include <iostream>

Room::Room() : puzzleAnswer("1234") {}

void Room::addMonster(const Monster& monster) {
    monsters.push_back(monster);
}

void Room::addItem(const Item& item) {
    items.push_back(item);
}

void Room::describeRoom() {
    cout << "Du bist in einem neuen Raum.\n";
    if (!monsters.empty()) {
        cout << "Monster sind hier.\n";
    }
    if (!items.empty()) {
        cout << "Es gibt einige Items im Raum.\n";
    }
    cout << "Lösen Sie das Rätsel, um weiterzukommen!\n";
}

bool Room::solvePuzzle(const std::string& answer) {
    if (answer == puzzleAnswer) {
        std::cout << "Rätsel gelöst! Der Weg ist nun frei.\n";
        return true;
    } else {
        std::cout << "Falsche Antwort. Versuche es noch einmal.\n";
        return false;
    }
}

void Room::enterRoom(Player& player) {
    string playerAnswer;
    cout << "Gib die Antwort auf das Rätsel ein: ";
    cin >> playerAnswer;
    
    if (solvePuzzle(playerAnswer)) {
        cout << "Du hast den Raum erfolgreich betreten!\n";
    } else {
        cout << "Du kannst den Raum nicht betreten, bevor du das Rätsel löst.\n";
    }
}
