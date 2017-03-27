#include <iostream>
#include <vector>
#include <utility>
#include "Wall.h"
using namespace std;

Wall::Wall(char type, int row, int col, int num): Cell(type, row, col, num) {}

Wall::~Wall(){}

void Wall::prettyPrint(){
	cout << type << endl;
}

bool Wall::canPass(){
	return false;
}
