#ifndef PLAYER_H
#define PLAYER_H

#include "Bag.h"
#include "Monster.h"
#include <memory>
#include <string>
using namespace std;

class Player {
public:
    Player(const string& name);

    // Getter-methods
    string getName() const;
    int getHealth() const;
    int getLevel() const;
    int getAP() const;
    Bag& getBag(); // Return by reference instead of: Bag getBag() const (for no copying);
    int getXP() const;
    int getXPNeededForNextLevel() const;
    int getTempAPBonus() const;
    int getTempAPDuration() const;
    int getMaxHealth() const { return maxHealth; }
    Weakness getSpellBonus() const;
    double getInitiative() const;
    double getCritChance() const;
    double getPrecision() const;
    int getBalance() const;
    // Setter-methods
    void setName(const string& name);
    void setHealth(int health);
    void setLevel(int level);
    void setAP(int attackPoints);
    void setSpellBonus(Weakness bonus);
    void setInitiative(double initiative);
    void setCritChance(double critChance);
    void setPrecision(double precision);
    void setBalance(int balance);

    void displayStats() const; // show player stats
    void attack(Monster& monster) const;
    void takeDamage(int damage);
    bool isAlive() const;
    void openBag();
    void addXP(int amount);
    void checkLevelUp();
    void setAPBonus(int bonus, int duration);
    void updateBuffs(); // Call this each turn to decrease buff durations
    void addItemToBag(std::unique_ptr<Item> item);
    void equipItem(Equipment* item); // Keep as raw pointer since Bag owns the item
    void unequipItem(ItemType type);
    void showEquippedItems() const;
    void removeEquipmentStats(const Equipment* item);
    void updateMaxHealth(); // Recalculates max health based on level and armor
    void updateAttackPoints(); // Recalculates AP based on level and weapon
    bool isInLikelihood(double likelihood) const;
    void updateInitiative();
    void updateCritChance();
    void updatePrecision();

private:
    std::unique_ptr<Equipment> equippedWeapon;
    std::unique_ptr<Equipment> equippedArmor;
    string name;
    int health;
    int level;
    int attackPoints = 20; // base attack damage
    std::unique_ptr<Bag> bag;
    int xp;
    int xpNeededForNextLevel;
    int tempAPBonus;
    int tempAPDuration;
    int maxHealth;
    int baseMaxHealth; // Stores base max HP without armor bonuses
    int baseAP; // Base attack power before bonuses
    Weakness spellBonus;
    double initiative; // likelihood of going first in battle
    double critChance; // likelihood of landing a critical hit
    double precision; // likelihood of hitting or missing an attack
    int balance; // for interactions with the shop feature
};

#endif