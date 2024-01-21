#pragma once

#include "Location.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Board {
public:
	Board(std::string fileName);				//defaut constructor
	Location getMouseLocation();
	std::vector<Location> getCatsLocations();
	int getBoardSize();						//fuction to get board size
	void printCurrBoard();						//function to print board
	char getChar(Location position);
	bool newPositionIsValid(const Location& newPosition);

private:
	Location m_mouseFirstLoc;
	std::vector<std::string> m_currBoard;
	std::vector<Location> m_catsFirstLocs;
};