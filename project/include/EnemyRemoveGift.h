#pragma once

#include "Gift.h"

class EnemyRemoveGift : public Gift {
public:
	EnemyRemoveGift(const sf::Vector2f position, const float size, sf::Texture* texture);
	virtual ~EnemyRemoveGift() = default;

	// double dispatch handling collision
	void handleCollision(Mouse&) override;
	void handleCollision(Cat&) override {};

private:
};