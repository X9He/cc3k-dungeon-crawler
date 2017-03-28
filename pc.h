#ifndef _PC_H_
#define _PC_H_
#include <string>
#include <iostream>
#include "character.h"

class PC: piblic Character {
  int max;
  string message;
  public:
  virtual PC(int initHP=125, int initAtk=25, int initDef=25, int Gold=0, int row, int col, int max=initHP, string message = "");
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


class Troll: public PC{
  int stealHP;
  pulic:
  Troll();
  ~Troll();
  void regainHealth();
  void hurt(Merchant &m);
  void hurt(Human &h);
  void hurt(Dragon &d);
  void hurt(Elf &e);
  void hurt(Halfing &l);
  void hurt(Dwarf &w);
  void hurt(Orcs &o);
};

class Vampire: public PC{ 
  public:
  ~Vampire();
  Vampire();
  void VchangHP(int effet);
  void attack(Enemy *target);
  void hurt(Merchant &m);
  void hurt(Human &h);
  void hurt(Dragon &d);
  void hurt(Elf &e);
  void hurt(Halfing &l);
  void hurt(Dwarf &w);
  void hurt(Orcs &o);

};

class Goblin: public PC{ 
  int stealGold;
  public:
  Goblin();
  ~Goblin();
  void stealGold();
  void attack(Enemy *target);
  void hurt(Merchant &m);
  void hurt(Human &h);
  void hurt(Dragon &d);
  void hurt(Elf &e);
  void hurt(Halfing &l);
  void hurt(Dwarf &w);
  void hurt(Orcs &o);

};

class Drow: public PC{
  int potionMagnify;
  public:
  Drow();
  ~Drow();
  void pickUpItem(Item &i, int effect);
  void hurt(Merchant &m);
  void hurt(Human &h);
  void hurt(Dragon &d);
  void hurt(Elf &e);
  void hurt(Halfing &l);
  void hurt(Dwarf &w);
  void hurt(Orcs &o);
};

#endif
