#include <iostream>
#include <vector>
#include <utility>
#include "door.h"
using namespace std;

Door::Door(char type, int row, int col, Character *c): NormalCell{type, row, col, c} {}

Door::~Door() {}

void Door::prettyPrint(){
	if(hasCharacter()){
		// cout << '.c';
		cout << getCharacter()->getName();
	} else {
		cout << getType();
	}
}

// int Door::canPass(char *c){
// 	if (c == '@') {
// 		return 0;
// 	} else {
// 		return 3;
// 	}
// }
