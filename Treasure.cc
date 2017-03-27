

#include "Treasure.h"

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

