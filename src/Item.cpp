#include "../include/Item.h"
#include "../include/Player.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

// constructor
Item::Item(const string& n, const string& d, ItemType t, ItemRarity r)
    : name(n)
    , description(d)
    , type(t)
    , rarity(r)
{
}

// Getter-Methoden
string Item::getName() const
{
    return name;
}

string Item::getDescription() const
{
    return description;
}

ItemType Item::getType() const
{
    return type;
}

ItemRarity Item::getRarity() const
{
    return rarity;
}

// Method to use Item
void Item::use(Player& player)
{
    cout << "Using item: " << name << endl;
}

// Method to get information about an item
void Item::showItem() const
{
    cout << "Item: " << name << endl;
    cout << "Description: " << description << endl;
    cout << "Rarity: " << static_cast<int>(rarity) << endl;
}

double Item::getRarityMultiplier(ItemRarity rarity)
{
    switch (rarity) {
    case ItemRarity::COMMON:
        return 1.0;
    case ItemRarity::UNCOMMON:
        return 1.2;
    case ItemRarity::RARE:
        return 1.5;
    case ItemRarity::EPIC:
        return 2.0;
    case ItemRarity::LEGENDARY:
        return 3.0;
    default:
        return 1.0;
    }
}

bool Item::operator==(const Item& other) const
{
    return name == other.name && description == other.description && type == other.type && rarity == other.rarity;
}

ItemRarity ItemFactory::rollRarity()
{
    int roll = rand() % 100;
    if (roll < 50)
        return ItemRarity::COMMON;
    if (roll < 80)
        return ItemRarity::UNCOMMON;
    if (roll < 95)
        return ItemRarity::RARE;
    if (roll < 99)
        return ItemRarity::EPIC;
    return ItemRarity::LEGENDARY;
}

unique_ptr<Item> ItemFactory::createRandomItem()
{
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation

    vector<unique_ptr<Item>> items;
    items.push_back(make_unique<Equipment>("Sword", "A sharp blade.", ItemType::WEAPON, rollRarity(), 10));
    items.push_back(make_unique<Equipment>("Shield", "A sturdy shield.", ItemType::ARMOUR, rollRarity(), 8));
    items.push_back(make_unique<Consumable>("Health Potion", "Restores health.", ItemType::POTION, rollRarity(), 20));
    items.push_back(make_unique<Consumable>("Mana Potion", "Restores mana.", ItemType::POTION, rollRarity(), 15));
    items.push_back(make_unique<Consumable>("Strength Potion", "Increases strength.", ItemType::STRENGTH_POTION, rollRarity(), 5));
    items.push_back(make_unique<Consumable>("Bread", "A loaf of bread.", ItemType::FOOD, rollRarity(), 5));
    items.push_back(make_unique<Equipment>("Helmet", "A protective helmet.", ItemType::ARMOUR, rollRarity(), 5));
    items.push_back(make_unique<Equipment>("Armor", "A suit of armor.", ItemType::ARMOUR, rollRarity(), 15));
    items.push_back(make_unique<Consumable>("Elixir", "A magical elixir.", ItemType::POTION, rollRarity(), 25));
    items.push_back(make_unique<Consumable>("Apple", "A fresh apple.", ItemType::FOOD, rollRarity(), 3));

    int randomIndex = rand() % items.size();
    return move(items[randomIndex]);
}

Equipment::Equipment(const string& n, const string& d, ItemType t, ItemRarity r, int bonus)
    : Item(n, d, t, r)
    , statBonus(bonus)
{
}

void Equipment::use(Player& player)
{
    cout << "Equipping: " << name << " with stat bonus: " << statBonus << endl;
}

void Equipment::showItem() const
{
    Item::showItem();
    cout << "Stat Bonus: " << statBonus << endl;
}

Consumable::Consumable(const string& n, const string& d, ItemType t, ItemRarity r, int power)
    : Item(n, d, t, r)
    , effectPower(power)
{
}

void Consumable::use(Player& player)
{
    cout << "Consuming: " << name << " with effect power: " << effectPower << endl;
}

void Consumable::showItem() const
{
    Item::showItem();
    cout << "Effect Power: " << effectPower << endl;
}
