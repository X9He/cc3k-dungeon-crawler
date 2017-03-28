
#include "enemy.h"

Human(PC * target):
Enemy{140, 20, 20, 4, PC}{}

Dward(PC * target):
Enemy{100, 20, 30, random_gold(), PC}{}

Elf(PC * target):
Enemy{140, 30, 10, random_gold(), PC}{}

Orcs(PC * target):
Enemy{180, 30, 25, random_gold(), PC}{}

Merchant(PC * target):
Enemy{30, 70, 5, random_gold(), PC}{}

Dragon(PC * target, Treasure * t):
Enemy{150, 20, 20, random_gold(), PC}, Treasure{t}{}

Halfing(PC * target):
Enemy{100, 15, 20, random_gold(), PC} {}
      
      
// enemy attack 50% miss
// generate random number
int random(int x, int y){
 int ran;
 srand(time(0));
 ran = x + (rand() % (y - x + 1));
 return ran;
}

// generate random gold
int random_gold(){
 int ran;
 srand(time(0));
 ran = 0 + (rand() % (1 - 0 + 1));
 if (ran == 0) return 1;
 return 2;
}

Enemy::Enemy(int initHP, int initAtk, int initDef, int Gold, PC * target, bool isFrozen, bool moved)
: Character{initHP, initAtk, initDef, Gold}, Target(target), isFrozon{isFrozen}, moevd{moved} {}


void Enemy::changeFrozen() {
    isFrozen = !isFrozen;
}

void Enemy::hurt(PC *p) {
    int effect = damage(p);
    changeHP(effect);
}

void Enemy::changeMoved() {
    moved = !moved;
}

bool Enemy::getMoved() {
    return moved;
}

void Elf::attack(PC * player) {
    int rad = random(0, 1);
    if (rad == 0) {
    player->hurt(*this);
    }
}


void Dward::attack(PC * player) {
    int rad = random(0, 1);
    if (rad == 0) {
    player->hurt(*this);
    }
}

void Halfing::attack(PC * player) {
    int rad = random(0, 1);
    if (rad == 0) {
    player->hurt(*this);
    }
}

void Orcs::attack(PC * player) {
    int rad = random(0, 1);
    if (rad == 0) {
    player->hurt(*this);
    }
}

void Merchant::attack(PC * player) {
   int rad = random(0, 1);
    if (rad == 0) {
    player->hurt(*this);
    }
}

void Dragon::attack(PC * player) {
    int rad = random(0, 1);
    if (rad == 0) {
    player->hurt(*this);
    }
}

void Human::attack(PC * player) {
    int rad = random(0, 1);
    if (rad == 0) {
    player->hurt(*this);
    }
}


