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
	void prettyPrint() override;

	int canPass() override;

	void putItem();

	void removeItem();

	void getItem();
}

#endif
