#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include "chamber.h"
using namespace std;

int random1(int x, int y){
	int ran;
	srand(time(0));
	ran = x + (rand() % (y - x + 1));
	return ran;
}

Chamber::Chamber(int chamberNumber, bool hasP, int capacity, int emptyAmount): chamberNumber{chamberNumber}, hasP{hasP}, capacity{capacity}, emptyAmount{emptyAmount}{}

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
}



int Chamber::getEmptyAmount() {
    return emptyAmount;
}


vector<Spawn *> Chamber::getEmptySpawn() {
    return emptySpawn;
}

void Chamber::assignItem(Item *i){
	int ran = random1(0, emptyAmount-1);
	emptySpawn[ran]->putItem(i);
	fullSpawn.emplace_back(emptySpawn[ran]);
	emptySpawn.erase(emptySpawn.begin()+ran);
	--emptyAmount;
}


void Chamber::assignCharacter(Character *c){
	if (emptyAmount <= 0){
		cout << "no more empty spawns!" << endl;
	} else {
		int ran = random1(0, emptyAmount-1);
		emptySpawn[ran]->putCharacter(c);
		// cout << "assignedCharacter" << endl;
		fullSpawn.emplace_back(emptySpawn[ran]);
		emptySpawn.erase(emptySpawn.begin()+ran);
		if (c->getName() == '@') {
			hasP = true;
			cout << "assignedPC" << endl;
		}
		--emptyAmount;		
	}
}


void Chamber::assignTreasure(Treasure *t, Dragon *d){
	int ran = random1(0, emptyAmount-1);
	Spawn *newS = emptySpawn[ran];
	emptySpawn[ran]->putItem(t);
	fullSpawn.emplace_back(emptySpawn[ran]);
	emptySpawn.erase(emptySpawn.begin()+ran);

	int tRow = newS->getRow();
	int tCol = newS->getCol();

	vector<Spawn*> newVec;
	int amount = 0;
	if (findSpawn(tRow, tCol + 1)!=nullptr){
		if (!findSpawn(tRow, tCol + 1)->hasCharacter() && !findSpawn(tRow, tCol + 1)->hasItem()){
		newVec.emplace_back(findSpawn(tRow, tCol + 1));
		}
		++amount;
	} 
	if (findSpawn(tRow + 1, tCol + 1)!=nullptr) {
		if (!findSpawn(tRow + 1, tCol + 1)->hasCharacter() && !findSpawn(tRow + 1, tCol + 1)->hasItem()){
		newVec.emplace_back(findSpawn(tRow + 1, tCol + 1));
		}
		++amount;
	}
	if (findSpawn(tRow + 1, tCol)!=nullptr) {
		if (!findSpawn(tRow + 1, tCol)->hasCharacter() && !findSpawn(tRow + 1, tCol)->hasItem()){
		newVec.emplace_back(findSpawn(tRow + 1, tCol));
		}
		++amount;
	}
	if (findSpawn(tRow + 1, tCol - 1)!=nullptr) {
		if (!findSpawn(tRow + 1, tCol - 1)->hasCharacter() && !findSpawn(tRow + 1, tCol - 1)->hasItem()){
		newVec.emplace_back(findSpawn(tRow + 1, tCol - 1));
		}
		++amount;
	}
	if (findSpawn(tRow, tCol - 1)!=nullptr) {
		if (!findSpawn(tRow, tCol - 1)->hasCharacter() && !findSpawn(tRow, tCol - 1)->hasItem()){
		newVec.emplace_back(findSpawn(tRow, tCol - 1));
		}
		++amount;
	}
	if (findSpawn(tRow - 1, tCol - 1)!=nullptr) {
		if (!findSpawn(tRow - 1, tCol - 1)->hasCharacter() && !findSpawn(tRow - 1, tCol - 1)->hasItem()){
		newVec.emplace_back(findSpawn(tRow - 1, tCol - 1));
		}
		++amount;
	}
	if (findSpawn(tRow - 1, tCol)!=nullptr) {
		if (!findSpawn(tRow - 1, tCol)->hasCharacter() && !findSpawn(tRow - 1, tCol)->hasItem()){
		newVec.emplace_back(findSpawn(tRow + 1, tCol + 1));
		}
		++amount;
	}
	if (findSpawn(tRow - 1, tCol + 1)!=nullptr) {
		if (!findSpawn(tRow - 1, tCol + 1)->hasCharacter() && !findSpawn(tRow - 1, tCol + 1)->hasItem()){
		newVec.emplace_back(findSpawn(tRow - 1, tCol + 1));
		}
		++amount;
	}


	int ranD = random1(0, amount-1);
	Spawn *dragonSpawn = newVec[ranD];
	dragonSpawn->putCharacter(d);	
	int dRow = dragonSpawn->getRow();
	int dCol = dragonSpawn->getCol();
	fullSpawn.emplace_back(newVec[ranD]);
	eraseEmptySpawn(dRow, dCol);
	--emptyAmount;
	--emptyAmount;
}


// void Chamber::setHasPlayer(bool t){
// 	hasP = t;
// }


bool Chamber::hasPlayer(){
	return hasP;
}



int Chamber::getNum(){
	return chamberNumber;
}


void Chamber::eraseEmptySpawn(int i) {
    emptySpawn.erase(emptySpawn.begin() + i);
}


void Chamber::eraseEmptySpawn(int x, int y) {
	int index;
	for(int i = 0; i < emptyAmount; ++i){
		if (emptySpawn[i]->getRow() == x && emptySpawn[i]->getCol() == y){
			index = i;
		}
	}
    emptySpawn.erase(emptySpawn.begin() + index);
}


