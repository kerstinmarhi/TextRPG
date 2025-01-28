#include "../include/Game.h"
#include <iostream>
using namespace std;

Game::Game() : player("Hero") {
    initializeRooms();
}

Game::~Game() {
    for(Room* room : rooms) {
        delete room;
    }
}

void Game::start() {
    cout << "Welcome to Dungeon-RPG!" << endl;
    mainMenu();
}

void Game::mainMenu() {
    int choice;

    //Game loop
    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Discover\n2. Player Stats\n3. Bag\n4. Exit Game\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
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
                break;
            default:
                cout << "No such choice!";
        }
    } while (choice != 4);
}

void Game::initializeRooms() {
    Room* entrance = new Room("The Beginning", "You are at the dungeon entrance. Torches flicker on the walls.");
    Room* hallway = new Room("Endless Darkness", "A long dark hallway stretches before you.");
    
    entrance->addConnection(hallway);
    hallway->addConnection(entrance);
    
    rooms.push_back(entrance);
    rooms.push_back(hallway);
    
    currentRoom = entrance;

    // Add a monster to the hallway
    Monster* goblin = new Monster("Goblin", 50, 10, "A dubious little creature");
    hallway->setMonster(goblin);
}

void Game::explore() {
    cout << currentRoom->getDescription() << endl;
    
    // Check for monster
    if (currentRoom->getMonster() != nullptr) {
        cout << "You encountered a monster!\n";
        combat(currentRoom->getMonster());
        // Remove monster after combat
        currentRoom->setMonster(nullptr);
    }

    vector<Room*> connections = currentRoom->getConnections();
    cout << "\nAvailable exits:";
    for (size_t i = 0; i < connections.size(); i++) {
        cout << i + 1 << ". Go to next room";
    }
    
    int choice;
    cout << "Choose a direction (0 to return to menu): ";
    cin >> choice;
    
    if (choice > 0 && choice <= static_cast<int>(connections.size())) {
        currentRoom = connections[choice - 1];
    }
}

void Game::combat(Monster* monster) {
    cout << "\n=== Combat Started ===\n";
    monster->showMonster();

    while (player.isAlive() && monster->getHealth() > 0) {
        // Player's turn
        player.attack(*monster);
        
        // Monster's turn if still alive
        if (monster->getHealth() > 0) {
            monster->attack();
            player.takeDamage(monster->getAttack());
        }

        // Display current status
        player.displayStats();
    }

    if (player.isAlive()) {
        cout << "You defeated the " << monster->getName() << "!";
        player.setLevel(player.getLevel() + 1); // Level up after victory
    } else {
        cout << "Game Over! You were defeated by " << monster->getName() << endl;
    }

}