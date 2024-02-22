#pragma once

#include "MovingObject.h"

const float CAT_SPEED = 100.f;

class Cat : public MovingObject {
public:
	Cat(const sf::Vector2f position, sf::Vector2f size, sf::Texture* texture);
	virtual ~Cat() = default;

	// double dispatch handling collision
	void handleCollision(GameObject& otherObject) override { ; };
	void handleCollision(Mouse& otherObject) override { ; };
	void handleCollision(Cheese& otherObject) override { ; };

private:
};