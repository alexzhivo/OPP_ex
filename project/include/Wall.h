#pragma once

#include "StaticObject.h"

class Wall : public StaticObject {
public:
	Wall(const sf::Vector2f position, sf::Vector2f size, sf::Texture* texture);
	virtual ~Wall() = default;

	// double dispatch handling collision
	void handleCollision(GameObject& otherObject) override { ; };
	void handleCollision(Mouse& otherObject) override { ; };
	void handleCollision(Cheese& otherObject) override { ; };

private:
};