#ifndef __FLOOR_H__
#define __FLOOR_H__
#include <iostream>
#include <vector>
#include <utility>

class Floor {
	std::vector<vector<Cell *>> cellList;
	Display *td;
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

	void init();

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

	void simpleMoveCharacter(int, int, int, int);

	vector<Cell*> produceSurroundEmpty(int, int);

	Cell* checkPC(int, int);
};

#endif
