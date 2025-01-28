#include "../include/Item.h"
#include <iostream>
using namespace std;

// constructor
Item::Item(const string& n, const string& d, ItemType t) : name(n), description(d), type(t) { }

// Getter-Methoden
string Item::getName() const {
    return name;
}

string Item::getDescription() const {
    return description;
}

ItemType Item::getType() const {
    return type;
}

// Method to use Item
void Item::useItem() {

    cout << "You use the item: " << name << endl;

}

// Method to get information about an item
void Item::showItem() const {
    cout << "Name: " << name << endl;
    cout << "Description: " << description << endl;
     cout << "Typ: ";
    switch (type) {
        case ItemType::FOOD:
            cout << "Food" << endl;
            break;
        case ItemType::POTION:
            cout << "Potion" << endl;
            break;
        case ItemType::WEAPON:
            cout << "Weapon" << endl;
            break;
        case ItemType::ARMOUR:
            cout << "Armour" << endl;
            break;
        case ItemType::MAGICAL:
            cout << "Magical Item" << endl;
            break;
        case ItemType::CURSED:
            cout << "Cursed Item" << endl;
            break;
        case ItemType::OTHER:
            cout << "Don't know" << endl;
            break;
    }
}


bool Item::operator==(const Item& other) const {
    return name == other.name; // Two items are the same when they have identical names.
}
