#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>
#include "LivingBeing.h" // Einbindung der LivingBeing-Klasse für die useItem-Methode

using namespace std;

enum class ItemType {
    Potion,
    Weapon,
    Armor
};

class Item {
private:
    std::string name;
    ItemType type;
    int value;

public:
    Item(const string& name, ItemType type, int value);
    string getName() const;
    ItemType getType() const;
    int getValue() const;
    void useItem(LivingBeing& target);
};

#endif
