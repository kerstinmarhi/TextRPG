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

void Game::initializeRooms()
{
    void Game::initializeRooms()
    {
        auto entrance = make_unique<Room>("The Beginning", "You are at the dungeon entrance. Torches flicker on the walls.");
        auto hallway = make_unique<Room>("Endless Darkness", "A long dark hallway stretches before you.");
        auto bossRoom = make_unique<Room>("Throne Room", "A massive chamber with an ornate throne. The air feels heavy with malice.");
        auto armory = make_unique<Room>("Armory", "A room filled with old, rusty weapons and armor.");
        auto library = make_unique<Room>("Library", "Shelves filled with dusty books line the walls.");
        auto hiddenChamber = make_unique<Room>("Hidden Chamber", "A secret room hidden behind a false wall.");
        auto diningHall = make_unique<Room>("Dining Hall", "A grand hall with a long table set for a feast.");
        auto treasury = make_unique<Room>("Treasury", "A room filled with glittering treasures and gold.");
        auto prison = make_unique<Room>("Prison", "A dark, damp room with cells lining the walls.");
        auto garden = make_unique<Room>("Garden", "An overgrown garden with strange, glowing plants.");
        auto barracks = make_unique<Room>("Barracks", "A room with rows of beds and weapon racks.");
        auto chapel = make_unique<Room>("Chapel", "A small chapel with an altar and pews.");
        auto laboratory = make_unique<Room>("Laboratory", "A room filled with strange equipment and bubbling potions.");
        auto observatory = make_unique<Room>("Observatory", "A room with a large telescope and star charts.");
        auto crypt = make_unique<Room>("Crypt", "A dark, eerie room filled with ancient tombs.");
        auto armory2 = make_unique<Room>("Armory 2", "Another room filled with old, rusty weapons and armor.");
        auto library2 = make_unique<Room>("Library 2", "Another room filled with dusty books.");
        auto hiddenChamber2 = make_unique<Room>("Hidden Chamber 2", "Another secret room hidden behind a false wall.");
        auto diningHall2 = make_unique<Room>("Dining Hall 2", "Another grand hall with a long table set for a feast.");
        auto treasury2 = make_unique<Room>("Treasury 2", "Another room filled with glittering treasures and gold.");
        auto prison2 = make_unique<Room>("Prison 2", "Another dark, damp room with cells lining the walls.");
        auto garden2 = make_unique<Room>("Garden 2", "Another overgrown garden with strange, glowing plants.");
        auto barracks2 = make_unique<Room>("Barracks 2", "Another room with rows of beds and weapon racks.");
        auto chapel2 = make_unique<Room>("Chapel 2", "Another small chapel with an altar and pews.");
        auto laboratory2 = make_unique<Room>("Laboratory 2", "Another room filled with strange equipment and bubbling potions.");
        auto observatory2 = make_unique<Room>("Observatory 2", "Another room with a large telescope and star charts.");
        auto crypt2 = make_unique<Room>("Crypt 2", "Another dark, eerie room filled with ancient tombs.");

        entrance->addConnection(hallway.get());
        hallway->addConnection(entrance.get());
        hallway->addConnection(bossRoom.get());
        bossRoom->addConnection(hallway.get());
        hallway->addConnection(armory.get());
        armory->addConnection(hallway.get());
        hallway->addConnection(library.get());
        library->addConnection(hallway.get());
        library->addConnection(hiddenChamber.get());
        hiddenChamber->addConnection(library.get());
        hallway->addConnection(diningHall.get());
        diningHall->addConnection(hallway.get());
        diningHall->addConnection(treasury.get());
        treasury->addConnection(diningHall.get());
        hallway->addConnection(prison.get());
        prison->addConnection(hallway.get());
        hallway->addConnection(garden.get());
        garden->addConnection(hallway.get());
        hallway->addConnection(barracks.get());
        barracks->addConnection(hallway.get());
        hallway->addConnection(chapel.get());
        chapel->addConnection(hallway.get());
        hallway->addConnection(laboratory.get());
        laboratory->addConnection(hallway.get());
        hallway->addConnection(observatory.get());
        observatory->addConnection(hallway.get());
        hallway->addConnection(crypt.get());
        crypt->addConnection(hallway.get());
        hallway->addConnection(armory2.get());
        armory2->addConnection(hallway.get());
        hallway->addConnection(library2.get());
        library2->addConnection(hallway.get());
        library2->addConnection(hiddenChamber2.get());
        hiddenChamber2->addConnection(library2.get());
        hallway->addConnection(diningHall2.get());
        diningHall2->addConnection(hallway.get());
        diningHall2->addConnection(treasury2.get());
        treasury2->addConnection(diningHall2.get());
        hallway->addConnection(prison2.get());
        prison2->addConnection(hallway.get());
        hallway->addConnection(garden2.get());
        garden2->addConnection(hallway.get());
        hallway->addConnection(barracks2.get());
        barracks2->addConnection(hallway.get());
        hallway->addConnection(chapel2.get());
        chapel2->addConnection(hallway.get());
        hallway->addConnection(laboratory2.get());
        laboratory2->addConnection(hallway.get());
        hallway->addConnection(observatory2.get());
        observatory2->addConnection(hallway.get());
        hallway->addConnection(crypt2.get());
        crypt2->addConnection(hallway.get());

        rooms.push_back(std::move(entrance));
        rooms.push_back(std::move(hallway));
        rooms.push_back(std::move(bossRoom));
        rooms.push_back(std::move(armory));
        rooms.push_back(std::move(library));
        rooms.push_back(std::move(hiddenChamber));
        rooms.push_back(std::move(diningHall));
        rooms.push_back(std::move(treasury));
        rooms.push_back(std::move(prison));
        rooms.push_back(std::move(garden));
        rooms.push_back(std::move(barracks));
        rooms.push_back(std::move(chapel));
        rooms.push_back(std::move(laboratory));
        rooms.push_back(std::move(observatory));
        rooms.push_back(std::move(crypt));
        rooms.push_back(std::move(armory2));
        rooms.push_back(std::move(library2));
        rooms.push_back(std::move(hiddenChamber2));
        rooms.push_back(std::move(diningHall2));
        rooms.push_back(std::move(treasury2));
        rooms.push_back(std::move(prison2));
        rooms.push_back(std::move(garden2));
        rooms.push_back(std::move(barracks2));
        rooms.push_back(std::move(chapel2));
        rooms.push_back(std::move(laboratory2));
        rooms.push_back(std::move(observatory2));
        rooms.push_back(std::move(crypt2));

        rooms[1]->setMonster(make_unique<Monster>("Goblin", 50, 10, 0.4, 2.0, Weakness::POISON, "A dubious little creature", 20));
        rooms[2]->setMonster(make_unique<Monster>("Hobgoblin Chief", 150, 25, 0.2, 1.5, Weakness::FREEZE,
            "A massive, muscular goblin wearing crude but effective armor. A makeshift wooden crown sits upon its head.", 100));
        rooms[2]->setIsBossRoom(true);
        rooms[3]->setMonster(make_unique<Monster>("Orc", 80, 15, 0.3, 1.8, Weakness::FIRE, "A brutish orc", 30));
        rooms[4]->setMonster(make_unique<Monster>("Dark Mage", 60, 20, 0.5, 2.5, Weakness::LIGHT, "A mage who has succumbed to the dark arts", 40));
        rooms[5]->setMonster(make_unique<Monster>("Werewolf", 100, 18, 0.25, 2.0, Weakness::SILVER, "A ferocious werewolf", 50));
        rooms[6]->setMonster(make_unique<Monster>("Troll", 120, 22, 0.2, 1.7, Weakness::FIRE, "A large, slow-moving troll", 60));
        rooms[7]->setMonster(make_unique<Monster>("Vampire", 90, 25, 0.35, 2.2, Weakness::LIGHT, "A blood-sucking vampire", 70));
        rooms[8]->setMonster(make_unique<Monster>("Skeleton", 40, 8, 0.4, 1.5, Weakness::BLUNT, "A reanimated skeleton", 15));
        rooms[9]->setMonster(make_unique<Monster>("Zombie", 60, 12, 0.3, 1.6, Weakness::FIRE, "A slow-moving undead", 25));
        rooms[10]->setMonster(make_unique<Monster>("Bat", 30, 5, 0.5, 1.2, Weakness::LIGHT, "A small, flying creature", 10));
        rooms[11]->setMonster(make_unique<Monster>("Rat", 20, 3, 0.6, 1.1, Weakness::POISON, "A large, aggressive rat", 5));
        rooms[12]->setMonster(make_unique<Monster>("Shadow Assassin", 90, 30, 0.4, 2.5, Weakness::LIGHT, "A silent killer lurking in the shadows", 50));
        rooms[13]->setMonster(make_unique<Monster>("Lich", 180, 28, 0.3, 2.0, Weakness::HOLY, "An undead sorcerer with powerful magic", 120));
        rooms[14]->setMonster(make_unique<Monster>("Giant", 220, 32, 0.2, 1.8, Weakness::FIRE, "A towering giant with immense strength", 140));
        rooms[15]->setMonster(make_unique<Monster>("Hobgoblin", 100, 25, 0.2, 1.5, Weakness::FREEZE, "A massive, muscular goblin wearing crude but effective armor.", 100));
        rooms[16]->setMonster(make_unique<Monster>("Dragon", 200, 35, 0.1, 3.0, Weakness::ICE, "A fearsome dragon with scales as hard as steel", 150));
        rooms[17]->setMonster(make_unique<Monster>("Demon Lord", 250, 40, 0.15, 2.8, Weakness::HOLY, "A powerful demon with dark magic", 200));
        rooms[18]->setMonster(make_unique<Monster>("Ancient Dragon", 300, 45, 0.1, 3.5, Weakness::ICE, "An ancient dragon with immense power", 250));
        rooms[19]->setMonster(make_unique<Monster>("Titan", 350, 50, 0.05, 4.0, Weakness::LIGHTNING, "A colossal titan with unmatched strength", 300));
        rooms[20]->setMonster(make_unique<Monster>("Lich", 180, 28, 0.3, 2.0, Weakness::HOLY, "An undead sorcerer with powerful magic", 120));

        currentRoom = rooms[0].get();
    }

    void Game::explore()
    {
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

    void Game::combat(Monster * monster)
    {
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
                if (monster->getWeakness() == player.getSpellBonus()) {
                    monster->attack();
                    cout << "But is weak due to a spell effect! (x0.75 attack damage)" << endl;
                    player.takeDamage(monster->getAttack() * 0.75);
                } else {
                    monster->attack();
                    player.takeDamage(monster->getAttack());
                }
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