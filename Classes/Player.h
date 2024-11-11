#ifndef PLAYER_H
#define PLAYER_H

#include "LivingBeing.h"

class Player : public LivingBeing {
public:
    // Konstruktor
    Player(const std::string& name, int maxHp, int attack);

    // Implementierung der Angriffsmethode
    void attackAction(LivingBeing& target) override;
};

#endif // PLAYER_H
