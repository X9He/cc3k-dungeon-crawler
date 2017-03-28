

#include "treasure.h"


Treasure::Treasure(int value, bool protect):
value{value}, protect{protect} {}

int Treasure::getValue() {
    return value;
}
bool Treasure::isProtect() {
    return protect;
}

void Treasure::useItem(int mag) {
    target->pickupItem(*this);
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

