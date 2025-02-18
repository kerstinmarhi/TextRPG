#include "../include/Item.h"
#include "../include/Player.h"
#include <iostream>
#include <random>
using namespace std;

// constructor
Item::Item(const string& n, const string& d, ItemType t, ItemRarity r, int p)
    : name(n)
    , description(d)
    , type(t)
    , rarity(r)
    , price(p)
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

int Item::getPrice() const
{
    return price;
}

ItemRarity Item::getRarity() const 
{
    return rarity;
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
    case ItemType::POISON_SPELL:
        cout << "Poison Spell" << endl;
        break;
    case ItemType::FIRE_SPELL:
        cout << "Fire Spell" << endl;
        break;
    case ItemType::FREEZE_SPELL:
        cout << "Freeze Spell" << endl;
        break;
    case ItemType::OTHER:
        cout << "Other" << endl;
        break;
    case ItemType::LIGHT_SPELL:
        cout << "Light Spell" << endl;
        break;
    case ItemType::HOLY_SPELL:
        cout << "Holy Spell" << endl;
        break;
    case ItemType::SILVER_SPELL:
        cout << "Silver Spell" << endl;
        break;
    case ItemType::BLUNT_SPELL:
        cout << "Blunt Spell" << endl;
        break;
    case ItemType::ICE_SPELL:
        cout << "Ice Spell" << endl;
        break;
    case ItemType::LIGHTNING_SPELL:
        cout << "Lightning Spell" << endl;
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
    static std::discrete_distribution<> d({ 32, 24, 20, 16, 8 }); // weights for each rarity

    return static_cast<ItemRarity>(d(gen));
}

std::unique_ptr<Item> ItemFactory::createRandomItem()
{
    ItemRarity rarity = rollRarity();
    
    // 10% chance to get a special weapon if the roll was already rare or better
    if (rarity >= ItemRarity::RARE && (rand() % 100) < 10) {
        vector<unique_ptr<Item>> specialWeapons;
        addSpecialWeapons(specialWeapons);
        
        // Pick a special weapon that matches or is better than the rolled rarity
        vector<unique_ptr<Item>> validChoices;
        for (auto& weapon : specialWeapons) {
            if (weapon->getRarity() >= rarity) {
                validChoices.push_back(std::move(weapon));
            }
        }
        
        if (!validChoices.empty()) {
            int choice = rand() % validChoices.size();
            return std::move(validChoices[choice]);
        }
    }
    
    int randomType = rand() % 17; // Updated to include new item types

    switch (randomType) {
    case 0:
        return std::make_unique<Equipment>("Sword", "A sharp blade",
            ItemType::WEAPON, rarity, 10, 5);
    case 1:
        return std::make_unique<Equipment>("Shield", "A sturdy shield",
            ItemType::ARMOUR, rarity, 20, 10);
    case 2:
        return std::make_unique<Consumable>("Health Potion", "Restores health",
            ItemType::POTION, rarity, 30, 20);
    case 3:
        return std::make_unique<Consumable>("Poison Spell", "Deals damage and slows enemies down",
            ItemType::POISON_SPELL, rarity, 40, 15);
    case 4:
        return std::make_unique<Consumable>("Strength Potion",
            "Temporarily increases attack power",
            ItemType::STRENGTH_POTION, rarity, 40, 15);
    case 5:
        return std::make_unique<Consumable>("Fire Spell", "Burns monsters alive",
            ItemType::FIRE_SPELL, rarity, 50, 30);
    case 6:
        return std::make_unique<Consumable>("Freeze Spell", "Monsters can't move quickly with this effect",
            ItemType::FREEZE_SPELL, rarity, 25, 5);
    case 7:
        return std::make_unique<Consumable>("Elixir", "A magical elixir",
            ItemType::POTION, rarity, 30, 35);
    case 8:
        return std::make_unique<Consumable>("Apple", "A fresh apple",
            ItemType::FOOD, rarity, 2, 3);
    case 9:
        return std::make_unique<Consumable>("Bread", "Fresh and tasty",
            ItemType::FOOD, rarity, 15, 10);
    case 10:
        return std::make_unique<Equipment>("Helmet", "A protective helmet",
            ItemType::ARMOUR, rarity, 10, 5);
    case 11:
        return std::make_unique<Equipment>("Armor", "A suit of armor",
            ItemType::ARMOUR, rarity, 20, 15);
    case 12:
        return std::make_unique<Consumable>("Energy Drink", "Boosts energy",
            ItemType::FOOD, rarity, 5, 10);
    case 13:
        return std::make_unique<Consumable>("Golden Apple", "Restores a large amount of health",
            ItemType::FOOD, rarity, 45, 50);
    case 15:
        return std::make_unique<Consumable>("Light Burst", "A blinding flash that banishes darkness",
            ItemType::LIGHT_SPELL, rarity, 35, 20);
    case 16:
        return std::make_unique<Consumable>("Holy Smite", "Sacred energy that punishes evil",
            ItemType::HOLY_SPELL, rarity, 45, 25);
    case 17:
        return std::make_unique<Consumable>("Silver Edge", "Enchants weapons with silver, deadly to certain creatures",
            ItemType::SILVER_SPELL, rarity, 40, 20);
    case 18:
        return std::make_unique<Consumable>("Impact Force", "Empowers blunt attacks",
            ItemType::BLUNT_SPELL, rarity, 30, 15);
    case 19:
        return std::make_unique<Consumable>("Ice Storm", "Summons a devastating winter storm",
            ItemType::ICE_SPELL, rarity, 40, 25);
    case 20:
        return std::make_unique<Consumable>("Thunder Strike", "Calls down lightning from above",
            ItemType::LIGHTNING_SPELL, rarity, 45, 30);
    default:
        return std::make_unique<Consumable>("Bread", "Fresh and tasty",
            ItemType::FOOD, rarity, 10, 10);
    }
}


