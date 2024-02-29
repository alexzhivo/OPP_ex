#include "Board.h"

#include "iostream" // for debuging

Board::Board(GraphicManager& graphicManager, std::string fileName , const int level)
	: m_graphicManager(graphicManager), m_gameHUD(graphicManager),
	m_background(), m_gameObjects(), m_player(), m_level(level)
{
	loadLevelFromFile(fileName);
}

bool Board::loadLevelFromFile(const std::string fileName)
{
	auto file = std::ifstream(fileName);

	if (!file)
	{
		return false;
	}

	// set timer (if 0 - no timer) (if > 0 - timer)
	file >> m_numOfRows >> m_numOfCols >> m_totalTime;

	// scaling board to window
	scaleBoard();
	//float startX, startY;
	float tileScale;
	if (m_width == BOARD_WIDTH) {
		m_start.x = 0;
		m_start.y = (BOARD_HEIGHT - m_height) / 2;
		tileScale = 18.75f / m_numOfCols;
	}
	else {
		m_start.y = 0;
		m_start.x = (BOARD_WIDTH - m_width) / 2;
		tileScale = 10.9375f / m_numOfRows;
	}

	// background creation
	m_background.setSize(sf::Vector2f(m_width, m_height));
	m_background.setFillColor(sf::Color(50, 50, 50));
	m_background.setPosition(m_start);

	auto line = std::string();
	getline(file, line);
	for (int i = 0; i < m_numOfRows; i++)
	{
		getline(file, line);
		for (int j = 0; j < line.length(); j++) {
			auto position = sf::Vector2f(m_tileSize * j + m_start.x, m_tileSize * i + m_start.y);
			switch (line.at(j)) {
			case '#':
				m_gameObjects.push_back(std::make_unique<Wall>(
					position,
					tileScale,
					m_graphicManager.getTexture("wall")));
				break;
			case '^':
				m_enemies.push_back(std::make_unique<Cat>(
					position,
					tileScale,
					m_graphicManager.getTexture("cat"),
					m_graphicManager.getTexture("cat"),
					m_graphicManager.getTexture("cat"),
					m_graphicManager.getTexture("cat")));
				break;
			case '%':
				if (!m_player) {
					m_player = (std::make_unique<Mouse>(
						position,
						tileScale,
						m_graphicManager.getTexture("mouse-front"),
						m_graphicManager.getTexture("mouse-right"),
						m_graphicManager.getTexture("mouse-back"),
						m_graphicManager.getTexture("mouse-left")));
				}
				else {
					static_cast<Mouse*>(m_player.get())->reload(position,tileScale);
				}
				break;
			case '*':
				m_gameObjects.push_back(std::make_unique<Cheese>(
					position,
					tileScale,
					m_graphicManager.getTexture("cheese")));
				break;
			case 'D':
				m_gameObjects.push_back(std::make_unique<Door>(
					position,
					tileScale,
					m_graphicManager.getTexture("door")));
				break;
			case 'F':
				m_gameObjects.push_back(std::make_unique<Key>(
					position,
					tileScale,
					m_graphicManager.getTexture("key")));
				break;
			case '$':
				addRandomGift(position, tileScale);
				break;
			default:
				break;
			}
		}
	}
	return true;
}

