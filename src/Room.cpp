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
    // Generate items to buy
    std::vector<std::unique_ptr<Item>> items;
    for (size_t i = 0; i < 4; ++i) {
        items.push_back(ItemFactory::createRandomItem());
    }

    int choice = -1;

    while(choice != 0)
    {
        cout << "\nYour current balance is " << player.getBalance() << " coins." << endl;
        cout << "\n=== Shop Inventory ===\n";
        
        // Display available items with prices
        for (size_t i = 0; i < items.size(); i++) {
            cout << "\nItem " << (i + 1) << ":\n";
            items[i]->showItem();
            cout << "Price: " << items[i]->getPrice() << " coins\n";
            cout << "------------------------\n";
        }

        cout << "\nShop Menu:\n";
        cout << "1-" << items.size() << ": Buy item\n";
        cout << "(5) Sell an item from your bag\n";
        cout << "(0) Exit\n\n";

        cin >> choice;

        // Buy item flow
        if (choice > 0 && choice <= (int)items.size()) {
            if (player.getBalance() < items[choice - 1]->getPrice()) {
                cout << "Not enough coins!" << endl;
            } else {
                cout << items[choice - 1]->getName() << " bought!" << endl;
                player.setBalance(player.getBalance() - items[choice - 1]->getPrice());
                player.addItemToBag(std::move(items[choice - 1]));
                items.erase(items.begin() + (choice - 1));
            }
        }
        // Sell item flow
        else if (choice == 5) {
            auto &bag = player.getBag(); 
            if (bag.isEmpty()) {
                cout << "Your bag is empty!" << endl;
            } else {
                bag.displayItems();
                cout << "Enter item number to sell (0 to cancel): ";
                int sellChoice;
                cin >> sellChoice;
                
                // Valid choice check
                if (sellChoice > 0 && (size_t)sellChoice <= bag.size()) {
                    Item* itemPtr = bag.getItem(sellChoice - 1); 
                    int sellPrice = itemPtr->getPrice() / 2; 
                    cout << "Sold " << itemPtr->getName() 
                         << " for " << sellPrice << " coins." << endl;
                    player.setBalance(player.getBalance() + sellPrice);
                    bag.removeItem(sellChoice - 1);
                }
            }
        }
    }
}
