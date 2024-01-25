#pragma once

#include "Location.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Board {
public:
	Board(std::string fileName, const int lvl);
	bool newPositionIsValid(const Location& newPosition);
	void clearItem(Location position, const char item);
	void clearCell(const Location& location);
	void print();							
	void levelUp();

	bool isSamePosition(const Location pos1, const Location pos2);
	bool isCheeseLeft() const;

	int getCatsNumInLevel() const;
	int getBoardSize() const;
	char getChar(Location position) const;
	int getLevel() const;
	Location getMouseLocation() const;
	std::vector<Location> getCatsLocations() const;
	std::vector<Location> getCheeseLocations() const;
	void removeItemFromVector(Location position, std::vector<Location>& items);
	void processCharacter(char character, const Location& currentLocation);

private:

	std::vector<std::string> m_currBoard;		// current level board
	Location m_mouseFirstLoc;					// mouse initial location
	std::vector<Location> m_catsFirstLocs;		// cats initial locations
	std::vector<Location> m_cheeseLocations;	// cheese locations
	std::vector<Location> m_keysLocations;		// kets locations
	std::vector<Location> m_presentsLocation;	// presents locations

	int m_level;
};