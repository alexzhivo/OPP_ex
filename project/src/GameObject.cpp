#include "GameObject.h"

GameObject::GameObject(const sf::Vector2f position)
	: m_sprite()
{
	// create the temp sprite for Object
	m_sprite.setPosition(position);
	m_sprite.setSize(sf::Vector2f(50, 50));
}

// for collision checking
sf::FloatRect GameObject::getObjectBounds() const
{
	return m_sprite.getGlobalBounds();
}

void GameObject::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}