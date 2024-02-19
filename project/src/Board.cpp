#include "Board.h"
#include "Window.h"

#include "iostream" // for debuging

Board::Board(std::string fileName)
	: m_background() , m_gameObjects()
{
	loadLevelFromFile(fileName);
	

	// background creation
	m_background.setSize(sf::Vector2f((float)m_boardWidth, (float)m_boardHeight));
	m_background.setFillColor(sf::Color(50, 50, 50));
	m_background.setPosition(sf::Vector2f(0.f, 0.f));

	//Mouse mouse(sf::Vector2f(20, 20), sf::Vector2f(m_tileSize, m_tileSIze));	// create mouse
}

void Board::loadLevelFromFile(std::string fileName)
{
	auto file = std::ifstream(fileName);

	if (!file)
	{
		return;
	}

	file >> m_numOfRows >> m_numOfCols;

	auto line = std::string();
	getline(file, line);
	for (int i = 0; i < m_numOfRows; i++)
	{
		getline(file, line);
		m_fileBoard.push_back(line);
	}

	setTileSize();	// change tile size to fit the screen.
	setBoardSize();

	sf::Vector2f position;
	

	for (int i = 0; i < m_numOfRows; i++) 
	{
		for (int j = 0; j < m_numOfCols; j++) 
		{
			if (m_fileBoard[i][j] == '#')
			{
				position.x = m_tileSize * j;
				position.y = m_tileSize * i;
				
				m_gameObjects.push_back(std::make_unique<Wall>(position, sf::Vector2f(m_tileSize, m_tileSize)));
			}
		}
	}
}

void Board::setTileSize()
{
	m_tileSize = ((float)WINDOW_WIDTH) / (std::max(m_numOfRows, m_numOfCols));
}

void Board::setBoardSize()
{
	m_boardWidth = m_tileSize * m_numOfCols;
	m_boardHeight = m_tileSize * m_numOfRows;
}
void Board::draw(sf::RenderWindow& window)
{
	window.draw(m_background);
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw(window);
	}
}

sf::FloatRect Board::getBoardBounds() const
{
	return m_background.getGlobalBounds();
}

float Board::getTileSize() // temporary for check
{
	return m_tileSize;

}