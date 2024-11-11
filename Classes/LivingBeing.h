#ifndef LIVINGBEING_H
#define LIVINGBEING_H

#include <string>
#include <iostream>

using namespace std;

class LivingBeing {
protected:
    string name;
    int hp;
    int maxHp;
    int attack;

public:
    LivingBeing(const string& name, int maxHp, int attack);
    virtual ~LivingBeing() = default; // Virtueller Destruktor

    std::string getName() const;
    int getHp() const;
    int getMaxHp() const;
    int getAttack() const;
    bool isAlive() const;

    void takeDamage(int damage);
    void heal(int amount);

    virtual void attackAction(LivingBeing& target) = 0; // Reine virtuelle Methode
};

#endif
