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
	Floor(PC*);

	~Floor();
	
	void prettyPrint();

	void clearFloor();

	void init();

	void notify();

	void initPC();

	int getLevel();

	bool gameOver();

	void createEnemy();

	void createPC();

	void createItem();

	void createTreasure();

};

#endif
