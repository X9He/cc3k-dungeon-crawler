#include <iostream>
#include <vector>
#include <utility>
#include "treasure.h"
#include "pc.h"


Treasure::Treasure(int value, bool protect, char itemType):
Item(itemType),value{value}, protect{protect} {}

Treasure::~Treasure() {}

int Treasure::getValue() {
    return value;
}
bool Treasure::isProtect() {
    return protect;
}

void Treasure::useItem(int mag) {
    target->changeGold(getValue());
}

void Treasure::changeProtect() {
    protect = !protect;
}

Small::Small():
Treasure{1, false} {}

Normal::Normal():
Treasure{2, false} {}

MH::MH():
Treasure{4, false} {}

DH::DH():
Treasure{6, true} {}

