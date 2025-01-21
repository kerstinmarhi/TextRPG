#include "../include/Room.h"

Room::Room(const string& name) : name(name) { }

string Room::getName() const {
    return name;
}
