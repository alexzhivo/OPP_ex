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

	//Read to a matrix the locations of the players
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			auto x = std::string();
			file >> x;
			m_playersLoc[i][j] = stoi(x);
		}
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

Location Board::getLocations(int searchedPlayer)
{
	switch (searchedPlayer)
	{
	case 0:
		return Location(m_playersLoc[0][0], m_playersLoc[0][1]);

	}
}