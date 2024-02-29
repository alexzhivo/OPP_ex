#pragma once

#include "StaticObject.h"

class Door : public StaticObject {
public:
	Door(const sf::Vector2f position, const float size, sf::Texture* texture);
	virtual ~Door() = default;

	// double dispatch handling collision
	void handleCollision(Mouse& otherObject) override;
	void handleCollision(Cat& otherObject) override;

private:
};