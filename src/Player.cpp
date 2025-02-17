#include "../include/Player.h"
#include "../include/Bag.h"
#include "../include/Monster.h"
#include <iostream>
#include <random>
using namespace std;

// Update constructor to set base AP
Player::Player(const string& name)
    : equippedWeapon(nullptr)
    , equippedArmor(nullptr)
    , name(name)
    , health(100)
    , level(1)
    , attackPoints(10)
    , bag(std::make_unique<Bag>())
    , xp(0)
    , xpNeededForNextLevel(100)
    , tempAPBonus(0)
    , tempAPDuration(0)
    , maxHealth(100)
    , baseMaxHealth(100)
    , baseAP(10)
    , spellBonus(Weakness::NONE)
    , initiative(0.5)
    , critChance(0.1)
    , precision(0.5)
    , balance(0)
{
}

// Getter-methods
string Player::getName() const
{
    return name;
}

int Player::getHealth() const
{
    return health;
}

int Player::getLevel() const
{
    return level;
}

int Player::getXP() const
{
    return xp;
}

int Player::getXPNeededForNextLevel() const
{
    return xpNeededForNextLevel;
}

int Player::getTempAPBonus() const
{
    return tempAPBonus;
}

int Player::getTempAPDuration() const
{
    return tempAPDuration;
}

Bag& Player::getBag()
{
    return *bag;
}

int Player::getAP() const
{
    return attackPoints + tempAPBonus;
}

Weakness Player::getSpellBonus() const
{
    return spellBonus;
}

double Player::getInitiative() const
{
    return initiative;
}

double Player::getCritChance() const
{
    return critChance;
}

double Player::getPrecision() const
{
    return precision;
}

int Player::getBalance() const
{
    return balance;
}

// Setter-methods
void Player::setName(const string& name)
{
    this->name = name;
}

void Player::setHealth(int newHealth)
{
    if (newHealth <= 0) {
        health = 0;
    } else {
        health = std::min(newHealth, maxHealth);
    }
}

void Player::setLevel(int level)
{
    if (level > 0) {
        this->level = level;
    }
}

void Player::setAPBonus(int bonus, int duration)
{
    tempAPBonus = bonus;
    tempAPDuration = duration;
}

void Player::setSpellBonus(Weakness bonus)
{
    spellBonus = bonus;
}

void Player::setInitiative(double initiative)
{
    this->initiative = initiative;
}

void Player::setCritChance(double critChance)
{
    this->critChance = critChance;
}

void Player::setPrecision(double precision)
{
    this->precision = precision;
}

void Player::setBalance(int balance)
{
    this->balance = balance;
}

void Player::displayStats() const
{
    cout << "\n--- Player Stats ---\n";
    cout << "Name: " << name << "\n";
    cout << "Health: " << health << "\n";
    cout << "Level: " << level << "\n";
    cout << "Attack Power: " << attackPoints;
    if (tempAPBonus > 0) {
        cout << " (+" << tempAPBonus << " for " << tempAPDuration << " turns)";
    }
    cout << "\n";

    cout << "\n--- Equipped Items ---\n";
    cout << "Weapon: " << (equippedWeapon ? equippedWeapon->getName() : "None") << "\n";
    cout << "Armor: " << (equippedArmor ? equippedArmor->getName() : "None") << "\n";
}

void Player::attack(Monster& monster) const
{
    // hit or miss
    if (isInLikelihood(precision)) {
        int currentAttackPoints = attackPoints;

        if (isInLikelihood(critChance)) {
            currentAttackPoints *= 1.5;
            cout << "Critical hit!" << endl;
        }
        cout << name << " attacks " << monster.getName() << " for " << currentAttackPoints << " damage!" << endl;

        if (this->getSpellBonus() == monster.getWeakness())
        {
            cout << monster.getName() << " is double weak to this spell! (-" << currentAttackPoints * 2 << ")" << endl;
            monster.takeDamage(currentAttackPoints * 2);
        } 
        else 
        {
            monster.takeDamage(currentAttackPoints);
        }
    } 
    else
    {
        cout << "Hit missed!" << endl;
    } 
}

// determines if the attributes initiative, critChance or precision apply
bool Player::isInLikelihood(double likelihood) const
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<double> dist(0.0, 1.0);

    return likelihood > dist(gen);
}

void Player::takeDamage(int damage)
{
    health -= damage;
    if (health < 0)
        health = 0;
    cout << name << " takes " << damage << " damage! Health: " << health << endl;
}

