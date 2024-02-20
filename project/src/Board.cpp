#include "Board.h"

#include "iostream" // for debuging

Board::Board(GraphicManager& graphicManager, std::string fileName , const int level)
	: m_graphicManager(graphicManager), m_background(), m_gameObjects(), m_level(level)
{
	loadLevelFromFile(fileName);
	
	// background creation
	m_background.setSize(sf::Vector2f((float)m_width, (float)m_height));
	m_background.setFillColor(sf::Color(50, 50, 50));
	m_background.setPosition(sf::Vector2f(0.f, 0.f));
}

void Board::loadLevelFromFile(std::string fileName)
{
	auto file = std::ifstream(fileName);

	if (!file)
	{
		return;
	}

	file >> m_numOfRows >> m_numOfCols;

	setTileSize();	// change tile size to fit the screen.
	setBoardSize();

	auto line = std::string();
	getline(file, line);
	for (int i = 0; i < m_numOfRows; i++)
	{
		getline(file, line);
		for (int j = 0; j < line.length(); j++) {
			if (line.at(j) == '#') {
				  m_gameObjects.push_back(std::make_unique<Wall>(
					sf::Vector2f(m_tileSize * j, m_tileSize * i),
					sf::Vector2f(m_tileSize, m_tileSize) , 
					m_graphicManager.getTexture("wall")));
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
	m_width = m_numOfCols * m_tileSize;
	m_height = m_numOfRows * m_tileSize;
}
void Board::draw(sf::RenderWindow& window)
{
	window.draw(m_background);
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw(window);
	}
}

void Board::upLevel()
{
	m_level++;
}


float Board::getTileSize() const // temporary for check
{
	return m_tileSize;
}

int Board::getLevel() const
{
	return m_level;
}