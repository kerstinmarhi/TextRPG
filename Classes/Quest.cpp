#include "Quest.h"
#include <iostream>

Quest::Quest(const string& name, const string& description)
    : name(name), description(description), isCompleted(false) {}

std::string Quest::getName() const {
    return name;
}

std::string Quest::getDescription() const {
    return description;
}

bool Quest::getIsCompleted() const {
    return isCompleted;
}

void Quest::completeQuest() {
    isCompleted = true;
    cout << "Quest '" << name << "' abgeschlossen!\n";
}
