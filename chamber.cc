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

Chamber::Chamber(int chamberNumber, bool hasP): chamberNumber{chamberNumber}, hasP{hasP}{}

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

int Chamber::getemptyAmount() {
    return emptyAmount;
}
vector<Spawn *> Chamber::getemptySpawn() {
    return emptySpawn;
}

void Chamber::assignItem(Item *i){
	int ran = random(0, emptyAmount-1);
	emptySpawn[ran]->putItem(i);
	fullSpawn.emplace_back(emptySpawn[ran]);
	emptySpawn.erase(emptySpawn.begin()+ran);
}


void Chamber::assignCharacter(Character *c){
	int ran = random(0, emptyAmount-1);
	emptySpawn[ran]->putCharacter(c);
	fullSpawn.emplace_back(emptySpawn[ran]);
	emptySpawn.erase(emptySpawn.begin()+ran);
	if (c->getName() == '@') {
		hasP = true;
	}
}


void Chamber::assignTreasure(Treasure *t, Dragon *d){
	int ran = random(0, emptyAmount-1);
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


	int ranD = random(1, amount);
	newVec[ranD]->putCharacter(d);	
	fullSpawn.emplace_back(emptySpawn[ranD]);
	emptySpawn.erase(emptySpawn.begin()+ranD);

}


void Chamber::setHasPlayer(bool t){
	hasP = t;
}


bool Chamber::hasPlayer(){
	return hasP;
}



int Chamber::getNum(){
	return chamberNumber;
}


void Chamber::erase_emptySpawn(int i) {
    emptySpawn.erase(i);
}




