#ifndef __CHAMBER_H__
#define __CHAMBER_H__
#include <iostream>
#include <vector>
#include <utility>
#include "spawn.h"
#include "potion.h"
#include "item.h"
#include "enemy.h"
#include <vector>

class Chamber {
	
	int chamberNumber;
	int capacity;
	int emptyAmount;
	bool hasP;
    std::vector<Spawn *> emptySpawn;
    std::vector<Spawn *> fullSpawn;
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
    int getemptyAmount();
	int getNum();
    std::vector<Spawn *> getemptySpawn();
    void erase_emptySpawn(int);
};



#endif
