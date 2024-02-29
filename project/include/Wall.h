#pragma once

#include "StaticObject.h"

class Wall : public StaticObject {
public:
	Wall(const sf::Vector2f position, const float size, sf::Texture* texture);
	virtual ~Wall() = default;

	// double dispatch handling collision
	void handleCollision(GameObject&) override {};
	void handleCollision(Mouse& otherObject) override;
	void handleCollision(Cat& otherObject) override;

private:
};