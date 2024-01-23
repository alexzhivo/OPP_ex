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
			if (line[col] == '%')
			{
				m_mouseFirstLoc.row = (int)(m_currBoard.size() - 1);
				m_mouseFirstLoc.col = col;
				m_currBoard[m_mouseFirstLoc.row][m_mouseFirstLoc.col] = ' ';
			}
			if (line[col] == '^')
			{
				m_catsFirstLocs.push_back(Location(col,(int)m_currBoard.size() - 1));
				m_currBoard[m_currBoard.size() - 1][col] = ' ';  // Update the board
			}
			if (line[col] == '*')
				m_cheeseLocations.emplace_back(Location(col,(int)m_currBoard.size() - 1));
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

// clears a block on board
void Board::clearBlock(Location position)
{
	m_currBoard[position.row][position.col] = ' ';
}

// remove the cheese from board and from cheese vector
void Board::removeCheese(Location position)
{
	clearBlock(position);

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