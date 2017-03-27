#ifndef __WALL_H__
#define __WALL_H__
#include <iostream>
#include <vector>
#include <utility>
#include "Cell.h"

class Wall: public Cell {
	char wallType;

public:
	Wall(char type, int row, int col, int num);

	~Wall();

	void prettyPrint() override;

	bool canPass() override;

};

#endif
