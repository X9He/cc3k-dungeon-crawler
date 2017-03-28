#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <typeinfo>
#include "floor.h"
#include "predefined.h"
using namespace std;

// Probability cur{2/9, 3/18, 5/18, 1/9, 1/9, 1/9};

int random(int x, int y){
	int ran;
	srand(time(0));
	ran = x + (rand() % (y - x + 1));
	return ran;
}


void Floor::prettyPrint(){
	for (int i = 0; i < cellList.size() ; ++i){
		for (int j = 0; j < cellList[i].size(); ++j){
			cout << cellList[i].[j]->getType();
		}
		cour << endl;
	}
}

void Floor::clearFloor(){
	td = nullptr;
	for (auto e: enemyList) {
		delete e;
	}
	enemyList.clear();
	for (int i = 0; i < cellList.size() ; ++i){
		for (int j = 0; j < cellList[i].size(); ++j){
			delete cellList[i].[j];
		}
	}
}

void Floor::init(){
	td = Display{n};

	fstream fs{"cc3k.txt"};
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
			chamberTwo->addSpawn(cellList[i][j]);
		}
	}
	for (int i = 7; i <= 12; ++i){
		for (int j = 61; j <= 75; ++j){
			chamberTwo->addSpawn(cellList[i][j]);
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
		Enemy *newE;
		if (r >= 1 && r <= 4) {
			newE = new Human{player};
		} else if (r >= 5 && r <= 7) {
			newE = new Dwarf{player};
		} else if (r >= 8 && r <= 12){
			newE = new Halfling{player};
		} else if (r >= 13 && r <= 14) {
			newE = new Elf{player};
		} else if (r >= 15 && r <= 16) {
			newE = new Orc{player};
		} else {
			newE = new Merchant{player};
		}
		enemyList.emplace_back(newE);
		--num;
	}
}


void Floor::createPotion(int num){
	while(num > 0) {
		int r = random(1, 6);
		Item *newP;
		if (r == 1) {
			newP = new ;
		} else if (r == 2) {
			newP = new ;
		} else if (r == 3){
			newP = new ;
		} else if (r == 4) {
			newP = new ; 
		} else if (r == 5) {
			newP = new ;
		} else {
			newP = new ;
		}
		--num;
	}

}

