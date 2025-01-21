#include "../include/Item.h"
#include <iostream>
using namespace std;

// constructor
Item::Item(const string& n, const string& d) : name(n), description(d) {}

// Getter-Methoden
string Item::getName() const {
    return name;
}

string Item::getBeschreibung() const {
    return description;
}

// Method to use Item
void Item::useItem() {

    cout << "You use the item: " << name << endl;

}

// Methode, um das Item anzuzeigen
void Item::showItem() const {
    cout << "Name: " << name << endl;
    cout << "Description: " << description << endl;
}
