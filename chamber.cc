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

void Chamber::print(){
	int size = emptySpawn.size();
	cout << size;
	for (int i = 0; i < size; ++i){
		cout << emptySpawn[i]->getType();
	}
	cout << endl;
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
		ran= random1(0, emptySpawn.size()-1);
		while(emptySpawn[ran]->hasCharacter()){
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


vector<vector<int>> generateEightCord(int i, int j) {
	vector<vector<int>> v;
	vector<int> v1;
	v1.emplace_back(i+1);
	v1.emplace_back(j);
	v.emplace_back(v1);
	vector<int> v2;
	v2.emplace_back(i-1);
	v2.emplace_back(j);
	v.emplace_back(v2);
	vector<int> v3;
	v3.emplace_back(i);
	v3.emplace_back(j+1);
	v.emplace_back(v3);
	vector<int> v4;
	v4.emplace_back(i);
	v4.emplace_back(j-1);
	v.emplace_back(v4);
	vector<int> v5;
	v5.emplace_back(i+1);
	v5.emplace_back(j+1);
	v.emplace_back(v5);
	vector<int> v6;
	v6.emplace_back(i-1);
	v6.emplace_back(j+1);
	v.emplace_back(v6);
	vector<int> v7;
	v7.emplace_back(i+1);
	v7.emplace_back(j-1);
	v.emplace_back(v7);
	vector<int> v8;
	v8.emplace_back(i-1);
	v8.emplace_back(j-1);
	v.emplace_back(v8);
	return v;	
}

void Chamber::assignTreasure(Treasure *t, Dragon *d){
	cout << "called assign" << endl;
	//generate random number
	int ran;
	if (emptySpawn.size() == 0) {
		ran = 0; 
	}else {
		ran= random1(0, emptySpawn.size()-1);
	}

	//select empty spawn cell
	Spawn *newS = emptySpawn[ran];

	//put item in spawn cell
	newS->putItem(t);

	//erase spawned cell from list
	emptySpawn.erase(emptySpawn.begin()+ran-1);


	cout << "treasure assignment complete" << endl;
	int tRow = newS->getRow();
	int tCol = newS->getCol();

	cout << "treasure cordinates: x " << tRow << " y " << tCol << endl;
	t->changePosition(tRow, tCol);

	cout << "begin spawning dragon" << endl;

	vector<Spawn*> newVec;
	vector<vector<int>> intVec = generateEightCord(tRow, tCol);

	for (int i = 0; i < 8 ; ++i) {
		int r = intVec[i][0];
		int c = intVec[i][1];
		Spawn *s = findSpawn(r, c);
		if(s!=nullptr){
			newVec.emplace_back(s);
		}
	}
	cout << "reached 2.2" << endl;

	int size = newVec.size();	
	int ranD= random1(0, size-1);
	

	cout << "reached 2.3" << endl;
	cout << "size is "<< size << " ranD is " << ranD << endl;
	cout << "empty amount is " << emptySpawn.size() << " and actual vector length is " << emptySpawn.size() << endl;
	cout << "to be assigned to cell type: " << newVec[ranD]->getType() << endl;
	Spawn *dragonSpawn = newVec[ranD];
	cout << "reached 2.4" << endl;
	dragonSpawn->putCharacter(d);

	cout << "reached 2.5" << endl;	
	int dRow = dragonSpawn->getRow();
	int dCol = dragonSpawn->getCol();

	cout << "reached 3" << endl;

	d->changePosition(dRow, dCol);
	cout << "reached 4" << endl;
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


