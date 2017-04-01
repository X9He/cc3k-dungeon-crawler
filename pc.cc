#include "pc.h"
#include <sstream>
using namespace std;

/*
Character::Character(int initHP, ini initAtk, int initDef, int Gold):
  initHP{initHP}, initAtk{initAtk}, initDef{initDef}, Gold{Gold}{
   curHP = initHp;
   curAtk = initAtk;
   curDef = initDef;
   }
}
*/

PC::PC(int initHP, int initAtk, int initDef, int damageE): 
  Character{initHP, initAtk, initDef,0}, max{initHP}, damageE{damageE}{
  name = '@';
  }

PC::~PC() {}

void PC::changeDamageE(int amount) {
  damageE= amount;
}

int PC::getDamageE() {
  return damageE;
}

void PC::pickUpItem(Item &i) {
  i.useItem();
}

int PC::getMax() {
  return max;
}

void PC::attack(Enemy  *target) {
  cout << "ONE" << endl;

  Shade *s = dynamic_cast<Shade *>(this);
  if(s){
    target->hurt(s);
  }


  Goblin *g = dynamic_cast<Goblin *>(this);
  if(g){
    target->hurt(g);
  }

  Drow *d = dynamic_cast<Drow *>(this);
  if(d){
    target->hurt(d);
  }

  Vampire *v = dynamic_cast<Vampire *>(this);
  if(v){
    target->hurt(v);
  }

  cout << "TWO" << endl;
  if (target->getHP() == 0) {
    changeGold(target->getGold());
    stringstream a;
    int amount = target->getGold();
    a << amount;
  } else {
    int effect1= target->damage(this, 2);
    int effect2 = damage(target);
    stringstream a1;
    stringstream a2;
    a1 << effect1;
    a2 << effect2;
  }
    cout << target->getHP() << endl;
}

/*
void PC::attack(Elf  *target) {
   target->hurt(*this);
   if (target->getHP() == 0) {
     changeGold(target->getGold());
     stringstream a;
     int amount = targey->getGold();
     a << amount
     message = "PC steals " + a.str() + " from " + to_string(target->name);
   } else {
     int effect1= target->damage(*this, 2);
     int effect2 = damage(target);
     stringstream a1;
     stringstream a2;
     a1 << effect1;
     a2 << effect2;
     message  = "PC deals " + a1.str() + "damages to (" + to_string(target->name) + 
       "). " + to_string(target->name) + " deals " + a2.str()+ " to PC.";
   }
}
void PC::attack(Dward  *target) {
   target->hurt(*this);
   if (target->getHP() == 0) {
     changeGold(target->getGold());
     stringstream a;
     int amount = targey->getGold();
     a << amount
     message = "PC steals " + a.str() + " from " + to_string(target->name);
   } else {
     int effect1= target->damage(*this);
     int effect2 = damage(target);
     stringstream a1;
     stringstream a2;
     a1 << effect1;
     a2 << effect2;
     message  = "PC deals " + a1.str() + "damages to (" + to_string(target->name) + 
       "). " + to_string(target->name) + " deals " + a2.str()+ " to PC.";
   }
}
void PC::attack(Halfing  *target) {
   target->hurt(*this);
   if (target->getHP() == 0) {
     changeGold(target->getGold());
     stringstream a;
     int amount = targey->getGold();
     a << amount
     message = "PC steals " + a.str() + " from " + to(target->name);
   } else {
     int effect1= target->damage(*this);
     int effect2 = damage(target);
     stringstream a1;
     stringstream a2;
     a1 << effect1;
     a2 << effect2;
     message  = "PC deals " + a1.str() + "damages to (" + to_string(target->name) + 
       "). " + to_string(target->name) + " deals " + a2.str()+ " to PC.";
   }
}
*/


int random3(int x, int y){
 int ran;
 ran = x + (rand() % (y - x + 1));
 return ran;
}


