#include <iostream>
#include <vector>
#include <utility>
#include "passage.h"
using namespace std;


Passage::Passage(char type, int row, int col, Character *c): NormalCell{type, row, col, c}{}

Passage::~Passage(){}

void Passage::prettyPrint(){
	if(hasCharacter()){
		// cout << 'c';
		cout << getCharacter()->getName();
	} else {
		cout << getType();
	}
}

// int Passage::canPass(char c){
// 	if (c == '@') {
// 		return 0;
// 	} else {
// 		return 3;
// 	}
// }
