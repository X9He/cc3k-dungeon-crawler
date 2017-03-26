#ifndef _CHARACTER_H_
#define _CHARACTER_H_
#include <string>
#include <iostream>
class Item;

class Character{
  int initHP, initAtk, initDef, Gold, row, col, curHp, curAtk, curDef;
  char name;
  publlic:
  virtual void move() = 0;
  virtual void move(string direction) = 0;
  virtual void attack(Character &Target) = 0;
  virtual void defense() = 0;
  Character(int initHp, int initAtk, int initDef, int Gold, int row, int col);
  virtual  ~Character();
  virtual void damage() = 0;
  bool die();
  virtual void changeHP(int effect) = 0;
  virtual void changeAtk(int effect) = 0;
  virtual void changeDef(int effect) = 0;
  virtual int getHp() = 0;
  virtual int getAtk() = 0;
  virtual int getDef() = 0;
  virtual int getGold() = 0;
  virtual void changeGold() = 0;
  int getrow();
  int getcol();
  char getName();
  void initHPAtkDef(); 
};  

#endif
