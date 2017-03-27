#ifndef __DOOR_H__
#define __DOOR_H__
#include <iostream>
#include <vector>
#include <utility>
#include "passage.h"

void Passage::prettyPrint(){
	cout << type << endl;
}

int Passage::canPass(char *c){
	if (c == '@') {
		return 0;
	} else {
		return 3;
	}
}