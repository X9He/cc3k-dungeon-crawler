#include "normalCell.h"
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

NormalCell::NormalCell(char type, int row, int col, Character *c): Cell(type, row, col), charTarget{charTarget} {}

NormalCell::~NormalCell(){}


// void NormalCell::attach(Cell *c){
// 	neighbours.emplaceback(c);
// }

void NormalCell::putCharacter(Character *c) {
	charTarget = c;
}

void NormalCell::removeCharacter(){
	charTarget = nullptr;
}

Character* NormalCell::getCharacter(){
	return charTarget;
}

bool NormalCell::hasCharacter(){
	return (charTarget != nullptr);
}
