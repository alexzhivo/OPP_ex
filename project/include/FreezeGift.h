#pragma once

#include "Gift.h"

class FreezeGift : public Gift {
public:
	FreezeGift(const sf::Vector2f position, const float size, sf::Texture* texture);
	virtual ~FreezeGift() = default;

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