

#include "Treasure.h"

int random(){
    int x = 0;
    int y = 1;
    int ran;
    srand(time(0));
    ran = x + (rand() % (y - x + 1));
    if (ran == 0) return 1;
    return 2;
}

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

