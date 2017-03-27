#ifndef __SPAWN_H__
#define __SPAWN_H__
#include <iostream>
#include <vector>
#include <utility>
#include "NormalCell.h"

class Spawn: public Cell {
	int chamberNum;

	Item *item;

public:
	Spawn(char type, int row, int col, int num, int chamberNum);

	~Spawn();

	void prettyPrint() override;

	int canPass() override;

	void putItem();

	void removeItem();

	void getItem();
};

#endif
