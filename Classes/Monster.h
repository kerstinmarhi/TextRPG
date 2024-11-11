#ifndef MONSTER_H
#define MONSTER_H

#include "LivingBeing.h"

class Monster : public LivingBeing {
public:
    // Konstruktor
    Monster(const std::string& name, int maxHp, int attack);

    // Implementierung der Angriffsmethode
    void attackAction(LivingBeing& target) override;
};

#endif // MONSTER_H
