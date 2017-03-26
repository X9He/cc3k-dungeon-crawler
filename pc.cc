#include "pc.h"

PC::PC(int initHP, int initAtk, int initDef, int Gold, int row, int col, int max): 
  Character(initHP, initAtk, initDef, row, col), max{max}, name{'@'} {}

PC::~PC() {}

void PC::pickUpItem(Item &i) {
  i.useItem();
}

int PC::getMax() {
  return max;
}


