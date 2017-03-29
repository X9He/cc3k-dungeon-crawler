#ifndef __CHAMBER_H__
#define __CHAMBER_H__
#include <iostream>
#include <vector>
#include <utility>
#include "spawn.h"
#include "potion.h"
#include "item.h"
#include "enemy.h"

class Chamber {
	std::vector<Spawn *> emptySpawn;
	std::vector<Spawn *> fullSpawn;
	int chamberNumber;
	int capacity;
	int emptyAmount;
	bool hasP;

public:
	Chamber(int, bool hasP = true);
	~Chamber();
	Spawn* findSpawn(int row, int col);
	void addSpawn(Spawn *);
	void assignItem(Item *);
	void assignCharacter(Character *);
	void assignTreasure(Treasure *, Dragon *);
	void setHasPlayer(bool);
	bool hasPlayer();
	int getNum();
};



#endif
