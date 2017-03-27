#include "pc.h"

PC::PC(int initHP, int initAtk, int initDef, int Gold, int row, int col, int max): 
  Character(initHP, initAtk, initDef, row, col), max{max}, name{'@'} {}

PC::~PC() {}

void PC::pickUpItem(Item &i) {
  i.useItem();
}

int PC::getMax() {
  return max;
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

