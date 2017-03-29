#include <iostream>
#include <vector>
#include <utility>
#include "Stair.h"
using namespace std;

Stair::Stair(char type, int row, int col, int num, Character *c): NormalCell{type, row, col, c}{}

Stair::~Stair() {}

void Stair::prettyPrint(){
	cout << getType();
}

// int Stair::canPass(char *c){
// 	if (c == '@') {
// 		return 0;
// 	} else {
// 		return 3;
// 	}
// }
