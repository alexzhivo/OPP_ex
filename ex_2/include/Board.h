#pragma once

#include "Location.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Board {
public:
	Board(std::string fileName);				// defaut constructor

	Location getMouseLocation();
	int getBoardSize();							// fuction to get board size
	void printCurrBoard();						// function to print board
	char getChar(Location position);			// get char symbol from location
	bool newPositionIsValid(const Location& newPosition);
	void clearCheese(Location position);
	void clearCell(const Location& location);

	std::vector<Location> getCatsLocations();	// get cats locations
	std::vector<Location> getCheeseLocations();	// get cheese locations
	bool isCheeseLeft();						// checks if cheese left on board

private:
	std::vector<std::string> m_currBoard;
	Location m_mouseFirstLoc;
	std::vector<Location> m_catsFirstLocs;
	std::vector<Location> m_cheeseLocations;
};