/*void PC::attack(Orcs  *target) {
  // 50% miss
  int ran = random(0, 1);
  if (ran == 0) {
   target->hurt(*this);
   if (target->getHP() == 0) {
     changeGold(target->getGold());
     stringstream a;
     int amount = targey->getGold();
     a << amount
     message = "PC steals " + a.str() + " from " + to_string(target->name);
   }
  } else {
    int effect1= target->damage(*this, 1.5);
    int effect2 = damage(target);
    stringstream a1;
    stringstream a2;
    a1 << effect1;
    a2 << effect2;
    message  = "PC deals " + a1.str() + "damages to (" + to_string(target->name) + 
      "). " + to_string(target->name) + " deals " + a2.str()+ " to PC.";
  }
}
void PC::attack(Merchant  *target) {
   target->hurt(*this);
   if (target->getHP() == 0) {
     changeGold(target->getGold());
     stringstream a;
     int amount = targey->getGold();
     a << amount
     message = "PC steals " + a.str() + " from " + to_string(target->name);
   } else {
     int effect1= target->damage(*this);
     int effect2 = damage(target);
     stringstream a1;
     stringstream a2;
     a1 << effect1;
     a2 << effect2;
     message  = "PC deals " + a1.str() + "damages to (" + to_string(target->name) +
       "). " + to_string(target->name) + " deals " + a2.str()+ " to PC.";
   }
}
void PC::attack(Dragon  *target) {
   target->hurt(*this);
   if (target->getHP() == 0) {
     changeGold(target->getGold());
     stringstream a;
     int amount = targey->getGold();
     a << amount
     message = "PC steals " + a.str() + " from " + to_string(target->name);
   }
  else {
    int effect1= target->damage(*this);
    int effect2 = damage(target);
    stringstream a1;
    stringstream a2;
    a1 << effect1;
    a2 << effect2;
    message  = "PC deals " + a1.str() + "damages to (" + to_string(target->name) +
      "). " + to_string(target->name) + " deals " + a2.str()+ " to PC.";
  }
}
void PC::attack(Human  *target) {
   target->hurt(*this);
   if (target->getHP() == 0) {
     changeGold(target->getGold());
     stringstream a;
     int amount = targey->getGold();
     a << amount
     message = "PC steals " + a.str() + " from " + to_string(target->name);
   }
  else {
    int effect1= target->damage(*this);
    int effect2 = damage(target);
    stringstream a1;
    stringstream a2;
    a1 << effect1;
    a2 << effect2;
    message  = "PC deals " + a1.str() + "damages to (" + to_string(target->name) + 
      "). " + to_string(target->name) + " deals " + a2.str()+ " to PC.";
  }
}
*/


/*
void PC::hurt(Merchant &m){
  if (!m.status){
    int effect = m.damage(*this);
    m.changetHP(effect);
  }
}
void PC::hurt(Human &h){
  int effect = h.damage(*this);
  h.changetHP(effect);
}
void PC::hurt(Dragon &d){
  int effect = d.damage(*this);
  d.changetHP(effect);
}
void PC::hurt(Elf &e){
  int effect = e.damage(*this);
   e.changetHP(effect);
}
integer Character::damage(Character &other, float mag = 1) {
  return 0 - ceiling((100 / (100 + Def))) * (mag * other.Atk);
}
void PC::hurt(Halfing &l){
  int effect = l.damage(*this);
  l.changetHP(effect);
}
void PC::hurt(Dwarf &w){
  int effect = w.damage(*this);
  w.changetHP(effect);
}
void PC::hurt(Orcs &o){
  int effect = o.damage(*this);
  o.changetHP(effect);
}
*/ 


//
void PC::hurt(Merchant & m) {
  int effect = damage(&m);
   changeHP(effect);
}

void PC::hurt(Dragon & d) {
  int effect = damage(&d);
  changeHP(effect);
}

void PC::hurt(Elf & e) {
    int effect = damage(&e, 2);
    changeHP(effect);
}

void PC::hurt(Dwarf & d) {
    int effect = damage(&d);
    changeHP(effect);
}

void PC::hurt(Halfling & h) {
   int effect = damage(&h);
    changeHP(effect);
}

void PC::hurt(Orcs & o) {
    int effect = damage(&o);
    changeHP(effect);
}

void PC::hurt(Human & h) {
    int effect = damage(&h);
    changeHP(effect);
}

/*
  void Vampire::hurt(Elf & e) {
    int effect = damage(e);
    changeHP(effect);
}
void Goblin::hurt(Orcs & o) {
    int effect = damage(o, 1.5);
    changHP(effect);
}
void Drow::hurt(Elf & e) {
    int effect = damage(e);
    changeHP(effect);
}
*/
void Shade::attack(Enemy *target){
  target->hurt(this);
}

