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
  virtual attack(Enemy *target) = 0;
  void pickUpItem(Item *i);
  int getMax()

  virtual void changeHP(int effect) = 0;
  virtual void changeAtk(int effect) = 0;
  virtual void changeDef(int effect) = 0;
  virtual int getHp() = 0;
  virtual int getAtk() = 0;
  virtual int getDef() = 0;
  virtual int getGold() = 0;
  virtual void changeGold() = 0;
};

#endif