Equipment::Equipment(const std::string& n, const std::string& d, ItemType t,
    ItemRarity r, int p, int bonus, int initBonus, int precBonus, int critBonus, Weakness elem)
    : Item(n, d, t, r, p)
    , statBonus(bonus * getRarityMultiplier(r))
    , initiativeBonus(initBonus)
    , precisionBonus(precBonus)
    , critChanceBonus(critBonus)
    , elementalBonus(elem)
{
}

void Equipment::use(Player& player) 
{
    player.equipItem(this);
}

void Equipment::showItem() const {
    Item::showItem();
    cout << "Effects:\n";
    
    // Show main stat bonus
    switch (getType()) {
    case ItemType::WEAPON:
        cout << "  +" << statBonus << " Attack Power\n";
        break;
    case ItemType::ARMOUR:
        cout << "  +" << statBonus << " Health\n";
        break;
    default:
        // Handle other cases silently
        break;
    }
    
    // Show additional bonuses
    if (initiativeBonus > 0)
        cout << "  +" << initiativeBonus << " Initiative\n";
    if (precisionBonus > 0)
        cout << "  +" << precisionBonus << " Precision\n";
    if (critChanceBonus > 0)
        cout << "  +" << critChanceBonus << "% Critical Chance\n";
    if (elementalBonus != Weakness::NONE) {
        cout << "  Imbued with ";
        switch (elementalBonus) {
            case Weakness::SILVER: cout << "Silver"; break;
            case Weakness::HOLY: cout << "Holy"; break;
            case Weakness::FIRE: cout << "Fire"; break;
            case Weakness::ICE: cout << "Ice"; break;
            case Weakness::LIGHTNING: cout << "Lightning"; break;
            case Weakness::LIGHT: cout << "Light"; break;
            case Weakness::POISON: cout << "Poison"; break;
            case Weakness::FREEZE: cout << "Freeze"; break;
            case Weakness::BLUNT: cout << "Blunt"; break;
            case Weakness::NONE: break;
        }
        cout << " power\n";
    }
}

void ItemFactory::addSpecialWeapons(vector<unique_ptr<Item>>& items) {
    // Rare weapons (1 bonus stat)
    items.push_back(make_unique<Equipment>(
        "Silver Sword", 
        "A finely crafted sword made of pure silver", 
        ItemType::WEAPON,
        ItemRarity::RARE,
        100, 15,  // base price and attack
        5, 0, 0,  // +5 initiative only
        Weakness::SILVER
    ));

    // Epic weapons (2 bonus stats)
    items.push_back(make_unique<Equipment>(
        "Holy Mace",
        "A blessed weapon that smites evil",
        ItemType::WEAPON,
        ItemRarity::EPIC,
        200, 25,  // base price and attack
        5, 10, 0, // +5 initiative, +10 precision
        Weakness::HOLY
    ));

    // Legendary weapons (all 3 bonus stats)
    items.push_back(make_unique<Equipment>(
        "Dragon's Fang",
        "A legendary blade crackling with lightning",
        ItemType::WEAPON,
        ItemRarity::LEGENDARY,
        500, 40,  // base price and attack
        10, 15, 5, // +10 initiative, +15 precision, +5% crit
        Weakness::LIGHTNING
    ));
}

