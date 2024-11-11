#include "LivingBeing.h"

using namespace std;

LivingBeing::LivingBeing(const string& name, int maxHp, int attack)
    : name(name), hp(maxHp), maxHp(maxHp), attack(attack) {}

string LivingBeing::getName() const {
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
    cout << name << " nimmt " << damage << " Schaden und hat jetzt " << hp << " HP übrig.\n";
}

void LivingBeing::heal(int amount) {
    hp += amount;
    if (hp > maxHp) hp = maxHp;
    cout << name << " heilt sich um " << amount << " Punkte und hat jetzt " << hp << " HP.\n";
}

