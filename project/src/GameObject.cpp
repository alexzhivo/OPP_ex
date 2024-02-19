#include "GameObject.h"

GameObject::GameObject(const sf::Vector2f position, sf::Vector2f size)
	: m_sprite()
{
	// create the temp sprite for Object
	m_sprite.setPosition(position);
	m_sprite.setSize(size);
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