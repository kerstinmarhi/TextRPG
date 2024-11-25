#ifndef MONSTER_H
#define MONSTER_H

#include "LivingBeing.h"

using namespace std;

class Monster : public LivingBeing {
public:
    Monster(const string& name, int maxHp, int attack);
    void attackAction(LivingBeing& target) override;
};

#endif
