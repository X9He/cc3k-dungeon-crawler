#ifndef _SUBPC_H_
#dedein _SUBPC_H_
#include "pc.h"

class Troll: public PC{
  int stealHP;
  pulic:
  ~Troll();
  void regainHealth(); 
};

class Vampire: public PC{ 
  public:
  ~Vampire();
  void VchangHP(int effet);

};

class Goblin: public PC{ 
  int stealGold;
  public:
  ~Goblin();
  void stealGold()

};

class Drow: public PC{
  int potionMagnify;
  public:
  ~Drow();
  void pickUpItem(Item &i); 
};

#endif
