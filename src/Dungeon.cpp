#include "../include/Dungeon.h"
#include "../include/Monster.h"
#include <iostream>
using namespace std;

Dungeon::Dungeon()
{
    initializeRooms();
}

void Dungeon::initializeRooms()
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

    rooms[1]->setMonster(Monster::generateMonster(1));
    rooms[2]->setMonster(Monster::generateMonster(3));
    rooms[2]->setIsBossRoom(true);
    rooms[3]->setMonster(Monster::generateMonster(2));
    rooms[4]->setMonster(Monster::generateMonster(2));
    rooms[5]->setMonster(Monster::generateMonster(1));
    rooms[6]->setMonster(Monster::generateMonster(1));
    rooms[7]->setMonster(Monster::generateMonster(1));
    rooms[8]->setMonster(Monster::generateMonster(2));
    rooms[9]->setMonster(Monster::generateMonster(1));
}

Room* Dungeon::getStartingRoom() const
{
    return rooms[0].get();
}
