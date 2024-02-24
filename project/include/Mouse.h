#pragma once

#include "MovingObject.h"

const float MOUSE_SPEED = 300.f;

class Mouse : public MovingObject {
public:
	Mouse(const sf::Vector2f position, const float size, sf::Texture* texture);
	virtual ~Mouse() = default;

	// get 
	int getLives() const;
	int getKeys() const;
	int getScore() const;

	void increaseScore(const int amount);
	void increaseKeys();
	bool useKey();

	// double dispatch handling collision
	void handleCollision(GameObject& otherObject) override;
	void handleCollision(Mouse& otherObject) override { ; };
	void handleCollision(Cat& otherObject) override { ; };
	void handleCollision(Cheese& otherObject) override { ; };
	void handleCollision(Wall& otherObject) override { ; };
	void handleCollision(Gift& otherObject) override { ; };
	void handleCollision(Key& otherObject) override { ; };
	void handleCollision(Door& otherObject) override { ; };

	void reduceLifeCount();
private:
	sf::Vector2f m_startingPosition;
	int m_lives;
	int m_keys;
	int m_score;
};