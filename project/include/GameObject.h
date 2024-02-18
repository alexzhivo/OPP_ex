#pragma once

#include <SFML/Graphics.hpp>

class GameObject {
public:
	GameObject(const sf::Vector2f position);
	virtual ~GameObject() = default;

	// for collision checking
	sf::FloatRect getObjectBounds() const;

	void draw(sf::RenderWindow& window) const;
protected:
	sf::RectangleShape m_sprite;
};