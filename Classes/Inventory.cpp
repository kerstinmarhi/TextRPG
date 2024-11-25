#include "Inventory.h"
#include <iostream>

void Inventory::addItem(const Item& item) {
    items.push_back(item);
}

void Inventory::useItem(int index, LivingBeing& target) {
    if (index >= 0 && index < items.size()) {
        items[index].useItem(target);
        items.erase(items.begin() + index);  // Entferne das Item nach Gebrauch
    } else {
        cout << "Ungültiger Index.\n";
    }
}

void Inventory::listItems() const {
    for (size_t i = 0; i < items.size(); ++i) {
        cout << i + 1 << ". " << items[i].getName() << "\n";
    }
}
