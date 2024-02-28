#pragma once

#include "Gift.h"

class LifeGift : public Gift {
public:
	LifeGift(const sf::Vector2f position, const float size, sf::Texture* texture);
	virtual ~LifeGift() = default;

	// double dispatch handling collision
	//void handleCollision(GameObject& otherObject) override;
	void handleCollision(Mouse&) override;
	void handleCollision(Cat&) override { ; };
	//void handleCollision(Cheese& otherObject) override { ; };
	//void handleCollision(Wall& otherObject) override { ; };
	//void handleCollision(Gift& otherObject) override { ; };
	//void handleCollision(Key& otherObject) override { ; };
	//void handleCollision(Door& otherObject) override { ; };

private:
};