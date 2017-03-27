#include <iostream>
#include <vector>
#include <utility>
#include "floor.h"
using namespace std;

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
	fstream fs;
	fs.open('cc3k.txt');
	string s;
	int i = 0;
	while(s << fs.getline()){
		char c;
		vector<Cell> newVec;
		for(int j = 0; j < s.size(); ++j) {			
			Cell *newC;
			if(ch == '-'){
				newC = new Wall('-', i, j, )
			} else if (ch == '|'){
			}
			= new Cell{}
			newVec.emplaceback();
		}

	}
}

void Floor::notify(){

}

void Floor::SpawnEnemy(){

}

void Floor::getLevel(){
	return level;
}

