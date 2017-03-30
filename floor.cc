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
#include "item.h"


using namespace std;

// Probability cur{2/9, 3/18, 5/18, 1/9, 1/9, 1/9};

int random(int x, int y){
	int ran;
	ran = x + (rand() % (y - x + 1));
	return ran;
}

Floor::~Floor() {
    delete player;
}

Floor::Floor(PC *player):
player{player}{}


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
			// cout<< cellList[i][j]->getType();
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
			// cout << c;
			Cell *newC= nullptr;

			if (c == ' ' || c == '-' || c == '|') 
			{
				newC = new Wall{c, i, j};
			} 
			else if (c == '#') 
			{
				newC = new Passage{c, i, j};
			} else if (c == '.') 
			{
				newC = new Spawn{c, i, j};
			} else
			{
				newC = new Door{c, i, j};
			} 
			newVec.emplace_back(newC);
		}
		// cout << endl;

		cellList.emplace_back(newVec);
		++i;
		// cout << i << endl;
	}
	fs.close();
	// prettyPrint();

	//Chamber 1
	Chamber *chamberOne = new Chamber{1};
	for (int i = 3; i <= 6; ++i){
		for (int j = 3; j <= 28; ++j){
			Spawn *cur=dynamic_cast<Spawn *>(cellList[i][j]);
			chamberOne->addSpawn(cur);
		}
	}
	roomList.emplace_back(chamberOne);
	// cout << chamberOne->getEmptyAmount() << endl;


	//Chamber 2
	Chamber *chamberTwo = new Chamber{2};
	for (int i = 3; i <= 6; ++i){
		for (int j = 39; j <= 72; ++j){
			if (cellList[i][j]->getType() == '.'){
				Spawn *cur=dynamic_cast<Spawn *>(cellList[i][j]);
				chamberTwo->addSpawn(cur);
			}
		}
	}
	for (int i = 7; i <= 12; ++i){
		for (int j = 61; j <= 75; ++j){
			if (cellList[i][j]->getType() == '.'){
				Spawn *cur=dynamic_cast<Spawn *>(cellList[i][j]);
				chamberTwo->addSpawn(cur);
			}
		}
	}
	roomList.emplace_back(chamberTwo);
	// cout << chamberTwo->getEmptyAmount() << endl;


	//Chamber 3
	Chamber *chamberThree = new Chamber{3};
	for (int i = 10; i <= 12; ++i){
		for (int j = 38; j <= 49; ++j){			
			Spawn *cur=dynamic_cast<Spawn *>(cellList[i][j]);
			chamberThree->addSpawn(cur);
		}
	}
	roomList.emplace_back(chamberThree);
	// cout << chamberThree->getEmptyAmount() << endl;


	//Chamber 4	
	Chamber *chamberFour = new Chamber{4};
	for (int i = 15; i <= 21; ++i){
		for (int j = 4; j <= 24; ++j){			
			Spawn *cur=dynamic_cast<Spawn *>(cellList[i][j]);
			chamberFour->addSpawn(cur);
		}
	}
	roomList.emplace_back(chamberFour);
	// cout << chamberFour->getEmptyAmount() << endl;


	//Chamber 5
	Chamber *chamberFive = new Chamber{5};
	for (int i = 19; i <= 21; ++i){
		for (int j = 37; j <= 75; ++j){
			Spawn *cur=dynamic_cast<Spawn *>(cellList[i][j]);
			chamberFive->addSpawn(cur);
		}
	}
	for (int i = 16; i <= 18; ++i){
		for (int j = 65; j <= 75; ++j){
			Spawn *cur=dynamic_cast<Spawn *>(cellList[i][j]);
			chamberFive->addSpawn(cur);
		}
	}
	roomList.emplace_back(chamberFive);
	// cout << chamberFive->getEmptyAmount() << endl;

	int rP = random(0,4);
	roomList[rP]->assignCharacter(p);

	createStair();
	cout << "finished created stairs" <<endl;
	createPotion(10);
	cout << "finished created potions" <<endl;
	createTreasure(10);
	// cout << "finished created treasures" <<endl;
	createEnemy(20);
	// cout << "finished created enemies" <<endl;
	prettyPrint();

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

		Enemy *newE = nullptr;
		int r = random(1, 18);
		int r2 = rand()%5;

		while(roomList[r2]->getEmptyAmount() < 1){
			r2 = rand()%5;
		}

		cout << "assigned enemy to chamber " << r2 << endl;

		if (r >= 1 && r <= 4) {
			newE = new Human{player};
		} else if (r >= 5 && r <= 7) {
			newE = new Dwarf{player};
		} else if (r >= 8 && r <= 12){
			newE = new Halfling{player};
		} else if (r >= 13 && r <= 14) {
			newE = new Elf{player};
		} else if (r >= 15 && r <= 16) {
			newE = new Orcs{player};
		} else {
			newE = new Merchant{player};
		}

		enemyList.emplace_back(newE);
		roomList[r2]->assignCharacter(newE);
		--num;
	}
}


