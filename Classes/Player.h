#ifndef PLAYER_H
#define PLAYER_H

#include "LivingBeing.h"
#include "Inventory.h"
#include "Quest.h"
#include <vector>

using namespace std;


class Player : public LivingBeing {
private:
    Inventory inventory;
    int level;
    int experience;
    int experienceForNextLevel;
    std::vector<Quest> quests;

public:
    Player(const string& name, int maxHp, int attack);
    void attackAction(LivingBeing& target) override;
    void addItem(const Item& item);
    void listInventory();
    void useItem(int index);

    void gainExperience(int xp);
    void levelUp();
    int getLevel() const;
    int getExperience() const;
    int getExperienceForNextLevel() const;

    void addQuest(const Quest& quest);
    void completeQuest(const std::string& questName);
    void listQuests() const;
};

#endif