bool Player::isAlive() const
{
    return health > 0;
}

void Player::openBag()
{
    bag->displayItems();

    if (!bag->isEmpty()) { // Add isEmpty() method to Bag class
        cout << "\nEnter item number to use (0 to exit): ";
        size_t choice;
        cin >> choice;

        if (choice > 0) {
            bag->useItem(choice - 1, *this);
        }
    }
}

void Player::addXP(int amount)
{
    xp += amount;
    cout << "Gained " << amount << " EXP! Current EXP: " << xp << endl;
    checkLevelUp();
}

// Modify checkLevelUp to update AP
void Player::checkLevelUp()
{
    while (xp >= xpNeededForNextLevel) {
        xp -= xpNeededForNextLevel;
        level++;
        xpNeededForNextLevel += 100;

        updateMaxHealth(); // Update max health on level up
        updateAttackPoints(); // Update AP on level up
        updateInitiative();
        updatePrecision();
        updateCritChance();

        health = maxHealth; // Heal to full on level up
        cout << "You leveled up! New level: " << level << endl;
        cout << "Max health increased to " << maxHealth << "!" << endl;
        cout << "Attack Power increased to " << attackPoints << "!" << endl;

        if (initiative == 1.0)
        {
            cout << "Initiative maxed out!";
        } else {
            cout << "You now have a " << initiative*100 << "% chance to attack first!" << endl;
        }
        
        if (precision == 1.0)
        {
            cout << "Precision maxed out!";
        } else {
            cout << "Hit rate increased to " << precision*100 << "%!" << endl;
        }
        
        if (critChance == 1.0)
        {
            cout << "Critical hitting maxed out!";
        } else {
            cout << "Critical hits have now a " << critChance*100 << "% success rate!" << endl;
        }
    }
}

void Player::updateBuffs()
{
    if (tempAPDuration > 0) {
        tempAPDuration--;
        if (tempAPDuration == 0) {
            std::cout << "Potion/spell effect wore off!" << std::endl;
            tempAPBonus = 0;
            spellBonus = Weakness::NONE;
        }
    }
}

void Player::addItemToBag(std::unique_ptr<Item> item)
{
    bag->addItem(std::move(item));
}

// Update equipItem to use updateAttackPoints
void Player::equipItem(Equipment* item)
{
    auto& slot = (item->getType() == ItemType::WEAPON) ? equippedWeapon : equippedArmor;

    // Remove old item's stats if exists
    if (slot) {
        removeEquipmentStats(slot.get());
    }

    // Add new item's stats
    switch (item->getType()) {
    case ItemType::WEAPON:
        updateAttackPoints(); // Recalculate AP with new weapon
        break;
    case ItemType::ARMOUR:
        updateMaxHealth(); // Recalculate max health with new armor
        health = std::min(health, maxHealth);
        break;
    default:
        return;
    }

    cout << "Equipped " << item->getName() << "\n";
    slot.reset(item);
}

void Player::removeEquipmentStats(const Equipment* item)
{
    switch (item->getType()) {
    case ItemType::WEAPON:
        attackPoints -= item->getStatBonus();
        break;
    case ItemType::ARMOUR:
        health -= item->getStatBonus();
        break;
    default:
        break;
    }
}

void Player::unequipItem(ItemType type)
{
    auto& slot = (type == ItemType::WEAPON) ? equippedWeapon : equippedArmor;

    if (slot) {
        removeEquipmentStats(slot.get());
        slot.reset();
    }
}

void Player::updateMaxHealth()
{
    // Base health increases by 20 per level
    int levelBonus = (level - 1) * 20;
    maxHealth = baseMaxHealth + levelBonus;

    // Add armor bonus if equipped
    if (equippedArmor) {
        maxHealth += equippedArmor->getStatBonus();
    }
}

// Add new method to update total AP
void Player::updateAttackPoints()
{
    // Base AP increases by 5 per level
    int levelBonus = (level - 1) * 5;
    attackPoints = baseAP + levelBonus;

    // Add weapon bonus if equipped
    if (equippedWeapon) {
        attackPoints += equippedWeapon->getStatBonus();
    }
}

void Player::updateInitiative()
{
    if (initiative < 1.0) {
        initiative += 0.1; 
    }
}

void Player::updateCritChance()
{
    if (critChance < 1.0) {
        critChance += 0.1; 
    }
}

void Player::updatePrecision()
{
    if (precision < 1.0) {
        precision += 0.1; 
    }
}