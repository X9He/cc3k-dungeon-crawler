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
	vector<Chamber *> roomList;

public:
	Floor(PC*);

	~Floor();
	
	void prettyPrint();

	void clearFloor();

	void init();

	void notify();

	void initPC(char);

	int getLevel();

	bool gameOver();

	void createEnemy(int);

	void createPotion(int);

	void createTreasure(int);

	void createStair();

	bool movePlayer(PC *);

	void updateEnemy();

	void deleteEnemy();

	void simpleMovePlayer(int, int, int, int);

};

#endif
