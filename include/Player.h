#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player {
public:
    Player(const string& name);

    // Getter-methods
    string getName() const;
    int getHealth() const;
    int getLevel() const;
    int getAP() const;
    // Setter-methods
    void setName(const string& name);
    void setHealth(int health);
    void setLevel(int level);
    void setAP(int attackPoints);
    void displayStats() const; // show player stats
    void attack(Monster& monster) const;
    void takeDamage(int damage);
    bool isAlive() const;

private:
    string name;
    int health;
    int level;
    const int attackPoints = 20; // base attack damage
};

#endif