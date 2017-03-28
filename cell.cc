#include "cell.h"
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

Cell::Cell(char type, int row, int col, int num):
type{type}, row{row}, col{col}, num{num} {}

Cell::~Cell(){}


int Cell::getRow(){
	return row;
}

int Cell::getCol(){
	return col;
}

char Cell::getType() {
    return type;
}
