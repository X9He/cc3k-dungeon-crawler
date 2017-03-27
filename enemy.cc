
#include "enemy.h"


// enemy attack 50% miss


Enemy::Enemy(int initHP, int initAtk, int initDef, int col, PC * target, bool isFrozen, bool moved)
: Character{initHP, initAtk, initDef, Gold, row, col}, Target(target), isFrozon{isFrozen}, moevd{moved} {}

void Enemy::changeFrozen() {
    isFrozen = !isFrozen;
}

void Enemy::hurt(PC *p) {
    int effect = p->damage(p);
    changeHP(effect);
}

void Enemy::changeMoved() {
    moved = !moved;
}

bool Enemy::getMoved() {
    return moved;
}

void Elf::attack(PC * player) {
    player->hurt(*this);
}

Human(PC * target):
Enemy{140, 20, 20, 4, PC, false}{}

Dward(PC * target):
Enemy{100, 20, 30, PC, false}{}

Elf(PC * target):
Enemy{140, 30, 10, PC, false}{}

Orcs(PC * target):
Enemy{180, 30, 25, PC, false}{}

Merchant(PC * target):
Enemy{30, 70, 5, PC, false}{}

Dragon(PC * target, Treasure * t):
Enemy{150, 20, 20, PC, false}, Treasure{t}{}

Halfing(PC * target):
Enemy{100, 15, 20, PC, false}{}

void Dward::attack(PC * player) {
    player->hurt(*this);
}

void Halfing::attack(PC * player) {
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


