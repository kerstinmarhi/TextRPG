#include "Monster.h"

Monster::Monster(const string& name, int maxHp, int attack)
    : LivingBeing(name, maxHp, attack) {}

void Monster::attackAction(LivingBeing& target) {
    std::cout << name << " greift " << target.getName() << " an und verursacht " << attack << " Schaden.\n";
    target.takeDamage(attack);
}
