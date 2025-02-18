#include "../include/Game.h"
#include <iostream>
using namespace std;

Game::Game()
    : player("Hero")
{
    // Don’t call initializeRooms() here
    // That way, if you re-enter “Play,” it won’t reset the dungeon.
}

Game::~Game()
{
    // No need to manually delete rooms, unique_ptr will handle it
}

void Game::start()
{
    if (rooms.empty()) {
        initializeRooms();
    }
    cout << "Welcome to Dungeon-RPG!" << endl;
    mainMenu();
}

void Game::mainMenu()
{
    int choice;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Play \n";
        cout << "2. Player Stats\n";
        cout << "3. Bag\n";
        cout << "4. Exit Game\n";
        cout << "5. Restart Game\n"; // new option
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            // Just call explore(), no new calls to initializeRooms()
            explore();
            break;
        case 2:
            player.displayStats();
            break;
        case 3:
            player.openBag();
            break;
        case 4:
            cout << "Game ends. Till we meet again!" << endl;
            exit(0);
        case 5:
            // Explicitly reset everything
            resetGame();
            break;
        default:
            cout << "No such choice!";
        }
    } while (choice != 4);
}

void Game::resetGame()
{
    cout << "\n-- Restarting Game --\n";
    // Clear out existing rooms
    rooms.clear();

    // Re-create a fresh player
    player = Player("Hero");

    // Re-initialize the dungeon
    initializeRooms();
}

