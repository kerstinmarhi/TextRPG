#include "../include/Game.h"
#include <iostream>
using namespace std;

Game::Game() : player("Hero") { }

void Game::start() {
    cout << "Welcome to Dungeon-RPG!" << endl;
    mainMenu();
}

void Game::mainMenu() {
    int choice;

    //Game loop
    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Discover\n2. Player Stats\n3. Exit Game\n";
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
                cout << "Game ends. Till we meet again!" << endl;
                break;
            default:
                cout << "No such choice!" << endl;
        }
    } while (choice != 3);
}

void Game::explore() {
    dungeon.explore();
}