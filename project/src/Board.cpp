#include "Board.h"

#include "iostream" // for debuging

Board::Board(GraphicManager& graphicManager, std::string fileName , const int level)
	: m_graphicManager(graphicManager), m_background(), m_gameObjects(), m_player(), m_level(level)
{
	loadLevelFromFile(fileName);
	

	// background creation
	m_background.setSize(sf::Vector2f(BOARD_WIDTH,BOARD_HEIGHT));
	m_background.setFillColor(sf::Color(50, 50, 50));
	m_background.setPosition(sf::Vector2f(0.f, 0.f));
}

void Board::loadLevelFromFile(const std::string fileName)
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
			switch (line.at(j)) {
			case '#':
				m_gameObjects.push_back(std::make_unique<Wall>(
					sf::Vector2f(m_tileSize.y * j, m_tileSize.x * i),
					m_tileSize,
					m_graphicManager.getTexture("wall")));
				break;
			case '^':
				m_enemies.push_back(std::make_unique<Cat>(
					sf::Vector2f(m_tileSize.y * j, m_tileSize.x * i),
					m_tileSize,
					m_graphicManager.getTexture("cat")));
				break;
			case '%':
				m_player = (std::make_unique<Mouse>(
					sf::Vector2f(m_tileSize.y * j, m_tileSize.x * i),
					m_tileSize,
					m_graphicManager.getTexture("mouse")));
				break;
			case '*':
				m_gameObjects.push_back(std::make_unique<Cheese>(
					sf::Vector2f(m_tileSize.y * j, m_tileSize.x * i),
					m_tileSize,
					m_graphicManager.getTexture("cheese")));
				break;
			case 'D':
				m_gameObjects.push_back(std::make_unique<Door>(
					sf::Vector2f(m_tileSize.y * j, m_tileSize.x * i),
					m_tileSize,
					m_graphicManager.getTexture("door")));
				break;
			case 'F':
				m_gameObjects.push_back(std::make_unique<Key>(
					sf::Vector2f(m_tileSize.y * j, m_tileSize.x * i),
					m_tileSize,
					m_graphicManager.getTexture("key")));
				break;
			case '$':
				m_gameObjects.push_back(std::make_unique<Gift>(
					sf::Vector2f(m_tileSize.y * j, m_tileSize.x * i),
					m_tileSize,
					m_graphicManager.getTexture("gift")));
				break;
			default:
				break;
			}
		}
	}
}

void Board::setTileSize()
{
	m_tileSize = sf::Vector2f((float)BOARD_HEIGHT / m_numOfRows, (float)BOARD_WIDTH / m_numOfCols);
}

void Board::setBoardSize()
{
	m_width = m_numOfCols * m_tileSize.x;
	m_height = m_numOfRows * m_tileSize.y;
}
void Board::draw(sf::RenderWindow& window)
{
	window.draw(m_background);
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw(window);
	}
	for (int i = 0; i < m_enemies.size(); i++) {
		m_enemies[i]->draw(window);
	}
	m_player->draw(window);
}

void Board::upLevel()
{
	m_level++;
}

void Board::movePlayer(const Direction direction, const float dtSeconds)
{
	switch (direction) {
	case LEFT:
		m_player->move(-1, 0, dtSeconds);
		break;
	case RIGHT:
		m_player->move(1, 0, dtSeconds);
		break;
	case UP:
		m_player->move(0, -1, dtSeconds);
		break;
	case DOWN:
		m_player->move(0, 1, dtSeconds);
		break;
	}
}

sf::Vector2f Board::getTileSize() const // temporary for check
{
	return m_tileSize;
}

int Board::getLevel() const
{
	return m_level;
}