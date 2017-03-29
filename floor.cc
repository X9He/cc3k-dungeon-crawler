#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <typeinfo>
#include "floor.h"
#include "wall.h"
#include "passage.h"
#include "door.h"
#include "stair.h"
#include "spawn.h"


using namespace std;

// Probability cur{2/9, 3/18, 5/18, 1/9, 1/9, 1/9};

int random(int x, int y){
	int ran;
	srand(time(0));
	ran = x + (rand() % (y - x + 1));
	return ran;
}

vector<vector<int>> genEightCord(int i, int j) {
	vector<vector<int>> v;
	vector<int> v1;
	v1.emplace_back(i+1);
	v1.emplace_back(j);
	v.emplace_back(v1);
	vector<int> v2;
	v1.emplace_back(i-1);
	v1.emplace_back(j);
	v.emplace_back(v2);
	vector<int> v3;
	v1.emplace_back(i);
	v1.emplace_back(j+1);
	v.emplace_back(v3);
	vector<int> v4;
	v1.emplace_back(i);
	v1.emplace_back(j-1);
	v.emplace_back(v4);
	vector<int> v5;
	v1.emplace_back(i+1);
	v1.emplace_back(j+1);
	v.emplace_back(v5);
	vector<int> v6;
	v1.emplace_back(i-1);
	v1.emplace_back(j+1);
	v.emplace_back(v6);
	vector<int> v7;
	v1.emplace_back(i+1);
	v1.emplace_back(j-1);
	v.emplace_back(v7);
	vector<int> v8;
	v1.emplace_back(i-1);
	v1.emplace_back(j-1);
	v.emplace_back(v8);
	return v;	
}

void Floor::prettyPrint(){
	for (int i = 0; i < cellList.size() ; ++i){
		for (int j = 0; j < cellList[i].size(); ++j){
			cellList[i][j]->prettyPrint();
		// char type  = cellList[i][j]->getType();
		// 	if (type == ' '|| type == '|' || type == '-') {
		// 		cout << type;
		// 	} else if (cellList[i][j]->hasCharacter()) {
		// 		cout << cellList[i][j]->getCharacter->getName();
		// 	} else if (Spawn *s=dynamic_cast<Spawn *>(cellList[i][j])) {
		// 		if (cellList[i][j]->hasItem()) {
		// 			if (Potion *p=dynamic_cast<Potion *>(cellList[i][j]->getItem())) {
		// 				cout << 'P';
		// 			} else {
		// 				cout << 'G';
		// 			}
		// 		}
		// 	}
		}
		cout << endl;
	}
}

void Floor::clearFloor(){
	for (auto e: enemyList) {
		delete e;
	}
	enemyList.clear();
	for (int i = 0; i < cellList.size() ; ++i){
		for (int j = 0; j < cellList[i].size(); ++j){
			delete cellList[i][j];
		}
	}

	for (int i = 0; i < roomList.size(); ++i){
		delete roomList[i];
	}

	for (int i = 0; i < itemList.size(); ++i){
		delete itemList[i];
	}
}

void Floor::init(PC *p){
	ifstream fs;
	fs.open("cc3k.txt");
	string s;
	int i = 0;
	while(getline(fs, s))
	{

		vector<Cell*> newVec;
		char c;

		for(int j = 0; j < s.size(); ++j)
		{
			c = s[j];
			Cell *newC;

			if (c == ' ' || c == '-' || c == '|') 
			{
				newC = new Wall{c, i, j};
			} 
			else if (c == '#') 
			{
				newC = new Passage{c, i , j};
			} else if (c == '.') 
			{
				newC = new Spawn{c, i, j};
			} else
			{
				newC = new Door{c, i, j};
			} 
			newVec.emplace_back(newC);
		}


		cellList.emplace_back(newVec);
		++i;
	}
	fs.close();

	//Chamber 1
	for (int i = 3; i <= 6; ++i){
		Chamber *newChamber = new Chamber{1};
		for (int j = 3; j <= 28; ++j){
			newChamber->addSpawn(cellList[i][j]);
		}
		roomList.emplace_back(newChamber);
	}

	//Chamber 2
	Chamber *chamberTwo = new Chamber{2};
	for (int i = 3; i <= 6; ++i){
		for (int j = 39; j <= 72; ++j){
			if (cellList[i][j]->getType() == '.'){
				chamberTwo->addSpawn(cellList[i][j]);
			}
		}
	}
	for (int i = 7; i <= 12; ++i){
		for (int j = 61; j <= 75; ++j){
			if (cellList[i][j]->getType() == '.'){
				chamberTwo->addSpawn(cellList[i][j]);
			}
		}
	}
	roomList.emplace_back(chamberTwo);

	//Chamber 3
	Chamber *chamberThree = new Chamber{3};
	for (int i = 10; i <= 12; ++i){
		for (int j = 38; j <= 49; ++j){
			chamberThree->addSpawn(cellList[i][j]);
		}
	}
	roomList.emplace_back(chamberThree);


	//Chamber 4	
	Chamber *chamberFour = new Chamber{4};
	for (int i = 15; i <= 21; ++i){
		for (int j = 4; j <= 24; ++j){
			chamberFour->addSpawn(cellList[i][j]);
		}
	}
	roomList.emplace_back(chamberFour);


	//Chamber 5
	Chamber *chamberFive = new Chamber{5};
	for (int i = 19; i <= 21; ++i){
		for (int j = 37; j <= 75; ++j){
			chamberFive->addSpawn(cellList[i][j]);
		}
	}
	for (int i = 16; i <= 18; ++i){
		for (int j = 65; j <= 75; ++j){
			chamberFive->addSpawn(cellList[i][j]);
		}
	}
	roomList.emplace_back(chamberFive);

	int rP = random(0,4);
	roomList[rP]->assignCharacter(p);
	createEnemy(20);
	createTreasure(10);
	createPotion(10);
	createStair();
}



