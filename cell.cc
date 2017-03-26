#include "cell.h"
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

Cell::Cell(): charTarget{nullptr}, item{nullptr} {}

Cell::~Cell(): {}

	//
int Cell::getRow(){
	return row;
}

int Cell::getCol(){
	return col;
}
