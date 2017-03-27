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

void Floor::init(x, y){
	td = new Display(x , y);


}

void Floor::notify(){

}