#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include "chamber.h"
using namespace std;

int random1(int x, int y){
	int ran;
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
}



int Chamber::getEmptyAmount() {
    return emptySpawn.size();
}


vector<Spawn *> Chamber::getEmptySpawn() {
    return emptySpawn;
}

void Chamber::assignItem(Item *i){
	cout << "called assign" << endl;
	int ran;
	if (emptySpawn.size() == 0) {
			ran = 0; 
		}else {
			ran= random1(0, emptySpawn.size()-1);
		}
	emptySpawn[ran]->putItem(i);

	cout << "reached 1" << endl;
	int row = emptySpawn[ran]->getRow();
	int col = emptySpawn[ran]->getCol();
	i->changePosition(row, col);

	cout << "reached 2" << endl;
	cout << "ran is " << ran << endl;
	cout << "empty amount is " << emptySpawn.size() << endl;
	cout << "actual vector length is " << emptySpawn.size() << endl;
	cout << "to be assigned to cell type: " << emptySpawn[ran]->getType() << endl;
	emptySpawn.erase(emptySpawn.begin()+ran-1);

	cout << "reached 3" << endl;
}


void Chamber::assignCharacter(Character *c){
	int ran;
	cout << "called assign" << endl;
	if (emptySpawn.size() <= 0){
		cout << "no more empty spawns!" << endl;
	}
	else 
	{
		if (emptySpawn.size() == 0) {
			ran = 0; 
		}else {
			ran= random1(0, emptySpawn.size()-1);
		}
		Spawn *s = emptySpawn[ran];

		cout << "reached 1" << endl;

		int row = s->getRow();
		int col = s->getCol();
		c->changePosition(row, col);

		cout << "reached 2" << endl;

		s->putCharacter(c);
		cout << "ran is " << ran << endl;
		cout << "empty amount is " << emptySpawn.size() << endl;
		cout << "actual vector length is " << emptySpawn.size() << endl;
		cout << "to be assigned to cell type: " << emptySpawn[ran]->getType() << endl;
		cout << "reached 2.5" << endl;
		// cout << "assignedCharacter" << endl;
		// fullSpawn.emplace_back(emptySpawn[ran]);
		emptySpawn.erase(emptySpawn.begin()+ran-1);

		cout << "reached 3" << endl;

		if (c->getName() == '@') {
			hasP = true;
			cout << "assignedPC" << endl;
		}
	}
}


void Chamber::assignTreasure(Treasure *t, Dragon *d){
	cout << "called assign" << endl;
	int ran;
	if (emptySpawn.size() == 0) {
		ran = 0; 
	}else {
		ran= random1(0, emptySpawn.size()-1);
	}

	Spawn *newS = emptySpawn[ran];

	newS->putItem(t);

	// fullSpawn.emplace_back(emptySpawn[ran]);
	emptySpawn.erase(emptySpawn.begin()+ran-1);
	cout << "reached 1" << endl;
	int tRow = newS->getRow();
	int tCol = newS->getCol();
	t->changePosition(tRow, tCol);

	cout << "reached 2" << endl;

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
	cout << "reached 2.2" << endl;

	int ranD;
	if (amount == 0) {
		ranD = 0; 
	}else {
		ranD= random1(0, amount-1);
	}
	cout << "reached 2.3" << endl;
	cout << "ranD is " << ranD << endl;
	cout << "empty amount is " << emptySpawn.size() << endl;
	cout << "actual vector length is " << emptySpawn.size() << endl;
	cout << "to be assigned to cell type: " << newVec[ranD]->getType() << endl;
	Spawn *dragonSpawn = newVec[ranD];
	cout << "reached 2.4" << endl;
	dragonSpawn->putCharacter(d);

	cout << "reached 2.5" << endl;	
	int dRow = dragonSpawn->getRow();
	int dCol = dragonSpawn->getCol();

	cout << "reached 3" << endl;

	d->changePosition(dRow, dCol);
	// fullSpawn.emplace_back(newVec[ranD]);
	eraseEmptySpawn(dRow, dCol);
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
	for(int i = 0; i < emptySpawn.size(); ++i){
		if (emptySpawn[i]->getRow() == x && emptySpawn[i]->getCol() == y){
			index = i;
		}
	}
    emptySpawn.erase(emptySpawn.begin() + index);
}


