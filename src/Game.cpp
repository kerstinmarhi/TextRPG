#include "../include/Game.h"
#include <iostream>
using namespace std;

Game::Game() : player("Hero") {
    // Don’t call initializeRooms() here
    // That way, if you re-enter “Play,” it won’t reset the dungeon.
}

Game::~Game() {
    // No need to manually delete rooms, unique_ptr will handle it
}

void Game::start() {
    if (rooms.empty()) {
        initializeRooms();
    }
    cout << "Welcome to Dungeon-RPG!" << endl;
    mainMenu();
}

void Game::mainMenu() {
    int choice;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Play \n";
        cout << "2. Player Stats\n";
        cout << "3. Bag\n";
        cout << "4. Exit Game\n";
        cout << "5. Restart Game\n";   // new option
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

void Game::resetGame() {
    cout << "\n-- Restarting Game --\n";
    // Clear out existing rooms
    rooms.clear();

    // Re-create a fresh player
    player = Player("Hero");

    // Re-initialize the dungeon
    initializeRooms();
}

void Game::initializeRooms() {
    auto entrance = make_unique<Room>("The Beginning", "You are at the dungeon entrance. Torches flicker on the walls.");
    auto hallway = make_unique<Room>("Endless Darkness", "A long dark hallway stretches before you.");
    auto bossRoom = make_unique<Room>("Throne Room", "A massive chamber with an ornate throne. The air feels heavy with malice.");

    entrance->addConnection(hallway.get());
    hallway->addConnection(entrance.get());
    hallway->addConnection(bossRoom.get());
    bossRoom->addConnection(hallway.get());

    rooms.push_back(std::move(entrance));
    rooms.push_back(std::move(hallway));
    rooms.push_back(std::move(bossRoom));

    rooms[1]->setMonster(make_unique<Monster>("Goblin", 50, 10, 0.4, 2.0, "A dubious little creature", 20));
    rooms[2]->setMonster(make_unique<Monster>("Hobgoblin Chief", 150, 25, 0.2, 1.5,
        "A massive, muscular goblin wearing crude but effective armor. A makeshift wooden crown sits upon its head.", 100));
    rooms[2]->setIsBossRoom(true);

    currentRoom = rooms[0].get();
}

void Game::explore() {
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

    // Show available exits
    vector<Room*> connections = currentRoom->getConnections();
    cout << "\nAvailable exits:\n";
    for (size_t i = 0; i < connections.size(); i++) {
        cout << (i + 1) << ". " << connections[i]->getName() << endl;
    }

    // Ask the user which room to move to
    int choice;
    cout << "\nChoose a direction (0 to return to menu): ";
    cin >> choice;

    // If the user picks a valid room, move there and continue exploring
    if (choice > 0 && choice <= static_cast<int>(connections.size())) {
        currentRoom = connections[choice - 1];
        explore(); // Recursively call explore to continue traveling
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
        
        if (choice == 1) {
            player.attack(*monster);
        } else if (choice == 2) {
            player.openBag();
        }
        
        // Monster's turn if still alive
        if (monster->getHealth() > 0) {
            monster->attack();
            player.takeDamage(monster->getAttack());
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