int Floor::getLevel(){
	return level;
}

bool Floor::gameOver(){
	if (player->getHP() <= 0){
		return true;
	}
	return false;
}

void Floor::createEnemy(int num){
	while (num > 0){
		int r = random(1, 18);
		if (r >= 1 && r <= 4) {
			Enemy *newE = new Human{player};
			enemyList.emplace_back(newE);
		} else if (r >= 5 && r <= 7) {
			Enemy *newE = new Dwarf{player};
			enemyList.emplace_back(newE);
		} else if (r >= 8 && r <= 12){
			Enemy *newE = new Halfling{player};
			enemyList.emplace_back(newE);
		} else if (r >= 13 && r <= 14) {
			Enemy *newE = new Elf{player};
			enemyList.emplace_back(newE);
		} else if (r >= 15 && r <= 16) {
			Enemy *newE = new Orc{player};
			enemyList.emplace_back(newE);
		} else {
			Enemy *newE = new Merchant{player};
			enemyList.emplace_back(newE);
		}
		--num;
	}
}


void Floor::createPotion(int num){
	while(num > 0) {
		int r = random(1, 6);
		if (r == 1) {
			Item *newP = new RH{};
			itemList.emplace_back(newP);
		} else if (r == 2) {
			Item *newP = new BA{};
			itemList.emplace_back(newP);
		} else if (r == 3){
			Item *newP = new BD{};
			itemList.emplace_back(newP);
		} else if (r == 4) {
			Item *newP = new PH{}; 
			itemList.emplace_back(newP);
		} else if (r == 5) {
			Item *newP = new WA{};
			itemList.emplace_back(newP);
		} else {
			Item *newP = new WD{};
			itemList.emplace_back(newP);
		}
		--num;
	}

}

void Floor::createTreasure(int num){
	while(num > 0){
		int r = random(1, 8);
		int chamberR = random(1,5);
		// Dragon Hoard
		if (r == 1) {
			Item *newT = new DH{};
			itemList.emplace_back(newT);
			Character *newD = new Dragon{player, newT};
			enemyList.emplace_back(newD);
			roomList[chamberR]->assignTreasure(newT, newD);
		}
		// Small Hoard
		 else if (r >=2 && r <= 4) {
			Item *newT = new Small{};
			itemList.emplace_back(newT);
			roomList[chamberR]->assignItem(newT);
		} 
		// Normal Hoard
		else {
			Item *newT = new Normal{};
			itemList.emplace_back(newT);
			roomList[chamberR]->assignItem(newT);
		}
		--num;
	}
}

void Floor::createStair(){

    int room_hasplayer;
    for (int i = 1; i < 6; i++) {
        roomList[i].hasplayer();
        room_hasplayer = i;
    }
    int r1 = random(1,4);
    int stair_room = r1;
    if (r1 > room_hasplayer) {
    	stair_room++;
    }

    int num = roomList[stair_room].getemptyAmount();
    int r2 = random(1, num);
    Spawn * tar = emptySpawn[r2];
      
    static_cast<Stair>(*tar);
    vector<Spawn*>::iterator pos = find(myVector.begin(), myVector.end(), tar);
    emptySpawn.erase(pos);
    fullSpawn.emplace_back(tar);
      

}

