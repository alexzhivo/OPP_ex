#pragma once

#include "MovingObject.h"

const float MOUSE_SPEED = 300.f;

enum CollisionType { NoCollision , PickUpKey , PickUpCheese ,
	OpenDoor , LoseLife , PickUpLife , PickUpEnemyRemove ,
	PickUpFreeze , PickUpTime };

class Mouse : public MovingObject {
public:
	Mouse(const sf::Vector2f position, const float size,
		sf::Texture* frontTexture,
		sf::Texture* leftTexture,
		sf::Texture* backTexture,
		sf::Texture* rightTexture);
	virtual ~Mouse() = default;

	// get 
	int getLives() const;
	int getKeys() const;
	int getScore() const;
	CollisionType getCollisionType();

	void increaseScore(const int amount);
	void increaseKeys();
	void increaseLife();
	bool useKey();
	void reduceLifeCount();

	// double dispatch handling collision
	void handleCollision(GameObject& otherObject) override;
	void handleCollision(Mouse&) override { ; };
	void handleCollision(Cat& otherObject) override;
	void handleCollision(Cheese& otherObject) override;
	void handleCollision(Wall& otherObject) override;
	void handleCollision(Key& otherObject) override;
	void handleCollision(Door& otherObject) override;
	void handleCollision(Gift&) override {};
	void handleCollision(LifeGift&) override;
	void handleCollision(TimeGift&) override;
	void handleCollision(FreezeGift&) override;
	void handleCollision(EnemyRemoveGift&) override;

	void reload(sf::Vector2f position, float size);
	void reset();
	void setReset();
private:

	CollisionType m_collision;
	int m_lives;
	int m_keys;
	int m_score;

	sf::Vector2f m_startingPosition;
	int m_startingLives;
	int m_startingScore;
	int m_startingKeys;
};