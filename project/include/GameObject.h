#pragma once

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <math.h>

// forward declaration
class Mouse;
class Cheese;
class Wall;
class Key;
class Door;
class Cat;
class Gift;
class EnemyRemoveGift;
class LifeGift;
class FreezeGift;
class TimeGift;

class GameObject {
public:
	GameObject(const sf::Vector2f position, const float size, sf::Texture* texture);
	virtual ~GameObject() = default;

	// double dispatch collision handling
	sf::Sprite getSprite() const { return m_sprite; };	// for copy
	sf::Sprite& getSprite() { return m_sprite; };	    // for ref

	bool collide_with(const GameObject& otherObject);

	virtual void handleCollision(GameObject& otherObject) = 0;
	virtual void handleCollision(Mouse& otherObject) = 0;
	virtual void handleCollision(Cat& otherObject) = 0;
	virtual void handleCollision(Cheese& otherObject) = 0;
	virtual void handleCollision(Wall& otherObject) = 0;
	virtual void handleCollision(Key& otherObject) = 0;
	virtual void handleCollision(Door& otherObject) = 0;
	virtual void handleCollision(Gift& otherObject) = 0;
	virtual void handleCollision(LifeGift& otherObject) = 0;
	virtual void handleCollision(TimeGift& otherObject) = 0;
	virtual void handleCollision(FreezeGift& otherObject) = 0;
	virtual void handleCollision(EnemyRemoveGift& otherObject) = 0;

	void draw(sf::RenderWindow& window) const;
protected:
	sf::Sprite m_sprite;
};