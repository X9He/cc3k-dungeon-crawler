#include "enemy.h"
#include "pc.h"
using namespace std;


Enemy::Enemy(int initHP, int initAtk, int initDef, int Gold, PC * target, bool moved, int damagePC)
  : Character{initHP, initAtk, initDef, Gold}, Target(target), moved{moved},damagePC{damagePC} {}


Enemy::~Enemy() {
    Target = nullptr;
}

void Enemy::changeMoved() {
    moved = !moved;
}

bool Enemy::getMoved() {
    return moved;
}


void Enemy::changeDamagePC(int amount) {
  damagePC = amount;
}

int Enemy::getDamagePC() {
  int result = damagePC;
  damagePC = 0;
  return result;
}


// enemy attack 50% miss
// generate random number
int random2(int x, int y){
    int ran;
    ran = x + (rand() % (y - x + 1));
    return ran;
}

// generate random gold
int random_gold(){
    int ran;
    ran = 0 + (rand() % (1 - 0 + 1));
    if (ran == 0) return 1;
    return 2;
}

NormalEnemy::NormalEnemy(int initHP, int initAtk, int initDef, int Gold, PC * target, bool moved, int damagePC):
  Enemy{initHP, initAtk, initDef, Gold, target, moved, damagePC}{}

NormalEnemy::~NormalEnemy() {}


//constructors
Human::Human(PC * target):
Enemy{140, 20, 20, 0, target}{
    name = 'H';
}

Dwarf::Dwarf(PC * target):
NormalEnemy{100, 20, 30, random_gold(), target}{
    name = 'W';
}

Elf::Elf(PC * target):
NormalEnemy{140, 30, 10, random_gold(), target}{
    name = 'E';
}

Orcs::Orcs(PC * target):
NormalEnemy{180, 30, 25, random_gold(), target}{
    name = 'O';
}

Merchant::Merchant(PC * target):
Enemy{30, 70, 5, 0, target}{
    name = 'M';
}

Dragon::Dragon(PC * target, Treasure *t):
Enemy{150, 20, 20, 0, target}{
    hoard = t;
    name = 'D';
}

Halfling::Halfling(PC * target):
NormalEnemy{100, 15, 20, random_gold(), target} {
    name = 'L';
}

//destructors

Dwarf::~Dwarf(){}

Elf::~Elf(){}

Orcs::~Orcs(){}

Merchant::~Merchant(){}

Dragon::~Dragon(){}

Halfling::~Halfling(){}

Human::~Human(){}



// normal enemy hurt
void NormalEnemy::hurt(Troll *p) {
  //cout << "THERE" << endl;
    int effect = damage(p);
    //cout << effect << endl;
    changeHP(effect);
    changeDamagePC(effect);
}

void NormalEnemy::hurt(Vampire *p) {
  //cout << "Four" << endl;
    int effect = damage(p);
    //cout << effect << endl;
    changeHP(effect);
    changeDamagePC(effect);
    cout << ">!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    p->changeHP(5);
}

void NormalEnemy::hurt(Goblin *p) {
  // cout << "FIVE" << endl;
    int effect = damage(p);
    // cout << effect << endl;
    changeHP(effect);
    changeDamagePC(effect);
}

void NormalEnemy::hurt(Drow *p) {
  // cout << "SIX" << endl;
    int effect = damage(p);
    // cout << effect << endl;
    changeHP(effect);
    changeDamagePC(effect);
}

void NormalEnemy::hurt(Shade *p) {
  // cout << "SEVEN" << endl;
    int effect = damage(p);
    // cout << effect << endl;
    changeHP(effect);
    changeDamagePC(effect);
    
}

//dragon hurt

void Dragon::hurt(Troll *p) {
  // cout << "THERE" << endl;
    int effect = damage(p);
    //cout << effect << endl;
    changeHP(effect);
    changeDamagePC(effect);
}

void Dragon::hurt(Vampire *p) {
  // cout << "Four" << endl;
    int effect = damage(p);
    //cout << effect << endl;
    changeHP(effect);
    changeDamagePC(effect);
    p->changeHP(5);
    
}

void Dragon::hurt(Goblin *p) {
  // cout << "FIVE" << endl;
    int effect = damage(p);
    // cout << effect << endl;
    changeHP(effect);
    changeDamagePC(effect);
}

void Dragon::hurt(Drow *p) {
  // cout << "SIX" << endl;
    int effect = damage(p);
    //cout << effect << endl;
    changeHP(effect);
    changeDamagePC(effect);
}

