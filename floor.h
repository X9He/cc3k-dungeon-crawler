#ifndef __FLOOR_H__
#define __FLOOR_H__
#include <iostream>
#include <vector>
#include <utility>

class Floor {
	std::vector<vector<Cell *>> cellList;
	Display *td;
	int level;
	vector<Enemy *> enemyList;
	PC *player;

public:
	void prettyPrint();

	void clearFloor();

	void init();

	void notify();

	void spawnEnemy();

	void spawnItem();

	void spawnStair();

	void initPC();

	int getLevel();

	bool gameOver();

	Enemy* createEnemy();

	PC* createPC();

	Item* createItem();

	Treasure* createTreasure();

}