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

double human = cur.human;

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

// void Floor::notify(){

// }

void Floor::CreateEnemy(int num){
	while (num > 0){
		int ran = random() % 18 + 1;
		if ()
		Enemy *newE = new Enemy{};
		enemyList.emplace_back(newE);

	}

}

int Floor::getLevel(){
	return level;
}

