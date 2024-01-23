#pragma once

#include "Location.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Board {
public:
	Board(std::string fileName);				// defaut constructor

	void printCurrBoard();						// function to print board
	bool newPositionIsValid(const Location& newPosition);

	int getBoardSize();							// fuction to get board size
	char getChar(Location position);			// get char symbol from location
	Location getMouseLocation();
	std::vector<Location> getCatsLocations();	// get cats locations
	std::vector<Location> getCheeseLocations();	// get cheese locations

	void removeCheese(Location position);		// removes cheese
	bool isCheeseLeft();						// checks if cheese left on board
	
	void clearBlock(Location position);			// clears a block on board

private:

	std::vector<std::string> m_currBoard;		// current level board

	Location m_mouseFirstLoc;					// mouse initial location
	std::vector<Location> m_catsFirstLocs;		// cats initial locations
	std::vector<Location> m_cheeseLocations;	// cheese locations
};