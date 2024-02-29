#pragma once

#include "Gift.h"

class FreezeGift : public Gift {
public:
	FreezeGift(const sf::Vector2f position, const float size, sf::Texture* texture);
	virtual ~FreezeGift() = default;

	// double dispatch handling collision
	void handleCollision(Mouse&) override;
	void handleCollision(Cat&) override { ; };

private:
};