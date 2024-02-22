#pragma once

#include "StaticObject.h"

class Key : public StaticObject {
public:
	Key(const sf::Vector2f position, sf::Vector2f size, sf::Texture* texture);
	virtual ~Key() = default;

	// double dispatch handling collision
	void handleCollision(GameObject& otherObject) override { ; };
	void handleCollision(Mouse& otherObject) override;
	void handleCollision(Cheese& otherObject) override { ; };
	void handleCollision(Wall& otherObject) override { ; };
	void handleCollision(Gift& otherObject) override { ; };
	void handleCollision(Key& otherObject) override { ; };

private:
};