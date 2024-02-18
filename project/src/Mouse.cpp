#include "Mouse.h"

Mouse::Mouse(const sf::Vector2f position)
	: MovingObject(position), m_lives(3)
{
	m_sprite.setFillColor(sf::Color::White);
	this->setSpeed(MOUSE_SPEED);
}

void Mouse::reduceLifeCount()
{
	m_lives--;
	if (!m_lives)
		this->eliminate();
}