bool Floor::movePlayer(string dir){
	// get current position of player
	int curRow = player.getRow();
	int curCol = player.getCol();

	// compute new position x and y
	int newRow = curRow;
	int newCol = curCol;
	if (dir == "no") {
		++newCol;
	}
	if (dir == "so") {
		--newCol;		
	}
	if (dir == "ea") {
		++newRow;
	}
	if (dir == "we") {
		--newRow;
	}
	if (dir == "ne") {
		++newCol;
		++newRow;
	}
	if (dir == "nw") {
		--newRow;
		++newCol;
	}
	if (dir == "se") {
		++newRow;
		--newCol;
	}
	if (dir == "sw") {
		--newRow;
		--newCol;
	}


	// find the cell player wants to move to
	Cell* curCell = cellList[newRow][newCol];
	char c = curCell->getType();


	// if the next cell is wall, spawn, passage, door, or stairs

	//WALL
	if (c == ' ' || c == '-' || c == '|') {
		return true;
	} 
	//SPAWN
	else if (c == '.')
	{
		// Spawn has an enemy
		if (curCell->hasChar())
		{
			Enemy *curE = cur->getCharacter();
			player.attack(curE);

			if (curE->getHP() <= 0) 
			{
				player->getGold(curE);
				curCell->putChar(nullptr);
				deleteEnemy(curE->getRow(), curE->getCol());
			}
		}

		// Spawn has an item
		else if (curCell->hasItem()) {
			Item *curI = curCell->getItem();
			curI->useItem();
			simpleMoveCharacter(newRow, newCol);
			curCell.putItem(nullptr);
		} 

		// Spawn is empty
		else {
			simpleMoveCharacter(newRow, newCol);
		}
	} 
	//PASSAGE
	else if (c == '#'){
		simpleMoveCharacter(newRow, newCol);
		return true;
	} 
	//DOOR
	else if (c == '+'){
		simpleMoveCharacter(newRow, newCol);
		return true;
	} 
	//STAIRS
	else {
		return false;
	}
}


void Floor::updateEnemy(){
	int x = cellList.size();
	int y = cellList[0].size();

	for(int i = 0; i < x; ++i){
		for (int j = 0; j < y; ++j){

			//check if cell has character
			Character *c = cellList[i][j]->getChar;
			if (c == nullptr){
				continue;
			} 

			//cell has player
			else if (c->getName() == '@') {
				continue;
			}


			//cell has enemy, and it has not moved this round
			else if (!c->getMoved()) {
				//cell has dragon
				if (c->getName() == 'D') {
					Treasure *t = c.getHoard();
					int tRow = t->getRow();
					int tCol = t->getCol();

					Player *tar = checkPC(tRow, tCol);

					if (tar != nullptr) {
						c->attack(tar);
					} 

				// cell has merchant
				} 

				else if (c->getName() == 'M') {					
					Player *tar = checkPC(i, j);
					if (c->isHostile()) {
						if (tar != nullptr){
							c->attack(tar);
						} 
					} else {
						vector<Cell *> surround = produceSurroundEmpty(i, j);
						if (surround.size() != 0) {
							int size = surround.size();
							int r = random(0, size - 1);
							int newR = surround[r].getRow;
							int newC = surround[r].getCol;
							simpleMoveCharacter(i, j, newR, newC, c);
						} else {
							continue;
						}
					}
				}



				// cell has normal enemy
				else {
					Player *tar = checkPC(i, j);
					if (tar != nullptr) 
					{
						c->attack(tar);
						continue;
					} 
					else 
					{
						vector<Cell *> surround = produceSurroundEmpty(i, j);
						if (surround.size() != 0) {
							int size = surround.size();
							int r = random(0, size - 1);
							int newR = surround[r].getRow;
							int newC = surround[r].getCol;
							simpleMoveCharacter(i, j, newR, newC, c);

						} else {
							continue;
						}
					}						
				}
			}

			//enemy has moved already
			else {
				continue;
			}
		}
	}


	// resset all enemies moved state to false
	for(int i = 0; i < x; ++i){
		for(int j = 0; j < y; ++j){

			//check if cell has character
			Character *c = cellList[i][j]->getChar;

			//cell does not have character
			if (c == nullptr){
				continue;
			} 

			//cell has character
			else {
				if (c->getMoved()){
					c->changeMoved();
				}
			}
		}
	}
}

void Floor::deleteEnemy(int row, int col){
	int i = 0;
	for (auto e: enemyList) {
		if (e->getRow() == row && e->getCol() == col) {
			break;
		}
		++i;
	}
	delete enemyList[i];
	enemyList.erase(i);
}

