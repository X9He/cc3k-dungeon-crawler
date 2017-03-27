#include <iostream>
#include <vector>
#include <utility>
#include "NormalCell.h"
using namespace std;

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
