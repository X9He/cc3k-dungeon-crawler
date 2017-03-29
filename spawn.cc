#include <iostream>
#include <vector>
#include <utility>
#include "spawn.h"
using namespace std;

Spawn::Spawn(char type, int row, int col, int num, int chamberNum, Item *item): Cell(type, row, col, num), chamberNum{chamberNum}, item{item} {}

Spawn::~Spawn() {}


void Spawn::prettyPrint(){
	if (charTarget != nullptr) {
		cout << "@" << endl;
	} else if (item != nullptr) {
		cout << item->getType() << endl;
	} else {
		cout << "." << endl;
	}
}

int Spawn::canPass(Cell *c){
	if(c->charTarget->getName() == '';

}

void Spawn::putItem(Item *i){
	item = i;
}




void Spawn::removeItem(){
	item = nullptr;
}


Item * Spawn::getItem(){
	return item;
}


bool Spawn::hasItem(){
	return (item != nullptr);
}

