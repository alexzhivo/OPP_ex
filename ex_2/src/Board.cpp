#include "Board.h"
#include <vector>
#include "Io.h"

Board::Board(std::string fileName,const int lvl)
	: m_level(lvl)
{
	auto file = std::ifstream(fileName);

	if (!file) {	// if cant find file
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

			if (line[col] == '%')
			{
				m_mouseFirstLoc = currentLocation;
				clearCell(currentLocation);
			}
			if (line[col] == '^')
			{
				m_catsFirstLocs.push_back(currentLocation);
				clearCell(currentLocation);
			}
			if (line[col] == '*')
				m_cheeseLocations.push_back(currentLocation);
			if (line[col] == 'F')
				m_keysLocations.push_back(currentLocation);
			if (line[col] == '$')
				m_presentsLocation.push_back(currentLocation);
		}
	}
}

// returns current board size
int Board::getBoardSize()
{
	return (int)m_currBoard.size();
}

// returns how many cats were at the beginning.
int Board::getCatsNumInLevel()
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
	// prints the pickable items
	// cheese
	for (auto item = 0; item < m_cheeseLocations.size(); item++) {
		Screen::setLocation(m_cheeseLocations[item]);
		std::cout << '*';
	}
	// keys
	for (auto item = 0; item < m_keysLocations.size(); item++) {
		Screen::setLocation(m_keysLocations[item]);
		std::cout << 'F';
	}
	// presents
	for (auto item = 0; item < m_presentsLocation.size(); item++) {
		Screen::setLocation(m_presentsLocation[item]);
		std::cout << '$';
	}
	Screen::resetLocation();
}

// returns a vector of first mouse location
Location Board::getMouseLocation()
{
		return m_mouseFirstLoc;
}

// returns a vector of Cats first Locations
std::vector<Location> Board::getCatsLocations()
{
	return m_catsFirstLocs;
}

// returns a vector of cheese Locations on Board
std::vector<Location> Board::getCheeseLocations()
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

	(*items).erase(std::remove_if(
		(*items).begin(),
		(*items).end(),
		[&position](const Location& loc) 
		{
			return loc.col == position.col && loc.row == position.row;
		}
	), (*items).end());
}

// checks if cheese left on board
bool Board::isCheeseLeft()
{
	return !m_cheeseLocations.empty();
}

// returns the Char in the given Location
char Board::getChar(Location position)
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