void Troll::attack(Enemy *target){
  target->hurt(this);
}

void Vampire::attack(Enemy *target){
  target->hurt(this);
}


void Drow::attack(Enemy *target){
  target->hurt(this);
}





Shade::Shade(): PC{125,15,15,0} {}

Shade::~Shade(){}

Troll::Troll() :
  PC(120, 25, 15,0){}

Troll::~Troll(){}

void Troll::regainHealth(){
  changeHP(5);
}

Vampire::Vampire() :
  PC(50, 25, 25,0) {}

Vampire::~Vampire() {}

void Vampire::VchangHP(int effect) {
   changeCurHP(effect);
}

Goblin::Goblin() :
  PC(110, 15, 20,0) {}

Goblin::~Goblin() {}

void Goblin::steal(){
  int amount = 5;
  changeGold(amount);
}

void Goblin::attack(Enemy *target) {
  target->hurt(this);
  if (target->getHP() == 0) {
    changeGold(target->getGold());
    steal();
  }
}

Drow::Drow():
  PC(150, 25, 15,0) {}

Drow::~Drow() {}

void Drow::pickUpItem(Item &i, int effect){
  i.useItem(effect);
}

////////////////////////////////////
void Troll::hurt(Merchant &m) {
  int effect = damage(&m);
  changeHP(effect);
  changeDamageE(effect);
}
void Troll::hurt(Human &h) {
  int effect = damage(&h);
  changeHP(effect);
  changeDamageE(effect);
}
void Troll::hurt(Dragon &d) {
  int effect = damage(&d);
  changeHP(effect);
  changeDamageE(effect);
}
void Troll::hurt(Elf &e) {
  int effect = damage(&e,2);
  changeHP(effect);
  changeDamageE(effect);
}
void Troll::hurt(Halfling &l) {
  int effect = damage(&l);
  changeHP(effect);
  changeDamageE(effect);
}
void Troll::hurt(Dwarf &w) {
  int effect = damage(&w);
  changeHP(effect);
  changeDamageE(effect);
}
void Troll::hurt(Orcs &o) {
  int effect = damage(&o);
  changeHP(effect);
  changeDamageE(effect);
}

void Vampire::hurt(Merchant &m) {
  int effect = damage(&m);
  changeHP(effect);
  changeDamageE(effect);
}
void Vampire::hurt(Human &h) {
  int effect = damage(&h);
  changeHP(effect);
  changeDamageE(effect);
}
void Vampire::hurt(Dragon &d) {
  int effect = damage(&d);
  changeHP(effect);
  changeDamageE(effect);
}
void Vampire::hurt(Elf &e) {
  int effect = damage(&e,2);
  changeHP(effect);
  changeDamageE(effect);
}
void Vampire::hurt(Halfling &l) {
  int effect = damage(&l);
  changeHP(effect);
  changeDamageE(effect);
}
void Vampire::hurt(Dwarf &w) {
  int effect = damage(&w);
  changeHP(effect);
  changeDamageE(effect);
}
void Vampire::hurt(Orcs &o) {
  int effect = damage(&o);
  changeHP(effect);
  changeDamageE(effect);
}

void Goblin::hurt(Merchant &m) {
  int effect = damage(&m);
  changeHP(effect);
  changeDamageE(effect);
}
void Goblin::hurt(Human &h) {
  int effect = damage(&h);
  changeHP(effect);
  changeDamageE(effect);
}
void Goblin::hurt(Dragon &d) {
  int effect = damage(&d);
  changeHP(effect);
  changeDamageE(effect);
}
void Goblin::hurt(Elf &e) {
  int effect = damage(&e,2);
  changeHP(effect);
  changeDamageE(effect);
}
void Goblin::hurt(Halfling &l) {
  int effect = damage(&l);
  changeHP(effect);
  changeDamageE(effect);
}
void Goblin::hurt(Dwarf &w) {
  int effect = damage(&w);
  changeHP(effect);
  changeDamageE(effect);
}
void Goblin::hurt(Orcs &o) {
  int effect = damage(&o, 1.5);
  changeHP(effect);
  changeDamageE(effect);
}

