#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "Item.h"

using namespace std;

class Inventory {
private:
    vector<Item> items;

public:
    void addItem(const Item& item);
    void useItem(int index, LivingBeing& target);
    void listItems() const;
};

#endif
