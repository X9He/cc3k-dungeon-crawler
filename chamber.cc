#include <iostream>
#include <vector>
#include <utility>
#include "chamber.h"
using namespace std;

Chamber::Chamber(char type, int row, int col, int num, int chamberNum): Cell(type, row, col, num), chamberNum{chamberNum} {}

Chamber::~Chamber() {}


void Chamber::prettyPrint(){
	if (charTarget != nullptr) {
		cout << "@" << endl;
	} else if (item != nullptr) {
		cout << item.getType() << endl;
	} else {
		cout << "." << endl;
	}
}

int Chamber::canPass(Cell *c){
	if(c->charTarget->getName() == '')

}

void Chamber::putItem(item *i){
	item = i;
}



void Chamber::removeItem(){
	item = nullptr;
}


Item* Chamber::getItem(){
	return item;
}

