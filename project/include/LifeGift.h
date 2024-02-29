#pragma once

#include "Gift.h"

class LifeGift : public Gift {
public:
	LifeGift(const sf::Vector2f position, const float size, sf::Texture* texture);
	virtual ~LifeGift() = default;

	// double dispatch handling collision
	void handleCollision(Mouse&) override;
	void handleCollision(Cat&) override { ; };

private:
};