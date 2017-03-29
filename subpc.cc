#include "subpc.cc"

Troll::~Troll(){}

void Troll::regainHealth(){
  changeHP(5);
}

Vampire::~Vampire() {}

void Vampire::VchangeHP(int effect) {
   int currrent = getHP();
  changeHP(effect, current + effect);
}

Goblin::~Goblin() {}

void Goblin::stealGold(){
  int amount = 5;
  changGold(amount);
}

Drow::~Drow() {}

void Drow::pickUpItem(Item &i){
  

