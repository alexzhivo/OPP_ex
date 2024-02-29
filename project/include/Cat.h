#pragma once

#include "MovingObject.h"

const float CAT_SPEED = 80.f;

class Cat : public MovingObject {
public:
	Cat(const sf::Vector2f position, const float size,
		sf::Texture* frontTexture,
		sf::Texture* leftTexture,
		sf::Texture* backTexture,
		sf::Texture* rightTexture);
	virtual ~Cat() = default;

	// double dispatch handling collision
	void handleCollision(GameObject& otherObject) override;
	void handleCollision(Mouse& otherObject) override;
	void handleCollision(Cat&) override {};
	void handleCollision(Cheese&) override {};
	void handleCollision(Wall& otherObject) override;
	void handleCollision(Key&) override {};
	void handleCollision(Door& otherObject) override;
	void handleCollision(Gift&) override {};
	void handleCollision(LifeGift&) override {};
	void handleCollision(TimeGift&) override {};
	void handleCollision(FreezeGift&) override {};
	void handleCollision(EnemyRemoveGift&) override {};

	sf::Vector2i findRandomLocation();
	void moveToRandomLocation(const float dtSeconds, const sf::Vector2f boardSize, const sf::Vector2f start);

private:
	sf::Vector2i m_nextLocation;
};