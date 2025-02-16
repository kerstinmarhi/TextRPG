#ifndef BAG_H
#define BAG_H

#include <vector>
#include <string>
#include "Item.h"
using namespace std;

class Bag {
public:
    Bag();
    void addItem(unique_ptr<Item> item);
    void removeItem(size_t index);
    void displayItems() const;
    void useItem(size_t index, Player& player);
    bool isEmpty() const;
private:
    vector<unique_ptr<Item>> items;
};

#endif