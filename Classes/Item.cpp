#include "Item.h"

Item::Item(const string& name, ItemType type, int value)
    : name(name), type(type), value(value) {}

string Item::getName() const {
    return name;
}

ItemType Item::getType() const {
    return type;
}

int Item::getValue() const {
    return value;
}

void Item::useItem(LivingBeing& target) {
    switch (type) {
        case ItemType::Potion:
            std::cout << "Verwende " << name << " auf " << target.getName() << ". Heilt " << value << " HP.\n";
            target.heal(value);
            break;
        case ItemType::Weapon:
            std::cout << "Waffe " << name << " erhöht den Angriff von " << target.getName() << " um " << value << ".\n";
           // target.increaseAttack(value);
            break;
        case ItemType::Armor:
            std::cout << "Rüstung " << name << " verringert den erlittenen Schaden für " << target.getName() << ".\n";
            // Logik zur Schadensminderung könnte hier hinzugefügt werden
            break;
        default:
            std::cout << "Unbekannter Item-Typ!\n";
            break;
    }
}
