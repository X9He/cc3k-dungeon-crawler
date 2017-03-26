#ifndef __DOOR_H__
#define __DOOR_H__
#include <iostream>
#include <vector>
#include <utility>
#include "NormalCell.h"

class Door : public NormalCell{
public:
	void prettyPrint() override;

	void canPass() override;
}