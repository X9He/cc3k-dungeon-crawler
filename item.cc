#include <stdio.h>
#include "item.h"

char Item::getType() {
    return itemType;
}
int Item::getRow() {
    return row;
}

int Item::getCol() {
    return col;
}

Item::Item(char itemType): row{0}, col{0}, itemType{itemType} {}

Item::~Item() { delete target; }

void Item::changePosition(int x, int y) {
    row = x;
    col = y;
}
