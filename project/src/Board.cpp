#include "Board.h"
#include "Window.h"

Board::Board(std::string fileName)
{
	loadLevelFromFile(fileName);
	setTileSize();
}

void Board::loadLevelFromFile(std::string fileName)
{
	auto file = std::ifstream(fileName);

	if (!file)
	{
		exit(EXIT_FAILURE);
	}

	file >> m_numOfRows >> m_numOfCols;

	auto line = std::string();

	while (std::getline(file, line))
	{
		m_fileBoard.push_back(line);
	}
}

void Board::setTileSize()
{
	m_tileSize.x = float(WINDOW_HEIGHT) / m_numOfRows;
	m_tileSize.y = float(WINDOW_WIDTH) / m_numOfCols;
}