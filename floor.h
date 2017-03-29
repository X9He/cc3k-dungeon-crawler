#ifndef __FLOOR_H__
#define __FLOOR_H__
#include <iostream>
#include <vector>
#include <utility>
#include "cell.h"
#include "enemy.h"
#include "pc.h"
#include "chamber.h"
#include "treasure.h"
#include "potion.h"

class Floor {
	std::vector<std::vector<Cell *>> cellList;
	int level;
	std::vector<Enemy *> enemyList;
	PC *player;
	std::vector<Chamber *> roomList;
	std::vector<Item *> itemList;

public:
	Floor(PC*);

	~Floor();
	
	void prettyPrint();

	void clearFloor();

	void init(PC*);

	void initPC(char);

	int getLevel();

	bool gameOver();

	void createEnemy(int);

	void createPotion(int);

	void createTreasure(int);

	void createStair();

	bool movePlayer(std::string dir);

	void updateEnemy();

	void deleteEnemy();

	void simpleMoveCharacter(int, int, int, int);

	std::vector<Cell*> produceSurroundEmpty(int, int);

	Cell* checkPC(int, int);
};

#endif
