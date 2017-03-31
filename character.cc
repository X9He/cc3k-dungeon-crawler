#include "character.h"
#include <cmath>
using namespace std;

Character::Character(int initHP, int initAtk, int initDef, int Gold):
initHP{initHP}, initAtk{initAtk}, initDef{initDef}, Gold{Gold}{
    curHp = this->initHP;
    curAtk = this->initAtk;
    curDef = this->initDef;
}


Character::~Character() {}

void Character::changeGold(int i) {
    Gold = Gold+i;
}

int Character::damage(Character *other, float mag) {
  cout << "FOurteen" << endl;
  this->getDef();
  cout << "Fifteen" << endl;
  
  if (&other) {
    cout << "there" << endl;
  } else {
    cout << "here" << endl;
  }
  other->getAtk();
  cout << "Sixteen" << endl;
    return 0 - ceil((100 * (mag * other->getAtk()))/ (100 + this->getDef()));
}

bool Character::die() {return curHp == 0;}

int Character::getRow() {return row;}

int Character::getCol() {return col;}

char Character::getName() {return name;}

void Character::changePosition(int x, int y) {
    row = x;
    col = y;
}

void Character::changeHP(int effect) {
    int max = getinitHp();
    int afterChange = curHp + effect;
    if (afterChange  <=0) curHp = 0;
    else if (afterChange >= max) curHp = max;
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
  cout << "getting atk" << endl;
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

int Character::getinitHp() {
    return initHP;
}

void Character::changeCurHP(int i) {
    curHp = i;
}





