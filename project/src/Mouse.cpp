#include "Mouse.h"

Mouse::Mouse(const sf::Vector2f position, sf::Vector2f size, sf::Texture* texture)
	: MovingObject(position, size, texture), m_lives(3)
{
	this->setSpeed(MOUSE_SPEED);
	m_sprite.scale(0.5f, 0.5f);
}

void Mouse::reduceLifeCount()
{
	m_lives--;
	if (!m_lives)
		this->eliminate();
}

void Mouse::handleCollision(GameObject& otherObject)
{
	otherObject.handleCollision(*this);
}