Consumable::Consumable(const std::string& n, const std::string& d, ItemType t,
    ItemRarity r, int p, int power)
    : Item(n, d, t, r, p)
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
    case ItemType::POISON_SPELL:
        player.addSpellBonus(Weakness::POISON);
        player.setAPBonus(effectPower, 2);
        std::cout << "Used " << getName() << ". Attack increased by "
                  << effectPower << " for 2 turns! The enemy is slowed down!" << std::endl;
        break;
    case ItemType::FIRE_SPELL:
        player.addSpellBonus(Weakness::FIRE);
        player.setAPBonus(effectPower, 1);
        std::cout << "Used " << getName() << ". A fire blast with "
                  << effectPower << " damage has been released!" << std::endl;
        break;
    case ItemType::FREEZE_SPELL:
        player.addSpellBonus(Weakness::FREEZE);
        player.setAPBonus(effectPower, 3);
        std::cout << "Used " << getName() << ". Attack increased by "
                  << effectPower << " for 3 turns! The enemy is slowed down!" << std::endl;
        break;
    case ItemType::LIGHT_SPELL:
        player.addSpellBonus(Weakness::LIGHT);
        player.setAPBonus(effectPower, 2);
        std::cout << "Used " << getName() << ". Attack increased by "
                  << effectPower << " for 2 turns! Dark creatures are blinded!" << std::endl;
        break;
    case ItemType::HOLY_SPELL:
        player.addSpellBonus(Weakness::HOLY);
        player.setAPBonus(effectPower, 3);
        std::cout << "Used " << getName() << ". Attack increased by "
                  << effectPower << " for 3 turns! Evil beings writhe in pain!" << std::endl;
        break;
    case ItemType::SILVER_SPELL:
        player.addSpellBonus(Weakness::SILVER);
        player.setAPBonus(effectPower, 2);
        std::cout << "Used " << getName() << ". Attack increased by "
                  << effectPower << " for 2 turns! Your weapon gleams with silver!" << std::endl;
        break;
    case ItemType::BLUNT_SPELL:
        player.addSpellBonus(Weakness::BLUNT);
        player.setAPBonus(effectPower, 2);
        std::cout << "Used " << getName() << ". Attack increased by "
                  << effectPower << " for 2 turns! Your strikes gain crushing force!" << std::endl;
        break;
    case ItemType::ICE_SPELL:
        player.addSpellBonus(Weakness::ICE);
        player.setAPBonus(effectPower, 3);
        std::cout << "Used " << getName() << ". Attack increased by "
                  << effectPower << " for 3 turns! Freezing winds howl!" << std::endl;
        break;
    case ItemType::LIGHTNING_SPELL:
        player.addSpellBonus(Weakness::LIGHTNING);
        player.setAPBonus(effectPower, 1);
        std::cout << "Used " << getName() << ". A devastating lightning bolt with "
                  << effectPower << " damage strikes!" << std::endl;
        break;
    case ItemType::OTHER:
        std::cout << "Used " << getName() << ". It has a special effect!" << std::endl;
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
    case ItemType::STRENGTH_POTION: // Added missing description
        cout << "Temporarily increases Attack Power by " << effectPower << " for 3 turns";
        break;
    case ItemType::POISON_SPELL:
        cout << "Temporarily increases Attack Power by " << effectPower << " for 2 turns";
        break;
    case ItemType::FIRE_SPELL:
        cout << "Temporarily increases Attack Power by " << effectPower << " for one attack";
        break;
    case ItemType::FREEZE_SPELL:
        cout << "Temporarily increases Attack Power by " << effectPower << " for 3 turns";
        break;
    case ItemType::LIGHT_SPELL:
        cout << "Temporarily increases Attack Power by " << effectPower << " for 2 turns";
        break;
    case ItemType::HOLY_SPELL:
        cout << "Temporarily increases Attack Power by " << effectPower << " for 3 turns";
        break;
    case ItemType::SILVER_SPELL:
        cout << "Temporarily increases Attack Power by " << effectPower << " for 2 turns";
        break;
    case ItemType::BLUNT_SPELL:
        cout << "Temporarily increases Attack Power by " << effectPower << " for 2 turns";
        break;
    case ItemType::ICE_SPELL:
        cout << "Temporarily increases Attack Power by " << effectPower << " for 3 turns";
        break;
    case ItemType::LIGHTNING_SPELL:
        cout << "Temporarily increases Attack Power by " << effectPower << " for one attack";
        break;
    case ItemType::OTHER:
        cout << "Has a special effect";
        break;
    default:
        cout << "No effect";
    }
    cout << endl;
}