void Dragon::hurt(Shade *p) {
  // cout << "SEVEN" << endl;
    int effect = damage(p);
    //cout << effect << endl;
    changeHP(effect);
    changeDamagePC(effect);
    
}

//merchant hurt

void Merchant::hurt(Troll *p) {
  //cout << "THERE" << endl;
    int effect = damage(p);
    //cout << effect << endl;
    changeHP(effect);
    changeDamagePC(effect);
}

void Merchant::hurt(Vampire *p) {
  //cout << "Four" << endl;
    int effect = damage(p);
    // cout << effect << endl;
    changeHP(effect);
    changeDamagePC(effect);
    p->changeHP(5);
}

void Merchant::hurt(Goblin *p) {
  // cout << "FIVE" << endl;
    int effect = damage(p);
    //cout << effect << endl;
    changeHP(effect);
    changeDamagePC(effect);
}

void Merchant::hurt(Drow *p) {
  // cout << "SIX" << endl;
    int effect = damage(p);
    //cout << effect << endl;
    changeHP(effect);
    changeDamagePC(effect);
}

void Merchant::hurt(Shade *p) {
  // cout << "SEVEN" << endl;
    int effect = damage(p);
    // cout << effect << endl;
    changeHP(effect);
    changeDamagePC(effect);
    
}

//human hurt

void Human::hurt(Troll *p) {
  //cout << "THERE" << endl;
    int effect = damage(p);
    // cout << effect << endl;
    changeHP(effect);
    changeDamagePC(effect);
}

void Human::hurt(Vampire *p) {
  //cout << "Four" << endl;
    int effect = damage(p);
    //cout << effect << endl;
    changeHP(effect);
    changeDamagePC(effect);
    p->changeHP(5);
}

void Human::hurt(Goblin *p) {
  //cout << "FIVE" << endl;
    int effect = damage(p);
    //cout << effect << endl;
    changeHP(effect);
    changeDamagePC(effect);
}

void Human::hurt(Drow *p) {
  //cout << "SIX" << endl;
    int effect = damage(p);
    //cout << effect << endl;
    changeHP(effect);
    changeDamagePC(effect);
}

void Human::hurt(Shade *p) {
  //cout << "SEVEN" << endl;
    int effect = damage(p);
    //cout << effect << endl;
    changeHP(effect);
    changeDamagePC(effect);
    
}

//halfing hurt

void Halfling::hurt(Troll *p) {
  // cout << "EIGHT" << endl;
    int effect = damage(p);
    int r = random2(0, 1);
    if (r == 0) {
        changeHP(effect);
	changeDamagePC(effect);
    }
}

void Halfling::hurt(Vampire *p) {
  // cout << "NINE" << endl;
    int effect = damage(p);
    int r = random2(0, 1);
    if (r == 0) {
        changeHP(effect);
	changeDamagePC(effect);
	p->changeHP(5);
    }
}

void Halfling::hurt(Goblin *p) {
    cout << "TEN" << endl;
    int effect = damage(p);
    int r = random2(0, 1);
    if (r == 0) {
        changeHP(effect);
	changeDamagePC(effect);
    }
}

void Halfling::hurt(Drow *p) {
  // cout << "ELEVEN" << endl;
    int effect = damage(p);
    int r = random2(0, 1);
    if (r == 0) {
        changeHP(effect);
	changeDamagePC(effect);
    }
}


void Halfling::hurt(Shade *p) {
  //cout << "TWELVE" << endl;
    int effect = damage(p);
    //cout << "Thirteen" << endl;
    int r = random2(0, 1);
    if (r == 0) {
        changeHP(effect);
	changeDamagePC(effect);
    }
}

//


// attack
void Elf::attack(PC * player) {
    player->hurt(*this);
}


void Dwarf::attack(PC * player) {
     player->hurt(*this);
}

void Halfling::attack(PC * player) {
     player->hurt(*this);
}

void Orcs::attack(PC * player) {
     player->hurt(*this);
}

void Merchant::attack(PC * player) {
     player->hurt(*this);
}

void Dragon::attack(PC * player) {
     player->hurt(*this);
}

void Human::attack(PC * player) {
     player->hurt(*this);
}


Treasure * Dragon::getHoard(){
    return hoard;
}


void Dragon::putHoard(Treasure *t){
  hoard = t;
}
