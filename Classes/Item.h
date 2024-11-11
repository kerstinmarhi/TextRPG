#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>
#include "LivingBeing.h" // Einbindung der LivingBeing-Klasse für die useItem-Methode

using namespace std;

// Definiert verschiedene Typen von Items
enum class ItemType {
    Potion,    // Heiltrank
    Weapon,    // Waffe
    Armor      // Rüstung
};

class Item {
private:
    string name;
    ItemType type;
    int value; // Effektwert: z.B. Heilungswert oder Angriffskraft

public:
    // Konstruktor
    Item(const string& name, ItemType type, int value);

    // Getter-Methoden
    std::string getName() const;
    ItemType getType() const;
    int getValue() const;

    // Anwenden des Items auf ein Lebewesen
    void useItem(LivingBeing& target);
};

#endif
