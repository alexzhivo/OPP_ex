#pragma once

#include "MovingObject.h"

const float CAT_SPEED = 100.f;

class Cat : public MovingObject {
public:
	Cat(const sf::Vector2f position, const float size, sf::Texture* texture);
	virtual ~Cat() = default;

	// double dispatch handling collision
	void handleCollision(GameObject& otherObject) override;
	void handleCollision(Mouse& otherObject) override;
	void handleCollision(Cat&) override {};
	void handleCollision(Cheese&) override {};
	void handleCollision(Wall&) override {};
	void handleCollision(Gift&) override {};
	void handleCollision(Key&) override {};
	void handleCollision(Door&) override {};

private:
};