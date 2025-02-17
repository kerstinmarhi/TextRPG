#include "../include/Room.h"
#include "../include/Item.h"
#include "../include/Player.h"

Room::Room(const string& name, const string& desc)
    : name(name)
    , description(desc)
    , monster(nullptr)
    , hasChest(false)
    , chestLooted(false)
    , isBossRoom(false)
{
}

//--------- Getter methods ----------------------
string Room::getName() const
{
    return name;
}

std::string Room::getDescription() const
{
    return description;
}

Monster* Room::getMonster()
{
    return monster.get();
}

std::vector<Room*> Room::getConnections()
{
    return connections;
}

//--------- Setter methods ----------------------
void Room::setMonster(std::unique_ptr<Monster> m)
{
    monster = std::move(m);
}

//--------- Other methods ----------------------
void Room::addConnection(Room* room)
{
    connections.push_back(room);
}

void Room::lootChest(Player& player)
{
    if (!hasChest || chestLooted) {
        cout << "No chest to loot here." << endl;
        return;
    }

    cout << "\nYou found a " << (isBossRoom ? "boss " : "") << "chest!" << endl;

    int itemCount = isBossRoom ? 3 : 1;

    for (int i = 0; i < itemCount; i++) {
        auto item = ItemFactory::createRandomItem();
        cout << "\nItem " << (i + 1) << ":" << endl;
        item->showItem();
        player.addItemToBag(std::move(item));
    }

    chestLooted = true;
}
