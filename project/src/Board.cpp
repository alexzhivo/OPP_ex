#include "Board.h"

#include "iostream" // for debuging

Board::Board(GraphicManager& graphicManager, std::string fileName , const int level)
	: m_graphicManager(graphicManager), m_gameHUD(graphicManager),
	m_background(), m_gameObjects(), m_player(), m_level(level)
{
	loadLevelFromFile(fileName);
}

void Board::loadLevelFromFile(const std::string fileName)
{
	auto file = std::ifstream(fileName);

	if (!file)
	{
		return;
	}

	// set timer (if 0 - no timer) (if > 0 - timer)
	file >> m_numOfRows >> m_numOfCols >> m_totalTime;

	// scaling board to window
	scaleBoard();
	float startX, startY;
	float tileScale;
	if (m_width == BOARD_WIDTH) {
		startX = 0;
		startY = (BOARD_HEIGHT - m_height) / 2;
		tileScale = 18.75f / m_numOfCols;
	}
	else {
		startY = 0;
		startX = (BOARD_WIDTH - m_width) / 2;
		tileScale = 10.9375f / m_numOfRows;
	}

	// background creation
	m_background.setSize(sf::Vector2f(m_width, m_height));
	m_background.setFillColor(sf::Color(50, 50, 50));
	m_background.setPosition(sf::Vector2f(startX, startY));

	auto line = std::string();
	getline(file, line);
	for (int i = 0; i < m_numOfRows; i++)
	{
		getline(file, line);
		for (int j = 0; j < line.length(); j++) {
			switch (line.at(j)) {
			case '#':
				m_gameObjects.push_back(std::make_unique<Wall>(
					sf::Vector2f(m_tileSize * j + startX, m_tileSize * i + startY),
					tileScale,
					m_graphicManager.getTexture("wall")));
				break;
			case '^':
				m_enemies.push_back(std::make_unique<Cat>(
					sf::Vector2f(m_tileSize * j + startX, m_tileSize * i + startY),
					tileScale,
					m_graphicManager.getTexture("cat")));
				break;
			case '%':
				m_player = (std::make_unique<Mouse>(
					sf::Vector2f(m_tileSize * j + startX, m_tileSize * i + startY),
					tileScale,
					m_graphicManager.getTexture("mouse")));
				break;
			case '*':
				m_gameObjects.push_back(std::make_unique<Cheese>(
					sf::Vector2f(m_tileSize * j + startX, m_tileSize * i + startY),
					tileScale,
					m_graphicManager.getTexture("cheese")));
				break;
			case 'D':
				m_gameObjects.push_back(std::make_unique<Door>(
					sf::Vector2f(m_tileSize * j + startX, m_tileSize * i + startY),
					tileScale,
					m_graphicManager.getTexture("door")));
				break;
			case 'F':
				m_gameObjects.push_back(std::make_unique<Key>(
					sf::Vector2f(m_tileSize * j + startX, m_tileSize * i + startY),
					tileScale,
					m_graphicManager.getTexture("key")));
				break;
			case '$':
				m_gameObjects.push_back(std::make_unique<Gift>(
					sf::Vector2f(m_tileSize * j + startX, m_tileSize * i + startY),
					tileScale,
					m_graphicManager.getTexture("gift")));
				break;
			default:
				break;
			}
		}
	}
}

void Board::scaleBoard()
{
	float boardRatio = m_numOfRows / m_numOfCols;
	float windowRatio = BOARD_HEIGHT / BOARD_WIDTH;

	if (boardRatio > windowRatio) {
		m_height = BOARD_HEIGHT;
		m_tileSize = m_height / m_numOfRows;
		m_width = m_tileSize * m_numOfCols;
	}
	else {
		m_width = BOARD_WIDTH;
		m_tileSize = m_width / m_numOfCols;
		m_height = m_tileSize * m_numOfRows;
	}
}
void Board::draw(sf::RenderWindow& window)
{
	Mouse* player = static_cast<Mouse*>(m_player.get());

	window.draw(m_background);
	m_gameHUD.updateAndDraw(window, m_level,
		player->getLives(), player->getKeys(), player->getScore() , getCurrentTime());

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
	m_gameObjects.clear();
	m_enemies.clear();
}

void Board::restartClock()
{
	m_levelClock.restart();
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

int Board::getLevel() const
{
	return m_level;
}

int Board::getCurrentTime() const
{
	if (m_totalTime > 0) {
		return m_totalTime - (int)m_levelClock.getElapsedTime().asSeconds();
	}
	return m_levelClock.getElapsedTime().asSeconds();
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
	handleCollisions(*m_player);	
}

void Board::handleCollisions(GameObject& gameObject)
{
	for (auto& unmovable : m_gameObjects)
	{
		if (gameObject.collide_with(*unmovable))
		{
			gameObject.handleCollision(*unmovable);
		}
	}

	for (auto& movable : m_enemies)
	{
		if (gameObject.collide_with(*movable))
		{
			gameObject.handleCollision(*movable);
		}
	}
}