void Drow::hurt(Merchant &m) {
  int effect = damage(&m);
  changeHP(effect);
  changeDamageE(effect);
}
void Drow::hurt(Human &h) {
  int effect = damage(&h);
  changeHP(effect);
  changeDamageE(effect);
}
void Drow::hurt(Dragon &d) {
  int effect = damage(&d);
  changeHP(effect);
  changeDamageE(effect);
}

void Drow::hurt(Elf &e) {
  int effect = damage(&e);
  changeHP(effect);
  changeDamageE(effect);
}
void Drow::hurt(Halfling &l) {
  int effect = damage(&l);
  changeHP(effect);
  changeDamageE(effect);
}
void Drow::hurt(Dwarf &w) {
  int effect = damage(&w);
  changeHP(effect);
  changeDamageE(effect);
}
void Drow::hurt(Orcs &o) {
  int effect = damage(&o);
  changeHP(effect);
  changeDamageE(effect);
}


void Shade::hurt(Merchant &m) {
  int effect = damage(&m);
  changeHP(effect);
  changeDamageE(effect);
}
void Shade::hurt(Human &h) {
  int effect = damage(&h);
  changeHP(effect);
  changeDamageE(effect);
}
void Shade::hurt(Dragon &d) {
  int effect = damage(&d);
  changeHP(effect);
  changeDamageE(effect);
}

void Shade::hurt(Elf &e) {
  int effect = damage(&e);
  changeHP(effect);
  changeDamageE(effect);
}
void Shade::hurt(Halfling &l) {
  int effect = damage(&l);
  changeHP(effect);
  changeDamageE(effect);
}
void Shade::hurt(Dwarf &w) {
  int effect = damage(&w);
  changeHP(effect);
  changeDamageE(effect);
}
void Shade::hurt(Orcs &o) {
  int effect = damage(&o);
  changeHP(effect);
  changeDamageE(effect);
}

//////////////////////////////////////
/*
void Troll::attack(Enemy *target) {
  target->hurt(*this);
  if (target->getHP() == 0) {
    changeGold(target->getGold());
     stringstream a;
     int amount = targey->getGold();
     a << amount
     message = "PC steals " + a.str() + " gold from " + to_string(target->name);
  }
  else {
    int effect1= target->damage(*this);
    int effect2 = damage(target);
    stringstream a1;
    stringstream a2;
    a1 << effect1;
    a2 << effect2;
    message  = "PC deals " + a1.str() + "damages to (" + to_string(target->name) + 
      "). " + to_string(target->name) + " deals " + a2.str()+ " to PC.";
  }
}
void Vampire::attack(Enemy *target) {
  target->hurt(*this);
   if (target->getHP() == 0) {
     changeGold(target->getGold());
     stringstream a;
     int amount = targey->getGold();
     a << amount
     message = "PC steals " + a.str() + " gold from " + to_string(target->name);
   }
  else {
    int effect1= target->damage(*this);
    int effect2 = damage(target);
    stringstream a1;
    stringstream a2;
    a1 << effect1;
    a2 << effect2;
    if (effect1 > 0) {
      message  = "PC deals " + a1.str() + "damages to (" + to_string(target->name) + "). "
        + "PC gains 5 HP. " + to_string(target->name) + " deals " + a2.str()+ " to PC.";
    } else {
      message  = "PC deals " + a1.str() + "damages to (" + to_string(target->name) + 
        "). " + to_string(target->name) + " deals " + a2.str()+ " to PC.";
    }
  }
}
void Drow::attaCK(Enemey *target) {
  target->hurt(*this);
   if (target->getHP() == 0) {
     changeGold(target->getGold());
     stringstream a;
     int amount = targey->getGold();
     a << amount
     message = "PC steals " + a.str() + " gold  from " + to_string(target->name);
   }
  else {
    int effect1= target->damage(*this);
    int effect2 = damage(target);
    stringstream a1;
    stringstream a2;
    a1 << effect1;
    a2 << effect2;
    message  = "PC deals " + a1.str() + "damages to (" + to_string(target->name) + 
      "). " + to_string(target->name) + " deals " + a2.str()+ " to PC.";
  }
}
*/


