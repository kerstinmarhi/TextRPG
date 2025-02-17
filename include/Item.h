#ifndef ITEM_H
#define ITEM_H

#include <memory>
#include <string>

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
    OTHER
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

public:
    Item(const std::string& n, const std::string& d, ItemType t, ItemRarity r);
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

    virtual void use(Player& player);
    virtual void showItem() const;
    bool operator==(const Item& other) const;

    static double getRarityMultiplier(ItemRarity rarity);
};

class Equipment : public Item {
protected:
    int statBonus;

public:
    Equipment(const std::string& n, const std::string& d, ItemType t,
        ItemRarity r, int bonus);
    void use(Player& player) override;
    void showItem() const override;
    int getStatBonus() const { return statBonus; }
};

class Consumable : public Item {
protected:
    int effectPower;

public:
    Consumable(const std::string& n, const std::string& d, ItemType t,
        ItemRarity r, int power);
    void use(Player& player) override;
    void showItem() const override;
};

class ItemFactory {
public:
    static std::unique_ptr<Item> createRandomItem();
    static ItemRarity rollRarity();
};

#endif
