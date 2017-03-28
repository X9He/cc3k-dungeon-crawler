#ifndef __PASSAGE_H__
#define __PASSAGE_H__
#include <iostream>
#include <vector>
#include <utility>
#include "normalCell.h"


class Passage : public NormalCell {
public:
	Passage(char type, int row, int col, int num);

	~Passage();

	void prettyPrint() override;

	void canPass() override;	
};

#endif

