#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <iostream>

using namespace std;

class Monster {
private:
    string name;        
    int health;   
    int attackPoints;
    double critChance;
    double critMultiplier;        
    string description; 
    int xpReward;

public:
    
    Monster(const string& n, int hp, int a, double cc, double cm, const string& d, int xpVal);

    // Getter-Methoden
    string getName() const;
    int getHealth() const;
    int getAttack() const;
    double getCritChance() const;
    double getCritMultiplier() const;
    string getDescription() const;
    int getXPReward() const;

    bool isAlive() const;
    
    void attack() const;

    void takeDamage(int damage);

    void showMonster() const;
};

#endif
