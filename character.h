#ifndef _CHARACTER_H_
#define _CHARACTER_H_
#include <string>
#include <iostream>
class Item;

class Character{
  int initHP, initAtk, initDef, Gold, row, col, curHp, curAtk, curDef;
  protected:
  char name;
  publlic:
  void changePosition(int x, int y);
  Character(int initHp, int initAtk, int initDef, int Gold);
  virtual  ~Character();
  integer damage(Character &other, float mag = 1);
  bool die();
  virtual void changeHP(int effect);
  virtual void changeAtk(int effect);
  virtual void changeDef(int effect);
  virtual int getHp();
  virtual int getAtk();
  virtual int getDef();
  virtual int getGold();
  int getrow();
  int getcol();
  char getName();
  void initHPAtkDef(); 
};  

#endif
