#ifndef _PC_H_
#define _PC_H_
#include <string>
#include <iostream>
#include "character.h"

class PC: public Character {
  int max;
  public:
  virtual PC(int initHP, int initAtk, int initDef, int Gold, int row, int col, int max);
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
