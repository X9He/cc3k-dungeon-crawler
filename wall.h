#ifndef __WALL_H__
#define __WALL_H__
#include <iostream>
#include <vector>
#include <utility>
#include "cell.h"

class Wall: public Cell {
	// char wallType;

public:
	Wall(char type, int row, int col);

	~Wall() override;

	void prettyPrint() override;

	// bool canPass();

};

#endif
