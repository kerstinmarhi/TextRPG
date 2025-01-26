#include "../include/Room.h"


Room::Room(const string& name, std::string desc, Monster& monster) : name(name), description(desc), monster(nullptr) { }

string Room::getName() const {
    return name;
}

std::string Room::getDescription() const {
    return description;
}

void Room::setMonster(Monster* m) {
    monster = m;
}

Monster* Room::getMonster() {
    return monster;
}

void Room::addConnection(Room* room) {
    connections.push_back(room);
}

std::vector<Room*> Room::getConnections() {
    return connections;
}

