#ifndef __DISPLAY_H__
#define __DISPLAY_H__
#include <iostream>
#include <vector>

class Display {
	std::vector<std::vector<char>> theDisplay;
	const int mapLen;
	const int mapWid;

public:
	Display(int x, int y);

	~Display();

	void update();
};

#endif