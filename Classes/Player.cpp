#include "Player.h"
#include <iostream>


Player::Player(const string& name, int maxHp, int attack)
    : LivingBeing(name, maxHp, attack), level(1), experience(0), experienceForNextLevel(100) {}

void Player::attackAction(LivingBeing& target) {
    // Beispiel für Angriff
    target.takeDamage(attack);
}

void Player::addItem(const Item& item) {
    inventory.addItem(item);
}

void Player::listInventory() {
    inventory.listItems();
}

void Player::useItem(int index) {
    inventory.useItem(index, *this);
}

void Player::gainExperience(int xp) {
    experience += xp;
    std::cout << "Erfahrungspunkte gewonnen: " << xp << "\n";
    if (experience >= experienceForNextLevel) {
        levelUp();
    }
}

void Player::levelUp() {
    level++;
    experience -= experienceForNextLevel;
    experienceForNextLevel *= 1.5;  // XP-Bedarf für nächstes Level
    hp = maxHp;  // Setze HP zurück
    attack += 5; // Beispiel: Erhöhe Angriffskraft
    std::cout << "Level-Up! Du bist jetzt Level " << level << "!\n";
}

int Player::getLevel() const {
    return level;
}

int Player::getExperience() const {
    return experience;
}

int Player::getExperienceForNextLevel() const {
    return experienceForNextLevel;
}

void Player::addQuest(const Quest& quest) {
    quests.push_back(quest);
}

void Player::completeQuest(const std::string& questName) {
    for (auto& quest : quests) {
        if (quest.getName() == questName && !quest.getIsCompleted()) {
            quest.completeQuest();
            gainExperience(50); // Beispielhafte Belohnung für Quests
            break;
        }
    }
}

void Player::listQuests() const {
    for (const auto& quest : quests) {
        std::cout << quest.getName() << ": " << (quest.getIsCompleted() ? "Abgeschlossen" : "Offen") << "\n";
    }
}
