#include "../include/Monster.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

Monster::Monster(const string& n, int hp, int a, const string& d, int xpVal)
    : name(n)
    , health(hp)
    , attackPoints(a)
    , description(d)
    , xpReward(xpVal)
{
}

// Getter methods
string Monster::getName() const
{
    return name;
}

int Monster::getHealth() const
{
    return health;
}

int Monster::getAttack() const
{
    return attackPoints;
}

string Monster::getDescription() const
{
    return description;
}

int Monster::getXPReward() const
{
    return xpReward;
}

void Monster::attack() const
{
    cout << name << " attacks with a value of " << attackPoints << " points!" << endl;
}

// Method to take damage
void Monster::takeDamage(int damage)
{
    health -= damage;
    if (health < 0) {
        health = 0; // no negative health
    }
    cout << name << " has " << health << " health points left." << endl;
}

bool Monster::isAlive() const
{
    return health > 0;
}

void Monster::showMonster() const
{
    cout << "Monster: " << name << endl;
    cout << "Description: " << description << endl;
    cout << "Health: " << health << endl;
    cout << "Attack: " << attackPoints << endl;
}

unique_ptr<Monster> Monster::generateMonster(int tier)
{
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation

    vector<Monster> tier1Monsters = {
        Monster("Goblin", 50, 10, "A dubious little creature", 20),
        Monster("Skeleton", 40, 8, "A reanimated skeleton", 15),
        Monster("Zombie", 60, 12, "A slow-moving undead", 25)
    };

    vector<Monster> tier2Monsters = {
        Monster("Orc", 80, 15, "A brutish orc", 30),
        Monster("Dark Mage", 60, 20, "A mage who has succumbed to the dark arts", 40),
        Monster("Werewolf", 100, 18, "A ferocious werewolf", 50)
    };

    vector<Monster> tier3Monsters = {
        Monster("Hobgoblin Chief", 150, 25, "A massive, muscular goblin wearing crude but effective armor. A makeshift wooden crown sits upon its head.", 100),
        Monster("Shadow Assassin", 90, 30, "A silent killer lurking in the shadows", 50),
        Monster("Dragon", 200, 35, "A fearsome dragon with scales as hard as steel", 150)
    };

    vector<vector<Monster>> monstersByTier = { tier1Monsters, tier2Monsters, tier3Monsters };

    if (tier < 1 || tier > static_cast<int>(monstersByTier.size())) {
        throw invalid_argument("Invalid level");
    }

    int randomIndex = rand() % monstersByTier[tier - 1].size();
    return make_unique<Monster>(monstersByTier[tier - 1][randomIndex]);
}
