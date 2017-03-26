#ifndef _PC_H_
#define _PC_H_
#include <string>
#include <iostream>
#include "character.h"

class PC: piblic Character {
  int max;
  public:
  virtual PC(int initHP, int initAtk, int initDef, int Gold, int row, int col, int max);
  virtual ~PC();
  void pickUpItem(Item *i);
  int getMax();
  void attack(Enemy *target);

#endif