void Floor::createPotion(int num){
	while(num > 0) {
		Item *newP = nullptr;
		int r = random(1, 6);
		int r2 = random(0, 4);

		while(roomList[r2]->getEmptyAmount() < 1){
			r2 = random(0, 4);
		}

		cout << "assigned potion to chamber " << r2 << endl;
		if (r == 1) {
			newP = new RH{};
		} else if (r == 2) {
			newP = new BA{};
		} else if (r == 3){
			newP = new BD{};
		} else if (r == 4) {
			newP = new PH{}; 
		} else if (r == 5) {
			newP = new WA{};
		} else {
			newP = new WD{};
		}
		itemList.emplace_back(newP);
		roomList[r2]->assignItem(newP);
		--num;
	}
}


void Floor::createTreasure(int num){
	while(num > 0){
		int r = random(1, 8);
		int chamberR = random(0,4);

		while(roomList[chamberR]->getEmptyAmount() < 1){
			chamberR = random(0, 4);
		}

		cout << "assigned treasure to chamber " << chamberR << endl;

		// Dragon Hoard
		if (r == 1) {
			while(roomList[chamberR]->getEmptyAmount() < 2){
				cout << "deciding dragon room" << endl;
				chamberR = random(0, 4);
			}
			Treasure *newT = new DH{};
			itemList.emplace_back(newT);
			Dragon *newD = new Dragon{player, newT};
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
    // find the number of chamber room that has the player
    int fullRoom;
    for (int i = 0; i < 5; i++) {
        roomList[i]->hasPlayer();
        fullRoom = i;
    }

    // randomly generate a chamber room number that does not have the player inside
    int r1 = random(0,4);
    while(r1 == fullRoom){
    	r1 = random(0,4);
    }
    int stairRoom = r1;
    
    // randomly generate index of vector of empty spawns to assign the stair 
    int num = roomList[stairRoom]->getEmptyAmount();
    int r2 = random(0, num-1);

    // find the spawn cell that we are going to replace
    Spawn *tar = (roomList[stairRoom]->getEmptySpawn())[r2];
    // get the row and col indices of the spawn cell we are going to replace
    int row = tar->getRow();
    int col = tar->getCol();
    
    // create the stair cell
    Stair *newStair = new Stair{'/', row, col};
    // assign 
    cellList[row][col] = newStair;
    // erase replaced cell from empty spawn list
    roomList[stairRoom]->eraseEmptySpawn(r2);
    

    delete tar;   
}



bool Floor::movePlayer(string dir){
	// get current position of player
	int curRow = player->getRow();
	int curCol = player->getCol();

	// compute new position x and y
	int newRow = curRow;
	int newCol = curCol;
	if (dir == "no") {
		--newRow;
	}
	if (dir == "so") {
		++newRow;		
	}
	if (dir == "ea") {
		++newCol;
	}
	if (dir == "we") {
		--newCol;
	}
	if (dir == "ne") {
		--newRow;
		++newCol;
	}
	if (dir == "nw") {
		--newCol;
		--newRow;
	}
	if (dir == "se") {
		++newCol;
		++newRow;
	}
	if (dir == "sw") {
		--newCol;
		++newRow;
	}

	// find the cell player wants to move to
	Cell* cur = cellList[newRow][newCol];
	char c = cur->getType();
	cout << "next cell type: " << c << endl;


	// if the next cell is wall, spawn, passage, door, or stairs

	//WALL
	if (c == ' ' || c == '-' || c == '|') {
		return true;
	} 
	//SPAWN
	else if (c == '.')
	{
		Spawn *curCell =dynamic_cast<Spawn *>(cur);
		// Spawn has an enemy
		if (curCell->hasCharacter())
		{
			Enemy *curE = dynamic_cast<Enemy *>(curCell->getCharacter());
			player->attack(curE);

			if (curE->getHP() <= 0) 
			{
				player->changeGold(curE->getGold());
				curCell->putCharacter(nullptr);
				deleteEnemy(curE->getRow(), curE->getCol());
			}
		}

		// Spawn has an item
		// else if (curCell->hasItem()) {
		// 	Item *curI = curCell->getItem();
		// 	curI->useItem();
		// 	simpleMoveCharacter(curRow, curCol, newRow, newCol, player);
		// 	curCell->putItem(nullptr);
		// } 

		// Spawn is empty
		else {
			cout << "cordinates" << " "<<curRow << " "<< curCol << " "<< newRow << " "<< newCol<< endl;
			simpleMoveCharacter(curRow, curCol, newRow, newCol, player);
			cout << "finished moving" << endl;
		}
		return true;
	} 
	//PASSAGE
	else if (c == '#'){
		simpleMoveCharacter(curRow, curCol, newRow, newCol, player);
		return true;
	} 
	//DOOR
	else if (c == '+'){
		simpleMoveCharacter(curRow, curCol, newRow, newCol, player);
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
		for (int j = 0; j < y && (cellList[i][j]->getType() == '.'); ++j){
			Spawn *curSpawn = dynamic_cast<Spawn *>(cellList[i][j]);
			//check if cell has character
			Character *c = curSpawn->getCharacter();
			if (c == nullptr){
				continue;
			} 

			//cell has player
			else if (c->getName() == '@') {
				continue;
			}

		
			//cell has enemy, 
			else {
				Enemy *curE = dynamic_cast<Enemy*>(c);

				//enemy has not moved this round
				if (!curE->getMoved()) {
					//cell has dragon

					if (curE->getName() == 'D') {
						Dragon *d = dynamic_cast<Dragon *>(c);
						Treasure *t = d->getHoard();
						int tRow = t->getRow();
						int tCol = t->getCol();

						PC *tar = checkPC(tRow, tCol);

						if (tar != nullptr) {
							d->attack(tar);
						}
					} 

					// cell has merchant
					else if (curE->getName() == 'M') {				
						Merchant *m = dynamic_cast<Merchant *>(c);					
						PC *tar = checkPC(i, j);
						if (m->isHostile()) {
							if (tar != nullptr){
								m->attack(tar);
							} 
						} else {
							vector<Spawn *> surround = scanEmptyEnemy(i, j);
							if (surround.size() != 0) {
								int size = surround.size();
								int r = random(0, size - 1);
								int newR = surround[r]->getRow();
								int newC = surround[r]->getCol();
								simpleMoveCharacter(i, j, newR, newC, c);
							} else {
								continue;
							}
						}
					}


					// cell has normal enemy
					else {
						Enemy *curE = dynamic_cast<Enemy *>(c);
						PC *tar = checkPC(i, j);
						if (tar != nullptr) 
						{
							curE->attack(tar);
							continue;
						} 
						else 
						{
							vector<Spawn *> surround = scanEmptyEnemy(i, j);
							if (surround.size() != 0) {
								int size = surround.size();
								int r = random(0, size - 1);
								int newR = surround[r]->getRow();
								int newC = surround[r]->getCol();
								simpleMoveCharacter(i, j, newR, newC, c);
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
	}


	// resset all enemies moved state to false
	for(int i = 0; i < x; ++i){
		for(int j = 0; j < y; ++j){
			if (cellList[i][j]->getType() == '.'){
				Spawn *s = dynamic_cast<Spawn*>(cellList[i][j]);
				Character *c = s->getCharacter();	
				if (c == nullptr){
					continue;
				} else {
					Enemy *e = dynamic_cast<Enemy *>(c);
					if (e->getMoved()){
						e->changeMoved();
					}
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
	enemyList.erase(enemyList.begin() + i);
}


void Floor::simpleMoveCharacter(int oldRow, int oldCol, int row, int col, Character *c){
	cout << "start simple move character" << endl;
	NormalCell *oldCell = dynamic_cast<NormalCell*>(cellList[oldRow][oldCol]);
	cout << "reached 1" << endl;
	oldCell->putCharacter(nullptr);
	cout << "reached 2" << endl;
	NormalCell *newCell = dynamic_cast<NormalCell*>(cellList[row][col]);
	cout << "reached 3" << endl;
	c->changePosition(row, col);
	cout << "reached 4" << endl;
	newCell->putCharacter(c);
	cout << "reached 5" << endl;
}



vector<Spawn *> Floor::scanEmptyEnemy(int i, int j){
	vector<vector<int>> newCords = genEightCord(i,j);
	vector<Spawn *> newVec;
	for (int i = 0; i < 8; ++i) {
		int newR = newCords[i][0];
		int newC = newCords[i][1];
		Cell *curCell = cellList[newR][newC];
		if(curCell->getType() == '.'){
			Spawn *curSpawn = dynamic_cast<Spawn *>(curCell);
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


PC* Floor::checkPC(int i, int j){

	vector<vector<int>> newCords = genEightCord(i,j);
	vector<Spawn *> newVec;
	for (int i = 0; i < 8; ++i) {
		int newR = newCords[i][0];
		int newC = newCords[i][1];
		Cell *curCell = cellList[newR][newC];
		if(curCell->getType() == '.'){
			Spawn *curSpawn = dynamic_cast<Spawn *>(curCell);
			if(curSpawn->hasCharacter() && (curSpawn->getCharacter()->getName()) == '@'){
				PC *p = dynamic_cast<PC*>(curSpawn->getCharacter());
				return p;
			}
		}
	}

	// if (((cellList[i+1][j]->getChar())->getName() == '@') && (!cellList[i+1][j]->hasChar) && (cellList[i+1][j]->getType()) == '.') {
	// 	return cellList[i+1][j];
	// } 
	// if (((cellList[i+1][j+1]->getChar())->getName() == '@') && (!cellList[i+1][j+1]->hasChar) && (cellList[i+1][j+1]->getType()) == '.') {
	// 	return cellList[i+1][j+1];
	// } 
	// if (((cellList[i][j+1]->getChar())->getName() == '@') && (cellList[i][j+1]->getType()) == '.') {
	// 	return cellList[i][j+1];
	// } 
	// if (((cellList[i-1][j]->getChar())->getName() == '@') && (!cellList[i-1][j]->hasChar) && (cellList[i-1][j]->getType()) == '.'){
	// 	return cellList[i-1][j];
	// } 
	// if (((cellList[i-1][j-1]->getChar())->getName() == '@') && (!cellList[i-1][j-1]->hasChar)  && (cellList[i-1][j-1]->getType()) == '.') {
	// 	return cellList[i-1][j-1];
	// } 
	// if (((cellList[i][j-1]->getChar())->getName() == '@') && (!cellList[i][j-1]->hasChar) && (cellList[i][j-1]->getType()) == '.') {
	// 	return cellList[i][j-1];
	// } 
	// if (((cellList[i+1][j-1]->getChar())->getName() == '@') && (!cellList[i+1][j-1]->hasChar) && (cellList[i+1][j-1]->getType()) == '.') {
	// 	return cellList[i+1][j-1];
	// } 
	// if (((cellList[i-1][j+1]->getChar())->getName() == '@') && (!cellList[i-1][j+1]->hasChar) && (cellList[i-1][j+1]->getType()) == '.'){
	// 	return cellList[i-1][j+1];
	// } 
	return nullptr;
}

