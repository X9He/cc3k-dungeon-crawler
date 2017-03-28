#include "pc.h"

/*
Character::Character(int initHP, ini initAtk, int initDef, int Gold):
  initHP{initHP}, initAtk{initAtk}, initDef{initDef}, Gold{Gold}{
   curHP = initHp;
   curAtk = initAtk;
   curDef = initDef;
   }
}
*/

PC::PC(int initHP, int initAtk, int initDef): 
  Character(initHP, initAtk, initDef, 0), max{initHP}, name{'@'} {}

PC::~PC() {}

void PC::pickUpItem(Item &i) {
  i.useItem();
}

int PC::getMax() {
  return max;
}

/*
void PC::attack(Enemy  *target) {
   target->hurt(*this);
   if (target->getHP() == 0) {
     changeGold(target->getGold());
   }
}
*/

void PC::attack(Elf  *target) {
   target->hurt(*this);
   if (target->getHP() == 0) {
     changeGold(target->getGold());
   }
}

void PC::attack(Dward  *target) {
   target->hurt(*this);
   if (target->getHP() == 0) {
     changeGold(target->getGold());
   }
}

void PC::attack(Halfing  *target) {
   target->hurt(*this);
   if (target->getHP() == 0) {
     changeGold(target->getGold());
   }
}

void PC::attack(Orcs  *target) {
   target->hurt(*this);
   if (target->getHP() == 0) {
     changeGold(target->getGold());
   }
}

void PC::attack(Merchant  *target) {
   target->hurt(*this);
   if (target->getHP() == 0) {
     changeGold(target->getGold());
   }
}

void PC::attack(Dragon  *target) {
   target->hurt(*this);
   if (target->getHP() == 0) {
     changeGold(target->getGold());
   }
}

void PC::attack(Human  *target) {
   target->hurt(*this);
   if (target->getHP() == 0) {
     changeGold(target->getGold());
   }
}


/*
void PC::hurt(Merchant &m){
  if (!m.status){
    int effect = m.damage(*this);
    m.changetHP(effect);
  }
}

void PC::hurt(Human &h){
  int effect = h.damage(*this);
  h.changetHP(effect);
}

void PC::hurt(Dragon &d){
  int effect = d.damage(*this);
  d.changetHP(effect);
}

void PC::hurt(Elf &e){
  int effect = e.damage(*this);
   e.changetHP(effect);
}

integer Character::damage(Character &other, float mag = 1) {
  return 0 - ceiling((100 / (100 + Def))) * (mag * other.Atk);
}

void PC::hurt(Halfing &l){
  int effect = l.damage(*this);
  l.changetHP(effect);
}

void PC::hurt(Dwarf &w){
  int effect = w.damage(*this);
  w.changetHP(effect);
}

void PC::hurt(Orcs &o){
  int effect = o.damage(*this);
  o.changetHP(effect);
}
*/ 


//
void PC::hurt(Merchant & m) {
    int effect = damage(m);
   changeHP(effect);
}

void PC::hurt(Dragon & d) {
    int effect = damage(d);
    changeHP(effect);
}

void PC::hurt(Elf & e) {
    int effect = damage(e, 2);
    changeHP(effect);
}

void PC::hurt(Dwarf & d) {
    int effect = damage(d);
    changeHP(effect);
}

void PC::hurt(Halfing & h) {
   int effect = damage(h);
    changeHP(effect);
}

void PC::hurt(Orcs & o) {
    int effect = damage(o);
    changeHP(effect);
}

void PC::hurt(Human & h) {
    int effect = damage(h);
    changeHP(effect);
}

void Vampire::hurt(Elf & e) {
    int effect = damage(e);
    changeHP(effect);
}

void Goblin::hurt(Orcs & o) {
    int effect = damage(o, 1.5);
    changHP(effect);
}

void Drow::hurt(Elf & e) {
    damage(e);
}

Troll::Troll() :
  Character{120, 25, 15, 0, 0, 0, 120, 25, 15}, max{120} {}

Troll::~Troll(){}

void Troll::regainHealth(){
  changeHP(5);
}

Vampire::Vampire() :
  Character{50, 25, 25, 0, 0, 0, 50, 25, 25}, max{50} {}

Vampire::~Vampire() {}

void Vampire::VchangeHP(int effect) {
   int currrent = getHP();
  changeHP(effect, current + effect);
}

Goblin::Goblin() :
  Character{110, 15, 20, 0, 0, 0, 110, 15, 20}, max{110} {}

Goblin::~Goblin() {}

void Goblin::stealGold(){
  int amount = 5;
  changGold(amount);
}

Drow::Drow():
  Character{150, 25, 15, 0, 0, 0, 150, 25, 15}, max{150} {}

Drow::~Drow() {}

void Drow::pickUpItem(Item &i, int effect){
  i.useItem(effect);
}
