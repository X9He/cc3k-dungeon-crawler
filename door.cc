#include <iostream>
#include <vector>
#include <utility>
#include "door.h"
using namespace std;

Door::Door(char type, int row, int col, int num): Cell(type, row, col, num) {}

Door::~Door() {}

void Door::prettyPrint(){
	cout << type << endl;
}

int Door::canPass(char *c){
	if (c == '@') {
		return 0;
	} else {
		return 3;
	}
}
