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
void PC::atack(Enemy  *target) {
   target->hurt(*this);
}
void PC::hurt(Merchant &m){
  if (!m.status){
    int effect = m.damage(*this);
    m.changetHP(effet);
  }
}

void PC::hurt(Human &h){
  int effect = h.damage(*this);
  h.changetHP(effet);
}

void PC::hurt(Dragon &d){
  int effect = d.damage(*this);
  d.changetHP(effet);
}

void PC::hurt(Elf &e){
  int effect = e.damage(*this);
   e.changetHP(effet);
}

void PC::hurt(Halfing &l){
  int effect = l.damage(*this);
  l.changetHP(effet);
}

void PC::hurt(Dwarf &w){
  int effect = w.damage(*this);
  w.changetHP(effet);
}

void PC::hurt(Orcs &o){
  int effect = o.damage(*this);
  o.changetHP(effet);
}
  
