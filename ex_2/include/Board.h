#pragma once

#include "Location.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Board {
public:
	Board(std::string fileName,const int lvl);				// defaut constructor

	void print();								// prints the board
	bool newPositionIsValid(const Location& newPosition);
	void clearItem(Location position, const char item);
	void clearCell(const Location& location);
	int getBoardSize();
	char getChar(Location position);
	Location getMouseLocation();
	bool isSamePosition(const Location pos1, const Location pos2);
	std::vector<Location> getCatsLocations();	// get cats locations
	std::vector<Location> getCheeseLocations();	// get cheese locations
	bool isCheeseLeft();						// checks if cheese left on board
	int getCatsNumInLevel();

	int getLevel() const;
	void levelUp();

private:

	std::vector<std::string> m_currBoard;		// current level board

	Location m_mouseFirstLoc;					// mouse initial location
	std::vector<Location> m_catsFirstLocs;		// cats initial locations

	std::vector<Location> m_cheeseLocations;	// cheese locations
	std::vector<Location> m_keysLocations;		// kets locations
	std::vector<Location> m_presentsLocation;	// presents locations

	int m_level;
};