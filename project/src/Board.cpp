#include "Board.h"
#include "Window.h"

#include "iostream" // for debuging

Board::Board(std::string fileName)
	: m_background() , m_gameObjects()
{
	loadLevelFromFile(fileName);

	// background creation
	m_background.setSize(sf::Vector2f(BOARD_WIDTH, BOARD_HEIGHT));
	m_background.setFillColor(sf::Color(50, 50, 50));
	m_background.setPosition(sf::Vector2f(0.f, 0.f));
}

void Board::loadLevelFromFile(std::string fileName)
{
	auto file = std::ifstream(fileName);

	if (!file)
	{
		std::cout << "file did not open.\n" << std::endl;
		return;
	}
	std::cout << "opened file.\n" << std::endl;

	auto line = std::string();

	if (std::getline(file, line)) {
		m_numOfRows = 1;
		m_numOfCols = (int)line.length();
	}
	while (std::getline(file, line))
	{
		m_numOfRows++;
	}

	setTileSize();	// change tile size to fit the screen.
	file.clear();	// cleaning EOF flag
	file.seekg(0);	// start from the beginning of the file.

	for  (int i = 0 ; std::getline(file, line) ; i++) 
	{
		for (int j = 0; j < line.length(); j++) {
			if (line.at(j) == '#') {
				m_gameObjects.emplace_back(std::make_unique<Wall>(sf::Vector2f(m_tileSize.y * j,m_tileSize.x * i)));
			}
		}
	}
}

void Board::setTileSize()
{
	m_tileSize.x = (float) BOARD_HEIGHT / m_numOfRows;
	m_tileSize.y = (float) BOARD_WIDTH / m_numOfCols;
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