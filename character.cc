#include "character.h"

Character::Character(int initHP, ini initAtk, int initDef, int Gold, int row, int col, int curHP, int curAtk, int curDef):
  initHP{initHP}, initAtk{initAtk}, initDef{initDef}, Gold{Gold}, row{row}, col{col} {
   curHP = initHp;
   curAtk = initAtk;
   curDef = initDef;
   }
}

Character::~Character() {}

bool Character::die() {return HP == 0;}

int Character::getRow() {return row;}

int Character::getCol() {return col;}

char Character::getNamr£¨£© {return char;}



