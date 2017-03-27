#include <iostream>
#include <vector>
#include <utility>
#include "Stair.h"
using namespace std;

Stair::Stair(char type, int row, int col, int num): Cell(type, row, col, num) {}

Stair::~Stair() {}

void Stair::prettyPrint(){
	cout << type << endl;
}

int Stair::canPass(char *c){
	if (c == '@') {
		return 0;
	} else {
		return 3;
	}
}
