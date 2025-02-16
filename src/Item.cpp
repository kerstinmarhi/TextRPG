#include "../include/Item.h"
#include "../include/Player.h"
#include <iostream>
#include <random>
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

// Method to use Item
void Item::use(Player& player)
{
    (void)player; // marks 'player' as intentionally unused.
    /**
     * @brief
     * If you want to use player later in this method, feel
     * free to delete this line. It only exists because
     * the compiler warnings annoyed me.
     */

    cout << "You use the item: " << name << endl;
}

// Method to get information about an item
void Item::showItem() const
{
    cout << "\n=== Item Information ===\n";
    cout << "Name: " << name << endl;
    cout << "Description: " << description << endl;
    cout << "Type: ";
    switch (type) {
    case ItemType::FOOD:
        cout << "Food" << endl;
        break;
    case ItemType::POTION:
        cout << "Potion" << endl;
        break;
    case ItemType::STRENGTH_POTION: // Missing case
        std::cout << "Strength Potion" << endl;
        break;
    case ItemType::WEAPON:
        cout << "Weapon" << endl;
        break;
    case ItemType::ARMOUR:
        cout << "Armour" << endl;
        break;
    case ItemType::OTHER:
        cout << "Other" << endl;
        break;
    default:
        std::cout << "Unknown item type!\n"; // just in case
        break;
    }
    cout << "Rarity: ";
    switch (rarity) {
    case ItemRarity::COMMON:
        cout << "Common";
        break;
    case ItemRarity::UNCOMMON:
        cout << "Uncommon";
        break;
    case ItemRarity::RARE:
        cout << "Rare";
        break;
    case ItemRarity::EPIC:
        cout << "Epic";
        break;
    case ItemRarity::LEGENDARY:
        cout << "Legendary";
        break;
    default:
        cout << "No such thing as rarity.";
        break;
    }
    cout << " (x" << getRarityMultiplier(rarity) << " multiplier)\n";
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
    return name == other.name; // Two items are the same when they have identical names.
}

ItemRarity ItemFactory::rollRarity()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::discrete_distribution<> d({ 50, 30, 15, 4, 1 }); // weights for each rarity

    return static_cast<ItemRarity>(d(gen));
}

std::unique_ptr<Item> ItemFactory::createRandomItem()
{
    ItemRarity rarity = rollRarity();
    int randomType = rand() % 5; // Updated to include new item type

    switch (randomType) {
    case 0:
        return std::make_unique<Equipment>("Sword", "A sharp blade",
            ItemType::WEAPON, rarity, 5);
    case 1:
        return std::make_unique<Equipment>("Shield", "A sturdy shield",
            ItemType::ARMOUR, rarity, 10);
    case 2:
        return std::make_unique<Consumable>("Health Potion", "Restores health",
            ItemType::POTION, rarity, 20);
    case 4:
        return std::make_unique<Consumable>("Strength Potion",
            "Temporarily increases attack power",
            ItemType::STRENGTH_POTION, rarity, 15);
    default:
        return std::make_unique<Consumable>("Bread", "Fresh and tasty",
            ItemType::FOOD, rarity, 10);
    }
}

Equipment::Equipment(const std::string& n, const std::string& d, ItemType t,
    ItemRarity r, int bonus)
    : Item(n, d, t, r)
    , statBonus(bonus * getRarityMultiplier(r))
{
}

void Equipment::use(Player& player)
{
    player.equipItem(this);
}

void Equipment::showItem() const
{
    Item::showItem();
    cout << "Effect: ";
    switch (getType()) {
    case ItemType::WEAPON:
        cout << "+" << statBonus << " Attack Power";
        break;
    case ItemType::ARMOUR:
        cout << "+" << statBonus << " Health";
        break;
    default:
        cout << "No effect";
    }
    cout << endl;
}

Consumable::Consumable(const std::string& n, const std::string& d, ItemType t,
    ItemRarity r, int power)
    : Item(n, d, t, r)
    , effectPower(power * getRarityMultiplier(r))
{
}

void Consumable::use(Player& player)
{
    switch (getType()) {
    case ItemType::POTION:
        player.setHealth(player.getHealth() + effectPower);
        std::cout << "Used " << getName() << ". Restored "
                  << std::min(effectPower,
                         player.getMaxHealth() - player.getHealth())
                  << " health! (" << player.getHealth() << "/"
                  << player.getMaxHealth() << ")" << std::endl;
        break;
    case ItemType::STRENGTH_POTION:
        player.setAPBonus(effectPower, 3); // Add temporary attack bonus for 3 turns
        std::cout << "Used " << getName() << ". Attack increased by "
                  << effectPower << " for 3 turns!" << std::endl;
        break;
    case ItemType::FOOD:
        player.setHealth(player.getHealth() + effectPower / 2);
        std::cout << "Ate " << getName() << ". Restored "
                  << std::min(effectPower / 2,
                         player.getMaxHealth() - player.getHealth())
                  << " health! (" << player.getHealth() << "/"
                  << player.getMaxHealth() << ")" << std::endl;
        break;
    default:
        std::cout << "This item cannot be consumed." << std::endl;
    }
}

void Consumable::showItem() const
{
    Item::showItem();
    cout << "Effect: ";
    switch (getType()) {
    case ItemType::POTION:
        cout << "Restores " << effectPower << " Health";
        break;
    case ItemType::FOOD:
        cout << "Restores " << effectPower / 2 << " Health";
        break;
    default:
        cout << "No effect";
    }
    cout << endl;
}
