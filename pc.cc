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
   if (target->getHP() == 0) {
     changeGold(getGold());
   }
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
