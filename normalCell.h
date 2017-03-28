#ifndef __NORMAL_CELL_H__
#define __NORMAL_CELL_H__
#include <iostream>
#include <vector>
#include <utility>
#include "cell.h"

class NormalCell : public Cell {
	Character *charTarget;

	vector<Cell> neighbours;

public:	

	NormalCell(char type, int row, int col, int num, Character* charTarget = nullptr);

	~NormalCell();

	void attach(Cell *c);

	void putCharacter(Character *ch);

	void removeCharacter();

	Character *getCharacter();
};

#endif
