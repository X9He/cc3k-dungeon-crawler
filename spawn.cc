#include <iostream>
#include <vector>
#include <utility>
#include "spawn.h"
using namespace std;

Spawn::Spawn(char type, int row, int col, int num, int chamberNum): Cell(type, row, col, num), chamberNum{chamberNum} {}

Spawn::~Spawn() {}


void Spawn::prettyPrint(){
	if (charTarget != nullptr) {
		cout << "@" << endl;
	} else if (item != nullptr) {
		cout << item.getType() << endl;
	} else {
		cout << "." << endl;
	}
}

int Spawn::canPass(Cell *c){
	if(c->charTarget->getName() == '')

}

void Spawn::putItem(item *i){
	item = i;
}



void Spawn::removeItem(){
	item = nullptr;
}


Item* Spawn::getItem(){
	return item;
}

