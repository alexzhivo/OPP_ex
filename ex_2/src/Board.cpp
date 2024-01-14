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
}

size_t Board::getBoardSize()
{
	return m_currBoard.size();
}

void Board::printCurrBoard()
{
	for (int x = 0; x < m_currBoard.size(); ++x)
	{
		std::cout << m_currBoard[x];
		std::cout << std::endl;
	}
}