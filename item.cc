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
