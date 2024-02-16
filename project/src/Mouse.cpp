#include "Mouse.h"

Mouse::Mouse(const sf::Vector2f position)
	: m_position(position) , m_sprite()
{
	// create the temp sprite for mouse
	m_sprite.setPosition(m_position);
	m_sprite.setSize(sf::Vector2f(50,50));
	m_sprite.setFillColor(sf::Color::White);
}

void Mouse::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

bool Mouse::isAlive()
{
	return m_alive;
}

void Mouse::move(float offsetX, float offsetY, float deltaTime) {
	float distanceX = offsetX * m_speed * deltaTime;
	float distanceY = offsetY * m_speed * deltaTime;
	m_sprite.move(distanceX, distanceY);
}