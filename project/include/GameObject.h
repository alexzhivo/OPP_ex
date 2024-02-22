#pragma once

class Mouse;
class Cheese;
class Wall;

#include <SFML/Graphics.hpp>

class GameObject {
public:
	GameObject(const sf::Vector2f position, sf::Vector2f size, sf::Texture* texture);
	virtual ~GameObject() = default;

	// double dispatch collision handling
	sf::Sprite getSprite() const { return m_sprite; }; //copy
	sf::Sprite& getSprite() { return m_sprite; }; // ref

	bool collide_with(const GameObject& otherObject);

	virtual void handleCollision(GameObject& otherObject) = 0;
	virtual void handleCollision(Mouse& otherObject) = 0;
	virtual void handleCollision(Cheese& otherObject) = 0;
	virtual void handleCollision(Wall& otherObject) = 0;

	void draw(sf::RenderWindow& window) const;
protected:
	sf::Sprite m_sprite;
};