void Floor::simpleMoveCharacter(int oldRow, int oldCol, int row, int col, Character *c){
	cellList[oldRow][oldCol]->putChar(nullptr);
	c->changePosition(row, col);
	cellList[row][col]->putChar(c);
}



vector<Spawn *> Floor::scanEmptyEnemy(int i, int j){
	vector<vector<int>> newCords = genEightCord(i,j);
	vector<Spawn *> newVec;
	for (int i = 0; i < 8; ++i) {
		int newR = newCords[i][0];
		int newC = newCords[i][1];
		Cell *curCell = cellList[newR][newC];
		if(curCell->getType() == '.'){
			Spawn *curSpawn = curCell;
			if(!curSpawn->hasItem() && !curSpawn->hasCharacter()){
				newVec.emplace_back(curSpawn);
			}
		}
	}
	// vector<Cell *> newVec;
	// if ((cellList[i+1][j]->getType()) == '.' && !(cellList[i+1][j]->hasItem) && (!cellList[i+1][j]->hasChar)) {
	// 	newVec.emplace_back(cellList[i+1][j]);
	// } 
	// if ((cellList[i+1][j+1]->getType()) == '.' && !(cellList[i+1][j+1]->hasItem) && (!cellList[i+1][j+1]->hasChar)) {
	// 	newVec.emplace_back(cellList[i+1][j+1]);
	// } 
	// if ((cellList[i][j+1]->getType()) == '.' && !(cellList[i][j+1]->hasItem) && (!cellList[i][j+1]->hasChar)) {
	// 	newVec.emplace_back(cellList[i][j+1]);
	// } 
	// if ((cellList[i][j+1]->getType()) == '.' && !(cellList[i-1][j]->hasItem) && (!cellList[i-1][j]->hasChar)){
	// 	newVec.emplace_back(cellList[i-1][j]);
	// } 
	// if ((cellList[i-1][j-1]->getType()) == '.' && !(cellList[i-1][j-1]->hasItem) && (!cellList[i-1][j-1]->hasChar)) {
	// 	newVec.emplace_back(cellList[i-1][j-1]);
	// } 
	// if ((cellList[i][j-1]->getType()) == '.' && !(cellList[i][j-1]->hasItem) && (!cellList[i][j-1]->hasChar)) {
	// 	newVec.emplace_back(cellList[i][j-1]);
	// } 
	// if ((cellList[i+1][j-1]->getType()) == '.' && !(cellList[i+1][j-1]->hasItem) && (!cellList[i+1][j-1]->hasChar)) {
	// 	newVec.emplace_back(cellList[i+1][j-1]);
	// } 
	// if ((cellList[i-1][j+1]->getType()) == '.' && !(cellList[i-1][j+1]->hasItem) && (!cellList[i-1][j+1]->hasChar)){
	// 	newVec.emplace_back(cellList[i-1][j+1]);
	// } 

	return newVec;
}


Cell * Floor::checkPC(int i, int j){
	if (((cellList[i+1][j]->getChar())->getName() == '@') && (!cellList[i+1][j]->hasChar) && (cellList[i+1][j]->getType()) == '.') {
		return cellList[i+1][j];
	} 
	if (((cellList[i+1][j+1]->getChar())->getName() == '@') && (!cellList[i+1][j+1]->hasChar) && (cellList[i+1][j+1]->getType()) == '.') {
		return cellList[i+1][j+1];
	} 
	if (((cellList[i][j+1]->getChar())->getName() == '@') && (cellList[i][j+1]->getType()) == '.') {
		return cellList[i][j+1];
	} 
	if (((cellList[i-1][j]->getChar())->getName() == '@') && (!cellList[i-1][j]->hasChar) && (cellList[i-1][j]->getType()) == '.'){
		return cellList[i-1][j];
	} 
	if (((cellList[i-1][j-1]->getChar())->getName() == '@') && (!cellList[i-1][j-1]->hasChar)  && (cellList[i-1][j-1]->getType()) == '.') {
		return cellList[i-1][j-1];
	} 
	if (((cellList[i][j-1]->getChar())->getName() == '@') && (!cellList[i][j-1]->hasChar) && (cellList[i][j-1]->getType()) == '.') {
		return cellList[i][j-1];
	} 
	if (((cellList[i+1][j-1]->getChar())->getName() == '@') && (!cellList[i+1][j-1]->hasChar) && (cellList[i+1][j-1]->getType()) == '.') {
		return cellList[i+1][j-1];
	} 
	if (((cellList[i-1][j+1]->getChar())->getName() == '@') && (!cellList[i-1][j+1]->hasChar) && (cellList[i-1][j+1]->getType()) == '.'){
		return cellList[i-1][j+1];
	} 
	return nullptr;
}

