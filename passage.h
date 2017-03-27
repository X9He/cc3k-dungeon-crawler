#ifndef __PASSAGE_H__
#define __PASSAGE_H__
#include <iostream>
#include <vector>
#include <utility>
#include "NormalCell.h"


class Passage : public NormalCell {

	
public:
	void prettyPrint() override;

	void canPass() override;	
}