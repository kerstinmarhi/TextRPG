#ifndef BAG_H
#define BAG_H

#include <vector>
#include <string>
#include "Item.h"
using namespace std;

class Bag {
public:
    Bag();

    void addItem(const Item& item);
    void removeItem(const Item& item);
    void displayItems() const;

private:
    vector<Item> items;
};

#endif