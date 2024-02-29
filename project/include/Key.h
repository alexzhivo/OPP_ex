#pragma once

#include "StaticObject.h"

class Key : public StaticObject {
public:
	Key(const sf::Vector2f position, const float size, sf::Texture* texture);
	virtual ~Key() = default;

	// double dispatch handling collision
	void handleCollision(Mouse& otherObject) override;
	void handleCollision(Cat&) override { ; };

private:
};