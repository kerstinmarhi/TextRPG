#include "LivingBeing.h"

//using namespace std;

LivingBeing::LivingBeing(const string& name, int maxHp, int attack)
    : name(name), maxHp(maxHp), hp(maxHp), attack(attack) {}

std::string LivingBeing::getName() const {
    return name;
}

int LivingBeing::getHp() const {
    return hp;
}

int LivingBeing::getMaxHp() const {
    return maxHp;
}

int LivingBeing::getAttack() const {
    return attack;
}

bool LivingBeing::isAlive() const {
    return hp > 0;
}

void LivingBeing::takeDamage(int damage) {
    hp -= damage;
    if (hp < 0) hp = 0;
}

void LivingBeing::heal(int amount) {
    hp += amount;
    if (hp > maxHp) hp = maxHp;
}
