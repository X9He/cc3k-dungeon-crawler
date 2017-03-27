#ifndef __DOOR_H__
#define __DOOR_H__
#include <iostream>
#include <vector>
#include <utility>
#include "NormalCell.h"

class Door : public NormalCell{
public:
	Door(char type, int row, int col, int num);

	~Door();

	void prettyPrint() override;

	int canPass() override;
};

#endif
