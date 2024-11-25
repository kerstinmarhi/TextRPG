#include "Monster.h"

Monster::Monster(const std::string& name, int maxHp, int attack)
    : LivingBeing(name, maxHp, attack) {}

void Monster::attackAction(LivingBeing& target) {
    // Beispiel für Angriff
    target.takeDamage(attack);
}
