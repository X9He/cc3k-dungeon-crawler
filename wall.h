#ifndef __WALL_H__
#define __WALL_H__
#include <iostream>
#include <vector>
#include <utility>
#include "NormalCell.h"

class Wall: public Cell {
	char wallType;

public:
	void prettyPrint() override;

	bool canPass() override;

	Wall(int i){};

	~Wall(){};
}
