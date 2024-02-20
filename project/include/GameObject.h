#pragma once

#include <SFML/Graphics.hpp>

class GameObject {
public:
	GameObject(const sf::Vector2f position, sf::Vector2f size, sf::Texture* texture);
	virtual ~GameObject() = default;

	// for collision checking
	sf::FloatRect getObjectBounds() const;

	void draw(sf::RenderWindow& window) const;
protected:
	sf::Sprite m_sprite;
};