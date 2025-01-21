#include "../include/Player.h"
#include <iostream>
using namespace std;

Player::Player(const string& name) : name(name), health(100), level(1) { }

// Getter-methods
string Player::getName() const {
    return name;
}

int Player::getHealth() const {
    return health;
}

int Player::getLevel() const {
    return level;
}

// Setter-methods
void Player::setName(const string& name) {
    this->name = name;
}

void Player::setHealth(int health) {
    if (health >= 0) {
        this->health = health;
    }
}

void Player::setLevel(int level) {
    if (level > 0) {
        this->level = level;
    }
}

void Player::displayStats() const {
    cout << "\n--- Player Stats ---\n";
    cout << "Name: " << name << "\n";
    cout << "Health: " << health << "\n";
    cout << "Level: " << level << "\n";
}