void Game::initializeRooms() {
    rooms.clear();

    // Room templates (name, description pairs)
    vector<pair<string, string>> roomTemplates = {
        {"Armory", "A room filled with old, rusty weapons and armor."},
        {"Library", "Shelves filled with dusty books line the walls."},
        {"Hidden Chamber", "A secret room hidden behind a false wall."},
        {"Dining Hall", "A grand hall with a long table set for a feast."},
        {"Treasury", "A room filled with glittering treasures and gold."},
        {"Prison", "A dark, damp room with cells lining the walls."},
        {"Garden", "An overgrown garden with strange, glowing plants."},
        {"Barracks", "A room with rows of beds and weapon racks."},
        {"Chapel", "A small chapel with an altar and pews."},
        {"Laboratory", "A room filled with strange equipment and bubbling potions."},
        {"Observatory", "A room with a large telescope and star charts."},
        {"Crypt", "A dark, eerie room filled with ancient tombs."}
    };

    // Boss room templates for each wave
    vector<pair<string, string>> bossRooms = {
        {"Throne Room", "A massive chamber with an ornate throne. The air feels heavy with malice."},
        {"Dragon's Lair", "A scorched chamber with piles of treasure and dragon scales."},
        {"Necropolis", "A vast underground city of the dead, filled with dark magic."},
        {"Hell Portal", "The final chamber, where reality itself seems to bend and twist."}
    };

    // Monster templates for each wave (name, description, weakness)
    vector<tuple<string, string, Weakness>> monsterTemplates = {
        {"Goblin", "A dubious little creature", Weakness::POISON},
        {"Orc", "A brutish orc", Weakness::FIRE},
        {"Dark Mage", "A mage who has succumbed to the dark arts", Weakness::LIGHT},
        {"Werewolf", "A ferocious werewolf", Weakness::SILVER},
        {"Troll", "A large, slow-moving troll", Weakness::FIRE},
        {"Vampire", "A blood-sucking vampire", Weakness::LIGHT},
        {"Skeleton", "A reanimated skeleton", Weakness::BLUNT},
        {"Shadow Assassin", "A silent killer lurking in the shadows", Weakness::LIGHT}
    };

    // Boss templates for each wave (name, description, weakness)
    vector<tuple<string, string, Weakness>> bossTemplates = {
        {"Hobgoblin Chief", "A massive, muscular goblin wearing crude but effective armor. A makeshift wooden crown sits upon its head.", Weakness::FREEZE},
        {"Ancient Dragon", "A fearsome dragon with scales as hard as steel", Weakness::LIGHTNING},
        {"Lich King", "An undead sorcerer of immense power", Weakness::HOLY},
        {"Demon Lord", "A being of pure evil and chaos", Weakness::ICE}
    };

    // Scaling factors for each wave
    vector<int> monsterHP = {20, 40, 60, 100};
    vector<int> monsterAP = {10, 15, 25, 35};
    vector<int> bossHP = {40, 60, 80, 120};
    vector<int> bossAP = {20, 25, 30, 45};
    vector<int> monsterXP = {50, 75, 100, 150};
    vector<int> bossXP = {200, 250, 350, 500};

    Room* prevRoom = nullptr;

    // Generate 4 waves of 5 rooms each
    for (int wave = 0; wave < 4; wave++) {
        // Create 4 normal rooms for this wave
        for (int room = 0; room < 4; room++) {
            // Randomly select a room template
            int roomIndex = rand() % roomTemplates.size();
            auto newRoom = make_unique<Room>(roomTemplates[roomIndex].first, 
                                          roomTemplates[roomIndex].second);

            // Randomly select a monster template
            int monsterIndex = rand() % monsterTemplates.size();
            auto& [monsterName, monsterDesc, monsterWeakness] = monsterTemplates[monsterIndex];
            
            // Create scaled monster
            newRoom->setMonster(make_unique<Monster>(
                monsterName, 
                monsterHP[wave], 
                monsterAP[wave],
                monsterWeakness,
                monsterDesc,
                monsterXP[wave]
            ));

            // Link rooms
            if (prevRoom) {
                prevRoom->addConnection(newRoom.get());
                newRoom->addConnection(prevRoom);
            }
            
            prevRoom = newRoom.get();
            rooms.push_back(std::move(newRoom));
        }

        // Create boss room for this wave
        string bossRoomName, bossRoomDesc;
        string bossName, bossDesc;
        Weakness bossWeakness;

        if (wave == 3) {
            // Final boss room is always Hell Portal with Demon Lord
            bossRoomName = "Hell Portal";
            bossRoomDesc = "The final chamber, where reality itself seems to bend and twist.";
            bossName = "Demon Lord";
            bossDesc = "A being of pure evil and chaos";
            bossWeakness = Weakness::HOLY;
        } else {
            // For other waves, use the templates as before
            auto& bossRoom = bossRooms[wave];
            bossRoomName = bossRoom.first;
            bossRoomDesc = bossRoom.second;
            
            auto& [name, desc, weakness] = bossTemplates[wave];
            bossName = name;
            bossDesc = desc;
            bossWeakness = weakness;
        }

        auto bossRoom = make_unique<Room>(bossRoomName, bossRoomDesc);
        
        // Create scaled boss
        bossRoom->setMonster(make_unique<Monster>(
            bossName,
            bossHP[wave],
            bossAP[wave],
            bossWeakness,
            bossDesc,
            bossXP[wave]
        ));

        bossRoom->setIsBossRoom(true);

        // Link boss room
        if (prevRoom) {
            prevRoom->addConnection(bossRoom.get());
            bossRoom->addConnection(prevRoom);
        }

        prevRoom = bossRoom.get();
        rooms.push_back(std::move(bossRoom));
    }

    // Set starting room
    currentRoom = rooms[0].get();
    currentRoom->setVisited(true);  // Mark starting room as visited
}

