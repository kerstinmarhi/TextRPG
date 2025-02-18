#ifndef ITEM_H
#define ITEM_H

#include <memory>
#include <string>
#include <vector>  // Add this
#include "Monster.h" // Add this for Weakness enum

// Declaration forwarding
class Player;

enum class ItemType {
    WEAPON,
    ARMOUR,
    POTION,
    FOOD,
    STRENGTH_POTION,
    POISON_SPELL,
    FIRE_SPELL,
    FREEZE_SPELL,
    OTHER,
    LIGHT_SPELL,
    HOLY_SPELL,
    SILVER_SPELL,
    BLUNT_SPELL,
    ICE_SPELL,
    LIGHTNING_SPELL
};

enum class ItemRarity {
    COMMON, // 1.0x multiplier, 50% chance
    UNCOMMON, // 1.2x multiplier, 30% chance
    RARE, // 1.5x multiplier, 15% chance
    EPIC, // 2.0x multiplier, 4% chance
    LEGENDARY // 3.0x multiplier, 1% chance
};

class Item {
protected:
    std::string name;
    std::string description;
    ItemType type;
    ItemRarity rarity;
    int price;

public:
    Item(const std::string& n, const std::string& d, ItemType t, ItemRarity r, int p);
    virtual ~Item() = default;

    // Delete copy constructor and assignment to prevent memory issues
    Item(const Item&) = delete;
    Item& operator=(const Item&) = delete;

    // Add move constructor and assignment
    Item(Item&&) noexcept = default;
    Item& operator=(Item&&) noexcept = default;

    // Getters
    std::string getName() const;
    std::string getDescription() const;
    ItemType getType() const;
    ItemRarity getRarity() const;
    int getPrice() const;

    virtual void use(Player& player);
    virtual void showItem() const;
    bool operator==(const Item& other) const;

    static double getRarityMultiplier(ItemRarity rarity);
};

class Equipment : public Item {
protected:
    int statBonus;
    int initiativeBonus;    
    int precisionBonus;     
    int critChanceBonus;    
    Weakness elementalBonus; 
public:
    Equipment(const std::string& n, const std::string& d, ItemType t,
        ItemRarity r, int p, int bonus, int initBonus = 0, int precBonus = 0, int critBonus = 0,
        Weakness elem = Weakness::NONE);
    void use(Player& player) override;
    void showItem() const override;
    int getStatBonus() const { return statBonus; }
    int getInitiativeBonus() const { return initiativeBonus; }
    int getPrecisionBonus() const { return precisionBonus; }
    int getCritChanceBonus() const { return critChanceBonus; }
    Weakness getElementalBonus() const { return elementalBonus; }
};

class Consumable : public Item {
protected:
    int effectPower;

public:
    Consumable(const std::string& n, const std::string& d, ItemType t,
        ItemRarity r, int p, int power);
    void use(Player& player) override;
    void showItem() const override;
};

class ItemFactory {
public:
    static std::unique_ptr<Item> createRandomItem();
    static ItemRarity rollRarity();
    static void addSpecialWeapons(std::vector<std::unique_ptr<Item>>& items); // Add std::
};

#endif
