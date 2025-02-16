#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Monster {
private:
    string name;
    int health;
    int attackPoints;
    string description;
    int xpReward;

public:
    Monster(const string& n, int hp, int a, const string& d, int xpVal);

    // Getter-Methoden
    string getName() const;
    int getHealth() const;
    int getAttack() const;
    string getDescription() const;
    int getXPReward() const;

    bool isAlive() const;

    void attack() const;
    void takeDamage(int damage);
    void showMonster() const;

    // Static method to generate monsters
    static std::unique_ptr<Monster> generateMonster(int level);
};

#endif
