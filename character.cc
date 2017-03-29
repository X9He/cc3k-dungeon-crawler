#include "character.h"
#include <cmath>

Character::Character(int initHP, int initAtk, int initDef, int Gold):
initHP{initHP}, initAtk{initAtk}, initDef{initDef}, Gold{Gold}{
    curHp = initHP;
    curAtk = initAtk;
    curDef = initDef;
}


Character::~Character() {}

void Character::changeGold(int i) {
    Gold = Gold+i;
}

int Character::damage(Character &other, float mag) {
    return 0 - ceil((100 / (100 + this->getDef()))) * (mag * other.getAtk());
}

bool Character::die() {return curHp == 0;}

int Character::getrow() {return row;}

int Character::getcol() {return col;}

char Character::getName() {return name;}

void Character::changePosition(int x, int y) {
    row = x;
    col = y;
}

void Character::changeHP(int effect) {
    int afterChange = curHp + effect;
    if (afterChange  <=0) curHp = 0;
    else if (afterChange >= initHP) curHp = initHP;
    else curHp = afterChange;
}

void Character::changeAtk(int effect) {
    int afterChange = curAtk + effect;
    if (afterChange <= 0) curAtk = 0;
    else curHp = afterChange;
}

void Character::changeDef(int effect){
    int afterChange = curDef + effect;
    if (afterChange  <=0) curDef = 0;
    else curDef = afterChange;
}

int Character::getHP() {
    return curHp;
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

void Character::initAtkDef() {
    curAtk = initAtk;
    curDef = initDef;
}





