#include "Cat.h"
#include "Mouse.h"

Cat::Cat(const sf::Vector2f position, const float size,
	sf::Texture* frontTexture,
	sf::Texture* leftTexture,
	sf::Texture* backTexture,
	sf::Texture* rightTexture)
	: MovingObject(position, size,
		frontTexture, leftTexture, backTexture, rightTexture), m_nextLocation(0,0)
{
	this->setSpeed(CAT_SPEED);
	findRandomLocation();
}

void Cat::handleCollision(GameObject& gameObject)
{
    // double dispatch
    gameObject.handleCollision(*this);
}

void Cat::handleCollision(Mouse& otherObject)
{
	// call the player so it can decrease its own live count
	otherObject.handleCollision(*this);
}

sf::Vector2i Cat::findRandomLocation()
{
	// set size for range
	float rangeMax = this->getSprite().getGlobalBounds().getSize().x * CAT_SPEED / 2;
	float rangeMin = -rangeMax;

	// Generate a random float between 0 and 1
	float randomX = (float)rand() / RAND_MAX;
	float randomY = (float)rand() / RAND_MAX;

	// Scale and shift the random float to fit the desired range
	m_nextLocation.x = randomX * (rangeMax - rangeMin) + rangeMin;
	m_nextLocation.y = randomY * (rangeMax - rangeMin) + rangeMin;

	return m_nextLocation;
}

void Cat::moveToRandomLocation(const float dtSeconds)
{
	if (m_nextLocation.x > 0) {
		// move right
		this->move(1, 0, dtSeconds);
		m_nextLocation.x--;
	} else if (m_nextLocation.x < 0) {
		// move left
		this->move(-1, 0, dtSeconds);
		m_nextLocation.x++;
	} else if (m_nextLocation.y > 0) {
		// move down
		this->move(0, 1, dtSeconds);
		m_nextLocation.y--;
	} else if (m_nextLocation.y < 0) {
		// move up
		this->move(0, -1, dtSeconds);
		m_nextLocation.y++;
	}
	else {
		m_nextLocation = findRandomLocation();
	}
}

void Cat::handleCollision(Wall& otherObject)
{
	m_nextLocation.x = 0;
	m_nextLocation.y = 0;
	this->setToLastPosition();
}

void Cat::handleCollision(Door& otherObject)
{
	m_nextLocation.x = 0;
	m_nextLocation.y = 0;
	this->setToLastPosition();
}
