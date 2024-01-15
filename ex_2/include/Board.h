#pragma once

#include "Location.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Board {
public:
	Board(std::string fileName);				//defaut constructor
	Location getLocations(int searchedPlayer);
	size_t getBoardSize();						//fuction to get board size
	void printCurrBoard();						//function to print board

private:
	int m_playersLoc[1][2];
	std::vector<std::string> m_currBoard;
};