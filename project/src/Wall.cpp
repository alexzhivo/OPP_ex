#include "Wall.h"

Wall::Wall(const sf::Vector2f position, sf::Vector2f size)
	: StaticObject(position, size)
{
	// wall sprite
	m_sprite.setFillColor(sf::Color::Red);
}