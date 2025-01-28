#include "../include/Bag.h"
#include <iostream>
#include <algorithm>

using namespace std;

Bag::Bag() { }

void Bag::addItem(const Item& item) {
    items.push_back(item);
    cout << item.getName() << " added to bag." << endl;
}

void Bag::removeItem(const Item& item) {
    auto it = find(items.begin(), items.end(), item);
    if (it != items.end()) {
        items.erase(it);
        cout << item.getName() << " removed from bag." << endl;
    } else {
        cout << item.getName() << " is not in bag." << endl;
    }
}

void Bag::displayItems() const {
    cout << "\n--- Items in bag ---\n";
    if (items.empty()) {
        cout << "Bag is empty." << endl;
    } else {
        for (const auto& item : items) {
            cout << "- " << item.getName() << endl;
        }
    }
}