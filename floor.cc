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
#include "message.h"


using namespace std;


// Probability cur{2/9, 3/18, 5/18, 1/9, 1/9, 1/9};

int random(int x, int y){
	int ran;
	ran = x + (rand() % (y - x + 1));
	return ran;
}

Floor::Floor(PC *player, bool isFrozen, bool hostile)
:player{player},isFrozen{isFrozen}, hostile{hostile}{
  message = new Message;
}


Floor::~Floor() {
	player = nullptr;
	delete message;
}

vector<vector<int>> genEightCord(int i, int j) {
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

void Floor::setFrozen(){
	if(isFrozen){
		isFrozen = false;
	} else {
		isFrozen = true;
	}
}

bool Floor::getFrozen(){
	return isFrozen;
}


void Floor::setHostile(bool f){
	hostile = f;
}

bool Floor::getHostile(){
	return hostile;
}

void Floor::printEnemyHP(){
	for (auto e: enemyList) {
		cout << e->getHP() << " ";
	}
	cout << endl;
}

void Floor::prettyPrint(){
	for (int i = 0; i < cellList.size() ; ++i){
		for (int j = 0; j < cellList[i].size(); ++j){
			cellList[i][j]->prettyPrint();
		}
		cout << endl;
	}

    message->getMessage(); 
    message->clearMessage();
}

void Floor::clearFloor(){
  //cout << "start clearing floor" << endl;
	
	for (auto i: enemyList){
		delete i;
	}

	//	cout << "cleared enemy list" << endl;

	for (auto cellVec : cellList){
		for (auto c: cellVec){
			delete c;
		}
	}
	//	cout << "cleared cell list" << endl;


	for(auto j: roomList){
		delete j;
	}
	// for (int i = 0; i < roomList.size(); ++i){
	// 	delete roomList[i];
	// }
	//cout << "cleared room list" << endl;

	// for (int i = 0; i < itemList.size(); ++i){
	// 	delete itemList[i];
	// }
	for(auto t: itemList){
		delete t;
	}
	//cout << "cleared item list" << endl;
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
	cout << chamberOne->getEmptyAmount() << endl;


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
	cout << chamberTwo->getEmptyAmount() << endl;


	//Chamber 3
	Chamber *chamberThree = new Chamber{3};
	for (int i = 10; i <= 12; ++i){
		for (int j = 38; j <= 49; ++j){			
			Spawn *cur=dynamic_cast<Spawn *>(cellList[i][j]);
			chamberThree->addSpawn(cur);
		}
	}
	roomList.emplace_back(chamberThree);
	cout << chamberThree->getEmptyAmount() << endl;


	//Chamber 4	
	Chamber *chamberFour = new Chamber{4};
	for (int i = 15; i <= 21; ++i){
		for (int j = 4; j <= 24; ++j){			
			Spawn *cur=dynamic_cast<Spawn *>(cellList[i][j]);
			chamberFour->addSpawn(cur);
		}
	}
	roomList.emplace_back(chamberFour);
	cout << chamberFour->getEmptyAmount() << endl;


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
	cout << chamberFive->getEmptyAmount() << endl;

	int rP = random(0,4);
	roomList[rP]->assignCharacter(p);

	createStair();
	//cout << "finished created stairs" <<endl;
	createPotion(10);
	//cout << "finished created potions" <<endl;
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


		if (r >= 1 && r <= 4) {
			cout << "assigned human to chamber " << r2 << endl;
			newE = new Human{player};
		} else if (r >= 5 && r <= 7) {
			cout << "assigned dwarf to chamber " << r2 << endl;
			newE = new Dwarf{player};
		} else if (r >= 8 && r <= 12){
			cout << "assigned halfing to chamber " << r2 << endl;
			newE = new Halfling{player};
		} else if (r >= 13 && r <= 14) {
			cout << "assigned elf to chamber " << r2 << endl;
			newE = new Elf{player};
		} else if (r >= 15 && r <= 16) {
			cout << "assigned orc to chamber " << r2 << endl;
			newE = new Orcs{player};
		} else {
			cout << "assigned merchant to chamber " << r2 << endl;
			newE = new Merchant{player};
		}

		enemyList.emplace_back(newE);
		//cout << "calling assign" << endl;
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
			newP = new RH{player};
		} else if (r == 2) {
			newP = new BA{player};
		} else if (r == 3){
			newP = new BD{player};
		} else if (r == 4) {
			newP = new PH{player}; 
		} else if (r == 5) {
			newP = new WA{player};
		} else {
			newP = new WD{player};
		}
		itemList.emplace_back(newP);
		//	cout << "failed before assign" << endl;
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


		// Dragon Hoard
		if (r == 1) {
			cout << "assigned dragon hoard to chamber " << chamberR << endl;

			while(roomList[chamberR]->getEmptyAmount() < 2){
			  //	cout << "deciding dragon room" << endl;
				chamberR = random(0, 4);
			}
			Treasure *newT = new DH{player};
			itemList.emplace_back(newT);
			Dragon *newD = new Dragon{player, newT};
			enemyList.emplace_back(newD);
			//cout << "failed before assign" << endl;
			roomList[chamberR]->assignTreasure(newT, newD);
		}

		// Small Hoard
		 else if (r >=2 && r <= 4) {
		   //cout << "assigned small hoard to chamber " << chamberR << endl;
			Item *newT = new Small{player};
			itemList.emplace_back(newT);
			//	cout << "failed before assign" << endl;
			roomList[chamberR]->assignItem(newT);
		} 

		// Normal Hoard
		else {
		  //cout << "assigned normal hoard to chamber " << chamberR << endl;
			Item *newT = new Normal{player};
			itemList.emplace_back(newT);
			//	cout << "failed before assign" << endl;
			roomList[chamberR]->assignItem(newT);
		}
		--num;
	}
}

