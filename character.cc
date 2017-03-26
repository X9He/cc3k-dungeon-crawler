#include "character.h"

Character::Character(int initHP, ini initAtk, int initDef, int Gold, int row, int col):
  initHP{initHP}, initAtk{initAtk}, initDef{initDef}, Gold{Gold}, row{row}, col{col}{
   curHP = initHp;
   curAtk = initAtk;
   curDef = initDef;
   }
}

Character::~Character() {}

integer Character::damage(Character &other) {
  ceiling((100 / (100 + Def))) * other.Atk;
}

bool Character::die() {return HP == 0;}

int Character::getRow() {return row;}

int Character::getCol() {return col;}

char Character::getNamr£¨£© {return char;}

void Character::changePosition(int x, int y) {
  row = x;
  col = y;
}

