#include "normalCell.h"
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

NormalCell::NormalCell(char type, int row, int col, int num): Cell(type, row, col, num) {}

NormalCell::~NormalCell(){}


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