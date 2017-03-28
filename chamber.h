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
	int capacity;
	int emptyAmount;
	bool hasP;

public:
	Chamber(int, bool hasP = true);
	~Chamber();
	Spawn* findSpawn(int row, int col);
	void addSpawn(Spawn *);
	void assignItem(Potion *);
	void assignCharacter(Character *);
	void assignTreasure(Treasure *, Dragon *);
	bool hasPlayer();
	int getNum();
	int getemptyAmount();
};



#endif
