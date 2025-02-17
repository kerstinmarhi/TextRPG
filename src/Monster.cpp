#include "../include/Monster.h"
#include <iostream>
using namespace std;

Monster::Monster(const string& n, int hp, int a, double cc, double cm, Weakness w, const string& d, int xpVal)
    : name(n), health(hp), attackPoints(a), critChance(cc), critMultiplier(cm), weakness(w), description(d), xpReward(xpVal) {}

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

double Monster::getCritChance() const {
    return critChance;
}

double Monster::getCritMultiplier() const {
    return critMultiplier;
}

Weakness Monster::getWeakness() const {
    return weakness;
}

string Monster::getDescription() const {
    return description;
}

int Monster::getXPReward() const {
    return xpReward;
}

void Monster::attack() const {
    cout << name << " attacks with a value of " << attackPoints << " points!" << endl;
}

// Methode, um Schaden zu nehmen
void Monster::takeDamage(int damage) {
    double roll = (double)rand() / RAND_MAX; // random number between 0.0 and 1.0

    if (roll < critChance) {
        damage *= critMultiplier;
        cout << "Critical Hit! " << damage << " damage dealt!" << endl;
    }

    health -= damage;
    if (health < 0) {
        health = 0; // no negative health
    }
    cout << name << " has " << health << " health points left." << endl;
}
bool Monster::isAlive() const {
    return health > 0;
}
void Monster::showMonster() const {
    cout << "Monster: " << name << endl;
    cout << "Description: " << description << endl;
    cout << "Health: " << health << endl;
    cout << "Attack: " << attackPoints << endl;
}
