#include "Board.h"

Board::Board(std::string fileName)
{
	auto file = std::ifstream(fileName);

	if (!file) 	        // if cant find file
		exit(EXIT_FAILURE);

	auto line = std::string();
	std::getline(file, line);	//Read a line

	while (!line.empty())
	{
		m_currBoard.push_back(line);	//each line is kept in the vector
		std::getline(file, line);
	}

	file >> m_mouseFirstLoc.col >> m_mouseFirstLoc.row;
}

size_t Board::getBoardSize()
{
	return m_currBoard.size();
}

void Board::printCurrBoard()
{
	for (auto x = 0; x < m_currBoard.size(); ++x)
	{
		for (auto y = 0; y < m_currBoard[x].size(); ++y)
		{
			std::cout << m_currBoard[x][y];
		}
		std::cout << std::endl;
	}
}


Location Board::getLocations(int searchedPlayer)
{
	switch (searchedPlayer)
	{
	case 0:
		return Location(m_mouseFirstLoc);
	}
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
