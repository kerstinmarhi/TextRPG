#include "../include/Monster.h"
#include <iostream>
using namespace std;

Monster::Monster(const string& n, int hp, int a, const string& d)
    : name(n), health(hp), attackPoints(a), description(d) {}

// Getter-Methoden
string Monster::getName() const {
    return name;
}

int Monster::getHealth() const {
    return health;
}

int Monster::getAttack() const {
    return attackPoints;
}

string Monster::getDescription() const {
    return description;
}

void Monster::attack() const {
    cout << name << " attacks with a value of " << attackPoints << " points!" << endl;
}

// Methode, um Schaden zu nehmen
void Monster::takeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0; // no negative health
    }
    cout << name << " has " << health << " health points left." << endl;
}

void Monster::showMonster() const {
    cout << "Monster: " << name << endl;
    cout << "Description: " << description << endl;
    cout << "Health: " << health << endl;
    cout << "Attack: " << attackPoints << endl;
}
