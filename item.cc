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

item::item(char itemType): row{0}, col{0}, itemType{itemType} {}

~item::item() { delete target; }