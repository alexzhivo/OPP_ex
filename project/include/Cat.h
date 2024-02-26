#pragma once

#include "MovingObject.h"

enum state { IDLE , PATROL , SEARCH };

const float CAT_SPEED = 80.f;

class Cat : public MovingObject {
public:
	Cat(const sf::Vector2f position, const float size,
		sf::Texture* frontTexture,
		sf::Texture* leftTexture,
		sf::Texture* backTexture,
		sf::Texture* rightTexture);
	virtual ~Cat() = default;

	// double dispatch handling collision
	void handleCollision(GameObject& otherObject) override;
	void handleCollision(Mouse& otherObject) override;
	void handleCollision(Cat&) override {};
	void handleCollision(Cheese&) override {};
	void handleCollision(Wall& otherObject) override;
	void handleCollision(Gift&) override {};
	void handleCollision(Key&) override {};
	void handleCollision(Door& otherObject) override;

	// cats algorithm
	
		// search for mouse in range.

		// find a random location in range.
	sf::Vector2i findRandomLocation();
		// move until get to x location.
		// move until get to y location.
	void moveToRandomLocation(const float dtSeconds);
		// if collision with wall stop.

private:
	sf::Vector2i m_nextLocation;
};