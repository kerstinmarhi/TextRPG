#include "LivingBeing.h"

class Player : public LivingBeing {
public:
    Player(const string& name, int maxHp, int attack)
        : LivingBeing(name, maxHp, attack) {}

    void attackAction(LivingBeing& target) override {
        std::cout << name << " greift " << target.getName() << " an und verursacht " << attack << " Schaden.\n";
        target.takeDamage(attack);
    }
};