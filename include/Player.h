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

    // Setter-methods
    void setName(const string& name);
    void setHealth(int health);
    void setLevel(int level);

    void displayStats() const; // show player stats

private:
    string name;
    int health;
    int level;
};

#endif