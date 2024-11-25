#include "Item.h"

Item::Item(const string& name, ItemType type, int value)
    : name(name), type(type), value(value) {}

std::string Item::getName() const {
    return name;
}

ItemType Item::getType() const {
    return type;
}

int Item::getValue() const {
    return value;
}

void Item::useItem(LivingBeing& target) {
    if (type == ItemType::Potion) {
        target.heal(value);
        cout << target.getName() << " wurde um " << value << " geheilt!\n";
    }
}
