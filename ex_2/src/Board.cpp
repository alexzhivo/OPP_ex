#include "Board.h"
#include <vector>

Board::Board(std::string fileName)
{
	auto file = std::ifstream(fileName);

	if (!file) 	// if cant find file
		exit(EXIT_FAILURE);

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
		}
	}
}

// returns current board size
int Board::getBoardSize()
{
	return (int)m_currBoard.size();
}

// prints current board
void Board::printCurrBoard()
{
	for (auto row = 0; row < m_currBoard.size(); ++row)
	{
		for (auto col = 0; col < m_currBoard[row].size(); ++col)
		{
			std::cout << m_currBoard[row][col];
		}
		std::cout << std::endl;
	}
}

      // old function before merge
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

void Board::clearCell(const Location& location) 
{
	m_currBoard[location.row][location.col] = ' ';
}


// remove the cheese from board and from cheese vector
void Board::clearCheese(Location position)
{
	clearCell(position);

	m_cheeseLocations.erase(std::remove_if(
		m_cheeseLocations.begin(),
		m_cheeseLocations.end(),
		[&position](const Location& loc) 
		{
			return loc.col == position.col && loc.row == position.row;
		}
	), m_cheeseLocations.end());
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