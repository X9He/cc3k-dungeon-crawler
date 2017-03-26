#include "normalCell.h"
#include <iostream>
#include <vector>
#include <utility>
using namespace std;


void NormalCell::attach(Cell *c){
	neighbours.emplaceback(c);
}

void NormalCell::putCharacter(Character *c) {
	charTarget = c;
}

void NormalCell::removeCharacter(){
	charTarget = nullptr;
}

Character* NormalCell::getCharacter(){
	return Character;
}