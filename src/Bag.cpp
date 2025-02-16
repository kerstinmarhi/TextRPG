#include "../include/Bag.h"
#include <iostream>
#include <algorithm>

using namespace std;

Bag::Bag() { }
void Bag::addItem(std::unique_ptr<Item> item) {
    cout << item->getName() << " added to bag." << endl;
    items.push_back(std::move(item));
}

void Bag::removeItem(size_t index) {
    if (index < items.size()) {
        cout << items[index]->getName() << " removed from bag." << endl;
        items.erase(items.begin() + index);
    }
}

void Bag::displayItems() const {
    cout << "\n--- Items in bag ---\n";
    if (items.empty()) {
        cout << "Bag is empty." << endl;
    } else {
        for (const auto& item : items) {
            cout << "- " << item->getName() << endl;
        }
    }
}

void Bag::useItem(size_t index, Player& player) {
    if (index >= items.size()) {
        cout << "Invalid item index!" << endl;
        return;
    }
    
    items[index]->use(player);
    
    // Remove consumables after use
    if (items[index]->getType() == ItemType::POTION || 
        items[index]->getType() == ItemType::FOOD) {
        removeItem(index);
    }
}

bool Bag::isEmpty() const{
    return items.empty();
};