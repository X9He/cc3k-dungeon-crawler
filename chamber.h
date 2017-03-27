#ifndef __CHAMBER_H__
#define __CHAMBER_H__
#include <iostream>
#include <vector>
#include <utility>
#include "NormalCell.h"

class Chamber: public Cell {
	int chamberNum;

	Item *item;

public:
	Chamber(char type, int row, int col, int num, int chamberNum);

	~Chamber();

	void prettyPrint() override;

	int canPass() override;

	void putItem();

	void removeItem();

	void getItem();
};

#endif
