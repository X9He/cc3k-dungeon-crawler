#ifndef _PC_H_
#define _PC_H_
#include <string>
#include <iostream>
#include "character.h"
// #include "item.h"
#include "enemy.h"

class Item;

class Enemy;
class Merchant;
class Human;
class Dragon;
class Elf;
class Halfling;
class Elf;
class Dwarf;
class Orcs;

class PC: public Character {
    int max;
public:
    PC(int initHP=125, int initAtk=25, int initDef=25);
    virtual ~PC();
    void pickUpItem(Item &i);
    int getMax();
    void attack(Enemy *target);
    void attack(Elf *target);
    void attack(Dwarf  *target);
    void attack(Halfling  *target);
    void attack(Orcs  *target);
    void attack(Merchant  *target);
    void attack(Dragon  *target);
    void attack(Human  *target);
    void hurt(Merchant &m);
    void hurt(Human &h);
    void hurt(Dragon &d);
    void hurt(Elf &e);
    void hurt(Halfling &l);
    void hurt(Dwarf &w);
    void hurt(Orcs &o);

    
};


class Troll: public PC{
  int stealHP;
  public:
  Troll();
  ~Troll() override;
  void regainHealth();
  void hurt(Merchant &m);
  void hurt(Human &h);
  void hurt(Dragon &d);
  void hurt(Elf &e);
  void hurt(Halfling &l);
  void hurt(Dwarf &w);
  void hurt(Orcs &o);
    void attack(Enemy *target);
};

class Vampire: public PC{ 
  public:
  ~Vampire() override;
  Vampire();
  void VchangHP(int effet);
  void attack(Enemy *target);
  void hurt(Merchant &m);
  void hurt(Human &h);
  void hurt(Dragon &d);
  void hurt(Elf &e);
  void hurt(Halfling &l);
  void hurt(Dwarf &w);
  void hurt(Orcs &o);

};

class Goblin: public PC{ 
  int stealGold;
  public:
  Goblin();
  ~Goblin() override;
  void steal();
  void attack(Enemy *target);
  void hurt(Merchant &m);
  void hurt(Human &h);
  void hurt(Dragon &d);
  void hurt(Elf &e);
  void hurt(Halfling &l);
  void hurt(Dwarf &w);
  void hurt(Orcs &o);

};

class Drow: public PC{
  int potionMagnify;
  public:
  Drow();
  ~Drow() override;
  void pickUpItem(Item &i, int effect);
  void hurt(Merchant &m);
  void hurt(Human &h);
  void hurt(Dragon &d);
  void hurt(Elf &e);
  void hurt(Halfling &l);
  void hurt(Dwarf &w);
  void hurt(Orcs &o);
    void attack(Enemy *target);
};

#endif
