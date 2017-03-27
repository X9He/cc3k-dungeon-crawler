//
//  enemy.cpp
//  CC3K
//
//  Created by Li on 2017-03-26.
//  Copyright © 2017 Wanxin Li. All rights reserved.
//

#include "enemy.hpp"


// enemy attack 50% miss


Enemy::Enemy(int initHP, int initAtk, int initDef, int Gold, int row, int col, int dropAmount, PC * target, int hitChance, bool isFrozen)
: Character{initHP, initAtk, initDef, Gold, row, col}, dropAmount(dropAmount), Target(target), hitChance{hitChance}, isFrozon{isFrozen} {}

void Elf::attack(PC * player) {
    player->hurt(*this);
}

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

void Troll::hurt(Elf & e) {
    damage(e);
}

void Vampire::hurt(Elf & e) {
    damage(e, 2);
}

void Goblin::hurt(Elf & e) {
    damage(e, 2);
}

void Drow::hurt(Elf & e) {
    damage(e, 2);
}

void PC::attack(Elf & e) {
    damage(e, 2);
}

void Troll::hurt(Dwarf & d) {
    damage(d);
}

void Vampire::hurt(Dwarf & d) {
    damage(d);
}

void Goblin::hurt(Dwarf & d) {
    damage(d);
}

void Drow::hurt(Dwarf & d) {
    damage(d);
}

void PC::hurt(Dwarf & d) {
    damage(d);
}

void Troll::hurt(Halfing & h) {
    damage(h);
}

void Vampire::hurt(Halfing & h) {
    damage(h);
}

void Goblin::hurt(Halfing & h) {
    damage(h);
}

void Drow::hurt(Halfing & h) {
    damage(h);
}

void PC::hurt(Halfing & h) {
    damage(h);
}

void Troll::hurt(Orcs & o) {
    damage(o);
}

void Vampire::hurt(Orcs & o) {
    damage(o);
}

void Goblin::hurt(Orcs & o) {
    damage(o, 1.5);
}

void Drow::hurt(Orcs & o) {
    damage(o);
}

void PC::hurt(Orcs & o) {
    damage(o);
}

void Troll::hurt(Merchant & m) {
    damage(m);
}

void Vampire::hurt(Merchant & m) {
    damage(m);
}

void Goblin::hurt(Merchant & m) {
    damage(m);
}

void Drow::hurt(Merchant & m) {
    damage(m);
}

void PC::hurt(Merchant & m) {
    damage(m);
}

void Troll::hurt(Dragon & d) {
    damage(d);
}

void Vampire::hurt(Dragon & d) {
    damage(d);
}

void Goblin::hurt(Dragon & d) {
    damage(d);
}

void Drow::hurt(Dragon & d) {
    damage(d);
}

void PC::hurt(Dragon & d) {
    damage(d);
}

void Troll::hurt(Human & h) {
    damage(h);
}

void Vampire::hurt(Human & h) {
    damage(h);
}

void Goblin::hurt(Human & h) {
    damage(h);
}

void Drow::hurt(Human & h) {
    damage(h);
}

void PC::hurt(Human & h) {
    damage(h);
}


