#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include "chamber.h"
using namespace std;

int random(int x, int y){
	int ran;
	srand(time(0));
	ran = x + (rand() % (y - x + 1));
	return ran;
}

Chamber::Chamber(int capacity, int emptyAmount): capacity{capacity}, emptyAmount{emptyAmount}{}

Chamber::~Chamber() {}

Spawn* Chamber::findSpawn(int row, int col){
	for (auto s: emptySpawn) {
		if(s->getRow() == row && s->getCol() == col){
			return s;
		}
	}
	return nullptr;
}

void Chamber::addSpawn(Spawn *s) {
	emptySpawn.emplace_back(s);
	++emptyAmount;
	++capacity;
}

void Chamber::assignPotion(Potion *p){
	int ran = random(1, emptyAmount);
	emptySpawn[ran]->attach(p);
	fullSpawn.emplace_back(emptySpawn[ran]);
	emptySpawn[ran].erase();
}


void Chamber::assignPC(PC *pc){
	int ran = random(1, emptyAmount);
	emptySpawn[ran]->attach(pc);
	fullSpawn.emplace_back(emptySpawn[ran]);
	emptySpawn[ran].erase();
}

void Chamber::assignEnemy(Enemy *e){
	int ran = random(1, emptyAmount);
	emptySpawn[ran]->attach(e);
	fullSpawn.emplace_back(emptySpawn[ran]);
	emptySpawn[ran].erase();
}

void Chamber::assignTreasure(Treasure *t, Dragon *d){
	int ran = random(1, emptyAmount);
	emptySpawn[ran]->attach(t);
	fullSpawn.emplace_back(emptySpawn[ran]);
	emptySpawn[ran].erase();

	int tRow = t->getRow();
	int tCol = t->getCol();

	vector<Cell*> newVec;
	int amount = 0;
	if (findSpawn(tRow, tCol + 1)!=nullptr){
		if (!findSpawn(tRow, tCol + 1).hasChar() && !findSpawn(tRow, tCol + 1).hasItem()){
		newVec.emplace_back(findSpawn(tRow, tCol + 1));
		}
		++amount;
	} 
	if (findSpawn(tRow + 1, tCol + 1)!=nullptr) {
		if (!findSpawn(tRow + 1, tCol + 1).hasChar() && !findSpawn(tRow + 1, tCol + 1).hasItem()){
		newVec.emplace_back(findSpawn(tRow + 1, tCol + 1));
		}
		++amount;
	}
	if (findSpawn(tRow + 1, tCol)!=nullptr) {
		if (!findSpawn(tRow + 1, tCol).hasChar() && !findSpawn(tRow + 1, tCol).hasItem()){
		newVec.emplace_back(findSpawn(tRow + 1, tCol));
		}
		++amount;
	}
	if (findSpawn(tRow + 1, tCol - 1)!=nullptr) {
		if (!findSpawn(tRow + 1, tCol - 1).hasChar() && !findSpawn(tRow + 1, tCol - 1).hasItem()){
		newVec.emplace_back(findSpawn(tRow + 1, tCol - 1));
		}
		++amount;
	}
	if (findSpawn(tRow, tCol - 1)!=nullptr) {
		if (!findSpawn(tRow, tCol - 1).hasChar() && !findSpawn(tRow, tCol - 1).hasItem()){
		newVec.emplace_back(findSpawn(tRow, tCol - 1));
		}
		++amount;
	}
	if (findSpawn(tRow - 1, tCol - 1)!=nullptr) {
		if (!findSpawn(tRow - 1, tCol - 1).hasChar() && !findSpawn(tRow - 1, tCol - 1).hasItem()){
		newVec.emplace_back(findSpawn(tRow - 1, tCol - 1));
		}
		++amount;
	}
	if (findSpawn(tRow - 1, tCol)!=nullptr) {
		if (!findSpawn(tRow - 1, tCol).hasChar() && !findSpawn(tRow - 1, tCol).hasItem()){
		newVec.emplace_back(findSpawn(tRow + 1, tCol + 1));
		}
		++amount;
	}
	if (findSpawn(tRow - 1, tCol + 1)!=nullptr) {
		if (!findSpawn(tRow - 1, tCol + 1).hasChar() && !findSpawn(tRow - 1, tCol + 1).hasItem()){
		newVec.emplace_back(findSpawn(tRow - 1, tCol + 1));
		}
		++amount;
	}


	bool spawned = true;
	int ranD = random(1, amount);
	newVec[ranD]->attach(d);	
	fullSpawn.emplace_back(emptySpawn[ranD]);
	emptySpawn[ranD].erase();

}
