#include "../include/Room.h"


Room::Room(const string& name, const string& desc) : name(name), description(desc) { }

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

