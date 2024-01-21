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

std::vector<Location> Board::getCatsLocations()
{
	return m_catsFirstLocs;
}

char Board::getChar(Location position)
{
	return m_currBoard[position.row][position.col];
}

bool Board::newPositionIsValid(const Location& newPosition)
{
	// Check if the new position is within the bounds of the board
	return (newPosition.row >= 0 && newPosition.row < m_currBoard.size() &&
			newPosition.col >= 0 && newPosition.col < m_currBoard[0].size());
}


