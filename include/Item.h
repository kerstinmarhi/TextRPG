#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

using namespace std;

class Item {
private:
    string name;         
    string description; 

public:
    // constructor
    Item(const string& n, const string& d);

    // Getter-Methoden
    string getName() const;
    string getBeschreibung() const;

    // Method to use item
    void useItem();
    //Method to show item
    void showItem() const;

};

#endif
