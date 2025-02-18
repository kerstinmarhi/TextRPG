#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include <string>

using namespace std;

enum class Weakness {
    NONE,
    POISON,
    FIRE,
    FREEZE,
    LIGHT,
    HOLY,
    SILVER,
    BLUNT,
    ICE,
    LIGHTNING
};
inline bool operator==(const Weakness& lhs, const Weakness& rhs) {
    return static_cast<int>(lhs) == static_cast<int>(rhs);
}
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
