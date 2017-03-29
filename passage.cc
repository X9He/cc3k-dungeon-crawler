#include <iostream>
#include <vector>
#include <utility>
#include "passage.h"
using namespace std;


Passage::Passage(char type, int row, int col, int num):
NormalCell(type, row, col, num) {}

void Passage::prettyPrint(){
	cout << getType() << endl;
}

int Passage::canPass(char c){
	if (c == '@') {
		return 0;
	} else {
		return 3;
	}
}
