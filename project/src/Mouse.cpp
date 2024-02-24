#include "Mouse.h"

Mouse::Mouse(const sf::Vector2f position, sf::Vector2f size, sf::Texture* texture)
	: MovingObject(position, size, texture), m_lives(3) , m_score(0), m_keys(0), m_startingPosition(position)
{
	this->setSpeed(MOUSE_SPEED);
	m_sprite.setScale(0.75f, 0.75f);	// for fiting through wall openings
}

int Mouse::getLives() const
{
	return m_lives;
}
int Mouse::getKeys() const
{
	return m_keys;
}
int Mouse::getScore() const
{
	return m_score;
}

void Mouse::reduceLifeCount()
{
	m_lives--;
	if (m_lives > 0) {
		m_sprite.setPosition(m_startingPosition);
	}
	else {
		this->eliminate();
	}
}
void Mouse::increaseScore(const int amount)
{
	m_score += amount;
}

void Mouse::increaseKeys()
{
	m_keys++;
}

bool Mouse::useKey()
{
	if (m_keys > 0) {
		m_keys--;
		return true;
	}
	return false;
}

void Mouse::handleCollision(GameObject& otherObject)
{
	otherObject.handleCollision(*this);
}