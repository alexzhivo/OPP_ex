#pragma once

#include "StaticObject.h"

class Cheese : public StaticObject {
public:
	Cheese(const sf::Vector2f position, const float size, sf::Texture* texture);
	virtual ~Cheese() = default;

	// double dispatch handling collision
	void handleCollision(GameObject& otherObject) override { ; };
	void handleCollision(Mouse& otherObject) override;
	void handleCollision(Cat& otherObject) override { ; };
	void handleCollision(Cheese& otherObject) override { ; };
	void handleCollision(Wall& otherObject) override { ; };
	void handleCollision(Gift& otherObject) override { ; };
	void handleCollision(Key& otherObject) override { ; };
	void handleCollision(Door& otherObject) override { ; };

private:
};