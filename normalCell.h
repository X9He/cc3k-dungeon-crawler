#ifndef __NORMAL_CELL_H__
#define __NORMAL_CELL_H__
#include <iostream>
#include <vector>
#include <utility>
#include "Cell.h"

class NormalCell : public Cell {
	Character *charTarget;

	vector<Cell> neighbours;

public:	

	void attach(Cell *c);

	void putCharacter(Character *ch);

	void removeCharacter();

	Character *getCharacter();
}
