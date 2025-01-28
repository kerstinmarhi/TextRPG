#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

using namespace std;

enum class ItemType {
    FOOD,
    POTION,
    WEAPON,
    ARMOUR,
    MAGICAL,
    CURSED,
    OTHER
};

class Item {
private:
    string name;         
    string description; 
    ItemType type;

public:
    // constructor
    Item(const string& n, const string& d, ItemType t);

    // Getter-Methoden
    string getName() const;
    string getDescription() const;
    ItemType getType() const;

    // Method to use item
    void useItem();
    //Method to show item
    void showItem() const;

};

#endif
