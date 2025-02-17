#include "../include/Room.h"
#include "../include/Item.h"
#include "../include/Player.h"

Room::Room(const string& name, const string& desc) 
    : name(name), description(desc), monster(nullptr), hasChest(false), chestLooted(false), isBossRoom(false) {}

string Room::getName() const {
    return name;
}

std::string Room::getDescription() const {
    return description;
}

void Room::setMonster(std::unique_ptr<Monster> m) {
    monster = std::move(m);
}

Monster* Room::getMonster() {
    return monster.get();
}

void Room::addConnection(Room* room) {
    connections.push_back(room);
}

std::vector<Room*> Room::getConnections() {
    return connections;
}

void Room::lootChest(Player& player) {
    if (!hasChest || chestLooted) {
        cout << "No chest to loot here." << endl;
        return;
    }

    cout << "\nYou found a " << (isBossRoom ? "boss " : "") << "chest!" << endl;
    
    int itemCount = isBossRoom ? 3 : 1;
    
    for(int i = 0; i < itemCount; i++) {
        auto item = ItemFactory::createRandomItem();
        cout << "\nItem " << (i + 1) << ":" << endl;
        item->showItem();
        player.addItemToBag(std::move(item));
    }
    
    chestLooted = true;
}

void Room::openShop(Player& player)
{
    std::vector<std::unique_ptr<Item>> items;

    // 4 items will be randomly generated
    for (size_t i = 0; i < 4; ++i) {
        items.push_back(ItemFactory::createRandomItem());
    }

    int choice = 1;

    while(choice != 0)
    {
        cout << "\nYour current balance is " << player.getBalance() << " coins." << endl;
        cout << "Which item would you like to choose?" << endl;

        for (int i = 0; i < (int)items.size(); ++i) {
            cout << i + 1 << ". " << items[i]->getName() << "(" << items[i]->getPrice() << " coins)" << std::endl;
        }
        cout << "(0) if you want to exit: ";

        cin >> choice;

        if (choice != 0)
        {
            if (player.getBalance() < items[choice-1]->getPrice())
            {
                cout << "Not enough coins!" << endl;
            }
            else
            {
                cout << items[choice-1]->getName() << " successfully bought!" << endl;
                player.setBalance(player.getBalance() - items[choice-1]->getPrice());
                player.addItemToBag(std::move(items[choice-1]));
                items.erase(items.begin() + (choice - 1));
            }
        }
    }
}
