
#include "enemy.h"


// enemy attack 50% miss


Enemy::Enemy(int initHP, int initAtk, int initDef, int Gold, int row, int col, PC * target, int hitChance, bool isFrozen)
: Character{initHP, initAtk, initDef, Gold, row, col}, Target(target), hitChance{hitChance}, isFrozon{isFrozen} {}

void Elf::attack(PC * player) {
    player->hurt(*this);
}

Elf(int row, int col, PC * target, int hitChance, bool isFrozen):
Enemy{140, 20, 20, 4, row, col, PC, hitChance, isFrozen}{}

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