void Board::scaleBoard()
{
	float boardRatio = (float)m_numOfRows / m_numOfCols;
	float windowRatio = (float)BOARD_HEIGHT / BOARD_WIDTH;

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
	std::cout << m_width << " " << m_height << std::endl;
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

bool Board::removeRandomEnemy()
{
	auto numberOfEnemies = m_enemies.size();
	if (numberOfEnemies != 0) {
		auto index = (rand() % numberOfEnemies);
		m_enemies.erase(m_enemies.begin() + index);
		return true;
	}
	return false;
}

bool Board::freezeEnemies(const float seconds)
{
	auto numberOfEnemies = m_enemies.size();
	if (numberOfEnemies != 0) {
		m_isFreezingEnemies = true;
		m_freezeDuration = seconds;
		m_elapsedFreezeTime = 0.0f;

		for (int i = 0; i < numberOfEnemies; i++) {
			m_enemies[i]->setSpeed(0);
		}
		return true;
	}
	return false;
}

void Board::addTime(const float seconds)
{
	m_totalTime += (int)sf::seconds(seconds).asSeconds();
}

void Board::upLevel()
{
	m_level++;
	static_cast<Mouse*>(m_player.get())->increaseScore(25 + m_enemies.size());

	m_gameObjects.clear();
	m_enemies.clear();
	static_cast<Mouse*>(m_player.get())->setReset();
}

void Board::resetBoard()
{
	m_player.release();
	loadLevelFromFile("Board1.txt");
	m_level = 1;
}

void Board::restartClock()
{
	m_levelClock.restart();
}

void Board::restartLevel()
{
	static_cast<Mouse*>(m_player.get())->reset();
	m_gameObjects.clear();
	m_enemies.clear();
}

void Board::movePlayer(const Direction direction, const float dtSeconds)
{
	MovingObject* player = static_cast<MovingObject*>(m_player.get());
	sf::Sprite playerSprite = player->getSprite();
	switch (direction) {
	case LEFT:
		if (playerSprite.getPosition().x > m_start.x) {
			player->move(-1, 0, dtSeconds);
			player->switchTexture(LEFT);
		}
		break;
	case RIGHT:
		if (playerSprite.getPosition().x + playerSprite.getGlobalBounds().width < m_start.x + m_width) {
			player->move(1, 0, dtSeconds);
			player->switchTexture(RIGHT);
		}
		break;
	case UP:
		if (playerSprite.getPosition().y > m_start.y) {
			player->move(0, -1, dtSeconds);
			player->switchTexture(DOWN);
		}
		break;
	case DOWN:
		if (playerSprite.getPosition().y + playerSprite.getGlobalBounds().height <= m_start.y + m_height) {
			std::cout << playerSprite.getPosition().y+playerSprite.getLocalBounds().height << " <= " << m_start.y + m_height<< std::endl;
			player->move(0, 1, dtSeconds);
			player->switchTexture(UP);
		}
		break;
	}
}

void Board::moveEnemies(const float dtSeconds)
{
	for (int i = 0; i < m_enemies.size(); i++) {
		Cat* enemy = static_cast<Cat*>(m_enemies[i].get());
		enemy->moveToRandomLocation(dtSeconds, sf::Vector2f(m_width,m_height), m_start);
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
	return (int)m_levelClock.getElapsedTime().asSeconds();
}

int Board::getScore() const
{
	return static_cast<Mouse*>(m_player.get())->getScore();
}

void Board::updateObjects(const float dtSeconds)
{
	for (int i = 0; i >= 0 && i < m_gameObjects.size(); i++) {
		if (dynamic_cast<StaticObject*>(m_gameObjects[i].get())->isExisting() == false)
		{
			m_gameObjects.erase(m_gameObjects.begin() + i);
			i--;
		}
	}

	if (m_isFreezingEnemies) {
		m_elapsedFreezeTime += dtSeconds;
		if (m_elapsedFreezeTime >= m_freezeDuration) {
			for (int i = 0; i < m_enemies.size(); i++) {
				m_enemies[i]->setSpeed(80);
			}
		}
	}
}

CollisionType Board::checkCollisions()
{
	handleCollisions(*m_player);
	for (int i = 0; i < m_enemies.size(); i++) {
		handleCollisions(*m_enemies[i]);
	}

	return static_cast<Mouse*>(m_player.get())->getCollisionType();
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

void Board::addRandomGift(const sf::Vector2f position, const float tileScale)
{
	static int lastRandomNum = 0;
	int seed = ((int)time(nullptr) + lastRandomNum) % 10000;
	srand(seed);
	lastRandomNum = seed;

	// prevent from getting time gift when no there is no time limit
	int gifts = 4;
	if (m_totalTime == 0)
		gifts--;

	auto num = (rand() % gifts) + 1;

	switch (num) {
	case 1:
		m_gameObjects.push_back(std::make_unique<EnemyRemoveGift>(
			position,
			tileScale,
			m_graphicManager.getTexture("gift")));
		break;
	case 2:
		m_gameObjects.push_back(std::make_unique<FreezeGift>(
			position,
			tileScale,
			m_graphicManager.getTexture("gift")));
		break;
	case 3:
		m_gameObjects.push_back(std::make_unique<LifeGift>(
			position,
			tileScale,
			m_graphicManager.getTexture("gift")));
		break;
	case 4:
		m_gameObjects.push_back(std::make_unique<TimeGift>(
			position,
			tileScale,
			m_graphicManager.getTexture("gift")));
		break;
	}
}