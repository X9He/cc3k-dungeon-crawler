#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include "floor.h"
#include "predefined.h"
using namespace std;

Probability cur{2/9, 3/18, 5/18, 1/9, 1/9, 1/9};

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
	while(getline(fs, s)){
		vector<Cell*> newVec;
		char c;
		for(int j = 0; j < s.size(); ++j)
		{


			c = s[j];
			Cell *newC;


			if (c == '' || c == '-' || c == '|') 
			{
				newC = new Wall{c, i, j};
			} 
			else if (c == '#') 
			{
				newC = new Passage{c, i , j};
			} else if (c == '.') 
			{
				newC = new Chamber{c, i, j};
			} else
			{
				newC = new Door{c, i, j};
			} 

			newVec.emplace_back(newC);
		}


		cellList.emplace_back(newVec);
	}
}



void Floor::initPC(string s){


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
		Potion *newP;
		
	}

}

void Floor::createTreasure(int num){

}

void Floor::createStair(int num){

}

bool Floor::movePlayer(PC *){

}


void Floor::updateEnemy(){}

