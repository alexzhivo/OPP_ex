#include "GameObject.h"

GameObject::GameObject(const sf::Vector2f position,const float size, sf::Texture* texture)
	: m_sprite()
{
	// create the temp sprite for Object
	m_sprite.setTexture(*texture);
	m_sprite.setPosition(position);
	m_sprite.setScale(sf::Vector2f(size, size));
}

bool GameObject::collide_with(const GameObject& otherObject)
{
	return getSprite().getGlobalBounds().intersects(otherObject.getSprite().getGlobalBounds());
}

void GameObject::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}