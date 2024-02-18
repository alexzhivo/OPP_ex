#include "Wall.h"

Wall::Wall(const sf::Vector2f position)
	: StaticObject(position)
{
	// wall sprite
	m_sprite.setFillColor(sf::Color::Red);
}