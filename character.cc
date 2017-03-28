#include "character.h"

Character::Character(int initHP, ini initAtk, int initDef, int Gold):
  initHP{initHP}, initAtk{initAtk}, initDef{initDef}, Gold{Gold}{
   curHP = initHp;
   curAtk = initAtk;
   curDef = initDef;
   }
}

Character::~Character() {}

int Character::damage(Character &other, float mag = 1) {
  return 0 - ceiling((100 / (100 + Def))) * (mag * other.Atk);
}

bool Character::die() {return HP == 0;}

int Character::getRow() {return row;}

int Character::getCol() {return col;}

char Character::getName() {return char;}

void Character::changePosition(int x, int y) {
  row = x;
  col = y;
}

void Character::changeHP(int effect) {
  int afterChange = curHP + effect;
   if (afterChange  <=0) curHP = 0;
   else if (afterChange >= initHP) curHp = initHP;
   else curHP = afterChange;
}

void Character::changeAtk(int effect) {
  int afterChange = curAtk + effect;
    if (afterChange <= 0) curAtk = 0;
   else curHp = afterChaneg;
}

void Charactetr::changeDef(int effect){
    int afterChange = curDef + effect;
   if (afterChange  <=0) curDef = 0;
   else curDef = afterChaneg;
}

int Character::getHp() {
 return curHP;
}

int Character::getAtk() {
  return curAtk;
}

int Character::getDef() {
  return curDef;
}

int Character::getGold(){
  return Gold;
}


