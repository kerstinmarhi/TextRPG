#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <iostream>

using namespace std;

enum class Weakness {
    NONE,
    POISON,
    FIRE,
    FREEZE
};

class Monster {
private:
    string name;        
    int health;   
    int attackPoints;
    Weakness weakness;        
    string description; 
    int xpReward;

public:
    
    Monster(const string& n, int hp, int a, Weakness w, const string& d, int xpVal);

    // Getter-Methoden
    string getName() const;
    int getHealth() const;
    int getAttack() const;
    Weakness getWeakness() const;
    string getDescription() const;
    int getXPReward() const;

    bool isAlive() const;
    
    void attack() const;

    void takeDamage(int damage);

    void showMonster() const;
};

#endif
