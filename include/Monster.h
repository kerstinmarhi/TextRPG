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
    string description; 

public:
    
    Monster(const string& n, int hp, int a, const string& d);

    // Getter-Methoden
    string getName() const;
    int getHealth() const;
    int getAttack() const;
    string getDescription() const;

    void attack() const;

    void takeDamage(int damage);

    void showMonster() const;
};

#endif
