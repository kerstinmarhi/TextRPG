#ifndef QUEST_H
#define QUEST_H

#include <string>

using namespace std;

class Quest {
private:
    string name;
    string description;
    bool isCompleted;

public:
    Quest(const string& name, const string& description);
    string getName() const;
    string getDescription() const;
    bool getIsCompleted() const;
    void completeQuest();
};

#endif
