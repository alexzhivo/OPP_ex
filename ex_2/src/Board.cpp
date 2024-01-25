#include "Board.h"
#include <vector>
#include "Io.h"

Board::Board(std::string fileName,const int lvl)
	: m_level(lvl)
{
	auto file = std::ifstream(fileName);

	if (!file) 
	{	// if cant find file
		m_level = 0;
		return;
	}
	auto line = std::string();

	while (std::getline(file, line))
	{
		m_currBoard.push_back(line);
		for (auto col = 0; col < line.size(); ++col)
		{
			const Location currentLocation(col, (int)m_currBoard.size() - 1);
			processCharacter(line[col], currentLocation);
		}
	}
}

// Helper function to process a character at a given location
void Board::processCharacter(char character, const Location& currentLocation)
{
	if (character == '%') 
	{
		m_mouseFirstLoc = currentLocation;
		clearCell(currentLocation);
	}
	else if (character == '^') 
	{
		m_catsFirstLocs.push_back(currentLocation);
		clearCell(currentLocation);
	}
	else if (character == '*') 
	{
		m_cheeseLocations.push_back(currentLocation);
	}
	else if (character == 'F') 
	{
		m_keysLocations.push_back(currentLocation);
	}
	else if (character == '$') 
	{
		m_presentsLocation.push_back(currentLocation);
	}
}

// returns current board size
int Board::getBoardSize() const
{
	return (int)m_currBoard.size();
}

// returns how many cats were at the beginning.
int Board::getCatsNumInLevel() const
{
	return (int)m_catsFirstLocs.size();
}

// prints the current board and the pickable items
void Board::print()
{
	// prints the board
	for (auto row = 0; row < m_currBoard.size(); ++row)
	{
		for (auto col = 0; col < m_currBoard[row].size(); ++col)
		{
			std::cout << m_currBoard[row][col];
		}
		std::cout << std::endl;
	}
}

// returns a vector of first mouse location
Location Board::getMouseLocation() const
{
		return m_mouseFirstLoc;
}

// returns a vector of Cats first Locations
std::vector<Location> Board::getCatsLocations() const
{
	return m_catsFirstLocs;
}

// returns a vector of cheese Locations on Board
std::vector<Location> Board::getCheeseLocations() const
{
	return m_cheeseLocations;
}

// clears a cell on board
void Board::clearCell(const Location& location) 
{
	m_currBoard[location.row][location.col] = ' ';
}

// remove an item from board and from item vector
void Board::clearItem(Location position, const char item)
{
	clearCell(position);

	std::vector<Location>* items = nullptr;

	switch (item) {
		case '*': 
			items = &m_cheeseLocations;
			break;
		case '$':
			items = &m_presentsLocation;
			break;
		case 'F':
			items = &m_keysLocations;
			break;
		default :
			return;
	}
	removeItemFromVector(position, *items);
	/*(*items).erase(std::remove_if(
		(*items).begin(),
		(*items).end(),
		[&position](const Location& loc) 
		{
			return loc.col == position.col && loc.row == position.row;
		}
	), (*items).end());*/
}

// Remove an item from the vector
void Board::removeItemFromVector(Location position, std::vector<Location>& items)
{
	items.erase(std::remove_if(
		items.begin(),
		items.end(),
		[&position](const Location& loc)
		{
			return loc.col == position.col && loc.row == position.row;
		}
	), items.end());
}

// checks if cheese left on board
bool Board::isCheeseLeft() const
{
	return !m_cheeseLocations.empty();
}

// returns the Char in the given Location
char Board::getChar(Location position) const
{
	return m_currBoard[position.row][position.col];
}

// Check if the new position is within the bounds of the board
bool Board::newPositionIsValid(const Location& newPosition)
{
	return (newPosition.row >= 0 && newPosition.row < m_currBoard.size() &&
			newPosition.col >= 0 && newPosition.col < m_currBoard[0].size());
}

bool Board::isSamePosition(const Location pos1, const Location pos2)
{
	return(pos1.col == pos2.col && pos1.row == pos2.row);
}
void Board::levelUp()
{
	m_level++;
}

int Board::getLevel() const
{
	return m_level;
}