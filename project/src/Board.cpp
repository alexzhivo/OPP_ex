#include "Board.h"

#include "iostream" // for debuging

Board::Board(GraphicManager& graphicManager, std::string fileName , const int level)
	: m_graphicManager(graphicManager), m_gameHUD(graphicManager), m_background(), m_gameObjects(), m_player(), m_level(level)
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
	Mouse* player = static_cast<Mouse*>(m_player.get());

	window.draw(m_background);
	m_gameHUD.updateAndDraw(window, m_level,
		player->getLives(), player->getKeys(), player->getScore());

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
	MovingObject* player = static_cast<MovingObject*>(m_player.get());

	switch (direction) {
	case LEFT:
		player->move(-1, 0, dtSeconds);
		break;
	case RIGHT:
		player->move(1, 0, dtSeconds);
		break;
	case UP:
		player->move(0, -1, dtSeconds);
		break;
	case DOWN:
		player->move(0, 1, dtSeconds);
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

void Board::updateObjects()
{
	for (int i = 0; i >= 0 && i < m_gameObjects.size(); i++) {
		if (dynamic_cast<StaticObject*>(m_gameObjects[i].get())->isExisting() == false)
		{
			m_gameObjects.erase(m_gameObjects.begin() + i);
			i--;
		}
	}
}

void Board::checkCollisions()
{
	// check collisions with static objects
	for (int i = 0 ; i < m_gameObjects.size() ; i++)
	{
		if (dynamic_cast<GameObject*>(m_gameObjects[i].get()) && m_player->collide_with(*m_gameObjects[i].get()))
			m_player->handleCollision(*m_gameObjects[i].get());
	}

	// check collisions with moving objects
	for (int i = 0; i < m_enemies.size(); i++) {
		if (dynamic_cast<GameObject*>(m_enemies[i].get()) && m_player->collide_with(*m_enemies[i].get()))
			m_player->handleCollision(*m_enemies[i].get());
	}
}

// for debugging
void Board::removeObject()
{
	// debug
	int index = 20;
	// -----
	if (index < m_gameObjects.size()) {
		StaticObject* objectToRemove = static_cast<StaticObject*>(m_gameObjects[index].get());
		objectToRemove->remove();
	}
}
// -------------