void Game::explore()
{
    // Mark current room as visited immediately
    currentRoom->setVisited(true);
    
    cout << currentRoom->getDescription() << endl;

    // Check for monster
    if (currentRoom->getMonster() != nullptr) {
        if (currentRoom->getIsBossRoom()) {
            cout << "\n!!! BOSS ENCOUNTER !!!\n";
        }
        cout << "You encountered a monster!\n";
        combat(currentRoom->getMonster());

        // Spawn chest after defeating monster
        if (player.isAlive()) {
            currentRoom->setHasChest(true);
        }

        if (player.isAlive()) {
            if (currentRoom->getIsBossRoom()) {
                player.setBalance(player.getBalance() + 100);
                cout << "Player gained 100 coins!" << endl;
            } else {
                player.setBalance(player.getBalance() + 25);
                cout << "Player gained 25 coins!" << endl;
            }
        }

        // Remove monster after combat
        currentRoom->setMonster(nullptr);
    }

    // Check for chest
    if (currentRoom->getHasChest() && !currentRoom->getChestLooted()) {
        cout << "\nThere's a chest in this room!" << endl;
        cout << "Do you want to open it? (1: Yes, 0: No): ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            currentRoom->lootChest(player);
        }
    }

    if(currentRoom->getIsBossRoom()) {
        cout << "\nYou can buy something from the boss shop!" << endl;
        cout << "Do you want to buy something? (1: Yes, 0: No): ";
        int buyChoice;
        cin >> buyChoice;

        if (buyChoice == 1) {
            currentRoom->openShop(player);
        }
    }

    // Only show connections to unvisited rooms
    vector<Room*> connections = currentRoom->getConnections();
    vector<Room*> availableRooms;
    
    cout << "\nAvailable paths forward:\n";
    int validChoice = 1;
    for (Room* room : connections) {
        if (!room->wasVisited()) {  // Only show unvisited rooms
            cout << validChoice << ". " << room->getName() << endl;
            availableRooms.push_back(room);
            validChoice++;
        }
    }

    if (availableRooms.empty()) {
        cout << "\nNo more paths forward. Returning to menu.\n";
        return;
    }

    cout << "\nChoose a direction (0 to return to menu): ";
    int choice;
    cin >> choice;

    // If the user picks a valid room, move there and continue exploring
    if (choice > 0 && choice <= static_cast<int>(availableRooms.size())) {
        Room* nextRoom = availableRooms[choice - 1];
        currentRoom = nextRoom;
        explore(); // Recursively call explore to continue traveling
    }
}


void performMonsterTurn(Player& player, Monster* monster)
{
    // Monster's turn if still alive
    if (monster->getHealth() > 0) {
        if (player.hasSpellBonus(monster->getWeakness()))
        {
            monster->attack();
            cout << "But is weak due to a spell effect! (x0.75 attack damage)" << endl;
            player.takeDamage(monster->getAttack() * 0.75);
        } else {
            monster->attack();
            player.takeDamage(monster->getAttack());
        }
    }
}

void Game::combat(Monster* monster) {

    cout << "\n=== Combat Started ===\n";
    monster->showMonster();

    int turnCount = 0;

    while (player.isAlive() && monster->getHealth() > 0) {
        turnCount++;
        cout << "\n=== Turn " << turnCount << " ===\n";

        // Display combat status at the start of each turn
        cout << "\n--- Combat Status ---\n";
        cout << "Player HP: " << player.getHealth() << "\n";
        cout << monster->getName() << " HP: " << monster->getHealth() << "\n";
        if (player.getTempAPBonus() > 0) {
            cout << "Attack Bonus: +" << player.getTempAPBonus()
                 << " (" << player.getTempAPDuration() << " turns remaining)\n";
        }
        cout << "-------------------\n";

        // Player's turn
        cout << "\nYour turn:\n";
        cout << "1. Attack\n2. Use Item\n";
        cout << "Choose action: ";
        int choice;
        cin >> choice;


        if (choice == 2) {
            player.openBag();
        }

        // determine who starts
        if(player.isInLikelihood(player.getInitiative()))
        {
            player.attack(*monster);
            performMonsterTurn(player, monster);
        } else {
            performMonsterTurn(player, monster);
            player.attack(*monster);

        }

        // Update buff durations
        player.updateBuffs();
    }

    // Show final combat status
    cout << "\n=== Combat Ended ===\n";
    cout << "Player HP: " << player.getHealth() << "\n";
    cout << monster->getName() << " HP: " << monster->getHealth() << "\n";

    // After the fight ends:
    if (player.isAlive()) {
        cout << "You defeated the " << monster->getName() << "!\n";
        player.addXP(monster->getXPReward());
    } else {
        cout << "Game Over! You were defeated by " << monster->getName() << "!\n";
        cout << "\nChoose an option:\n1) Restart Game\n2) Exit\n> ";
        int deathChoice;
        cin >> deathChoice;
        if (deathChoice == 1) {
            resetGame();
            mainMenu(); // Return to main menu after reset
        } else {
            cout << "Exiting the game. Till we meet again!\n";
            exit(0); // Terminates the application
        }
    }
}