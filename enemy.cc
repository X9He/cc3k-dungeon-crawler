
#include "enemy.h"


// enemy attack 50% miss


Enemy::Enemy(int initHP, int initAtk, int initDef, int Gold, int row, int col, PC * target, int hitChance, bool isFrozen)
: Character{initHP, initAtk, initDef, Gold, row, col}, Target(target), hitChance{hitChance}, isFrozon{isFrozen} {}

void Elf::attack(PC * player) {
    player->hurt(*this);
}

Human(int row, int col, PC * target, int hitChance, bool isFrozen):
Enemy{140, 20, 20, 4, row, col, PC, hitChance, isFrozen}{}

Dward(int row, int col, PC * target, int Gold, int hitChance, bool isFrozen):
Enemy{100, 20, 30, Gold, row, col, PC, hitChance, isFrozen}{}

Elf(int row, int col, PC * target, int Gold, int hitChance, bool isFrozen):
Enemy{140, 30, 10, Gold, row, col, PC, hitChance, isFrozen}{}

Orcs(int row, int col, PC * target, int Gold, int hitChance, bool isFrozen):
Enemy{180, 30, 25, Gold, row, col, PC, hitChance, isFrozen}{}

Merchant(int row, int col, PC * target, int Gold, int hitChance, bool isFrozen):
Enemy{30, 70, 5, Gold, row, col, PC, hitChance, isFrozen}{}

Dragon(int row, int col, PC * target, int hitChance, bool isFrozen, Treasure * t):
Enemy{150, 20, 20, 6, row, col, PC, hitChance, isFrozen}, Treasure{t}{}

Halfing(int row, int col, PC * target, int Gold, int hitChance, bool isFrozen):
Enemy{100, 15, 20, Gold, row, col, PC, hitChance, isFrozen}{}

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


