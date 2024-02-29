#pragma once

#include "Gift.h"

class TimeGift : public Gift {
public:
	TimeGift(const sf::Vector2f position, const float size, sf::Texture* texture);
	virtual ~TimeGift() = default;

	// double dispatch handling collision
	void handleCollision(Mouse&) override;
	void handleCollision(Cat&) override { ; };

private:
};