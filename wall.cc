#include <iostream>
#include <vector>
#include <utility>
#include "Wall.h"
using namespace std;

Wall::Wall(int i) {
	Cell{} {
		if (int i == 0) {
			wallType = '';
		} else if (int i == 1) {
			wallType = '|';
		} else {
			wallType = '-';
		}
	}
}

Wall::~Wall(){
}

void Wall::prettyPrint(){
	cout << type << endl;
}

bool Wall::canPass(){
	return false;
}