void Floor::createTreasure(int num){
	while(num > 0){
		int r = random(1, 8);
		int chamberR = random(1,5);
		Item *newT;
		// Dragon Hoard
		if (r == 1) {
			newT = new Treasure; //psudeo
			Character *newD = new Dragon; //psudeo
			enemyList.emplace_back(newD);
			roomList[chamberR]->assignTreasure(newT, newD);
		}
		// Small Hoard
		 else if (r >=2 && r <= 4) {
			newT = new Treasure; //psudeo
			roomList[chamberR]->assignItem(newT);
		} 
		// Normal Hoard
		else {
			newT = new NormalTreasure; //psudeo
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
    std::vector<Spawn*>::iterator pos = std::find(myVector.begin(), myVector.end(), tar);
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
		return;
	} 
	//SPAWN
	else if (c == '.')
	{
		// Spawn has an enemy
		if (curCell->hasChar())
		{
			Enemy *curE = cur->getCharacter();
			player.attack(curE);

			if (curE.getHP() <= 0) 
			{
				player.getGold(curE);
				curCell->putChar(nullptr);
				deleteEnemy(curE->getRow(), curE->getCol());
			}
		}

		// Spawn has an item
		else if (curCell->hasItem()) {
			Item *curI = curCell->getItem();
			curI.useItem();
			simpleMoveCharacter(newRow, newCol);
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

			Enemy *e = cellList[i][j]

			Player *tar = checkChar(i, j);
			if (tar != nullptr) 
			{
				vector<Cell *> surround = produceSurroundEmpty(i, j);
				if (surround.size() == 0) 
				{

				} else 
				{
					int size = surround.size();
					int r = random(0, size - 1);
					int newR = surround[r].getRow;
					int newC = surround[r].getCol;
					simpleMoveCharacter(i, j, newR, newC, )
				}
			}
			enemy->attack
			if (surround.size() == 0) {
				int r = random(1,)
				simpleMoveCharacter(i, j, new)
			}
			int newI = i;
			int newJ = j;

			


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



vector<Cell *> Floor::produceSurroundEmpty(int i, int j){
	vector<Cell *> newVec;
	if (!(cellList[i+1][j]->hasItem) && (!cellList[i+1][j]->hasChar) && (cellList[i+1][j]->getType) == '.') {
		newVec.emplace_back(cellList[i+1][j]);
	} 
	if (!(cellList[i+1][j+1]->hasItem) && (!cellList[i+1][j+1]->hasChar) && (cellList[i+1][j+1]->getType) == '.') {
		newVec.emplace_back(cellList[i+1][j+1]);
	} 
	if (!(cellList[i][j+1]->hasItem) && (!cellList[i][j+1]->hasChar) && (cellList[i][j+1]->getType) == '.') {
		newVec.emplace_back(cellList[i][j+1]);
	} 
	if (!(cellList[i-1][j]->hasItem) && (!cellList[i-1][j]->hasChar) && (cellList[i-1][j]->getType) == '.'){
		newVec.emplace_back(cellList[i-1][j]);
	} 
	if (!(cellList[i-1][j-1]->hasItem) && (!cellList[i-1][j-1]->hasChar)  && (cellList[i-1][j-1]->getType) == '.') {
		newVec.emplace_back(cellList[i-1][j-1]);
	} 
	if (!(cellList[i][j-1]->hasItem) && (!cellList[i][j-1]->hasChar) && (cellList[i][j-1]->getType) == '.') {
		newVec.emplace_back(cellList[i][j-1]);
	} 
	if (!(cellList[i+1][j-1]->hasItem) && (!cellList[i+1][j-1]->hasChar) && (cellList[i+1][j-1]->getType) == '.') {
		newVec.emplace_back(cellList[i+1][j-1]);
	} 
	if (!(cellList[i-1][j+1]->hasItem) && (!cellList[i-1][j+1]->hasChar) && (cellList[i-1][j+1]->getType) == '.'){
		newVec.emplace_back(cellList[i-1][j+1]);
	} 

	return newVec;
}


Cell * Floor::checkPC(int i, int j){
	if ((PC *pc = dynamic_cast<PC*>(cellList[i+1][j]->getChar())) && (!cellList[i+1][j]->hasChar) && (cellList[i+1][j]->getType) == '.') {
		return cellList[i+1][j];
	} 
	if ((PC *pc = dynamic_cast<PC*>(cellList[i+1][j+1]->getChar())) && (!cellList[i+1][j+1]->hasChar) && (cellList[i+1][j+1]->getType) == '.') {
		return cellList[i+1][j+1];
	} 
	if ((PC *pc = dynamic_cast<PC*>(cellList[i][j+1]->getChar())) && (cellList[i][j+1]->getType) == '.') {
		return cellList[i][j+1];
	} 
	if ((PC *pc = dynamic_cast<PC*>(cellList[i-1][j]->getChar())) && (!cellList[i-1][j]->hasChar) && (cellList[i-1][j]->getType) == '.'){
		return cellList[i-1][j];
	} 
	if ((PC *pc = dynamic_cast<PC*>(cellList[i-1][j-1]->getChar())) && (!cellList[i-1][j-1]->hasChar)  && (cellList[i-1][j-1]->getType) == '.') {
		return cellList[i-1][j-1];
	} 
	if ((PC *pc = dynamic_cast<PC*>(cellList[i][j-1]->getChar())) && (!cellList[i][j-1]->hasChar) && (cellList[i][j-1]->getType) == '.') {
		return cellList[i][j-1];
	} 
	if ((PC *pc = dynamic_cast<PC*>(cellList[i+1][j-1]->getChar())) && (!cellList[i+1][j-1]->hasChar) && (cellList[i+1][j-1]->getType) == '.') {
		return cellList[i+1][j-1];
	} 
	if ((PC *pc = dynamic_cast<PC*>(cellList[i-1][j+1]->getChar())) && (!cellList[i-1][j+1]->hasChar) && (cellList[i-1][j+1]->getType) == '.'){
		return cellList[i-1][j+1];
	} 
	return nullptr;
}

