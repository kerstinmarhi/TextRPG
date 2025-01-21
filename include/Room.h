#ifndef ROOM_H
#define ROOM_H

#include <string>
using namespace std;

class Room {
public:
    Room(const string& name);
    string getName() const;

private:
    string name;
};

#endif
