#include "Board.h"
#include <vector>

Board::Board(std::string fileName)
{
	auto file = std::ifstream(fileName);

	if (!file) 	        // if cant find file
		exit(EXIT_FAILURE);

	auto line = std::string();

	while (std::getline(file, line))
	{
		m_currBoard.push_back(line);
		for (auto col = 0; col < line.size(); ++col)
		{
			if (line[col] == '%')
			{
				m_mouseFirstLoc.row = m_currBoard.size() - 1;
				m_mouseFirstLoc.col = col;
				m_currBoard[m_mouseFirstLoc.row][m_mouseFirstLoc.col] = ' ';
			}
			if (line[col] == '^')
			{
				m_catsFirstLocs.push_back(Location(col, m_currBoard.size() - 1));
				m_currBoard[m_currBoard.size() - 1][col] = ' ';  // Update the board
			}
			if (line[col] == '*')
				m_cheeseLocations.emplace_back(Location(col, m_currBoard.size() - 1));
		}
	}
}

int Board::getBoardSize()
{
	return m_currBoard.size();
}

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

Location Board::getMouseLocation()
{
		return m_mouseFirstLoc;
}

// returns a vector of Cats Locations
std::vector<Location> Board::getCatsLocations()
{
	return m_catsFirstLocs;
}

std::vector<Location> Board::getCheeseLocations()
{
	return m_cheeseLocations;
}

void Board::clearCheese(Location position)
{
	m_currBoard[position.row][position.col] = ' ';

	m_cheeseLocations.erase(std::remove_if(
		m_cheeseLocations.begin(),
		m_cheeseLocations.end(),
		[&position](const Location& loc) {
			return loc.col == position.col && loc.row == position.row;
		}
	), m_cheeseLocations.end());

	std::cout << m_cheeseLocations.size() << std::endl;
}

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