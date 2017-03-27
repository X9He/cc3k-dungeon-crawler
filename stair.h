#ifndef __STAIR_H__
#define __STAIR_H__
#include <iostream>
#include <vector>
#include <utility>
#include "NormalCell.h"

class Stair : public NormalCell {	
public:
	Stair(char type, int row, int col, int num);

	~Stair();
	
	void prettyPrint() override;

	int canPass() override;

};

#endif
