#ifndef __CHAMBER_H__
#define __CHAMBER_H__
#include <iostream>
#include <vector>
#include <utility>
#include "spawn.h"

class Chamber {
	vector<Spawn *> emptySpawn;
	vector<Spawn *> fullSpawn;
	int chamberNumber;
	int emptyAmount;

public:
	Chamber(int);
	~Chamber();
	Spawn* findSpawn(int row, int col);
	void addSpawn(Spawn *);
	void assignItem(Potion *);
	void assignCharacter(Character *);
	void assignTreasure(Treasure *, Dragon *);
};



#endif