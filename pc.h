#ifndef _PC_H_
#define _PC_H_
#include <string>
#include <iostream>
#include "character.h"

class PC: piblic Character {
  int max;
  public:
  virtual PC(int initHP=125, int initAtk=25, int initDef=25, int Gold=0, int row, int col, int max=initHP);
  virtual ~PC();
  void pickUpItem(Item *i);
  int getMax();
  void attack(Enemy *target);
  void hurt(Merchant &m);
  void hurt(Human &h);
  void hurt(Dragon &d);
  void hurt(Elf &e);
  void hurt(Halfing &l);
  void hurt(Dwarf &w);
  void hurt(Orcs &o);

};

#endif
