#pragma once

#include "Location.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Board {
public:
	Board(std::string fileName);				//defaut constructor

	size_t getBoardSize();						//fuction to get board size
	void printCurrBoard();						//function to print board

private:

	std::vector<std::string> m_currBoard;

};