void Floor::createStair(){
    // find the number of chamber room that has the player
    int fullRoom;
    for (int i = 0; i < 5; i++) {
        if(roomList[i]->hasPlayer()){
        	fullRoom = i;
        }
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
	Troll *t = dynamic_cast<Troll*>(player);
    string direction;
  if(dir == "no") direction = "North";
  if(dir == "ea") direction = "East";
  if(dir == "we") direction = "West";
  if(dir == "so") direction = "South";
  if(dir == "ne") direction = "Northeast";
  if(dir == "se") direction = "Southeast";
  if(dir == "nw") direction = "Northwest";
  if(dir == "sw") direction = "Southwest";
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
	if (dir == "ea")  {
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
	// cout << "next cell type: " << c << endl;


	// if the next cell is wall, spawn, passage, door, or stairs

	//WALL
	if (c == ' ' || c == '-' || c == '|') {
		if(t){
			t->changeHP(5);
		}
		return true;		
	} 
	//SPAWN
	else if (c == '.')
	{
		message->addMessage("PC moves to " + direction + ".");
		vector<vector<int>> sets;
	       sets = genEightCord(newRow, newCol);
	       for(int i = 0; i < 8; ++i){
		 int newR = sets[i][0];
		 int newC = sets[i][1];
		 Cell *ce = cellList[newR][newC];
		 Spawn *s = nullptr;
		 if(ce->getType() == '.' ){
		   s = dynamic_cast<Spawn*>(cellList[newR][newC]);
		   if(s->getItem() != nullptr &&
		    s->getItem()->getType() == 'P') {
		   message->addMessage("PC sees an unknown potion.");
		   break;
		 }
	       }
	       }
	       
		Spawn *curCell =dynamic_cast<Spawn *>(cur);
		// Spawn has an enemy
		if (curCell->hasCharacter())
		{
		}

		// Spawn has an item
		else if (curCell->hasItem()) {
            if (curCell->getItem()->getType() == 'G') {
                Item *curI = curCell->getItem();
                Treasure *t = dynamic_cast<Treasure*>(curI);
		// cout << "you tried to pickup a gold that is " <<t->isProtect() << " protected!"<< endl;
                if(!t->isProtect()){
	                curI->useItem();
	                simpleMoveCharacter(curRow, curCol, newRow, newCol, player);
	                curCell->putItem(nullptr);
                }
            }
        }
		// Spawn is empty
		else {
			// cout << "cordinates" << " "<<curRow << " "<< curCol << " "<< newRow << " "<< newCol<< endl;
			simpleMoveCharacter(curRow, curCol, newRow, newCol, player);
			// cout << "finished moving" << endl;
		}
		if(t){
			t->changeHP(5);
		}
		return true;
	} 
	//PASSAGE
	else if (c == '#'){
		simpleMoveCharacter(curRow, curCol, newRow, newCol, player);
		 message->addMessage("PC moves to " + direction + ".");
		if(t){
			t->changeHP(5);
		}
		return true;
	} 
	//DOOR
	else if (c == '+'){
		simpleMoveCharacter(curRow, curCol, newRow, newCol, player);
		message->addMessage("PC moves to " + direction + ".");
		if(t){
			t->changeHP(5);
		}
		return true;
	} 
	//STAIRS
	else {
		return false;
	}
}


void Floor::updateEnemy(){
	// int x = cellList.size();
	// int y = cellList[0].size();
	// cout << "begin updating enemy, cords of cell is " << "x: " << x << " y: " << y << endl;
	//cout << "begin updating enemy" << endl;
	if(isFrozen){
		return;
	}

	for(int i = 0; i < 25; ++i){
		for (int j = 0; j < 79; ++j){
			// cout << "we got to x " <<i << " and y " << j << endl;
			if (cellList[i][j]->getType() != '.'){
				// cout << "not spawn" << endl;
				continue;
			}


			Spawn *curSpawn = dynamic_cast<Spawn *>(cellList[i][j]);

			//check if cell has character
			if (!curSpawn->hasCharacter()){
				// cout << "no character" << endl;
				continue;
			}

			//cell has character
			Character *c = curSpawn->getCharacter();

			//cell has player
			if (c->getName() == '@') {
				// cout << "has player" << endl;
				continue;
			}

		
			//cell has enemy, 
			else {
				// cout <<"cell has enemy" << endl;

				Enemy *curE = dynamic_cast<Enemy*>(c);

				//enemy has not moved this round
				if (!curE->getMoved()) 
				{
					// cout << "enemy in cell has not moved" << endl;

					//cell has dragon
					if (curE->getName() == 'D')
					{

						// cout << "got dragon" << endl;
						Dragon *d = dynamic_cast<Dragon *>(curE);
						
						// cout << "I'm not a dragon, I'm actually a " << c->getName() << endl;
						


						//cout << "cast dragon success" << endl;
						Treasure *t = d->getHoard();
						//cout << "got dragon hoard success" << endl;
						int tRow = t->getRow();
						int tCol = t->getCol();

						PC *tar = checkPC(tRow, tCol);

						if (tar) {
							d->attack(tar);
							int pchurt = player->getDamageE();
string act;
act += d->getName();
message->addMessage(act + " deals " + to_string(0 -pchurt) + " damages to PC.");
						}
					} 

					// cell has merchant
					else if (curE->getName() == 'M') 
					{
						// cout << "got merchant" << endl;
						Merchant *m = dynamic_cast<Merchant *>(c);	
						// cout << "cast merchant success" << endl;			
						PC *tar = checkPC(i, j);
						if (hostile) {
							if (tar != nullptr){
								m->attack(tar);
								int pchurt =player->getDamageE();
string act;
act += m->getName();
message->addMessage(act + " deals " + to_string(0 -pchurt) + " damages to PC.");
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
					else 
					{
						// cout << "got normal enemy" << endl;
						Enemy *curE = dynamic_cast<Enemy *>(c);
						// cout << "cast normal enemy success" << endl;
						PC *tar = checkPC(i, j);
						if (tar != nullptr) 
						{
							curE->attack(tar);
							int pchurt = player->getDamageE();
string act;
act += curE->getName();
message->addMessage(act + " deals " + to_string(0 -pchurt) + " damages to PC.");

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
					curE->changeMoved();
				}

				//enemy has moved already
				else 
				{
					cout << "success" << endl;
					continue;
				}
			}
		}
	}
	// cout << "semi finished updating enemy" << endl;

	// resset all enemies moved state to false
	for(int i = 0; i < 25; ++i){
		for(int j = 0; j < 79; ++j){

			if (cellList[i][j]->getType() == '.'){
			// cout << "we got to x " <<i << " and y " << j << endl;

				Spawn *s = dynamic_cast<Spawn*>(cellList[i][j]);

				Character *c = s->getCharacter();	
				if (c){
					if (!(c->getName()== '@')){
						Enemy *e = dynamic_cast<Enemy *>(c);
						if (e){
							if (e->getMoved()){
								e->changeMoved();
							}
						}
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
	// cout << "start simple move character" << endl;
	NormalCell *oldCell = dynamic_cast<NormalCell*>(cellList[oldRow][oldCol]);
	// cout << "reached 1" << endl;
	oldCell->putCharacter(nullptr);
	// cout << "reached 2" << endl;
	NormalCell *newCell = dynamic_cast<NormalCell*>(cellList[row][col]);
	// cout << "reached 3" << endl;
	c->changePosition(row, col);
	// cout << "reached 4" << endl;
	newCell->putCharacter(c);
	// cout << "reached 5" << endl;
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
	return newVec;
}


PC* Floor::checkPC(int i, int j){
	vector<vector<int>> newCords = genEightCord(i,j);
	vector<Spawn *> newVec;
	for (int i = 0; i < 8; ++i) {
		int newR = newCords[i][0];
		int newC = newCords[i][1];
		Cell *curCell = cellList[newR][newC];		
		// cout << "checking if pc for in cell " << newR << " " << newC << endl;

		if(curCell->getType() == '.')
		{

			Spawn *curSpawn = dynamic_cast<Spawn *>(curCell);

			if(!(curSpawn->hasCharacter()))
			{
				continue;
			} 



			if (curSpawn->getCharacter()->getName() == '@')
			{
				PC *p = dynamic_cast<PC*>(curSpawn->getCharacter());
				return p;
			}
		}
	}
	return nullptr;
}



void Floor::playerUsePotion(string dir) {
	cout << "start using potion" << endl;
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
    
    
    if (cellList[newRow][newCol]->getType() == '.') {
    	cout << "potion is in the right cell" << endl;
        Spawn *s = dynamic_cast<Spawn*>(cellList[newRow][newCol]);
        if(s->hasItem()) {
        	cout << "has item" << endl;
        	if (s->getItem()->getType() == 'P'){
		  //cout << "item is potion" << endl;
        		Potion * p = dynamic_cast<Potion *>(s->getItem());
        		if (p) {        			
			  //cout << "potion cast complete" << endl;
	        		p->useItem(1);
				message->addMessage("PC uses " + p->getPotionType() +".");
	        		//cout << "use potion complete" << endl;
	        		s->putItem(nullptr);
	        		//cout << "put item success" << endl;
        		}
        	}
        }
    }
}






void Floor::playerAttack(string dir) {
    int newCol = player->getCol();
    int newRow = player->getRow();
    if (dir == "no"){
        --newRow;
    }
    if (dir == "so") {
        ++newRow;
    }
    if (dir == "ea") {
        ++newCol;
    }
    if (dir == "ne") {
        --newRow;
        ++newCol;
    }
    if (dir == "we") {
        --newCol;
    }
    if (dir == "nw") {
        --newRow;
        --newCol;
    }
    if (dir == "sw") {
        --newCol;
        ++newRow;
    }
    if (dir == "se") {
        ++newRow;
        ++newCol;
    }
    
    Spawn * s = nullptr;

    if (cellList[newRow][newCol]->getType() == '.'){
        s = dynamic_cast<Spawn*>(cellList[newRow][newCol]);

	    if (s->hasCharacter()) {

	        Enemy * e = dynamic_cast<Enemy *> (s->getCharacter());

	        if (e) {
	        	if (e->getName() == 'M'){
		        	if(!hostile){
		            			hostile=true;
		            		}

	        	}
	        	//cout << "start attack" << endl;
	            player->attack(e);
	            int damage = e->getDamagePC();

	            message->addMessage("PC deals " + to_string(0-damage) + " damages to " + e->getName() + ".");
	            
	            if (e->getHP() <= 0) {
	            	if (e->getName()=='M')
	            	{

	            		Item *h= new Normal{player};
	            		itemList.emplace_back(h);

	            		// assign treasure
	            		s->putItem(h);
	            		s->putCharacter(nullptr);

	            	} 


	            	else if (e->getName() == 'H')
	            	{
	            		Item *hoardOne = new Normal{player};
	            		Item *hoardTwo = new Normal{player};
	            		itemList.emplace_back(hoardOne);
	            		itemList.emplace_back(hoardTwo);

	            		int eRow = e->getRow();
	            		int eCol = e->getCol();

	            		vector<Spawn*> newVec = scanEmptyEnemy(eRow, eCol);

	            		int size = newVec.size();
	            		int ran = random(0,size-1);



	            		//assign treasure one

	            		s->putItem(hoardOne);
	            		s->putCharacter(nullptr);

	            		//assign treasure two

	            		Spawn *chosen = newVec[ran];
	            		chosen->putItem(hoardTwo);

	            	} else if (e->getName() == 'D') {
	            		Dragon *d = dynamic_cast<Dragon *>(e);
	            		Treasure *t = d->getHoard();
	            		t->changeProtect(false);
	            		s->putCharacter(nullptr);

	            	}

	            	else {
	            		s->putCharacter(nullptr);

	            	}
	            }
	        }
	    }
	}
}


