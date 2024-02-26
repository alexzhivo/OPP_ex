#pragma once

#include "StaticObject.h"

class Key : public StaticObject {
public:
	Key(const sf::Vector2f position, const float size, sf::Texture* texture);
	virtual ~Key() = default;

	// double dispatch handling collision
	//void handleCollision(GameObject& otherObject) override { ; };
	void handleCollision(Mouse&) override { this->remove();  };
	void handleCollision(Cat&) override {};
	//void handleCollision(Cheese& otherObject) override { ; };
	//void handleCollision(Wall& otherObject) override { ; };
	//void handleCollision(Gift& otherObject) override { ; };
	//void handleCollision(Key& otherObject) override { ; };
	//void handleCollision(Door& otherObject) override { ; };

private:
};