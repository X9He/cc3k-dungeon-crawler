#include "character.h"
#include <math.h>

Character::Character(int initHP, int initAtk, int initDef, int Gold):
  initHP{initHP}, initAtk{initAtk}, initDef{initDef}, Gold{Gold}{
   curHP = initHP;
   curAtk = initAtk;
   curDef = initDef;
   }


Character::~Character() {}

int Character::damage(Character &other, float mag) {
  return (0 - ceil((100 / (100 + getDef()))) * (mag * other.curAtk));
}

bool Character::die() {return curHP == 0;}

int Character::getrow() {return row;}

int Character::getcol() {return col;}

char Character::getName() {return name;}

void Character::changePosition(int x, int y) {
  row = x;
  col = y;
}

void Character::changeHP(int effect) {
  int afterChange = curHP + effect;
   if (afterChange  <=0) curHP = 0;
   else if (afterChange >= initHP) curHP = initHP;
   else curHP = afterChange;
}

void Character::changeAtk(int effect) {
  int afterChange = curAtk + effect;
    if (afterChange <= 0) curAtk = 0;
   else curAtk = afterChange;
}

void Character::changeDef(int effect){
    int afterChange = curDef + effect;
   if (afterChange  <=0) curDef = 0;
   else curDef = afterChange;
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


