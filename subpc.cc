#include "subpc.cc"

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

void Drow::pickUpItem(Item &i){
  

